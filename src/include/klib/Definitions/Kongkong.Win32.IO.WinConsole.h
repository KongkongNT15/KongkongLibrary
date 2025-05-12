#ifndef KONGKONG_WIN32_IO_WINCONSOLE_H
#define KONGKONG_WIN32_IO_WINCONSOLE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::IO
{
    class WinConsole final {
        public:

        STATIC_CLASS(WinConsole)

        [[nodiscard]]
        static OutputDevice Error();

        static void Error(OutputDevice const& error);

        [[nodiscard]]
        static InputDevice In();

        static void In(InputDevice const& in);

        [[nodiscard]]
        static OutputDevice Out();

        static void Out(OutputDevice const& out);

        /// @brief ふぁ！？っく
        static void SetErrorUnsafe(std::nullptr_t) = delete;

        static void SetErrorUnsafe(OutputDevice const& error) noexcept;

        /// @brief ふぁ！？っく
        static void SetInUnsafe(std::nullptr_t) = delete;

        static void SetInUnsafe(InputDevice const& in) noexcept;

        /// @brief ふぁ！？っく
        static void SetOutUnsafe(std::nullptr_t) = delete;

        static void SetOutUnsafe(OutputDevice const& out) noexcept;

        /// @brief ふぁ！？っく
        static uint32_t Write(std::nullptr_t) = delete;

        static uint32_t Write(char16_t c);
        static uint32_t Write(const char16_t* str);
        static uint32_t Write(uint32_t length, const char16_t* str);
        static uint32_t Write(String const& str);
        static uint32_t Write(StringView const& str);

        /// @brief ふぁ！？っく
        static uint32_t WriteLine(std::nullptr_t) = delete;

        static uint32_t WriteLine();
        static uint32_t WriteLine(char16_t c);
        static uint32_t WriteLine(const char16_t* str);
        static uint32_t WriteLine(uint32_t length, const char16_t* str);
        static uint32_t WriteLine(String const& str);
        static uint32_t WriteLine(StringView const& str);

        /// @brief ふぁ！？っく
        static uint32_t WriteUnsafe(std::nullptr_t) = delete;

        static uint32_t WriteUnsafe(char16_t c) noexcept;
        static uint32_t WriteUnsafe(const char16_t* str) noexcept;
        static uint32_t WriteUnsafe(uint32_t length, const char16_t* str) noexcept;
        static uint32_t WriteUnsafe(String const& str) noexcept;
        static uint32_t WriteUnsafe(StringView const& str) noexcept;
    };
}

#endif //!KONGKONG_WIN32_IO_WINCONSOLE_H
