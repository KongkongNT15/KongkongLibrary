//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Threading
{
    AsyncAction AsyncAction::DelayAsync(uint32_t milliseconds) noexcept
    {
        return ThreadPool::RunAsync(Thread::Sleep, milliseconds);
    }

    AsyncAction AsyncAction::promise_type::get_return_object()
    {
        return AsyncAction(*this);
    }

    void AsyncAction::await_resume() const
    {
        _awaiterBase::_throw();
    }

    AsyncAction::AsyncAction(AsyncAction&& right) noexcept :
        _awaiterBase(::std::move(right)),
        _handle(std::move(right._handle))
    {
        switch (_status) {
            case TaskStatus::Canceled:
            case TaskStatus::Completed:
            case TaskStatus::Faulted:
                break;

            default:
                _handle.promise().__action = this;
                break;
        }

        right._handle = nullptr;
    }

    AsyncAction::~AsyncAction()
    {
        if (_handle == nullptr) return;

        switch (_status) {
            case TaskStatus::Canceled:
            case TaskStatus::Completed:
            case TaskStatus::Faulted:
                break;

            default:
                _handle.promise().__action = nullptr;
                break;
        }
    }

    String AsyncAction::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Threading::AsyncAction");
    }

    AsyncAction::AsyncAction(promise_type& promise) : _handle(::std::coroutine_handle<promise_type>::from_promise(promise))
    {
        promise.__action = this;
    }
}
