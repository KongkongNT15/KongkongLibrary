#ifndef KONGKONG_WIN32_COMPUTERNAME_H
#define KONGKONG_WIN32_COMPUTERNAME_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    class ComputerName final {
        public:

        STATIC_CLASS(ComputerName)

        /// @brief ふぁ！？っく
        static void DnsDomain(std::nullptr_t) = delete;

        [[nodiscard]] static String DnsDomain();
        static void DnsDomain(const char16_t* value);
        static void DnsDomain(String const& value);

        /// @brief ふぁ！？っく
        static void DnsFullyQualified(std::nullptr_t) = delete;

        [[nodiscard]] static String DnsFullyQualified();
        static void DnsFullyQualified(const char16_t* value);
        static void DnsFullyQualified(String const& value);

        /// @brief ふぁ！？っく
        static void DnsHostname(std::nullptr_t) = delete;

        [[nodiscard]] static String DnsHostname();
        static void DnsHostname(const char16_t* value);
        static void DnsHostname(String const& value);

        /// @brief ふぁ！？っく
        static void NetBIOS(std::nullptr_t) = delete;

        [[nodiscard]] static String NetBIOS();
        static void NetBIOS(const char16_t* value);
        static void NetBIOS(String const& value);

        /// @brief ふぁ！？っく
        static void PhysicalDnsDomain(std::nullptr_t) = delete;

        [[nodiscard]] static String PhysicalDnsDomain();
        static void PhysicalDnsDomain(const char16_t* value);
        static void PhysicalDnsDomain(String const& value);

        /// @brief ふぁ！？っく
        static void PhysicalDnsFullyQualified(std::nullptr_t) = delete;

        [[nodiscard]] static String PhysicalDnsFullyQualified();
        static void PhysicalDnsFullyQualified(const char16_t* value);
        static void PhysicalDnsFullyQualified(String const& value);

        /// @brief ふぁ！？っく
        static void PhysicalDnsHostname(std::nullptr_t) = delete;

        [[nodiscard]] static String PhysicalDnsHostname();
        static void PhysicalDnsHostname(const char16_t* value);
        static void PhysicalDnsHostname(String const& value);

        /// @brief ふぁ！？っく
        static void PhysicalNetBIOS(std::nullptr_t) = delete;

        [[nodiscard]] static String PhysicalNetBIOS();
        static void PhysicalNetBIOS(const char16_t* value);
        static void PhysicalNetBIOS(String const& value);
        
        private:
        static String _getComputerName(::COMPUTER_NAME_FORMAT nameType);
        static void _setComputerName(::COMPUTER_NAME_FORMAT nameType, const char16_t* value);
        static void _setComputerName(::COMPUTER_NAME_FORMAT nameType, String const& value);
    
    };
}

#endif //!KONGKONG_WIN32_COMPUTERNAME_H
