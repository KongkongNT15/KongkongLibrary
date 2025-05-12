#ifndef KONGKONG_THREADING_GENERATOR_H
#define KONGKONG_THREADING_GENERATOR_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.PointerType.h"
#include "Kongkong.LazyObject.h"
#include "Kongkong.Threading.TaskStatus.h"
#include "Kongkong.InvalidOperationException.h"

#include <coroutine>

namespace KONGKONG_NAMESPACE::Threading
{
    template <class T>
    struct Generator final : public ValueType {

        struct Iterator;
        struct promise_type final {

            constexpr promise_type() noexcept : _value(), _pIterator(nullptr), _pGenerator(nullptr) {}

            Generator get_return_object() noexcept { return *this; }

            static constexpr ::std::suspend_always initial_suspend() noexcept { return {}; }
            static constexpr ::std::suspend_always final_suspend() noexcept { return {}; }

            static constexpr void return_void() noexcept {}

            [[noreturn]]
            void unhandled_exception();

            ::std::suspend_always yield_value(T const& value) noexcept(::std::is_nothrow_constructible_v<T>)
            {
                _value.InitializeUnsafe(value);
                return {};
            }

            ::std::suspend_always yield_value(T&& value) noexcept
            {
                _value.InitializeUnsafe(::std::move(value));
                return {};
            }

            T __getValue()
            {
                if (!_value.IsInitialized()) [[unlikely]] throw InvalidOperationException(u"同じ値を2回取得することはできません");
                T v = ::std::move(_value.GetValueUnsafe());
                _value.ResetUnsafe();

                return v;
            }
            constexpr bool __hasRefenrece() const noexcept { return _pGenerator != nullptr && _pIterator != nullptr; }
            constexpr bool __noReference() const noexcept { return _pGenerator == nullptr || _pIterator == nullptr; }

            private:
            LazyObject<T> _value;

            Generator* _pGenerator;
            Iterator* _pIterator;

            friend Generator;
            friend Iterator;
        };

        using handleType = ::std::coroutine_handle<promise_type>;

        struct Iterator final : public PointerType {

            constexpr Iterator() noexcept : _h_coro(nullptr), _done(true) {}
            Iterator(Iterator const&) = delete;
            constexpr Iterator(Iterator&& right) noexcept : _h_coro(right._h_coro), _done(right._done) { right._h_coro = nullptr; }

            ~Iterator()
            {
                if (!_h_coro) return;
                
                auto& promise = _h_coro.promise();

                promise._pIterator = nullptr;

                if (promise._pGenerator == nullptr) _h_coro.destroy();
            }

            Iterator& operator=(Iterator const&) = delete;

            Iterator& operator++()
            {
                //if (!_h_coro) [[unlikely]] throw InvalidOperationException(u"破棄されたオブジェクトにアクセスしようとしました");
                _h_coro.resume();

                _done = _h_coro.done();

                return *this;
            }

            friend constexpr bool operator!=(Iterator const& left, Iterator const& right) noexcept { return left._done != right._done; }

            T operator*() const
            {
                //if (!_h_coro) [[unlikely]] throw InvalidOperationException(u"破棄されたオブジェクトにアクセスしようとしました");
                return _h_coro.promise().__getValue();
            }

            private:
            handleType _h_coro;
            bool _done;

            Iterator(handleType h) noexcept : _h_coro(h), _done(h.done())
            {
                h.promise()._pIterator = this;
            }

            friend Generator;
            friend promise_type;
        };

        Generator(Generator const&) = delete;
        constexpr Generator(Generator&& right) noexcept : _h(right._h), _begun(right.begun) { right._h = nullptr; }

        ~Generator()
        {
            if (!_h) return;
            
            auto& promise = _h.promise();

            promise._pGenerator = nullptr;

            if (promise._pIterator == nullptr) _h.destroy();
        }

        Generator& operator=(Generator const&) = delete;

        [[nodiscard]]
        Iterator begin()
        {
            if (_begun) [[unlikely]] throw InvalidOperationException(u"begin()が2回呼ばれました");
            _begun = true;
            _h.resume();
            return Iterator(_h);
        }

        [[nodiscard]] static constexpr Iterator end() noexcept { return Iterator(); }

        [[nodiscard]]
        bool IsFinished() const noexcept { return _h.done(); }

        [[nodiscard]]
        bool IsRunning() const noexcept { return !_h.done(); }

        private:

        handleType _h;
        bool _begun;

        Generator(promise_type& promise) noexcept : _h(handleType::from_promise(promise)), _begun(false)
        {
            promise._pGenerator = this;
        }
    };
}

namespace KONGKONG_NAMESPACE::Threading
{
    template <class T>
    void Generator<T>::promise_type::unhandled_exception()
    {
        auto h = _pGenerator->_h;
        _pGenerator->_h = nullptr;

        if (_pIterator != nullptr) _pIterator->_h_coro = nullptr;

        h.destroy();
        
        ::std::rethrow_exception(::std::current_exception());
    }
}

#endif //!KONGKONG_THREADING_GENERATOR_H
