#ifndef KONGKONG_WIN32_STRINGHELPER_H
#define KONGKONG_WIN32_STRINGHELPER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    class StringHelper final {
        public:

        STATIC_CLASS(StringHelper)

        /// @brief ふぁ！？っく
        static String ToLower(std::nullptr_t) = delete;

        [[nodiscard]] static String ToLower(const char16_t* wcs);
        [[nodiscard]] static String ToLower(String const& right);

        /// @brief ふぁ！？っく
        static String ToString(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static String ToString(ssize_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static String ToString(std::nullptr_t, CodePage) = delete;

        /// @brief ふぁ！？っく
        static String ToString(ssize_t, std::nullptr_t, CodePage) = delete;

        //文字コード変換
        [[nodiscard]] static String ToString(const char* ansiStr);
        [[nodiscard]] static String ToString(ssize_t length, const char* ansiStr);
        [[nodiscard]] static String ToString(std::string const& ansiStr);
        [[nodiscard]] static String ToString(const char8_t* u8Str);
        [[nodiscard]] static String ToString(ssize_t length, const char8_t* u8Str);
        [[nodiscard]] static String ToString(std::u8string const& u8Str);
        [[nodiscard]] static String ToString(ssize_t length, const char* str, CodePage codePage);
        [[nodiscard]] static String ToString(const char* str, CodePage codePage);

        /// @brief ふぁ！？っく
        static String ToUpper(std::nullptr_t) = delete;

        [[nodiscard]] static String ToUpper(const char16_t* wcs);
        [[nodiscard]] static String ToUpper(String const& right);

    };
}

#endif //!KONGKONG_WIN32_STRINGHELPER_H
