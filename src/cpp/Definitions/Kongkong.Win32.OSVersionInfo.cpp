//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32
{
    String OSVersionInfo::CSDVersion() const
    {
        return String::FromPointerUnsafe((char16_t*)_info.szCSDVersion, true);
    }

    String OSVersionInfo::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Win32::OSVersionInfo");
    }

}
