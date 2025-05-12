//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    void ConsoleAPI::AllocConsole()
    {
        ErrorChecker::CheckBool(::AllocConsole());
    }

    uint32_t ConsoleAPI::Fill(HANDLE hOutputHandle, char16_t c, uint32_t length, ConsolePoint const& point)
    {
        DWORD writtenLength;

        if (::FillConsoleOutputCharacterW(hOutputHandle, c, length, point, &writtenLength) == 0) throw HResultException();

        return writtenLength;
    }

    void ConsoleAPI::FreeConsole()
    {
        if (::FreeConsole() == 0) [[unlikely]] throw HResultException();
    }

    HWND ConsoleAPI::Handle() noexcept
    {
        return ::GetConsoleWindow();
    }

    void ConsoleAPI::GenerateCtrlEvent(CtrlKeyEventKind kind, uint32_t processGroupId)
    {
        if (::GenerateConsoleCtrlEvent((uint32_t)kind, processGroupId) == 0) throw HResultException();
    }

    ConsolePoint ConsoleAPI::LargestWindowSize(HANDLE hOutputHandle)
    {
        ConsolePoint info = ::GetLargestConsoleWindowSize(hOutputHandle);

        if (info.IsOrigin()) [[unlikely]] throw HResultException();

        return info;
    }

    uint32_t ConsoleAPI::NumberOfMouseButtons()
    {
        DWORD ret;
        if (GetNumberOfConsoleMouseButtons(&ret) == 0) [[unlikely]] throw HResultException();

        return ret;
    }

    char16_t ConsoleAPI::Read(HANDLE hInputHandle)
    {
        char16_t c;
        DWORD tmp;
        if (::ReadConsoleW(hInputHandle, &c, 1u, &tmp, nullptr) == 0) throw HResultException();

        return c;
    }

    String ConsoleAPI::Read(HANDLE hInputHandle, uint32_t maxLength)
    {
        if (maxLength <= 0) throw InvalidArgumentException(u"maxLengthがゼロ以下でした");

        String str;
        char16_t c;

        for (uint32_t i = 0; i < maxLength; ++i) {
            c = Read(hInputHandle);
            str.Append(c);

            if (c == u'\n') break;
        }

        return str;
    }

    String ConsoleAPI::ReadLine(HANDLE hInputHandle)
    {
        String str;
        char16_t c;

        //Read(HANDLE, ssize_t)の呼び出し直後にコレを呼び出すと u'\n' のみが残っている可能性がある
        while ((c = Read(hInputHandle)) != u'\r' && c != u'\n') {
            str.Append(c);
        }

        if (c == u'\r') (void)Read(hInputHandle);

        return str;
    }

    String ConsoleAPI::OriginalTitle()
    {
        DWORD length = ::GetConsoleTitleW(nullptr, 0);
        if (length == 0) [[unlikely]] throw HResultException();

        char16_t* wcs = String::AllocMemoryUnsafe(length);

        if (::GetConsoleOriginalTitleW((wchar_t*)wcs, length) == 0) [[unlikely]] {
            String::FreeMemoryUnsafe(wcs);

            throw HResultException();
        }

        return String::WrapUnsafe(length, wcs);
    }

    bool ConsoleAPI::SetTitleUnsafe(const char16_t* newTitle) noexcept
    {
        return (bool)::SetConsoleTitleW((const wchar_t*)newTitle);
    }

    bool ConsoleAPI::SetTitleUnsafe(String const& newTitle) noexcept
    {
        return (bool)::SetConsoleTitleW((const wchar_t*)newTitle.c_str());
    }

    HANDLE ConsoleAPI::StandardErrorHandle() noexcept
    {
        return ::GetStdHandle(STD_ERROR_HANDLE);
    }

    HANDLE ConsoleAPI::StandardInputHandle() noexcept
    {
        return ::GetStdHandle(STD_INPUT_HANDLE);
    }

    HANDLE ConsoleAPI::StandardOutputHandle() noexcept
    {
        return ::GetStdHandle(STD_OUTPUT_HANDLE);
    }

    String ConsoleAPI::Title()
    {
        DWORD length = ::GetConsoleTitleW(nullptr, 0);
        if (length == 0) [[unlikely]] throw HResultException();

        char16_t* wcs = String::AllocMemoryUnsafe(length);

        if (::GetConsoleTitleW((wchar_t*)wcs, length) == 0) [[unlikely]] {
            String::FreeMemoryUnsafe(wcs);

            throw HResultException();
        }

        return String::WrapUnsafe(length, wcs);
    }

    void ConsoleAPI::Title(const char16_t* newTitle)
    {
        if (::SetConsoleTitleW((const wchar_t*)newTitle) == 0) [[unlikely]] throw HResultException();
    }

    void ConsoleAPI::Title(String const& newTitle)
    {
        if (::SetConsoleTitleW((const wchar_t*)newTitle.c_str()) == 0) [[unlikely]] throw HResultException();
    }

    uint32_t ConsoleAPI::Write(HANDLE hOutputHandle, char16_t c)
    {
        DWORD ret;

        if (::WriteConsoleW(hOutputHandle, &c, 1u, &ret, nullptr) == 0) [[unlikely]] throw HResultException();

        return ret;
    }

    uint32_t ConsoleAPI::Write(HANDLE hOutputHandle, const char16_t* p, uint32_t length)
    {
        Collections::CollectionHelper::CheckLength(length);
        DWORD ret;

        if (::WriteConsoleW(hOutputHandle, p, (DWORD)length, &ret, nullptr) == 0) [[unlikely]] throw HResultException();

        return ret;
    }

    uint32_t ConsoleAPI::Write(HANDLE hOutput, const char16_t* p)
    {
        return Write(hOutput, p, (uint32_t)Text::StringHelper::GetLength(p));
    }

    uint32_t ConsoleAPI::Write(HANDLE hOutput, StringView const& view)
    {
        return Write(hOutput, view.c_str(), (uint32_t)view.Length());
    }

    uint32_t ConsoleAPI::Write(HANDLE hOutput, String const& str)
    {
        return Write(hOutput, str.c_str(), (uint32_t)str.Length());
    }

    uint32_t ConsoleAPI::WriteLine(HANDLE hOutput)
    {
        return Write(hOutput, u"\r\n");
    }

    uint32_t ConsoleAPI::WriteLine(HANDLE hOutput, char16_t c)
    {
        return Write(hOutput, u"\r\n") + Write(hOutput, c);
    }

    uint32_t ConsoleAPI::WriteLine(HANDLE hOutput, const char16_t* p)
    {

        return Write(hOutput, p) + WriteLine(hOutput);
    }

    uint32_t ConsoleAPI::WriteLine(HANDLE hOutput, const char16_t* p, uint32_t length)
    {
        return Write(hOutput, p, length) + WriteLine(hOutput);
    }

    uint32_t ConsoleAPI::WriteLine(HANDLE hOutput, StringView const& view)
    {
        return Write(hOutput, view) + WriteLine(hOutput);
    }

    uint32_t ConsoleAPI::WriteLine(HANDLE hOutput, String const& str)
    {
        return Write(hOutput, str) + WriteLine(hOutput);
    }

    uint32_t ConsoleAPI::WriteLineUnsafe(HANDLE hOutput) noexcept
    {
        return WriteUnsafe(hOutput, u"\r\n");
    }

    uint32_t ConsoleAPI::WriteLineUnsafe(HANDLE hOutput, char16_t c) noexcept
    {
        return WriteUnsafe(hOutput, u"\r\n") + WriteUnsafe(hOutput, c);
    }

    uint32_t ConsoleAPI::WriteLineUnsafe(HANDLE hOutput, const char16_t* p) noexcept
    {

        return WriteUnsafe(hOutput, p) + WriteLineUnsafe(hOutput);
    }

    uint32_t ConsoleAPI::WriteLineUnsafe(HANDLE hOutput, const char16_t* p, uint32_t length) noexcept
    {
        return WriteUnsafe(hOutput, p, length) + WriteLineUnsafe(hOutput);
    }

    uint32_t ConsoleAPI::WriteLineUnsafe(HANDLE hOutput, StringView const& view) noexcept
    {
        return WriteUnsafe(hOutput, view) + WriteLineUnsafe(hOutput);
    }

    uint32_t ConsoleAPI::WriteLineUnsafe(HANDLE hOutput, String const& str) noexcept
    {
        return WriteUnsafe(hOutput, str) + WriteLineUnsafe(hOutput);
    }

    uint32_t ConsoleAPI::WriteUnsafe(HANDLE hOutputHandle, char16_t c) noexcept
    {
        DWORD ret;

        ::WriteConsoleW(hOutputHandle, &c, 1u, &ret, nullptr);

        return ret;
    }

    uint32_t ConsoleAPI::WriteUnsafe(HANDLE hOutputHandle, const char16_t* p, uint32_t length) noexcept
    {
        DWORD ret;

        ::WriteConsoleW(hOutputHandle, p, (DWORD)length, &ret, nullptr);

        return ret;
    }

    uint32_t ConsoleAPI::WriteUnsafe(HANDLE hOutput, const char16_t* p) noexcept
    {
        return WriteUnsafe(hOutput, p, (uint32_t)Text::StringHelper::GetLengthUnsafe(p));
    }

    uint32_t ConsoleAPI::WriteUnsafe(HANDLE hOutput, StringView const& view) noexcept
    {
        return WriteUnsafe(hOutput, view.c_str(), (uint32_t)view.Length());
    }

    uint32_t ConsoleAPI::WriteUnsafe(HANDLE hOutput, String const& str) noexcept
    {
        return WriteUnsafe(hOutput, str.c_str(), (uint32_t)str.Length());
    }
}
