//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    void LibLoaderAPI::FreeLibrary(::HMODULE hLibraryModule)
    {
        if (::FreeLibrary(hLibraryModule) == 0) [[unlikely]] throw HResultException();
    }

    String LibLoaderAPI::GetModuleFileName(::HMODULE hModule)
    {
        DWORD length = FileAPI::MaxPathLength();

        char16_t* c16s = String::AllocMemoryUnsafe(length);

        DWORD tmp;

        while (true) {
            tmp = ::GetModuleFileNameW(hModule, (wchar_t*)c16s, length);
            if (tmp == 0) {
                String::FreeMemoryUnsafe(c16s);

                throw HResultException();
            }

            //正常終了
            if (tmp < length) break;

            String::FreeMemoryUnsafe(c16s);

            length += FileAPI::MaxPathLength();

            c16s = String::AllocMemory(length);
        }

        return String::WrapUnsafe(length, c16s);
    }

    void* LibLoaderAPI::GetProcedureAdress(::HMODULE hModule, const char* procName)
    {
        void* p = ::GetProcAddress(hModule, procName);
        if (p == nullptr) [[unlikely]] throw HResultException();

        return p;
    }

    void* LibLoaderAPI::GetProcedureAdress(::HMODULE hModule, const char16_t* procName)
    {
        void* p = ::GetProcAddress(hModule, std::to_string(procName).c_str());
        if (p == nullptr) [[unlikely]] throw HResultException();

        return p;
    }

    void* LibLoaderAPI::GetProcedureAdress(::HMODULE hModule, String const& procName)
    {
        return GetProcedureAdress(hModule, std::to_string(procName).c_str());
    }

    ::HMODULE LibLoaderAPI::LoadLibrary(const char16_t* libraryFileName)
    {
        ::HMODULE module = ::LoadLibraryW((const wchar_t*)libraryFileName);
        if (module == nullptr) [[unlikely]] throw HResultException();

        return module;
    }

    ::HMODULE LibLoaderAPI::LoadLibrary(String const& libraryFileName)
    {
        return LoadLibrary(libraryFileName.c_str());
    }

    ::HMODULE LibLoaderAPI::LoadLibrary(const char16_t* libraryFileName, LoadLibraryFlag flag)
    {
        ::HMODULE module = ::LoadLibraryExW((const wchar_t*)libraryFileName, nullptr, (DWORD)flag);
        if (module == nullptr) [[unlikely]] throw HResultException();

        return module;
    }

    ::HMODULE LibLoaderAPI::LoadLibrary(String const& libraryFileName, LoadLibraryFlag flag)
    {
        return LoadLibrary(libraryFileName.c_str(), flag);
    }

}
