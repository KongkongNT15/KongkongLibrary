//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Threading
{
    ::std::suspend_never _awaiterBase::promise_type_base::final_suspend() noexcept
    {
        if (__action != nullptr) {
            __action->_status = TaskStatus::Completed;

            if (__action->_hOther != nullptr) __action->_hOther.resume();
        }

        return ::std::suspend_never{};
    }

    void _awaiterBase::await_suspend(::std::coroutine_handle<> h)
    {
        switch (_status) {
            case TaskStatus::Canceled:
            case TaskStatus::Completed:
            case TaskStatus::Faulted:
                h.resume();
                break;
            default:
                _hOther = h;
                break;

        }
    }

    void _awaiterBase::Wait() const noexcept
    {
        using namespace ::std::chrono;

        while (_status == TaskStatus::Waiting || _status == TaskStatus::Running) {
            ::std::this_thread::sleep_for(1ms);
        }
        
    }

    void _awaiterBase::_throw() const
    {
        if (_status == TaskStatus::Faulted) [[unlikely]] throw InvalidOperationException(u"コルーチンが失敗しました");
    }
}
