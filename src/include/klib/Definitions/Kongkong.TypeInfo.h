#ifndef KONGKONG_TYPEINFO_H
#define KONGKONG_TYPEINFO_H

#include "Base.h"
#include "Kongkong.ValueType.h"

#include <typeinfo>

namespace KONGKONG_NAMESPACE
{
    struct TypeInfo final : public ValueType {

        TypeInfo(TypeInfo const& right);
        TypeInfo(TypeInfo&& right);

        ~TypeInfo();

        TypeInfo& operator=(TypeInfo const& right);
        TypeInfo& operator=(TypeInfo&& right);

        friend constexpr bool operator==(TypeInfo const& left, TypeInfo const& right) noexcept { return left._hashCode == right._hashCode; }

        /// @brief 型のハッシュ値
        [[nodiscard]]
        constexpr size_t HashCode() const noexcept { return _hashCode; }

        /// @brief クラス名
        [[nodiscard]]
        constexpr const char* Name() const noexcept { return _name; }

        [[nodiscard]]
        String ToString() const;

        private:
        friend IMPLEMENTATION::Object;

        TypeInfo(::std::type_info const& info);

        size_t _hashCode;
        char* _name;
    };
}

#endif //!KONGKONG_TYPEINFO_H
