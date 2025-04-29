#ifndef KONGKONG_SYSTEM_CPPVERSION_H
#define KONGKONG_SYSTEM_CPPVERSION_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::System
{
    struct CppVersion final : public ValueType {

        [[nodiscard]]
        static constexpr CppVersion Cpp03() noexcept { return CppVersion(KONGKONG_CPP03); }

        [[nodiscard]]
        static constexpr CppVersion Cpp11() noexcept { return CppVersion(KONGKONG_CPP11); }

        [[nodiscard]]
        static constexpr CppVersion Cpp14() noexcept { return CppVersion(KONGKONG_CPP14); }

        [[nodiscard]]
        static constexpr CppVersion Cpp17() noexcept { return CppVersion(KONGKONG_CPP17); }

        [[nodiscard]]
        static constexpr CppVersion Cpp20() noexcept { return CppVersion(KONGKONG_CPP20); }

        [[nodiscard]]
        static constexpr CppVersion Cpp23() noexcept { return CppVersion(KONGKONG_CPP23); }

        [[nodiscard]]
        static constexpr CppVersion Current() noexcept { return CppVersion(KONGKONG_CPP_LANG_VERSION); }

        [[nodiscard]]
        constexpr bool HasCpp03() const noexcept { return _version >= KONGKONG_CPP03; }

        [[nodiscard]]
        constexpr bool HasCpp11() const noexcept { return _version >= KONGKONG_CPP11; }

        [[nodiscard]]
        constexpr bool HasCpp14() const noexcept { return _version >= KONGKONG_CPP14; }

        [[nodiscard]]
        constexpr bool HasCpp17() const noexcept { return _version >= KONGKONG_CPP17; }

        [[nodiscard]]
        constexpr bool HasCpp20() const noexcept { return _version >= KONGKONG_CPP20; }

        [[nodiscard]]
        constexpr bool HasCpp23() const noexcept { return _version >= KONGKONG_CPP23; }

        constexpr CppVersion& operator++() noexcept
        {
            switch (_version) {
                case KONGKONG_CPP03: _version = KONGKONG_CPP11; break;
                case KONGKONG_CPP11: _version = KONGKONG_CPP14; break;
                case KONGKONG_CPP14: _version = KONGKONG_CPP17; break;
                case KONGKONG_CPP17: _version = KONGKONG_CPP20; break;
                case KONGKONG_CPP20: _version = KONGKONG_CPP23; break;
                case KONGKONG_CPP23: _version = KONGKONG_CPP03; break;
            };

            return *this;
        }

        constexpr CppVersion operator++(int) noexcept
        {
            CppVersion ret = *this;
            operator++();

            return ret;
        }

        constexpr CppVersion& operator--() noexcept
        {
            switch (_version) {
                case KONGKONG_CPP03: _version = KONGKONG_CPP23; break;
                case KONGKONG_CPP11: _version = KONGKONG_CPP03; break;
                case KONGKONG_CPP14: _version = KONGKONG_CPP11; break;
                case KONGKONG_CPP17: _version = KONGKONG_CPP14; break;
                case KONGKONG_CPP20: _version = KONGKONG_CPP17; break;
                case KONGKONG_CPP23: _version = KONGKONG_CPP20; break;
            };
            
            return *this;
        }

        constexpr CppVersion operator--(int) noexcept
        {
            CppVersion ret = *this;
            operator--();

            return ret;
        }

        [[nodiscard]]
        String ToString() const;

        private:
        long _version;

        constexpr CppVersion(long version) noexcept : _version(version) {}

        friend constexpr bool operator==(CppVersion const&, CppVersion const&) noexcept;
        friend constexpr bool operator!=(CppVersion const&, CppVersion const&) noexcept;
        friend constexpr bool operator<(CppVersion const&, CppVersion const&) noexcept;
        friend constexpr bool operator<=(CppVersion const&, CppVersion const&) noexcept;
        friend constexpr bool operator>(CppVersion const&, CppVersion const&) noexcept;
        friend constexpr bool operator>=(CppVersion const&, CppVersion const&) noexcept;
        friend constexpr ::std::strong_ordering operator<=>(CppVersion const&, CppVersion const&) noexcept;
    };

    [[nodiscard]] constexpr bool operator==(CppVersion const& left, CppVersion const& right) noexcept { return left._version == right._version; }
    [[nodiscard]] constexpr bool operator!=(CppVersion const& left, CppVersion const& right) noexcept { return left._version != right._version; }
    [[nodiscard]] constexpr bool operator<(CppVersion const& left, CppVersion const& right) noexcept { return left._version < right._version; }
    [[nodiscard]] constexpr bool operator<=(CppVersion const& left, CppVersion const& right) noexcept { return left._version <= right._version; }
    [[nodiscard]] constexpr bool operator>(CppVersion const& left, CppVersion const& right) noexcept { return left._version > right._version; }
    [[nodiscard]] constexpr bool operator>=(CppVersion const& left, CppVersion const& right) noexcept { return left._version >= right._version; }
    [[nodiscard]] constexpr ::std::strong_ordering operator<=>(CppVersion const& left, CppVersion const& right) noexcept { return left._version <=> right._version; }
}

#endif //!KONGKONG_SYSTEM_CPPVERSION_H
