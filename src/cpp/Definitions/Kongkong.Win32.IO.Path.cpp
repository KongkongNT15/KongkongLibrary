//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::IO
{
    bool Path::Exists(const char16_t* path) noexcept
    {
        WIN32_FIND_DATA tmp;
        HANDLE hFind = ::FindFirstFileW((const wchar_t*)path, &tmp);

        ::SetLastError(NO_ERROR);

        if (hFind == Primitives::HandleAPI::InvalidValue()) return false;

        ::FindClose(hFind);

        return true;
    }

    bool Path::Exists(String const& path) noexcept
    {
        return Exists(path.c_str());
    }

    Collections::IArray<FileSystemInfo> Path::Find(const char16_t* path)
    {
        WIN32_FIND_DATA data;
        Collections::ArrayList<FileSystemInfo> list;

        auto& rList = Object::GetInstanceUnsafe(list);

        auto error = ::GetLastError();

        HANDLE hFind = ::FindFirstFileW((const wchar_t*)path, &data);

        if (hFind == Primitives::HandleAPI::InvalidValue()) {
            if (::GetLastError() != ERROR_FILE_NOT_FOUND) [[unlikely]] throw HResultException();

            ::SetLastError(error);

            return list;
        }

        rList.Append(data);

        while (::FindNextFileW(hFind, &data)) {
            rList.Append(data);
        }

        ::FindClose(hFind);

        return list;
    }

    Collections::IArray<FileSystemInfo> Path::Find(String const& path)
    {
        return Find(path.c_str());
    }

    Collections::IArray<FileSystemInfo> Path::GetDirectories(const char16_t* path)
    {
        WIN32_FIND_DATA data;
        Collections::ArrayList<FileSystemInfo> list;

        auto& rList = Object::GetInstanceUnsafe(list);

        auto error = ::GetLastError();

        HANDLE hFind = ::FindFirstFileW((const wchar_t*)path, &data);

        if (hFind == Primitives::HandleAPI::InvalidValue()) {
            if (::GetLastError() != ERROR_FILE_NOT_FOUND) [[unlikely]] throw HResultException();

            ::SetLastError(error);

            return list;
        }

        if ((bool)((FileAttribute)data.dwFileAttributes & FileAttribute::Directory)) rList.Append(data);

        while (::FindNextFileW(hFind, &data)) {
            if ((bool)((FileAttribute)data.dwFileAttributes & FileAttribute::Directory)) rList.Append(data);
        }

        ::FindClose(hFind);

        return list;
    }

    Collections::IArray<FileSystemInfo> Path::GetFiles(const char16_t* path)
    {
        WIN32_FIND_DATA data;
        Collections::ArrayList<FileSystemInfo> list;

        auto& rList = Object::GetInstanceUnsafe(list);

        auto error = ::GetLastError();

        HANDLE hFind = ::FindFirstFileW((const wchar_t*)path, &data);

        if (hFind == Primitives::HandleAPI::InvalidValue()) {
            if (::GetLastError() != ERROR_FILE_NOT_FOUND) [[unlikely]] throw HResultException();

            ::SetLastError(error);

            return list;
        }

        if (!(bool)((FileAttribute)data.dwFileAttributes & FileAttribute::Directory)) rList.Append(data);

        while (::FindNextFileW(hFind, &data)) {
            if (!(bool)((FileAttribute)data.dwFileAttributes & FileAttribute::Directory)) rList.Append(data);
        }

        ::FindClose(hFind);

        return list;
    }

    String Path::GetFullPath(const char16_t* name)
    {
        constexpr ssize_t defaultSize = MaxPathLength() + 1;

        ssize_t capacity = defaultSize;
        char16_t* fullPath = String::AllocMemoryUnsafe(capacity);

        DWORD result = ::GetFullPathNameW((const wchar_t*)name, (DWORD)capacity, (wchar_t*)fullPath, nullptr);

        if (result == 0) [[unlikely]] {
            String::FreeMemoryUnsafe(fullPath);
            throw HResultException();
        }

        if ((ssize_t)result > capacity) [[unlikely]] {
            capacity = result;

            String::FreeMemoryUnsafe(fullPath);

            fullPath = String::AllocMemoryUnsafe(capacity);

            if (::GetFullPathNameW((const wchar_t*)name, (DWORD)capacity, (wchar_t*)fullPath, nullptr) == 0) [[unlikely]] {
                String::FreeMemoryUnsafe(fullPath);
                throw HResultException();
            }
        }

        return String::WrapUnsafe(capacity, result, fullPath);
    }

    String Path::GetFullPath(String const& name)
    {
        return GetFullPath(name.c_str());
    }

}
