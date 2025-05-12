//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    int CConsole::Read() noexcept
    {
        return ::getchar();
    }

    std::string CConsole::ReadLine()
    {
        std::string str;

        int c;

        while ((c = ::getchar()) != '\n' && c != EOF) {
            str.push_back(c);
        }

        return str;
    }

    int CConsole::Write(char c) noexcept
    {
        return ::putchar(c);
    }

    void CConsole::Write(const char* str) noexcept
    {
        if (str == nullptr) [[unlikely]] {
            for (char c : "Null") {
                ::putchar(c);
            }

            return;
        }

        ssize_t length = (ssize_t)std::strlen(str);

        const char* p = str;
        const char* end = p + length;

        while (p != end) {
            ::putchar(*p);
            ++p;
        }
        
    }

    int CConsole::WriteLine(const char* str) noexcept
    {
        if (str == nullptr) [[unlikely]] {
            return ::puts("Null");
        }

        return ::puts(str);
    }
}
