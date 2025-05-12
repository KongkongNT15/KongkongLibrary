//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32
{
    String ComputerName::DnsDomain()
    {
        return _getComputerName(::COMPUTER_NAME_FORMAT::ComputerNameDnsDomain);
    }

    void ComputerName::DnsDomain(const char16_t* value)
    {
        _setComputerName(::COMPUTER_NAME_FORMAT::ComputerNameDnsDomain, value);
    }

    void ComputerName::DnsDomain(String const& value)
    {
        DnsDomain(value.c_str());
    }

    String ComputerName::DnsFullyQualified()
    {
        return _getComputerName(::COMPUTER_NAME_FORMAT::ComputerNameDnsFullyQualified);
    }

    void ComputerName::DnsFullyQualified(const char16_t* value)
    {
        _setComputerName(::COMPUTER_NAME_FORMAT::ComputerNameDnsFullyQualified, value);
    }

    void ComputerName::DnsFullyQualified(String const& value)
    {
        DnsFullyQualified(value.c_str());
    }

    String ComputerName::DnsHostname()
    {
        return _getComputerName(::COMPUTER_NAME_FORMAT::ComputerNameDnsHostname);
    }

    void ComputerName::DnsHostname(const char16_t* value)
    {
        _setComputerName(::COMPUTER_NAME_FORMAT::ComputerNameDnsHostname, value);
    }

    void ComputerName::DnsHostname(String const& value)
    {
        DnsHostname(value.c_str());
    }

    String ComputerName::NetBIOS()
    {
        return _getComputerName(::COMPUTER_NAME_FORMAT::ComputerNameNetBIOS);
    }

    void ComputerName::NetBIOS(const char16_t* value)
    {
        _setComputerName(::COMPUTER_NAME_FORMAT::ComputerNameNetBIOS, value);
    }

    void ComputerName::NetBIOS(String const& value)
    {
        NetBIOS(value.c_str());
    }

    String ComputerName::PhysicalDnsDomain()
    {
        return _getComputerName(::COMPUTER_NAME_FORMAT::ComputerNamePhysicalDnsDomain);
    }

    void ComputerName::PhysicalDnsDomain(const char16_t* value)
    {
        _setComputerName(::COMPUTER_NAME_FORMAT::ComputerNamePhysicalDnsDomain, value);
    }

    void ComputerName::PhysicalDnsDomain(String const& value)
    {
        PhysicalDnsDomain(value.c_str());
    }

    String ComputerName::PhysicalDnsFullyQualified()
    {
        return _getComputerName(::COMPUTER_NAME_FORMAT::ComputerNamePhysicalDnsFullyQualified);
    }

    void ComputerName::PhysicalDnsFullyQualified(const char16_t* value)
    {
        _setComputerName(::COMPUTER_NAME_FORMAT::ComputerNamePhysicalDnsFullyQualified, value);
    }

    void ComputerName::PhysicalDnsFullyQualified(String const& value)
    {
        PhysicalDnsFullyQualified(value.c_str());
    }

    String ComputerName::PhysicalDnsHostname()
    {
        return _getComputerName(::COMPUTER_NAME_FORMAT::ComputerNamePhysicalDnsHostname);
    }

    void ComputerName::PhysicalDnsHostname(const char16_t* value)
    {
        _setComputerName(::COMPUTER_NAME_FORMAT::ComputerNamePhysicalDnsHostname, value);
    }

    void ComputerName::PhysicalDnsHostname(String const& value)
    {
        PhysicalDnsHostname(value.c_str());
    }

    String ComputerName::PhysicalNetBIOS()
    {
        return _getComputerName(::COMPUTER_NAME_FORMAT::ComputerNamePhysicalNetBIOS);
    }

    void ComputerName::PhysicalNetBIOS(const char16_t* value)
    {
        _setComputerName(::COMPUTER_NAME_FORMAT::ComputerNamePhysicalNetBIOS, value);
    }

    void ComputerName::PhysicalNetBIOS(String const& value)
    {
        PhysicalNetBIOS(value.c_str());
    }

    String ComputerName::_getComputerName(::COMPUTER_NAME_FORMAT nameType)
    {
        DWORD length;
        ::GetComputerNameExW(nameType, nullptr, &length);

        char16_t* p = String::AllocMemoryUnsafe(length);

        if (::GetComputerNameExW(nameType, (wchar_t*)p, &length) == 0) [[unlikely]] {
            String::FreeMemoryUnsafe(p);

            throw HResultException();
        }

        return String::WrapUnsafe(length, p);
    }

    void ComputerName::_setComputerName(::COMPUTER_NAME_FORMAT nameType, const char16_t* value)
    {
        if (::SetComputerNameExW(nameType, (const wchar_t*)value) == 0) throw HResultException();
    }

    void ComputerName::_setComputerName(::COMPUTER_NAME_FORMAT nameType, String const& value)
    {
        _setComputerName(nameType, value.c_str());
    }

}
