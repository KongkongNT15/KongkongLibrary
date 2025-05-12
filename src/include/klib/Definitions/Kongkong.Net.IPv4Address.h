#ifndef KONGKONG_NET_IPV4ADDRESS_H
#define KONGKONG_NET_IPV4ADDRESS_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Net
{
    struct IPv4Address final : public ValueType {

        constexpr IPv4Address(uint8_t octetA, uint8_t octetB, uint8_t octetC, uint8_t octetD) : _octetA(octetA), _octetB(octetB), _octetC(octetC), _octetD(octetD) {}

        [[nodiscard]]
        constexpr uint8_t OctetA() const noexcept { return _octetA; }

        constexpr void OctetA(uint8_t value) noexcept { _octetA = value; }

        [[nodiscard]]
        constexpr uint8_t OctetB() const noexcept { return _octetB; }

        constexpr void OctetB(uint8_t value) noexcept { _octetB = value; }

        [[nodiscard]]
        constexpr uint8_t OctetC() const noexcept { return _octetC; }

        constexpr void OctetC(uint8_t value) noexcept { _octetC = value; }

        [[nodiscard]]
        constexpr uint8_t OctetD() const noexcept { return _octetD; }

        constexpr void OctetD(uint8_t value) noexcept { _octetD = value; }

        /// @brief 
        /// @return u"XX.XX.XX.XX"
        [[nodiscard]]
        String ToString() const;

        private:
        uint8_t _octetA;
        uint8_t _octetB;
        uint8_t _octetC;
        uint8_t _octetD;
    };

    [[nodiscard]] constexpr bool operator==(IPv4Address const& left, IPv4Address const& right) noexcept { return *(int32_t*)(&left) == *(int32_t*)(&right); }
    [[nodiscard]] constexpr bool operator!=(IPv4Address const& left, IPv4Address const& right) noexcept { return *(int32_t*)(&left) != *(int32_t*)(&right); }
}

#endif //!KONGKONG_NET_IPV4ADDRESS_H
