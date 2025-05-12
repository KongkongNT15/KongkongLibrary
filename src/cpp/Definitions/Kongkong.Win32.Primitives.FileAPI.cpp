//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    bool FileAPI::AreFileApisANSI() noexcept
    {
        return (bool)::AreFileApisANSI();
    }

    ::HANDLE FileAPI::Create(const char16_t* fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, ::SECURITY_ATTRIBUTES& securityAttributes, IO::FileOpenMode fileOpenMode, IO::FileAttribute attribute, IO::FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile)
    {
        HANDLE handle = ::CreateFileW((const wchar_t*)fileName, (DWORD)fileAccessMode, (DWORD)shareMode, &securityAttributes, (DWORD)fileOpenMode, (DWORD)attribute | (DWORD)flag | (DWORD)securityFlag, hTemplateFile);

        if (handle == INVALID_HANDLE_VALUE) [[unlikely]] throw HResultException();

        return handle;
    }

    ::HANDLE FileAPI::Create(const char16_t* fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, IO::FileOpenMode fileOpenMode, IO::FileAttribute attribute, IO::FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile)
    {
        HANDLE handle = ::CreateFileW((const wchar_t*)fileName, (DWORD)fileAccessMode, (DWORD)shareMode, nullptr, (DWORD)fileOpenMode, (DWORD)attribute | (DWORD)flag | (DWORD)securityFlag, hTemplateFile);

        if (handle == INVALID_HANDLE_VALUE) throw HResultException();

        return handle;
    }

    ::HANDLE FileAPI::Create(const char16_t* fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, IO::FileOpenMode fileOpenMode, IO::FileAttribute attribute, IO::FileFlag flag, SecurityFlag securityFlag)
    {
        return Create(fileName, fileAccessMode, shareMode, fileOpenMode, attribute, flag, securityFlag, nullptr);
    }

    ::HANDLE FileAPI::Create(const char16_t* fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, IO::FileOpenMode fileOpenMode, IO::FileAttribute attribute, IO::FileFlag flag)
    {
        return Create(fileName, fileAccessMode, shareMode, fileOpenMode, attribute, flag, SecurityFlag::None, nullptr);
    }

    ::HANDLE FileAPI::Create(const char16_t* fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, IO::FileOpenMode fileOpenMode)
    {
        return Create(fileName, fileAccessMode, shareMode, fileOpenMode, IO::FileAttribute::Normal, IO::FileFlag::None, SecurityFlag::None, nullptr);
    }

    ::HANDLE FileAPI::Create(const char16_t* fileName, IO::FileAccessMode fileAccessMode, IO::FileOpenMode fileOpenMode)
    {
        return Create(fileName, fileAccessMode, IO::FileShareMode::Private, fileOpenMode, IO::FileAttribute::Normal, IO::FileFlag::None, SecurityFlag::None, nullptr);
    }

    ::HANDLE FileAPI::Create(String const& fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, ::SECURITY_ATTRIBUTES& securityAttributes, IO::FileOpenMode fileOpenMode, IO::FileAttribute attribute, IO::FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile)
    {
        return Create(fileName.c_str(), fileAccessMode, shareMode, securityAttributes, fileOpenMode, attribute, flag, securityFlag, hTemplateFile);
    }

    ::HANDLE FileAPI::Create(String const& fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, IO::FileOpenMode fileOpenMode, IO::FileAttribute attribute, IO::FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile)
    {
        return FileAPI::Create(fileName.c_str(), fileAccessMode, shareMode, fileOpenMode, attribute, flag, securityFlag, hTemplateFile);
    }

    ::HANDLE FileAPI::Create(String const& fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, IO::FileOpenMode fileOpenMode, IO::FileAttribute attribute, IO::FileFlag flag, SecurityFlag securityFlag)
    {
        return Create(fileName.c_str(), fileAccessMode, shareMode, fileOpenMode, attribute, flag, securityFlag);
    }

    ::HANDLE FileAPI::Create(String const& fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, IO::FileOpenMode fileOpenMode, IO::FileAttribute attribute, IO::FileFlag flag)
    {
        return Create(fileName, fileAccessMode, shareMode, fileOpenMode, attribute, flag, SecurityFlag::None, nullptr);
    }

    ::HANDLE FileAPI::Create(String const& fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, IO::FileOpenMode fileOpenMode)
    {
        return Create(fileName.c_str(), fileAccessMode, shareMode, fileOpenMode);
    }

    ::HANDLE FileAPI::Create(String const& fileName, IO::FileAccessMode fileAccessMode, IO::FileOpenMode fileOpenMode)
    {
        return Create(fileName.c_str(), fileAccessMode, IO::FileShareMode::Private, fileOpenMode);
    }

    void FileAPI::Delete(char16_t const* fileName)
    {
        if (::DeleteFileW((const wchar_t*)fileName) == 0) [[unlikely]] throw HResultException();
    }

    void FileAPI::Delete(String const& fileName)
    {
        Delete(fileName.c_str());
    }

    void FileAPI::FindClose(::HANDLE hFindFile)
    {
        if (::FindClose(hFindFile) == 0) [[unlikely]] throw HResultException();
    }

    void FileAPI::FlushBuffers(::HANDLE hFile)
    {
        if (::FlushFileBuffers(hFile) == 0) [[unlikely]] throw HResultException();
    }

    IO::DriveKind FileAPI::GetCurrentDriveKind() noexcept
    {
        return GetDriveKind(nullptr);
    }

    IO::DriveKind FileAPI::GetDriveKind(const char16_t* rootPathName) noexcept
    {
        return (IO::DriveKind)::GetDriveTypeW((const wchar_t*)rootPathName);
    }

    IO::DriveKind FileAPI::GetDriveKind(String const& rootPathName) noexcept
    {
        return GetDriveKind(rootPathName.c_str());
    }

    IO::FileAttribute FileAPI::GetFileAttributes(const char16_t* fileName)
    {
        DWORD value = ::GetFileAttributesW((const wchar_t*)fileName);
        if (value == INVALID_FILE_ATTRIBUTES) [[unlikely]] throw HResultException();

        return (IO::FileAttribute)value;
    }

    IO::FileAttribute FileAPI::GetFileAttributes(String const& fileName)
    {
        return GetFileAttributes(fileName.c_str());
    }

    int64_t FileAPI::GetFileSize(HANDLE hFile)
    {
        LARGE_INTEGER integer;
        if (::GetFileSizeEx(hFile, &integer) == 0) [[unlikely]] throw HResultException();

        return integer.QuadPart;
    }

    int64_t FileAPI::GetFileSizeUnsafe(::HANDLE hFile) noexcept
    {
        LARGE_INTEGER integer;
        ::GetFileSizeEx(hFile, &integer);

        return integer.QuadPart;
    }

    IO::FileType FileAPI::GetFileType(::HANDLE hFile)
    {
        DWORD value = ::GetFileType(hFile);
        if (::GetLastError() != NO_ERROR) throw HResultException();

        return (IO::FileType)value;
    }

    IO::FileType FileAPI::GetFileTypeUnsafe(::HANDLE hFile) noexcept
    {
        return (IO::FileType)::GetFileType(hFile);
    }

    String FileAPI::GetFinalPathName(HANDLE hFile)
    {
        return GetFinalPathName(hFile, IO::FileNameKind::Normalized, IO::VolumeNameKind::DOS);
    }

    String FileAPI::GetFinalPathName(HANDLE hFile, IO::FileNameKind fileNameType)
    {
        return GetFinalPathName(hFile, fileNameType, IO::VolumeNameKind::DOS);
    }

    String FileAPI::GetFinalPathName(HANDLE hFile, IO::VolumeNameKind volumeNameType)
    {
        return GetFinalPathName(hFile, IO::FileNameKind::Normalized, volumeNameType);
    }

    String FileAPI::GetFinalPathName(HANDLE hFile, IO::FileNameKind fileNameType, IO::VolumeNameKind volumeNameType)
    {
        unsigned flag = (unsigned)fileNameType | (unsigned)volumeNameType;
        DWORD length = ::GetFinalPathNameByHandleW(hFile, nullptr, 0, flag);
        if (length == 0) throw HResultException();

        char16_t* c16s = String::AllocMemoryUnsafe(length);

        if (::GetFinalPathNameByHandleW(hFile, (wchar_t*)c16s, length, flag) == 0) [[unlikely]] {
            String::FreeMemoryUnsafe(c16s);

            throw HResultException();
        }

        return String::WrapUnsafe(length, length - 1, c16s);
    }

    FILETIME FileAPI::LocalFileTimeToFileTime(FILETIME const& value)
    {
        FILETIME fileTime;
        if (::LocalFileTimeToFileTime(&value, &fileTime) == 0) [[unlikely]] throw HResultException();

        return fileTime;
    }

    Collections::IArray<String> FileAPI::LogicalDrives()
    {
        uint32_t length = ::GetLogicalDriveStringsW(0, nullptr);
        if (length == 0) [[unlikely]] throw HResultException();

        char16_t* c16s = NEW char16_t[length];

        MemoryAllocationException::CheckNull(c16s);

        if (::GetLogicalDriveStringsW(length, (wchar_t*)c16s) == 0) [[unlikely]] throw HResultException();

        char16_t* p = c16s;
        char16_t* end = p + length - 1;

        Collections::ArrayList<String> list;
        auto& listInstance = Object::GetInstanceUnsafe(list);

        while (p != end) {
            ssize_t pLength = Text::StringHelper::GetLengthUnsafe(p);
            listInstance += String::FromPointerUnsafe(pLength, p, true);
            p += pLength + 1;
        }

        delete[] c16s;

        return list;
    }

    uint8_t FileAPI::Read(::HANDLE hFileHandle)
    {
        uint8_t value;
        DWORD tmp;
        if (::ReadFile(hFileHandle, &value, 1u, &tmp, nullptr) == 0) throw HResultException();

        return value;
    }

    uint8_t FileAPI::Read(::HANDLE hFileHandle, ::OVERLAPPED& overlapped)
    {
        uint8_t value;
        DWORD tmp;
        if (::ReadFile(hFileHandle, &value, 1u, &tmp, &overlapped) == 0) throw HResultException();

        return value;
    }

    uint8_t FileAPI::ReadUnsafe(::HANDLE hFileHandle) noexcept
    {
        uint8_t value;
        DWORD tmp;
        ::ReadFile(hFileHandle, &value, 1u, &tmp, nullptr);

        return value;
    }

    uint8_t FileAPI::ReadUnsafe(::HANDLE hFileHandle, ::OVERLAPPED& overlapped) noexcept
    {
        uint8_t value;
        DWORD tmp;
        ::ReadFile(hFileHandle, &value, 1u, &tmp, &overlapped);

        return value;
    }

    Collections::IArray<uint8_t> FileAPI::Read(HANDLE hFileHandle, uint32_t length)
    {
        DWORD tmp;
        Collections::Array<uint8_t> arr(length);
        auto& arrInstance = Object::GetInstanceUnsafe(arr);

        if (::ReadFile(hFileHandle, arrInstance.Data(), (DWORD)length, &tmp, nullptr) == 0) throw HResultException();

        return arr;
    }

    Collections::IArray<uint8_t> FileAPI::Read(HANDLE hFileHandle, uint32_t length, ::OVERLAPPED& overlapped)
    {
        DWORD tmp;
        Collections::Array<uint8_t> arr(length);
        auto& arrInstance = Object::GetInstanceUnsafe(arr);

        if (::ReadFile(hFileHandle, arrInstance.Data(), (DWORD)length, &tmp, &overlapped) == 0) throw HResultException();

        return arr;
    }

    void FileAPI::RemoveDirectory(const char16_t* directoryName)
    {
        if (::RemoveDirectoryW((const wchar_t*)directoryName) == 0) throw HResultException();
    }

    void FileAPI::RemoveDirectory(String const& directoryName)
    {
        RemoveDirectory(directoryName.c_str());
    }

    void FileAPI::SetFileAttributes(const char16_t* fileName, IO::FileAttribute attributes)
    {
        if (::SetFileAttributesW((const wchar_t*)fileName, (DWORD)attributes) == 0) throw HResultException();
    }

    void FileAPI::SetFileAttributes(String const& fileName, IO::FileAttribute attributes)
    {
        SetFileAttributes(fileName.c_str(), attributes);
    }

    String FileAPI::TempPath()
    {
        constexpr uint32_t length = MaxPathLength() + 1;
        char16_t* p = String::AllocMemoryUnsafe(length);

        if (::GetTempPath2W(length, (wchar_t*)p) == 0u) [[unlikely]] throw HResultException();

        return String::WrapUnsafe(length, p);
    }

    void FileAPI::Write(::HANDLE hFile, uint8_t value)
    {
        Write(hFile, &value, 1);
    }

    uint32_t FileAPI::Write(::HANDLE hFile, const void* buffer, uint32_t length)
    {
        DWORD writtenLength;

        if (::WriteFile(hFile, buffer, length, &writtenLength, nullptr) == 0) [[unlikely]] throw HResultException();

        return writtenLength;
    }

    bool FileAPI::WriteUnsafe(::HANDLE hFile, uint8_t value) noexcept
    {
        return (bool)::WriteFile(hFile, &value, 1, nullptr, nullptr);
    }

    uint32_t FileAPI::WriteUnsafe(::HANDLE hFile, const void* buffer, uint32_t length) noexcept
    {
        DWORD writtenLength;

        ::WriteFile(hFile, buffer, length, &writtenLength, nullptr);

        return writtenLength;
    }

    void FileAPI::Write(::HANDLE hFile, uint8_t value, ::OVERLAPPED& overlapped)
    {
        Write(hFile, &value, 1, overlapped);
    }

    uint32_t FileAPI::Write(::HANDLE hFile, const void* buffer, uint32_t length, ::OVERLAPPED& overlapped)
    {
        DWORD writtenLength;

        if (::WriteFile(hFile, buffer, length, &writtenLength, &overlapped) == 0) [[unlikely]] throw HResultException();

        return writtenLength;
    }
}
