//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    void WinBase::CopyFile(const char16_t* originalFilePath, const char16_t* newFilePath, bool failIfFileExists)
    {
        if (::CopyFileW((const wchar_t*)originalFilePath, (const wchar_t*)newFilePath, failIfFileExists) == 0) throw HResultException();
    }

    void WinBase::CopyFile(const char16_t* originalFilePath, String const& newFilePath, bool failIfFileExists)
    {
        CopyFile(originalFilePath, newFilePath.c_str(), failIfFileExists);
    }

    void WinBase::CopyFile(String const& originalFilePath, const char16_t* newFilePath, bool failIfFileExists)
    {
        CopyFile(originalFilePath.c_str(), newFilePath, failIfFileExists);
    }

    void WinBase::CopyFile(String const& originalFilePath, String const& newFilePath, bool failIfFileExists)
    {
        CopyFile(originalFilePath.c_str(), newFilePath.c_str(), failIfFileExists);
    }

}
