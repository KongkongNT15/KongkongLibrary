//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    CThreadPool::CThreadPool() : _buffer(), _conditionVariable(), _taskQueue(), _mutex(CMutexKind::Recursive), _isRunning(true)
    {
        _buffer.AllocUnsafe(System::Environment::ProcessorCount());

        CThread* p = _buffer.begin();
        CThread* end = _buffer.end();

        while (p != end) {
            try {
                new (p) CThread(_threadFunction, this);
            }
            catch (...) {
                _isRunning = false;
                CThread* q = _buffer.begin();

                while (q != p) {
                    q->~CThread();
                    ++q;
                }
            }
            
            p++;
        }
    }

    CThreadPool::~CThreadPool()
    {
        _mutex.LockUnsafe();
        _isRunning = false;
        _mutex.UnlockUnsafe();

        for (CThread& thread : _buffer) {
            thread.Join();
        }

        _buffer.DestoryAllUnsafe();
    }

    void CThreadPool::PushTask(FuncType func)
    {
        _checkFunc(func);
        
        PushTaskUnsafe(func);
    }

    void CThreadPool::PushTask(FuncType func, std::nullptr_t)
    {
        _checkFunc(func);
        
        PushTaskUnsafe(func, nullptr);
    }

    void CThreadPool::PushTask(FuncType func, void* args)
    {
        _checkFunc(func);
        
        PushTaskUnsafe(func, args);
    }

    void CThreadPool::PushTaskUnsafe(FuncType func)
    {
        CScopeLock lock(_mutex);

        _taskQueue.Push({ func, nullptr });

        _conditionVariable.SignalUnsafe();
    }

    void CThreadPool::PushTaskUnsafe(FuncType func, std::nullptr_t)
    {
        CScopeLock lock(_mutex);

        _taskQueue.Push({ func, nullptr });

        _conditionVariable.SignalUnsafe();
    }

    void CThreadPool::PushTaskUnsafe(FuncType func, void* args)
    {
        CScopeLock lock(_mutex);

        _taskQueue.Push({ func, args });

        _conditionVariable.SignalUnsafe();
    }

    String CThreadPool::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::CStd::CThreadPool");
    }

    int CThreadPool::_threadFunction(void* args) noexcept
    {
        //C++23 [[assume(args != nullptr)]];

        CThreadPool* pCThreadPool = static_cast<CThreadPool*>(args);
        CMutex* pMutex = &pCThreadPool->_mutex;
        auto pTaskQueue = &pCThreadPool->_taskQueue;
        bool* pIsRunning = &pCThreadPool->_isRunning;
        CConditionVariable* pConditionVariable = &pCThreadPool->_conditionVariable;

        while (true) {
            FuncType func;
            void* args;
            {
                CScopeLock lock(pCThreadPool->_mutex);

                while (pTaskQueue->IsEmpty() && *pIsRunning) {
                    pConditionVariable->Wait(*pMutex);
                }

                if (!(*pIsRunning) && pTaskQueue->IsEmpty()) break;

                auto pair = pTaskQueue->PopUnsafe();

                func = pair.Key();
                args = pair.Value();
            }
            
            func(args);
        }

        return 0;
    }

    void CThreadPool::_checkFunc(FuncType func)
    {
        if (func == nullptr) [[unlikely]] ArgumentNullException::ThrowWithName(u"func");
    }
}
