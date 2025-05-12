#ifndef KONGKONG_STANDARD_CPP_STDSTRING_H
#define KONGKONG_STANDARD_CPP_STDSTRING_H

#include "Base.h"

#include <string>

namespace KONGKONG_NAMESPACE::Standard::Cpp
{
    class StdString final {
        public:

        STATIC_CLASS(StdString)

        /// @brief ふぁ！？っく
        static void* FromCStrings(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::string FromCStrings(std::nullptr_t, const char*) = delete;

        /// @brief ふぁ！？っく
        static std::string FromCStrings(const char*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::wstring FromCStrings(const wchar_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::wstring FromCStrings(std::nullptr_t, const wchar_t*) = delete;

        /// @brief ふぁ！？っく
        static std::u8string FromCStrings(const char8_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::u8string FromCStrings(std::nullptr_t, const char8_t*) = delete;

        /// @brief ふぁ！？っく
        static std::u16string FromCStrings(const char16_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::u16string FromCStrings(std::nullptr_t, const char16_t*) = delete;

        /// @brief ふぁ！？っく
        static std::u32string FromCStrings(const char32_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::u32string FromCStrings(std::nullptr_t, const char32_t*) = delete;

        /// @brief C文字列を連結
        /// @param cString1 C文字列
        /// @param cString2 C文字列
        /// @return 連結された文字列
        /// @throws ArgumentNullException: cString1, cString2がnullptrのとき
        [[nodiscard]] static std::string FromCStrings(const char* cString1, const char* cString2);
        [[nodiscard]] static std::wstring FromCStrings(const wchar_t* cString1, const wchar_t* cString2);
        [[nodiscard]] static std::u8string FromCStrings(const char8_t* cString1, const char8_t* cString2);
        [[nodiscard]] static std::u16string FromCStrings(const char16_t* cString1, const char16_t* cString2);
        [[nodiscard]] static std::u32string FromCStrings(const char32_t* cString1, const char32_t* cString2);

        /// @brief ふぁ！？っく
        static void* FromCStringsUnsafe(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::string FromCStringsUnsafe(std::nullptr_t, const char*) = delete;

        /// @brief ふぁ！？っく
        static std::string FromCStringsUnsafe(const char*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::wstring FromCStringsUnsafe(const wchar_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::wstring FromCStringsUnsafe(std::nullptr_t, const wchar_t*) = delete;

        /// @brief ふぁ！？っく
        static std::u8string FromCStringsUnsafe(const char8_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::u8string FromCStringsUnsafe(std::nullptr_t, const char8_t*) = delete;

        /// @brief ふぁ！？っく
        static std::u16string FromCStringsUnsafe(const char16_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::u16string FromCStringsUnsafe(std::nullptr_t, const char16_t*) = delete;

        /// @brief ふぁ！？っく
        static std::u32string FromCStringsUnsafe(const char32_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::u32string FromCStringsUnsafe(std::nullptr_t, const char32_t*) = delete;

        /// @brief C文字列を連結
        /// @param cString1 C文字列
        /// @param cString2 C文字列
        /// @return 連結された文字列
        [[nodiscard]] static std::string FromCStringsUnsafe(const char* cString1, const char* cString2);
        [[nodiscard]] static std::wstring FromCStringsUnsafe(const wchar_t* cString1, const wchar_t* cString2);
        [[nodiscard]] static std::u8string FromCStringsUnsafe(const char8_t* cString1, const char8_t* cString2);
        [[nodiscard]] static std::u16string FromCStringsUnsafe(const char16_t* cString1, const char16_t* cString2);
        [[nodiscard]] static std::u32string FromCStringsUnsafe(const char32_t* cString1, const char32_t* cString2);

        private:

        /// @brief C文字列を連結
        /// @tparam TChar 文字型
        /// @param cString1 C文字列
        /// @param cString2 C文字列
        /// @return 連結された文字列
        /// @throws ArgumentNullException: cString1, cString2がnullptrのとき
        template <class TChar>
        static std::basic_string<TChar, std::char_traits<TChar>> _fromCStrings(const TChar* cString1, const TChar* cString2);

        /// @brief C文字列を連結
        /// @tparam TChar 文字型
        /// @param cString1 C文字列
        /// @param cString2 C文字列
        /// @return 連結された文字列
        template <class TChar>
        static std::basic_string<TChar, std::char_traits<TChar>> _fromCStringsUnsafe(const TChar* cString1, const TChar* cString2);
    };
}

#endif //!KONGKONG_STANDARD_CPP_STDSTRING_H
