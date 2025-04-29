//このcppファイルをコンパイルに含めないでください

#define CON_ERROR (::GetStdHandle(STD_ERROR_HANDLE))
#define CON_IN (::GetStdHandle(STD_INPUT_HANDLE))
#define CON_OUT (::GetStdHandle(STD_OUTPUT_HANDLE))

namespace KONGKONG_NAMESPACE::Win32::IO
{
    uint32_t WinConsole::Write(char16_t c)
    {
        return Primitives::ConsoleAPI::Write(CON_OUT, c);
    }

    uint32_t WinConsole::Write(const char16_t* str)
    {
        return Primitives::ConsoleAPI::Write(CON_OUT, str);
    }

    uint32_t WinConsole::Write(uint32_t length, const char16_t* str)
    {
        return Primitives::ConsoleAPI::Write(CON_OUT, str, length);
    }

    uint32_t WinConsole::Write(String const& str)
    {
        return Primitives::ConsoleAPI::Write(CON_OUT, str);
    }

    uint32_t WinConsole::Write(StringView const& str)
    {
        return Primitives::ConsoleAPI::Write(CON_OUT, str);
    }

    uint32_t WinConsole::WriteLine()
    {
        return Primitives::ConsoleAPI::WriteLine(CON_OUT);
    }

    uint32_t WinConsole::WriteLine(char16_t c)
    {
        return Primitives::ConsoleAPI::WriteLine(CON_OUT, c);
    }

    uint32_t WinConsole::WriteLine(const char16_t* str)
    {
        return Primitives::ConsoleAPI::WriteLine(CON_OUT, str);
    }

    uint32_t WinConsole::WriteLine(uint32_t length, const char16_t* str)
    {
        return Primitives::ConsoleAPI::WriteLine(CON_OUT, str, length);
    }

    uint32_t WinConsole::WriteLine(String const& str)
    {
        return Primitives::ConsoleAPI::WriteLine(CON_OUT, str);
    }

    uint32_t WinConsole::WriteLine(StringView const& str)
    {
        return Primitives::ConsoleAPI::WriteLine(CON_OUT, str);
    }

    uint32_t WinConsole::WriteUnsafe(char16_t c) noexcept
    {
        return Primitives::ConsoleAPI::WriteUnsafe(CON_OUT, c);
    }

    uint32_t WinConsole::WriteUnsafe(const char16_t* str) noexcept
    {
        return Primitives::ConsoleAPI::WriteUnsafe(CON_OUT, str);
    }

    uint32_t WinConsole::WriteUnsafe(uint32_t length, const char16_t* str) noexcept
    {
        return Primitives::ConsoleAPI::WriteUnsafe(CON_OUT, str, length);
    }

    uint32_t WinConsole::WriteUnsafe(String const& str) noexcept
    {
        return Primitives::ConsoleAPI::WriteUnsafe(CON_OUT, str);
    }

    uint32_t WinConsole::WriteUnsafe(StringView const& str) noexcept
    {
        return Primitives::ConsoleAPI::WriteUnsafe(CON_OUT, str);
    }
}

#undef CON_ERROR
#undef CON_IN
#undef CON_OUT
