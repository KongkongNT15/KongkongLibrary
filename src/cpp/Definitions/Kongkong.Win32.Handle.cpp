//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32
{
    std::map<::HANDLE, Handle::_handleCounter> Handle::_typeMap = { { INVALID_HANDLE_VALUE, ClassType::Null } };
    ::KONGKONG_NAMESPACE::Threading::Mutex Handle::_mutex;

    Handle::_handleWrapper::_handleWrapper(_handleWrapper const& right) noexcept
    {
        __handle = right.__handle;

        if (right.__handle == INVALID_HANDLE_VALUE) [[unlikely]] return;

        _mutex.Lock();
        ++_typeMap[__handle];
        _mutex.Unlock();
    }

    Handle::_handleWrapper::~_handleWrapper()
    {
        __close();
    }

    Handle::_handleWrapper& Handle::_handleWrapper::operator=(Handle::_handleWrapper const& right) noexcept
    {
        __close();

        __handle = right.__handle;
        if (right.__handle == INVALID_HANDLE_VALUE) [[unlikely]] return *this;

        _mutex.Lock();
        ++_typeMap[__handle];
        _mutex.Unlock();

        return *this;
    }

    Handle::_handleWrapper& Handle::_handleWrapper::operator=(Handle::_handleWrapper&& right) noexcept
    {
        __close();

        __handle = right.__handle;

        right.__handle = Primitives::HandleAPI::InvalidValue();

        return *this;
    }

    Handle::_handleWrapper& Handle::_handleWrapper::operator=(std::nullptr_t) noexcept
    {
        __close();

        return *this;
    }

    bool Handle::_handleWrapper::__close() noexcept
    {
        if (__handle == INVALID_HANDLE_VALUE) return false;

        _mutex.Lock();
        auto& counter = --_typeMap[__handle];

        if (!counter.__hasHandle()) {
            ::CloseHandle(__handle);
            _typeMap.erase(__handle);
        }

        _mutex.Unlock();

        __handle = INVALID_HANDLE_VALUE;

        return true;
    }

    std::pair<std::map<::HANDLE, Handle::_handleCounter>::iterator, bool> Handle::_handleWrapper::__rawHandle(::HANDLE handle, ClassType type)
    {
        ::KONGKONG_NAMESPACE::Threading::ScopeLock lock(_mutex);
        __handle = handle;

        return _typeMap.try_emplace(handle, type);
    }

    void Handle::_handleWrapper::__setRawHandle(::HANDLE handle, ClassType type)
    {
        __handle = handle;
        ::KONGKONG_NAMESPACE::Threading::ScopeLock lock(_mutex);

        auto&& pair = _typeMap.try_emplace(handle, type);

        if (!pair.second) {
            auto& counter = (*pair.first).second;

            ++counter;
        } 
    }

    template <>
    Handle Handle::As<Handle>() const noexcept
    {
        return *this;
    }

    bool Handle::Close() noexcept
    {
        return _h.__close();
    }

    template <>
    bool Handle::Is<Handle>() const noexcept
    {
        return *this != nullptr;
    }

    String Handle::ToString() const
    {
        _mutex.Lock();
        ClassType type = _typeMap[_h.__rawHandle()].__classType();
        _mutex.Unlock();
        switch (type) {
            case ClassType::Event: return Threading::Event::_toString(*this);
            case ClassType::Mutex: return Threading::Mutex::_toString(*this);
            case ClassType::Null: return String::FromLiteral(u"Null");
            case ClassType::OutputDevice: return IO::OutputDevice::_toString(*this);
            case ClassType::Semaphore: return Threading::Semaphore::_toString(*this);
            case ClassType::Thread: return Threading::Thread::_toString(*this);
        }
    }

    ClassType Handle::Type() const noexcept
    {
        ::KONGKONG_NAMESPACE::Threading::ScopeLock lock(_mutex);
        return _typeMap[_h.__rawHandle()].__classType();
    }

    bool Handle::_canCastHandle(ClassType from, ClassType to) noexcept
    {
        switch (from) {
            case ClassType::Event:
            {
                switch (to) {
                    case ClassType::Event:
                    case ClassType::WaitHandle:
                        return true;

                    default: return false;
                }
                //C++23 ::std::unreachable();
                break;
            }
            case ClassType::Mutex:
            {
                switch (to) {
                    case ClassType::Mutex:
                    case ClassType::WaitHandle:
                        return true;

                    default: return false;
                }
                //C++23 ::std::unreachable();
                break;
            }
            case ClassType::Null: return false;
            case ClassType::OutputDevice:
            {
                switch (to) {
                    case ClassType::IODevice:
                    case ClassType::OutputDevice:
                    return true;

                    default: return false;
                }
                //C++23 ::std::unreachable();
                break;
            }
            case ClassType::Semaphore:
            {
                switch (to) {
                    case ClassType::Semaphore:
                    case ClassType::WaitHandle:
                        return true;

                    default: return false;
                }
                //C++23 ::std::unreachable();
                break;
            }
            case ClassType::Thread:
            {
                switch (to) {
                    case ClassType::Thread:
                    case ClassType::WaitHandle:
                        return true;

                    default: return false;
                }
                //C++23 ::std::unreachable();
                break;
            }

            default: 
                //C++23 ::std::unreachable();
                return false;
        }

        //C++23 ::std::unreachable();
    }

    bool operator==(Handle const& left, Handle const& right) noexcept
    {
        if (!left) return !right;

        return (bool)::CompareObjectHandles(left._h.__rawHandle(), right._h.__rawHandle());
    }

    bool operator!=(Handle const& left, Handle const& right) noexcept
    {
        return !(left == right);
    }
}

CREATE_CLASS_TYPE(Handle, Handle)
