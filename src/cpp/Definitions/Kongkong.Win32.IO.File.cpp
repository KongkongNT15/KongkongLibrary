//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::IO
{
    void File::Copy(const char16_t* originalFilePath, const char16_t* newFilePath)
    {
        Primitives::WinBase::CopyFile(originalFilePath, newFilePath, true);
    }

    void File::Copy(const char16_t* originalFilePath, String const& newFilePath)
    {
        Primitives::WinBase::CopyFile(originalFilePath, newFilePath, true);
    }

    void File::Copy(String const& originalFilePath, const char16_t* newFilePath)
    {
        Primitives::WinBase::CopyFile(originalFilePath, newFilePath, true);
    }

    void File::Copy(String const& originalFilePath, String const& newFilePath)
    {
        Primitives::WinBase::CopyFile(originalFilePath, newFilePath, true);
    }

    void File::Copy(const char16_t* originalFilePath, const char16_t* newFilePath, bool failIfFileExists)
    {
        Primitives::WinBase::CopyFile(originalFilePath, newFilePath, failIfFileExists);
    }

    void File::Copy(const char16_t* originalFilePath, String const& newFilePath, bool failIfFileExists)
    {
        Primitives::WinBase::CopyFile(originalFilePath, newFilePath, failIfFileExists);
    }

    void File::Copy(String const& originalFilePath, const char16_t* newFilePath, bool failIfFileExists)
    {
        Primitives::WinBase::CopyFile(originalFilePath, newFilePath, failIfFileExists);
    }

    void File::Copy(String const& originalFilePath, String const& newFilePath, bool failIfFileExists)
    {
        Primitives::WinBase::CopyFile(originalFilePath, newFilePath, failIfFileExists);
    }

    void File::Delete(const char16_t* fileName)
    {
        Primitives::FileAPI::Delete(fileName);
    }

    void File::Delete(String const& fileName)
    {
        Primitives::FileAPI::Delete(fileName);
    }

    bool File::Exists(const char16_t* filePath) noexcept
    {
        FileSystemInfo info;

        auto error = ::GetLastError();

        HANDLE hFind = ::FindFirstFileW((const wchar_t*)filePath, &info._data);

        ::SetLastError(error);

        if (hFind == Primitives::HandleAPI::InvalidValue()) return false;

        ::FindClose(hFind);

        return !(bool)(info.Attributes() & FileAttribute::Directory);
    }

    bool File::Exists(String const& filePath) noexcept
    {
        return Exists(filePath.c_str());
    }

}
