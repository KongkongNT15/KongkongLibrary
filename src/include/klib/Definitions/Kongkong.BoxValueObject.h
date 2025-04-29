#ifndef KONGKONG_BOXVALUEOBJECT_H
#define KONGKONG_BOXVALUEOBJECT_H

#include "Base.h"
#include "Kongkong.Object.h"
#include "Kongkong.GenericString.h"

namespace KONGKONG_NAMESPACE::IMPLEMENTATION
{
    //ValueTypeのボックス化に使用
    //ユーザーは直接扱えない
    template <class TKS>
    struct BoxValueObject final : public Object {
        private:
        using ProjType = ::KONGKONG_NAMESPACE::BoxValueObject<TKS>;

        BoxValueObject(TKS const& right) requires std::copy_constructible<TKS> : _value(right) {}
        BoxValueObject(TKS&& right) requires std::move_constructible<TKS> : _value(std::move(right)) {}

        String ToString() const override;

        String _toString() const requires ::std::derived_from<TKS, KongkongTypeBase>;
        String _toString() const requires (::std::integral<TKS> || ::std::floating_point<TKS>);
        String _toString() const;

        TKS _value;

        friend ::KONGKONG_NAMESPACE::BoxValueObject<TKS>;
        friend Object::ProjType;

    };
}

namespace KONGKONG_NAMESPACE
{
    //ValueTypeのボックス化に使用
    //ユーザーは直接扱えない
    template <class TKS>
    class BoxValueObject final : public Object {
        using ImplType = IMPLEMENTATION::BoxValueObject<TKS>;

        BoxValueObject(TKS const& right) requires std::copy_constructible<TKS> : Object(nullptr) { Object::_setInstance(NEW ImplType(right)); }
        BoxValueObject(TKS&& right) requires std::move_constructible<TKS> : Object(nullptr) { Object::_setInstance(NEW ImplType(std::move(right))); }
        constexpr BoxValueObject(std::nullptr_t) noexcept : Object(nullptr) {}

        friend Object;

    };
}

namespace KONGKONG_NAMESPACE::IMPLEMENTATION
{
    template <class TKS>
    String BoxValueObject<TKS>::ToString() const
    {
        return _toString();
    }

    template <class TKS>
    String BoxValueObject<TKS>::_toString() const requires ::std::derived_from<TKS, KongkongTypeBase>
    {
        return _value.ToString();
    }

    template <class TKS>
    String BoxValueObject<TKS>::_toString() const requires (::std::integral<TKS> || ::std::floating_point<TKS>)
    {
        return String::ValueOf(_value);
    }

    template <class TKS>
    String BoxValueObject<TKS>::_toString() const
    {
        return String::FromAsciiUnsafe(typeid(TKS).name());
    }
}

#endif //!KONGKONG_BOXVALUEOBJECT_H
