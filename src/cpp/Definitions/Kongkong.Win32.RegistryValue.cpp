//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32
{
    String RegistryValue::ToString() const
    {
        const char16_t* p;
        switch (_type) {
            case RegistryValueType::None: p = u"REG_NONE"; break;
            case RegistryValueType::String: p = u"REG_SZ"; break;
            case RegistryValueType::ExpandString: p = u"REG_EXPAND_SZ"; break;
            case RegistryValueType::Binary: p = u"REG_BINARY"; break;
            case RegistryValueType::DoubleWord: p = u"REG_DWORD"; break;
            case RegistryValueType::MultiString: p = u"REG_MULTI_SZ"; break;
            case RegistryValueType::QuadWord: p = u"REG_QWORD"; break;
            
            default: [[unlikely]] p = u"Unknown Type"; break;
        }
        
        return String::FromPointerUnsafe(p, true);
    }

    bool operator==(RegistryValue const& left, RegistryValue const& right) noexcept 
    { 
        return left.Value() == right.Value() && left.Type() == right.Type(); 
    }

    bool operator!=(RegistryValue const& left, RegistryValue const& right) noexcept
    {
        return left.Value() != right.Value() && left.Type() != right.Type();
    }
}
