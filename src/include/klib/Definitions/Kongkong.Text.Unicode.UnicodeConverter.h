#ifndef KONGKONG_TEXT_UNICODE_UNICODECONVERTER_H
#define KONGKONG_TEXT_UNICODE_UNICODECONVERTER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Text::Unicode
{
    class UnicodeConverter final {
        public:

        STATIC_CLASS(UnicodeConverter)

        /// @brief ふぁ！？っく
        static ssize_t GetCharCount(::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static ssize_t GetCharCount(ssize_t, ::std::nullptr_t) = delete;

        /// @brief UTF-32からUTF-16に変換したときの文字数を取得
        /// @param str UTF-32文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetCharCount(const char32_t* str);

        /// @brief UTF-32からUTF-16に変換したときの文字数を取得
        /// @param length 文字列の長さ
        /// @param str UTF-32文字列
        /// @throws InvalidArgumentException: lengthが負の値の時
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetCharCount(ssize_t length, const char32_t* str);

        /// @brief UTF-32からUTF-16に変換したときの文字数を取得
        /// @param str UTF-32文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetCharCount(Utf32String const& str);

        /// @brief UTF-32からUTF-16に変換したときの文字数を取得
        /// @param str UTF-32文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetCharCount(Utf32StringView const& str);

        /// @brief UTF-32からUTF-16に変換したときの文字数を取得
        /// @param chars UTF-32文字配列
        /// @throws ArgumentNullException: charsがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetCharCount(Collections::Array<char32_t> const& chars);

        /// @brief UTF-32からUTF-16に変換したときの文字数を取得
        /// @param chars UTF-32文字配列
        /// @throws ArgumentNullException: charsがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetCharCount(Collections::ArrayList<char32_t> const& chars);

        /// @brief UTF-32からUTF-16に変換したときの文字数を取得
        /// @param chars UTF-32文字配列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetCharCount(Collections::Turbo::FastArray<char32_t> const& chars);

        /// @brief UTF-32からUTF-16に変換したときの文字数を取得
        /// @param chars UTF-32文字配列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetCharCount(Collections::Turbo::FastArrayList<char32_t> const& chars);

        /// @brief ふぁ！？っく
        static ssize_t GetCharCountUnsafe(::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static ssize_t GetCharCountUnsafe(ssize_t, ::std::nullptr_t) = delete;

        /// @brief UTF-32からUTF-16に変換したときの文字数を取得
        /// @param str UTF-32文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetCharCountUnsafe(const char32_t* str);

        /// @brief UTF-32からUTF-16に変換したときの文字数を取得
        /// @param length 文字列の長さ
        /// @param str UTF-32文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetCharCountUnsafe(ssize_t length, const char32_t* str);

        /// @brief ふぁ！？っく
        static ssize_t GetUtf8CharCount(::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static ssize_t GetUtf8CharCount(ssize_t, ::std::nullptr_t) = delete;

        /// @brief UTF-16からUTF-8に変換したときの文字数を取得
        /// @param str UTF-16文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCount(const char16_t* str);

        /// @brief UTF-32からUTF-8に変換したときの文字数を取得
        /// @param str UTF-32文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCount(const char32_t* str);

        /// @brief UTF-16からUTF-8に変換したときの文字数を取得
        /// @param length 文字列の長さ
        /// @param str UTF-16文字列
        /// @throws InvalidArgumentException: lengthが負の値の時
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCount(ssize_t length, const char16_t* str);

        /// @brief UTF-32からUTF-8に変換したときの文字数を取得
        /// @param length 文字列の長さ
        /// @param str UTF-32文字列
        /// @throws InvalidArgumentException: lengthが負の値の時
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCount(ssize_t length, const char32_t* str);

        /// @brief UTF-16からUTF-8に変換したときの文字数を取得
        /// @param str UTF-16文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCount(String const& str);

        /// @brief UTF-32からUTF-8に変換したときの文字数を取得
        /// @param str UTF-32文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCount(Utf32String const& str);

        /// @brief UTF-16からUTF-8に変換したときの文字数を取得
        /// @param str UTF-16文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCount(StringView const& str);

        /// @brief UTF-32からUTF-8に変換したときの文字数を取得
        /// @param str UTF-32文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCount(Utf32StringView const& str);

        /// @brief UTF-16からUTF-8に変換したときの文字数を取得
        /// @param chars UTF-16文字配列
        /// @throws ArgumentNullException: charsがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCount(Collections::Array<char16_t> const& chars);

        /// @brief UTF-32からUTF-8に変換したときの文字数を取得
        /// @param chars UTF-32文字配列
        /// @throws ArgumentNullException: charsがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCount(Collections::Array<char32_t> const& chars);

        /// @brief UTF-16からUTF-8に変換したときの文字数を取得
        /// @param chars UTF-16文字配列
        /// @throws ArgumentNullException: charsがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCount(Collections::ArrayList<char16_t> const& chars);

        /// @brief UTF-32からUTF-8に変換したときの文字数を取得
        /// @param chars UTF-32文字配列
        /// @throws ArgumentNullException: charsがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCount(Collections::ArrayList<char32_t> const& chars);

        /// @brief UTF-16からUTF-8に変換したときの文字数を取得
        /// @param chars UTF-16文字配列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCount(Collections::Turbo::FastArray<char16_t> const& chars);

        /// @brief UTF-32からUTF-8に変換したときの文字数を取得
        /// @param chars UTF-32文字配列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCount(Collections::Turbo::FastArray<char32_t> const& chars);

        /// @brief UTF-16からUTF-8に変換したときの文字数を取得
        /// @param chars UTF-16文字配列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCount(Collections::Turbo::FastArrayList<char16_t> const& chars);

        /// @brief UTF-32からUTF-8に変換したときの文字数を取得
        /// @param chars UTF-32文字配列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCount(Collections::Turbo::FastArrayList<char32_t> const& chars);

        /// @brief ふぁ！？っく
        static ssize_t GetUtf8CharCountUnsafe(::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static ssize_t GetUtf8CharCountUnsafe(ssize_t, ::std::nullptr_t) = delete;

        /// @brief UTF-16からUTF-8に変換したときの文字数を取得
        /// @param str UTF-16文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCountUnsafe(const char16_t* str);

        /// @brief UTF-32からUTF-8に変換したときの文字数を取得
        /// @param str UTF-32文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCountUnsafe(const char32_t* str);

        /// @brief UTF-16からUTF-8に変換したときの文字数を取得
        /// @param length 文字列の長さ
        /// @param str UTF-16文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCountUnsafe(ssize_t length, const char16_t* str);

        /// @brief UTF-32からUTF-8に変換したときの文字数を取得
        /// @param length 文字列の長さ
        /// @param str UTF-32文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static ssize_t GetUtf8CharCountUnsafe(ssize_t length, const char32_t* str);

        /// @brief ふぁ！？っく
        static Threading::Generator<char16_t> IterateChars(::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static Threading::Generator<char16_t> IterateChars(ssize_t, ::std::nullptr_t) = delete;

        /// @brief 右辺値は最初のco_yieldで破棄されるのでダメです！
        static Threading::Generator<char16_t> IterateChars(Utf32String&&) = delete;

        /// @brief 右辺値は最初のco_yieldで破棄されるのでダメです！
        static Threading::Generator<char16_t> IterateChars(Collections::Array<char32_t>&&) = delete;

        /// @brief 右辺値は最初のco_yieldで破棄されるのでダメです！
        static Threading::Generator<char16_t> IterateChars(Collections::ArrayList<char32_t>&&) = delete;

        /// @brief 右辺値は最初のco_yieldで破棄されるのでダメです！
        static Threading::Generator<char16_t> IterateChars(Collections::Turbo::FastArray<char32_t>&&) = delete;

        /// @brief 右辺値は最初のco_yieldで破棄されるのでダメです！
        static Threading::Generator<char16_t> IterateChars(Collections::Turbo::FastArrayList<char32_t>&&) = delete;

        /// @brief UTF-32からUTF-16に変換して1文字ずつ取得
        /// @param str UTF-32文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char16_t> IterateChars(const char32_t* str);

        /// @brief UTF-32からUTF-16に変換して1文字ずつ取得
        /// @param length 文字列の長さ
        /// @param str UTF-32文字列
        /// @throws InvalidArgumentException: lengthが負の値の時
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char16_t> IterateChars(ssize_t length, const char32_t* str);

        /// @brief UTF-32からUTF-16に変換して1文字ずつ取得
        /// @param str UTF-32文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char16_t> IterateChars(Utf32String const& str);

        /// @brief UTF-32からUTF-16に変換して1文字ずつ取得
        /// @param str UTF-32文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char16_t> IterateChars(Utf32StringView const& str);

        /// @brief UTF-32からUTF-16に変換して1文字ずつ取得
        /// @param chars UTF-32文字配列
        /// @throws ArgumentNullException: charsがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char16_t> IterateChars(Collections::Array<char32_t> const& chars);

        /// @brief UTF-32からUTF-16に変換して1文字ずつ取得
        /// @param chars UTF-32文字配列
        /// @throws ArgumentNullException: charsがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char16_t> IterateChars(Collections::ArrayList<char32_t> const& chars);

        /// @brief UTF-32からUTF-16に変換して1文字ずつ取得
        /// @param chars UTF-32文字配列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char16_t> IterateChars(Collections::Turbo::FastArray<char32_t> const& chars);

        /// @brief UTF-32からUTF-16に変換して1文字ずつ取得
        /// @param chars UTF-32文字配列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char16_t> IterateChars(Collections::Turbo::FastArrayList<char32_t> const& chars);

        /// @brief ふぁ！？っく
        static Threading::Generator<char16_t> IterateCharsUnsafe(::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static Threading::Generator<char16_t> IterateCharsUnsafe(ssize_t, ::std::nullptr_t) = delete;

        /// @brief UTF-32からUTF-16に変換して1文字ずつ取得
        /// @param str UTF-32文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char16_t> IterateCharsUnsafe(const char32_t* str);

        /// @brief UTF-32からUTF-16に変換して1文字ずつ取得
        /// @param length 文字列の長さ
        /// @param str UTF-32文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char16_t> IterateCharsUnsafe(ssize_t length, const char32_t* str);

        /// @brief ふぁ！？っく
        static Threading::Generator<char8_t> IterateUtf8Chars(::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static Threading::Generator<char8_t> IterateUtf8Chars(ssize_t, ::std::nullptr_t) = delete;

        /// @brief 右辺値は最初のco_yieldで破棄されるのでダメです！
        static Threading::Generator<char8_t> IterateUtf8Chars(String&&) = delete;

        /// @brief 右辺値は最初のco_yieldで破棄されるのでダメです！
        static Threading::Generator<char8_t> IterateUtf8Chars(Utf32String&&) = delete;

        /// @brief 右辺値は最初のco_yieldで破棄されるのでダメです！
        static Threading::Generator<char8_t> IterateUtf8Chars(Collections::Array<char16_t>&&) = delete;

        /// @brief 右辺値は最初のco_yieldで破棄されるのでダメです！
        static Threading::Generator<char8_t> IterateUtf8Chars(Collections::Array<char32_t>&&) = delete;

        /// @brief 右辺値は最初のco_yieldで破棄されるのでダメです！
        static Threading::Generator<char8_t> IterateUtf8Chars(Collections::ArrayList<char16_t>&&) = delete;

        /// @brief 右辺値は最初のco_yieldで破棄されるのでダメです！
        static Threading::Generator<char8_t> IterateUtf8Chars(Collections::ArrayList<char32_t>&&) = delete;

        /// @brief 右辺値は最初のco_yieldで破棄されるのでダメです！
        static Threading::Generator<char8_t> IterateUtf8Chars(Collections::Turbo::FastArray<char16_t>&&) = delete;

        /// @brief 右辺値は最初のco_yieldで破棄されるのでダメです！
        static Threading::Generator<char8_t> IterateUtf8Chars(Collections::Turbo::FastArray<char32_t>&&) = delete;

        /// @brief 右辺値は最初のco_yieldで破棄されるのでダメです！
        static Threading::Generator<char8_t> IterateUtf8Chars(Collections::Turbo::FastArrayList<char16_t>&&) = delete;

        /// @brief 右辺値は最初のco_yieldで破棄されるのでダメです！
        static Threading::Generator<char8_t> IterateUtf8Chars(Collections::Turbo::FastArrayList<char32_t>&&) = delete;

        /// @brief UTF-16からUTF-8に変換して1文字ずつ取得
        /// @param str UTF-16文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8Chars(const char16_t* str);

        /// @brief UTF-32からUTF-8に変換して1文字ずつ取得
        /// @param str UTF-32文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8Chars(const char32_t* str);

        /// @brief UTF-16からUTF-8に変換して1文字ずつ取得
        /// @param length 文字列の長さ
        /// @param str UTF-16文字列
        /// @throws InvalidArgumentException: lengthが負の値の時
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8Chars(ssize_t length, const char16_t* str);

        /// @brief UTF-32からUTF-8に変換して1文字ずつ取得
        /// @param length 文字列の長さ
        /// @param str UTF-32文字列
        /// @throws InvalidArgumentException: lengthが負の値の時
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8Chars(ssize_t length, const char32_t* str);

        /// @brief UTF-16からUTF-8に変換して1文字ずつ取得
        /// @param str UTF-16文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8Chars(String const& str);

        /// @brief UTF-32からUTF-8に変換して1文字ずつ取得
        /// @param str UTF-32文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8Chars(Utf32String const& str);

        /// @brief UTF-16からUTF-8に変換して1文字ずつ取得
        /// @param str UTF-16文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8Chars(StringView const& str);

        /// @brief UTF-32からUTF-8に変換して1文字ずつ取得
        /// @param str UTF-32文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8Chars(Utf32StringView const& str);

        /// @brief UTF-16からUTF-8に変換して1文字ずつ取得
        /// @param chars UTF-16文字配列
        /// @throws ArgumentNullException: charsがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8Chars(Collections::Array<char16_t> const& chars);

        /// @brief UTF-32からUTF-8に変換して1文字ずつ取得
        /// @param chars UTF-32文字配列
        /// @throws ArgumentNullException: charsがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8Chars(Collections::Array<char32_t> const& chars);

        /// @brief UTF-16からUTF-8に変換して1文字ずつ取得
        /// @param chars UTF-16文字配列
        /// @throws ArgumentNullException: charsがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8Chars(Collections::ArrayList<char16_t> const& chars);

        /// @brief UTF-32からUTF-8に変換して1文字ずつ取得
        /// @param chars UTF-32文字配列
        /// @throws ArgumentNullException: charsがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8Chars(Collections::ArrayList<char32_t> const& chars);

        /// @brief UTF-16からUTF-8に変換して1文字ずつ取得
        /// @param chars UTF-16文字配列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8Chars(Collections::Turbo::FastArray<char16_t> const& chars);

        /// @brief UTF-32からUTF-8に変換して1文字ずつ取得
        /// @param chars UTF-32文字配列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8Chars(Collections::Turbo::FastArray<char32_t> const& chars);

        /// @brief UTF-16からUTF-8に変換して1文字ずつ取得
        /// @param chars UTF-16文字配列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8Chars(Collections::Turbo::FastArrayList<char16_t> const& chars);

        /// @brief UTF-32からUTF-8に変換して1文字ずつ取得
        /// @param chars UTF-32文字配列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8Chars(Collections::Turbo::FastArrayList<char32_t> const& chars);

        /// @brief ふぁ！？っく
        static Threading::Generator<char8_t> IterateUtf8CharsUnsafe(::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static Threading::Generator<char8_t> IterateUtf8CharsUnsafe(ssize_t, ::std::nullptr_t) = delete;

        /// @brief UTF-16からUTF-8に変換して1文字ずつ取得
        /// @param str UTF-16文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8CharsUnsafe(const char16_t* str);

        /// @brief UTF-32からUTF-8に変換して1文字ずつ取得
        /// @param str UTF-32文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8CharsUnsafe(const char32_t* str);

        /// @brief UTF-16からUTF-8に変換して1文字ずつ取得
        /// @param length 文字列の長さ
        /// @param str UTF-16文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8CharsUnsafe(ssize_t length, const char16_t* str);

        /// @brief UTF-32からUTF-8に変換して1文字ずつ取得
        /// @param length 文字列の長さ
        /// @param str UTF-32文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Threading::Generator<char8_t> IterateUtf8CharsUnsafe(ssize_t length, const char32_t* str);

        /// @brief ふぁ！？っく
        static Utf8String ToUtf8(::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static Utf8String ToUtf8(ssize_t, ::std::nullptr_t) = delete;

        /// @brief UTF-16からUTF-8に変換
        /// @param str UTF-16文字列
        /// @return UTF-8文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8(const char16_t* str);

        /// @brief UTF-32からUTF-8に変換
        /// @param str UTF-32文字列
        /// @return UTF-8文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8(const char32_t* str);

        /// @brief UTF-16からUTF-8に変換
        /// @param length 文字列の長さ
        /// @param str UTF-16文字列
        /// @return UTF-8文字列
        /// @throws InvalidArgumentException: lengthが負の値の時
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8(ssize_t length, const char16_t* str);

        /// @brief UTF-32からUTF-8に変換
        /// @param length 文字列の長さ
        /// @param str UTF-32文字列
        /// @return UTF-8文字列
        /// @throws InvalidArgumentException: lengthが負の値の時
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8(ssize_t length, const char32_t* str);

        /// @brief UTF-16からUTF-8に変換
        /// @param str UTF-16文字列
        /// @return UTF-8文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8(String const& str);

        /// @brief UTF-32からUTF-8に変換
        /// @param str UTF-32文字列
        /// @return UTF-8文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8(Utf32String const& str);

        /// @brief UTF-16からUTF-8に変換
        /// @param str UTF-16文字列
        /// @return UTF-8文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8(StringView const& str);

        /// @brief UTF-32からUTF-8に変換
        /// @param str UTF-32文字列
        /// @return UTF-8文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8(Utf32StringView const& str);

        /// @brief UTF-16からUTF-8に変換
        /// @param chars UTF-16文字配列
        /// @return UTF-8文字列
        /// @throws ArgumentNullException: charsがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8(Collections::Array<char16_t> const& chars);

        /// @brief UTF-32からUTF-8に変換
        /// @param chars UTF-32文字配列
        /// @return UTF-8文字列
        /// @throws ArgumentNullException: charsがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8(Collections::Array<char32_t> const& chars);

        /// @brief UTF-16からUTF-8に変換
        /// @param chars UTF-16文字配列
        /// @return UTF-8文字列
        /// @throws ArgumentNullException: charsがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8(Collections::ArrayList<char16_t> const& chars);

        /// @brief UTF-32からUTF-8に変換
        /// @param chars UTF-32文字配列
        /// @return UTF-8文字列
        /// @throws ArgumentNullException: charsがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8(Collections::ArrayList<char32_t> const& chars);

        /// @brief UTF-16からUTF-8に変換
        /// @param chars UTF-16文字配列
        /// @return UTF-8文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8(Collections::Turbo::FastArray<char16_t> const& chars);

        /// @brief UTF-32からUTF-8に変換
        /// @param chars UTF-32文字配列
        /// @return UTF-8文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8(Collections::Turbo::FastArray<char32_t> const& chars);

        /// @brief UTF-16からUTF-8に変換
        /// @param chars UTF-16文字配列
        /// @return UTF-8文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8(Collections::Turbo::FastArrayList<char16_t> const& chars);

        /// @brief UTF-32からUTF-8に変換
        /// @param chars UTF-32文字配列
        /// @return UTF-8文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8(Collections::Turbo::FastArrayList<char32_t> const& chars);

        /// @brief ふぁ！？っく
        static Utf8String ToUtf8Unsafe(::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static Utf8String ToUtf8Unsafe(ssize_t, ::std::nullptr_t) = delete;

        /// @brief UTF-16からUTF-8に変換
        /// @param str UTF-16文字列
        /// @return UTF-8文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8Unsafe(const char16_t* str);

        /// @brief UTF-32からUTF-8に変換
        /// @param str UTF-32文字列
        /// @return UTF-8文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8Unsafe(const char32_t* str);

        /// @brief UTF-16からUTF-8に変換
        /// @param length 文字列の長さ
        /// @param str UTF-16文字列
        /// @return UTF-8文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8Unsafe(ssize_t length, const char16_t* str);

        /// @brief UTF-32からUTF-8に変換
        /// @param length 文字列の長さ
        /// @param str UTF-32文字列
        /// @return UTF-8文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static Utf8String ToUtf8Unsafe(ssize_t length, const char32_t* str);

        /// @brief ふぁ！？っく
        static String ToUtf16(::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static String ToUtf16(ssize_t, ::std::nullptr_t) = delete;

        /// @brief UTF-32からUTF-16に変換
        /// @param str UTF-32文字列
        /// @return UTF-16文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static String ToUtf16(const char32_t* str);

        /// @brief UTF-32からUTF-16に変換
        /// @param length 文字列の長さ
        /// @param str UTF-32文字列
        /// @return UTF-16文字列
        /// @throws InvalidArgumentException: lengthが負の値の時
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static String ToUtf16(ssize_t length, const char32_t* str);

        /// @brief UTF-32からUTF-16に変換
        /// @param str UTF-32文字列
        /// @return UTF-16文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static String ToUtf16(Utf32String const& str);

        /// @brief UTF-32からUTF-16に変換
        /// @param str UTF-32文字列
        /// @return UTF-16文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static String ToUtf16(Utf32StringView const& str);

        /// @brief UTF-32からUTF-16に変換
        /// @param chars UTF-32文字配列
        /// @return UTF-16文字列
        /// @throws ArgumentNullException: charsがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static String ToUtf16(Collections::Array<char32_t> const& chars);

        /// @brief UTF-32からUTF-16に変換
        /// @param chars UTF-32文字配列
        /// @return UTF-16文字列
        /// @throws ArgumentNullException: charsがnullptrのとき
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static String ToUtf16(Collections::ArrayList<char32_t> const& chars);

        /// @brief UTF-32からUTF-16に変換
        /// @param chars UTF-32文字配列
        /// @return UTF-16文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static String ToUtf16(Collections::Turbo::FastArray<char32_t> const& chars);

        /// @brief UTF-32からUTF-16に変換
        /// @param chars UTF-32文字配列
        /// @return UTF-16文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static String ToUtf16(Collections::Turbo::FastArrayList<char32_t> const& chars);

        /// @brief ふぁ！？っく
        static String ToUtf16Unsafe(::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static String ToUtf16Unsafe(ssize_t, ::std::nullptr_t) = delete;

        /// @brief UTF-32からUTF-16に変換
        /// @param str UTF-32文字列
        /// @return UTF-16文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static String ToUtf16Unsafe(const char32_t* str);

        /// @brief UTF-32からUTF-16に変換
        /// @param length 文字列の長さ
        /// @param str UTF-32文字列
        /// @return UTF-16文字列
        /// @throws InvalidCodePointException: 無効なコードポイントが見つかった時
        [[nodiscard]]
        static String ToUtf16Unsafe(ssize_t length, const char32_t* str);
    };
}

#endif //!KONGKONG_TEXT_UNICODE_UNICODECONVERTER_H