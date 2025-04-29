#ifndef KONGKONG_WIN32_PRIMITIVES_CONSOLEAPI_H
#define KONGKONG_WIN32_PRIMITIVES_CONSOLEAPI_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    //<ConsoleAPI.h>
    //<ConsoleAPI2.h>
    //<ConsoleAPI3.h>
    //https://learn.microsoft.com/ja-jp/windows/console/console-functions
    class ConsoleAPI final {
        public:

        STATIC_CLASS(ConsoleAPI)

        static void AllocConsole();

        /// @brief 指定した場所を文字で埋める
        /// @param hOutput 書き込み先
        /// @param c 書き込む文字
        /// @param length 書き込む文字数
        /// @param point 書き込み開始位置
        /// @return 書き込まれた文字数
        static uint32_t Fill(HANDLE hOutput, char16_t c, uint32_t length, ConsolePoint const& point);

        static void FlushInput(::HANDLE hInput);

        static void FreeConsole();

        static void GenerateCtrlEvent(CtrlKeyEventKind kind, uint32_t processGroupId = 0u);

        [[nodiscard]] static ::HWND Handle() noexcept;

        [[nodiscard]] static ConsolePoint LargestWindowSize(::HANDLE hOutput);

        [[nodiscard]] static uint32_t NumberOfMouseButtons();

        static String OriginalTitle();

        //1文字取り込む
        [[nodiscard]] static char16_t Read(::HANDLE hInput);
        //最大 maxLength 文字取り込む
        [[nodiscard]] static String Read(::HANDLE hInput, uint32_t maxLength);
        //1行分取り込む
        [[nodiscard]] static String ReadLine(::HANDLE hInput);

        /// @brief ふぁ！？っく
        static bool SetTitleUnsafe(std::nullptr_t) = delete;

        static bool SetTitleUnsafe(const char16_t* newTitle) noexcept;
        static bool SetTitleUnsafe(String const& newTitle) noexcept;

        [[nodiscard]] static ::HANDLE StandardErrorHandle() noexcept;
        [[nodiscard]] static ::HANDLE StandardInputHandle() noexcept;
        [[nodiscard]] static ::HANDLE StandardOutputHandle() noexcept;

        /// @brief ふぁ！？っく
        static void Title(std::nullptr_t) = delete;

        [[nodiscard]] static String Title();
        static void Title(const char16_t* newTitle);
        static void Title(String const& newTitle);

        /// @brief ふぁ！？っく
        static uint32_t Write(std::nullptr_t, char16_t) = delete;

        /// @brief ふぁ！？っく
        static uint32_t Write(std::nullptr_t, const char16_t*) = delete;

        /// @brief ふぁ！？っく
        static uint32_t Write(std::nullptr_t, const char16_t*, uint32_t) = delete;

        /// @brief ふぁ！？っく
        static uint32_t Write(std::nullptr_t, StringView const&) = delete;

        /// @brief ふぁ！？っく
        static uint32_t Write(std::nullptr_t, String const&) = delete;

        static uint32_t Write(HANDLE hOutput, char16_t c);
        static uint32_t Write(HANDLE hOutput, const char16_t* p);
        static uint32_t Write(HANDLE hOutput, const char16_t* p, uint32_t length);
        static uint32_t Write(HANDLE hOutput, StringView const& view);
        static uint32_t Write(HANDLE hOutput, String const& str);

        /// @brief ふぁ！？っく
        static uint32_t WriteLine(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static uint32_t WriteLine(std::nullptr_t, char16_t) = delete;

        /// @brief ふぁ！？っく
        static uint32_t WriteLine(std::nullptr_t, const char16_t*) = delete;

        /// @brief ふぁ！？っく
        static uint32_t WriteLine(std::nullptr_t, const char16_t*, uint32_t) = delete;

        /// @brief ふぁ！？っく
        static uint32_t WriteLine(std::nullptr_t, StringView const&) = delete;

        /// @brief ふぁ！？っく
        static uint32_t WriteLine(std::nullptr_t, String const&) = delete;

        static uint32_t WriteLine(HANDLE hOutput);
        static uint32_t WriteLine(HANDLE hOutput, char16_t c);
        static uint32_t WriteLine(HANDLE hOutput, const char16_t* p);
        static uint32_t WriteLine(HANDLE hOutput, const char16_t* p, uint32_t length);
        static uint32_t WriteLine(HANDLE hOutput, StringView const& view);
        static uint32_t WriteLine(HANDLE hOutput, String const& str);

        /// @brief ふぁ！？っく
        static uint32_t WriteLineUnsafe(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static uint32_t WriteLineUnsafe(std::nullptr_t, char16_t) = delete;

        /// @brief ふぁ！？っく
        static uint32_t WriteLineUnsafe(std::nullptr_t, const char16_t*) = delete;

        /// @brief ふぁ！？っく
        static uint32_t WriteLineUnsafe(std::nullptr_t, const char16_t*, uint32_t) = delete;

        /// @brief ふぁ！？っく
        static uint32_t WriteLineUnsafe(std::nullptr_t, StringView const&) = delete;

        /// @brief ふぁ！？っく
        static uint32_t WriteLineUnsafe(std::nullptr_t, String const&) = delete;

        static uint32_t WriteLineUnsafe(HANDLE hOutput) noexcept;
        static uint32_t WriteLineUnsafe(HANDLE hOutput, char16_t c) noexcept;
        static uint32_t WriteLineUnsafe(HANDLE hOutput, const char16_t* p) noexcept;
        static uint32_t WriteLineUnsafe(HANDLE hOutput, const char16_t* p, uint32_t length) noexcept;
        static uint32_t WriteLineUnsafe(HANDLE hOutput, StringView const& view) noexcept;
        static uint32_t WriteLineUnsafe(HANDLE hOutput, String const& str) noexcept;

        /// @brief ふぁ！？っく
        static uint32_t WriteUnsafe(std::nullptr_t, char16_t) = delete;

        /// @brief ふぁ！？っく
        static uint32_t WriteUnsafe(std::nullptr_t, const char16_t*) = delete;

        /// @brief ふぁ！？っく
        static uint32_t WriteUnsafe(std::nullptr_t, const char16_t*, uint32_t) = delete;

        /// @brief ふぁ！？っく
        static uint32_t WriteUnsafe(std::nullptr_t, StringView const&) = delete;

        /// @brief ふぁ！？っく
        static uint32_t WriteUnsafe(std::nullptr_t, String const&) = delete;

        static uint32_t WriteUnsafe(HANDLE hOutput, char16_t c) noexcept;
        static uint32_t WriteUnsafe(HANDLE hOutput, const char16_t* p) noexcept;
        static uint32_t WriteUnsafe(HANDLE hOutput, const char16_t* p, uint32_t length) noexcept;
        static uint32_t WriteUnsafe(HANDLE hOutput, StringView const& view) noexcept;
        static uint32_t WriteUnsafe(HANDLE hOutput, String const& str) noexcept;
    };
}

#endif //!KONGKONG_WIN32_PRIMITIVES_CONSOLEAPI_H
