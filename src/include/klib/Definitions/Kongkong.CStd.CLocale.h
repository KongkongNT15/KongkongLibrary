#ifndef KONGKONG_CSTD_CLOCALE_H
#define KONGKONG_CSTD_CLOCALE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::CStd
{
    class CLocale final {
        public:

        STATIC_CLASS(CLocale)

        /// @brief ふぁ！？っく
        static char* All(std::nullptr_t) = delete;

        /// @brief 設定されたロケールを取得
        [[nodiscard]] static char* All() noexcept;

        /// @brief すべてのロケールを設定
        /// @param locale ロケール文字列
        /// @return 設定されたロケール
        static char* All(const char* locale);
        /// @brief すべてのロケールを設定
        /// @param locale ロケール文字列
        /// @return 設定されたロケール
        static char* All(CharString const& locale);

        /// @brief ふぁ！？っく
        static char* Collate(std::nullptr_t) = delete;

        [[nodiscard]] static char* Collate() noexcept;
        static char* Collate(const char* locale);
        static char* Collate(CharString const& locale);

        /// @brief ふぁ！？っく
        static char* CharType(std::nullptr_t) = delete;

        [[nodiscard]] static char* CharType() noexcept;
        static char* CharType(const char* locale);
        static char* CharType(CharString const& locale);

        /// @brief ふぁ！？っく
        static char* Monetary(std::nullptr_t) = delete;

        [[nodiscard]] static char* Monetary() noexcept;
        static char* Monetary(const char* locale);
        static char* Monetary(CharString const& locale);

        /// @brief ふぁ！？っく
        static char* Numeric(std::nullptr_t) = delete;

        [[nodiscard]] static char* Numeric() noexcept;
        static char* Numeric(const char* locale);
        static char* Numeric(CharString const& locale);

        /// @brief ふぁ！？っく
        static char* Time(std::nullptr_t) = delete;

        [[nodiscard]] static char* Time() noexcept;
        static char* Time(const char* locale);
        static char* Time(CharString const& locale);

        [[nodiscard]] static char* GetLocale(CLocaleCategory category);

        [[nodiscard]] static char* GetLocaleUnsafe(CLocaleCategory category) noexcept;
        
        /// @brief ふぁ！？っく
        static char* SetLocale(CLocaleCategory category, std::nullptr_t) = delete;

        static char* SetLocale(CLocaleCategory category, const char* locale);
        static char* SetLocale(CLocaleCategory category, CharString const& locale);
    };
}

#endif //!KONGKONG_CSTD_CSTDLOCALE_H
