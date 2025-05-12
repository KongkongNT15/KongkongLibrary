#ifndef KONGKONG_EVENTS_EVENTFUNCTION_H
#define KONGKONG_EVENTS_EVENTFUNCTION_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.GenericString.h"

namespace KONGKONG_NAMESPACE::Events
{
    template <class TSender, class TArgs>
    struct EventFunction final : public ValueType {
        using FunctionType = void (*)(void*, void*, TSender const&, TArgs const&);

        friend constexpr bool operator==(EventFunction const& left, EventFunction const& right) noexcept
        {
            return left._pointer == right._pointer && left._func == right._func && left._funcPointer == right._funcPointer;
        }

        template <class TResult>
        EventFunction(TResult(*func)(TSender const&, TArgs const&)) noexcept :
            _pointer(nullptr),
            _func(func),
            _funcPointer(_callFunction<TResult(*)(TSender const&, TArgs const&)>)
        {
        }

        template <class T, class TFunction>
        EventFunction(T* pointer, TFunction func) noexcept :
            _pointer(pointer),
            _func(_fromMemberFunction(func)),
            _funcPointer(_callMemberFunction<T, TFunction>)
        {
        }

        void Call(TSender const& sender, TArgs const& args)
        {
            _funcPointer(_pointer, _func, sender, args);
        }

        String ToString() const { return String::FromPointerUnsafe(u"Kongkong::Events::EventFunction", true); }

        private:
        void* _pointer;
        void* _func;
        FunctionType _funcPointer;

        template <class TFunction>
        static void _callFunction(void*, void* func, TSender const& sender, TArgs const& args)
        {
            TFunction f = (TFunction)func;
            f(sender, args);
        }

        template <class T, class TFunction>
        static void _callMemberFunction(void* pointer, void* func, TSender const& sender, TArgs const& args)
        {
            void* fp = &func;
            TFunction* tp = (TFunction*)fp;
            TFunction f = *tp;

            T* p = reinterpret_cast<T*>(pointer);

            //ふぁ！？っく
            (p->*f)(sender, args);
        }

        template <class TFunction>
        static void* _fromMemberFunction(TFunction func) noexcept
        {
            void* p = &func;
            void** pp = (void**)p;

            return *pp;
        }
    };
}

#endif //!KONGKONG_EVENTS_EVENTFUNCTION_H
