#ifndef KONGKONG_CSTD_CSTRING_H
#define KONGKONG_CSTD_CSTRING_H

#include "Base.h"
#include "Kongkong.ArgumentNullException.h"

#include <stdio.h>
#include <limits.h>

namespace KONGKONG_NAMESPACE::CStd
{
    /// @brief C文字列の操作
    class CString final {
        public:

        STATIC_CLASS(CString)

        /// @brief マルチバイト文字の最大長
        [[nodiscard]]
        static constexpr size_t MaxMultiByteCharLength() noexcept { return MB_LEN_MAX; }

        /// @brief Find()で見つからなかった時の戻り値
        [[nodiscard]]
        static constexpr size_t NotFound() noexcept { return (size_t)-1; }

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(const char*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(std::nullptr_t, const char*) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(const wchar_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(std::nullptr_t, const wchar_t*) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(const char8_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(std::nullptr_t, const char8_t*) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(const char16_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(std::nullptr_t, const char16_t*) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(const char32_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(std::nullptr_t, const char32_t*) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(size_t, std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(size_t, const char*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(size_t, std::nullptr_t, const char*) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(size_t, const wchar_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(size_t, std::nullptr_t, const wchar_t*) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(size_t, const char8_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(size_t, std::nullptr_t, const char8_t*) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(size_t, const char16_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(size_t, std::nullptr_t, const char16_t*) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(size_t, const char32_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static std::strong_ordering Compare(size_t, std::nullptr_t, const char32_t*) = delete;

        /// @brief C文字列を比較
        /// @param left 比較する文字列
        /// @param right 比較する文字列
        /// @return std::basic_string<>の (left <=> right) と同じである(ハズ)
        /// @throws ArgumentNullException: leftまたはrightがnullptrのとき
        [[nodiscard]] static std::strong_ordering Compare(const char* left, const char* right);
        [[nodiscard]] static std::strong_ordering Compare(const wchar_t* left, const wchar_t* right);
        [[nodiscard]] static std::strong_ordering Compare(const char8_t* left, const char8_t* right);
        [[nodiscard]] static std::strong_ordering Compare(const char16_t* left, const char16_t* right);
        [[nodiscard]] static std::strong_ordering Compare(const char32_t* left, const char32_t* right);

        /// @brief C文字列を長さ制限付きで比較
        /// @param count 比較する文字列の長さ
        /// @param left 比較する文字列
        /// @param right 比較する文字列
        /// @return count文字以内で (left <=> right) となっている(ハズ)
        /// @throws ArgumentNullException: leftまたはrightがnullptrのとき
        [[nodiscard]] static std::partial_ordering Compare(size_t count, const char* left, const char* right);
        [[nodiscard]] static std::partial_ordering Compare(size_t count, const wchar_t* left, const wchar_t* right);
        [[nodiscard]] static std::partial_ordering Compare(size_t count, const char8_t* left, const char8_t* right);
        [[nodiscard]] static std::partial_ordering Compare(size_t count, const char16_t* left, const char16_t* right);
        [[nodiscard]] static std::partial_ordering Compare(size_t count, const char32_t* left, const char32_t* right);

        /// @brief ふぁ！？っく
        static size_t CountMultibyteChars(std::nullptr_t) = delete;

        /// @brief C文字列内のマルチバイト文字の数を取得
        /// @param mbChars 対象の文字列 NULLの場合はArgumentNullExceptionをスロー
        /// @return マルチバイト文字の数
        /// @return (例: "abcあいう" => 6)
        /// @throws ArgumentNullException: mbCharsがnullptrのとき
        /// @throws CStdException: 無効な文字が含まれていた時
        [[nodiscard]]
        static size_t CountMultibyteChars(const char* mbChars);

        /// @brief ふぁ！？っく
        static void* Dump(std::nullptr_t) = delete;

        /// @brief malloc()で文字列のコピーを作成
        /// @attention コピーされた文字列は::free()で開放してね！
        /// @param str コピー元の文字列
        /// @return 確保されたメモリブロック
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        [[nodiscard]] static char* Dump(const char* str);
        [[nodiscard]] static wchar_t* Dump(const wchar_t* str);
        [[nodiscard]] static char8_t* Dump(const char8_t* str);
        [[nodiscard]] static char16_t* Dump(const char16_t* str);
        [[nodiscard]] static char32_t* Dump(const char32_t* str);

        /// @brief ふぁ！？っく
        static size_t Find(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t Find(const char*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t Find(std::nullptr_t, const char*) = delete;

        /// @brief ふぁ！？っく
        static size_t Find(const wchar_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t Find(std::nullptr_t, const wchar_t*) = delete;

        /// @brief 文字列内を検索
        /// @param str 検索対象の文字列
        /// @param subString 探し出す文字列
        /// @return 指定したsubStringが始まるインデックス 見つからなれればNotFound()
        /// @throws ArgumentNullException: strまたはsubStringがnullptrのとき
        [[nodiscard]] static size_t Find(const char* str, const char* subString);
        [[nodiscard]] static size_t Find(const wchar_t* str, const wchar_t* subString);

        /// @brief ふぁ！？っく
        template <class... Args>
        static CharString Format(std::nullptr_t, Args...) = delete;
        
        /// @brief Cスタイルフォーマット文字列作成
        /// @tparam ...Args 可変長引数テンプレート
        /// @param format Cスタイル文字列フォーマット
        /// @param ...args 出力する値
        /// @return フォーマット文字列
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        template <class... Args>
        [[nodiscard]] static CharString Format(const char* format, Args... args)
        {
            int capacity = GetFormatStringLengthUnsafe(format, args...);

            char* p = CharString::AllocMemoryUnsafe(capacity);

            ::snprintf(p, capacity, format, args...);

            return CharString::WrapUnsafe(capacity, capacity - 1, p);
        }

        /// @brief ふぁ！？っく
        template <class... Args>
        static CharString FormatSafe(std::nullptr_t, Args...) = delete;
        
        /// @brief Cスタイルフォーマット文字列作成
        /// @tparam ...Args 可変長引数テンプレート
        /// @param format Cスタイル文字列フォーマット
        /// @param ...args 出力する値
        /// @return フォーマット文字列
        /// @throws ArgumentNullException: formatがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        template <class... Args>
        [[nodiscard]] static CharString FormatSafe(const char* format, Args... args)
        {
            int capacity = GetFormatStringLength(format, args...);

            char* p = CharString::AllocMemoryUnsafe(capacity);

            ::snprintf(p, capacity, format, args...);

            return CharString::WrapUnsafe(capacity, capacity - 1, p);
        }

        /// @brief ふぁ！？っく
        template <class... Args>
        static int GetFormatStringLength(std::nullptr_t, Args...) = delete;

        /// @brief Cスタイルフォーマット文字列のを作成するのに必要なnull文字を含む長さを取得
        /// @tparam ...Args 可変長引数テンプレート
        /// @param format フォーマット NULLの場合はArgumentNullExceptionをスロー
        /// @param ...args 出力する値
        /// @return 必要な文字数
        /// @throws ArgumentNullException: formatがnullptrのとき
        template <class... Args>
        [[nodiscard]] static int GetFormatStringLength(const char* format, Args... args)
        {
            ArgumentNullException::CheckNull(format, u"format");
            return ::snprintf(nullptr, 0, format, args...) + 1;
        }

        /// @brief ふぁ！？っく
        template <class... Args>
        static int GetFormatStringLengthUnsafe(std::nullptr_t, Args...) = delete;

        /// @brief Cスタイルフォーマット文字列のを作成するのに必要なnull文字を含む長さを取得
        /// @tparam ...Args 可変長引数テンプレート
        /// @param format フォーマット NULLの場合はArgumentNullExceptionをスロー
        /// @param ...args 出力する値
        /// @return 必要な文字数
        template <class... Args>
        [[nodiscard]] static int GetFormatStringLengthUnsafe(const char* format, Args... args) noexcept
        {
            return ::snprintf(nullptr, 0, format, args...) + 1;
        }

        /// @brief ふぁ！？っく
        static bool IsEqual(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(const char*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(std::nullptr_t, const char*) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(const wchar_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(std::nullptr_t, const wchar_t*) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(const char8_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(std::nullptr_t, const char8_t*) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(const char16_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(std::nullptr_t, const char16_t*) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(const char32_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(std::nullptr_t, const char32_t*) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(size_t, std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(size_t, const char*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(size_t, std::nullptr_t, const char*) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(size_t, const wchar_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(size_t, std::nullptr_t, const wchar_t*) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(size_t, const char8_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(size_t, std::nullptr_t, const char8_t*) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(size_t, const char16_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(size_t, std::nullptr_t, const char16_t*) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(size_t, const char32_t*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static bool IsEqual(size_t, std::nullptr_t, const char32_t*) = delete;

        /// @brief 2つのC文字列の中身が等しいかを判定
        /// @param left C文字列
        /// @param right C文字列
        /// @return 等しければtrue そうでなければfalse
        /// @throws ArgumentNullException: leftまたはrightがnullptrの時
        [[nodiscard]] static bool IsEqual(const char* left, const char* right);
        [[nodiscard]] static bool IsEqual(const wchar_t* left, const wchar_t* right);
        [[nodiscard]] static bool IsEqual(const char8_t* left, const char8_t* right);
        [[nodiscard]] static bool IsEqual(const char16_t* left, const char16_t* right);
        [[nodiscard]] static bool IsEqual(const char32_t* left, const char32_t* right);
        
        /// @brief 2つのC文字列の中身が等しいかを長さ制限付きで判定
        /// @param count 比較する長さ
        /// @param left C文字列
        /// @param right C文字列
        /// @return 等しければtrue そうでなければfalse
        /// @throws ArgumentNullException: leftまたはrightがnullptrの時
        [[nodiscard]] static bool IsEqual(size_t count, const char* left, const char* right);
        [[nodiscard]] static bool IsEqual(size_t count, const wchar_t* left, const wchar_t* right);
        [[nodiscard]] static bool IsEqual(size_t count, const char8_t* left, const char8_t* right);
        [[nodiscard]] static bool IsEqual(size_t count, const char16_t* left, const char16_t* right);
        [[nodiscard]] static bool IsEqual(size_t count, const char32_t* left, const char32_t* right);

        /// @brief ふぁ！？っく
        static bool IsNull(std::nullptr_t) = delete;

        /// @brief C文字列がNULLであるかを判定
        /// @param str C文字列
        /// @return strがNULLならtrue そうでなければfalse
        [[nodiscard]] static constexpr bool IsNull(const char* str) noexcept { return str == nullptr; }
        [[nodiscard]] static constexpr bool IsNull(const wchar_t* str) noexcept { return str == nullptr; }
        [[nodiscard]] static constexpr bool IsNull(const char8_t* str) noexcept { return str == nullptr;}
        [[nodiscard]] static constexpr bool IsNull(const char16_t* str) noexcept { return str == nullptr; }
        [[nodiscard]] static constexpr bool IsNull(const char32_t* str) noexcept { return str == nullptr; }

        /// @brief ふぁ！？っく
        static size_t ToDouble(double&, std::nullptr_t) = delete;

        /// @brief 文字列からdoubleに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        static size_t ToDouble(double& target, const char* str);

        /// @brief ふぁ！？っく
        static size_t ToDoubleUnsafe(double&, std::nullptr_t) = delete;

        /// @brief 文字列からdoubleに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        static size_t ToDoubleUnsafe(double& target, const char* str) noexcept;

        /// @brief ふぁ！？っく
        static size_t ToLLong(long long&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToLLong(long long&, std::nullptr_t, int) = delete;

        /// @brief 文字列からlong longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        static size_t ToLLong(long long& target, const char* str);

        /// @brief 文字列からlong longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @param radix 基数
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidArgumentException: 基数が無効なとき 
        static size_t ToLLong(long long& target, const char* str, int radix);

        /// @brief ふぁ！？っく
        static size_t ToLLongUnsafe(long long&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToLLongUnsafe(long long&, std::nullptr_t, int) = delete;

        /// @brief 文字列からlong longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        static size_t ToLLongUnsafe(long long& target, const char* str) noexcept;

        /// @brief 文字列からlong longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @param radix 基数
        /// @return 読み取った文字数
        static size_t ToLLongUnsafe(long long& target, const char* str, int radix) noexcept;

        /// @brief ふぁ！？っく
        static size_t ToLong(long&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToLong(long&, std::nullptr_t, int) = delete;

        /// @brief 文字列からlongに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        static size_t ToLong(long& target, const char* str);

        /// @brief 文字列からlongに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @param radix 基数
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidArgumentException: 基数が無効なとき 
        static size_t ToLong(long& target, const char* str, int radix);

        /// @brief ふぁ！？っく
        static size_t ToLongDouble(double&, std::nullptr_t) = delete;

        /// @brief 文字列からlong doubleに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        static size_t ToLongDouble(long double& target, const char* str);

        /// @brief ふぁ！？っく
        static size_t ToLongDoubleUnsafe(double&, std::nullptr_t) = delete;

        /// @brief 文字列からlong doubleに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        static size_t ToLongDoubleUnsafe(long double& target, const char* str) noexcept;

        /// @brief ふぁ！？っく
        static size_t ToLongUnsafe(long&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToLongUnsafe(long&, std::nullptr_t, int) = delete;

        /// @brief 文字列からlongに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        static size_t ToLongUnsafe(long& target, const char* str) noexcept;

        /// @brief 文字列からlongに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @param radix 基数
        /// @return 読み取った文字数
        static size_t ToLongUnsafe(long& target, const char* str, int radix) noexcept;

        /// @brief ふぁ！？っく
        static void ToLower(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static void ToLower(size_t, std::nullptr_t) = delete;

        /// @brief 'str'の大文字をすべて小文字にする
        /// @param str 変更対象の文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        static void ToLower(char* str);

        /// @brief 'str'の大文字をすべて小文字にする
        /// @param length 文字列の長さ
        /// @param str 変更対象の文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        static void ToLower(size_t length, char* str);
        
        /// @brief 'str'の大文字をすべて小文字にする
        /// @param str 変更対象の文字列
        static void ToLower(CharString& str) noexcept;

        /// @brief 'str'の大文字をすべて小文字にする
        /// @param str 変更対象の文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        static void ToLower(wchar_t* str);

        /// @brief 'str'の大文字をすべて小文字にする
        /// @param length 文字列の長さ
        /// @param str 変更対象の文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        static void ToLower(size_t length, wchar_t* str);

        /// @brief 'str'の大文字をすべて小文字にする
        /// @param str 変更対象の文字列
        static void ToLower(WideString& str) noexcept;

        /// @brief ふぁ！？っく
        static CharString ToMultiByte(std::nullptr_t) = delete;

        /// @brief ワイド文字からマルチバイト文字に変換
        /// @param c ワイド文字
        [[nodiscard]]
        static CharString ToMultiByte(wchar_t c);

        /// @brief ワイド文字列からマルチバイト文字に変換
        /// @param wcs ワイド文字列
        /// @throws ArgumentNullException: wcsがnullptrのとき
        [[nodiscard]]
        static CharString ToMultiByte(const wchar_t* wcs);

        /// @brief ワイド文字列からマルチバイト文字に変換
        /// @param wstr ワイド文字列
        [[nodiscard]]
        static CharString ToMultiByte(WideString const& wstr);

        /// @brief ふぁ！？っく
        static size_t ToNumber(long&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumber(unsigned long&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumber(long long&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumber(unsigned long long&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumber(float&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumber(double&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumber(long double&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumber(long&, std::nullptr_t, int) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumber(unsigned long&, std::nullptr_t, int) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumber(long long&, std::nullptr_t, int) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumber(unsigned long long&, std::nullptr_t, int) = delete;
        
        /// @brief 文字列からlongに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        static size_t ToNumber(long& target, const char* str);

        /// @brief 文字列からunsigned longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        static size_t ToNumber(unsigned long& target, const char* str);

        /// @brief 文字列からlong longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        static size_t ToNumber(long long& target, const char* str);

        /// @brief 文字列からunsigned long longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        static size_t ToNumber(unsigned long long& target, const char* str);

        /// @brief 文字列からfloatに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        static size_t ToNumber(float& target, const char* str);

        /// @brief 文字列からdoubleに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        static size_t ToNumber(double& target, const char* str);

        /// @brief 文字列からlong doubleに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        static size_t ToNumber(long double& target, const char* str);

        /// @brief 文字列からlongに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @param radix 基数
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidArgumentException: 基数が無効なとき 
        static size_t ToNumber(long& target, const char* str, int radix);

        /// @brief 文字列からunsigned longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @param radix 基数
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidArgumentException: 基数が無効なとき 
        static size_t ToNumber(unsigned long& target, const char* str, int radix);

        /// @brief 文字列からlong longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @param radix 基数
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidArgumentException: 基数が無効なとき 
        static size_t ToNumber(long long& target, const char* str, int radix);

        /// @brief 文字列からunsigned long longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @param radix 基数
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidArgumentException: 基数が無効なとき 
        static size_t ToNumber(unsigned long long& target, const char* str, int radix);

        /// @brief ふぁ！？っく
        static size_t ToNumberUnsafe(unsigned long&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumberUnsafe(long long&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumberUnsafe(unsigned long long&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumberUnsafe(float&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumberUnsafe(double&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumberUnsafe(long double&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumberUnsafe(long&, std::nullptr_t, int) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumberUnsafe(unsigned long&, std::nullptr_t, int) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumberUnsafe(long long&, std::nullptr_t, int) = delete;

        /// @brief ふぁ！？っく
        static size_t ToNumberUnsafe(unsigned long long&, std::nullptr_t, int) = delete;

        /// @brief 文字列からlongに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        static size_t ToNumberUnsafe(long& target, const char* str) noexcept;

        /// @brief 文字列からunsigned longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        static size_t ToNumberUnsafe(unsigned long& target, const char* str) noexcept;

        /// @brief 文字列からlong longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        static size_t ToNumberUnsafe(long long& target, const char* str) noexcept;

        /// @brief 文字列からunsigned long longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        static size_t ToNumberUnsafe(unsigned long long& target, const char* str) noexcept;

        /// @brief 文字列からfloatに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        static size_t ToNumberUnsafe(float& target, const char* str) noexcept;

        /// @brief 文字列からdoubleに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        static size_t ToNumberUnsafe(double& target, const char* str) noexcept;

        /// @brief 文字列からlong doubleに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        static size_t ToNumberUnsafe(long double& target, const char* str) noexcept;

        /// @brief 文字列からlongに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @param radix 基数
        /// @return 読み取った文字数
        static size_t ToNumberUnsafe(long& target, const char* str, int radix) noexcept;

        /// @brief 文字列からunsigned longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @param radix 基数
        /// @return 読み取った文字数
        static size_t ToNumberUnsafe(unsigned long& target, const char* str, int radix) noexcept;

        /// @brief 文字列からlong longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @param radix 基数
        /// @return 読み取った文字数
        static size_t ToNumberUnsafe(long long& target, const char* str, int radix) noexcept;

        /// @brief 文字列からunsigned long longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @param radix 基数
        /// @return 読み取った文字数
        static size_t ToNumberUnsafe(unsigned long long& target, const char* str, int radix) noexcept;

        /// @brief ふぁ！？っく
        static size_t ToSingle(float&, std::nullptr_t) = delete;

        /// @brief 文字列からfloatに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        static size_t ToSingle(float& target, const char* str);

        /// @brief ふぁ！？っく
        static size_t ToSingleUnsafe(float&, std::nullptr_t) = delete;

        /// @brief 文字列からfloatに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        static size_t ToSingleUnsafe(float& target, const char* str) noexcept;

        /// @brief ふぁ！？っく
        static size_t ToULLong(unsigned long long&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToULLong(unsigned long long&, std::nullptr_t, int) = delete;

        /// @brief 文字列からunsigned long longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        static size_t ToULLong(unsigned long long& target, const char* str);

        /// @brief 文字列からunsigned long longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @param radix 基数
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidArgumentException: 基数が無効なとき 
        static size_t ToULLong(unsigned long long& target, const char* str, int radix);

        /// @brief ふぁ！？っく
        static size_t ToULLongUnsafe(unsigned long long&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToULLongUnsafe(unsigned long long&, std::nullptr_t, int) = delete;

        /// @brief 文字列からunsigned long longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        static size_t ToULLongUnsafe(unsigned long long& target, const char* str) noexcept;

        /// @brief 文字列からunsigned long longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @param radix 基数
        /// @return 読み取った文字数
        static size_t ToULLongUnsafe(unsigned long long& target, const char* str, int radix) noexcept;

        /// @brief ふぁ！？っく
        static size_t ToULong(unsigned long&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToULong(unsigned long&, std::nullptr_t, int) = delete;

        /// @brief 文字列からunsigned longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        static size_t ToULong(unsigned long& target, const char* str);

        /// @brief 文字列からunsigned longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @param radix 基数
        /// @return 読み取った文字数
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidArgumentException: 基数が無効なとき 
        static size_t ToULong(unsigned long& target, const char* str, int radix);

        /// @brief ふぁ！？っく
        static size_t ToULongUnsafe(unsigned long&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static size_t ToULongUnsafe(unsigned long&, std::nullptr_t, int) = delete;

        /// @brief 文字列からunsigned longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @return 読み取った文字数
        static size_t ToULongUnsafe(unsigned long& target, const char* str) noexcept;

        /// @brief 文字列からunsigned longに変換
        /// @param target 値の書き込み先
        /// @param str 読み取る文字列
        /// @param radix 基数
        /// @return 読み取った文字数
        static size_t ToULongUnsafe(unsigned long& target, const char* str, int radix) noexcept;

        /// @brief ふぁ！？っく
        static void ToUpper(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static void ToUpper(size_t, std::nullptr_t) = delete;

        /// @brief 'str'の小文字をすべて大文字にする
        /// @param str 変更対象の文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        static void ToUpper(char* str);

        /// @brief 'str'の小文字をすべて大文字にする
        /// @param length 文字列の長さ
        /// @param str 変更対象の文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        static void ToUpper(size_t length, char* str);

        /// @brief 'str'の小文字をすべて大文字にする
        /// @param str 変更対象の文字列
        static void ToUpper(CharString& str) noexcept;

        /// @brief 'str'の小文字をすべて大文字にする
        /// @param str 変更対象の文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        static void ToUpper(wchar_t* str);

        /// @brief 'str'の小文字をすべて大文字にする
        /// @param length 文字列の長さ
        /// @param str 変更対象の文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        static void ToUpper(size_t length, wchar_t* str);

        /// @brief 'str'の小文字をすべて大文字にする
        /// @param str 変更対象の文字列
        static void ToUpper(WideString& str) noexcept;

#if KONGKONG_ENV_WINDOWS

        /// @brief UTF-16からUTF-8に変換
        /// @param c UTF-16文字
        /// @throws CStdException: 文字が無効なとき
        [[nodiscard]]
        static std::u8string ToUtf8(char16_t c);

        /// @brief UTF-16からUTF-8に変換
        /// @param c16s UTF-16文字列
        /// @throws ArgumentNullException: c16sがnullptrのとき
        /// @throws CStdException: 無効な文字が含まれているとき
        [[nodiscard]]
        static std::u8string ToUtf8(const char16_t* c16s);

        /// @brief UTF-16からUTF-8に変換
        /// @param length 文字列の長さ
        /// @param c16s UTF-16文字列
        /// @throws ArgumentNullException: c16sがnullptrのとき
        /// @throws CStdException: 無効な文字が含まれているとき
        [[nodiscard]]
        static std::u8string ToUtf8(size_t length, const char16_t* c16s);

        /// @brief UTF-16からUTF-8に変換
        /// @param c16str UTF-16文字列
        /// @throws CStdException: 無効な文字が含まれているとき
        [[nodiscard]]
        static std::u8string ToUtf8(std::u16string const& c16str);
#endif

        /// @brief ふぁ！？っく
        static WideString ToWide(std::nullptr_t) = delete;

        /// @brief マルチバイト文字列からワイド文字列に変換
        /// @param mbs マルチバイト文字列
        /// @throws ArgumentNullException: mbsがnullptrのとき
        /// @throws CStdException: 無効な文字が含まれているとき
        [[nodiscard]]
        static WideString ToWide(const char* mbs);

        /// @brief マルチバイト文字列からワイド文字列に変換
        /// @param str マルチバイト文字列
        /// @throws CStdException: 無効な文字が含まれているとき
        [[nodiscard]]
        static WideString ToWide(CharString const& str);

        /// @brief ふぁ！？っく
        static WideString ToWideChar(std::nullptr_t) = delete;

        /// @brief マルチバイト文字からワイド文字に変換
        /// @param mbc マルチバイト文字
        /// @throws ArgumentNullException: mbcがnullptrのとき
        /// @throws CStdException: 文字が無効なとき
        [[nodiscard]]
        static wchar_t ToWideChar(const char* mbc);

        /// @brief マルチバイト文字からワイド文字に変換
        /// @param mbc マルチバイト文字
        /// @throws CStdException: 文字が無効なとき
        [[nodiscard]]
        static wchar_t ToWideChar(CharString const& mbc);

        private:
        /// @brief 基数が正しいかを判定
        /// @param radix 基数
        /// @throws InvalidArgumentException: 基数が無効なとき
        static void _checkRadix(int radix);

        template <class TC>
        static std::strong_ordering _compare(const TC* left, const TC* right);

        template <class TC>
        static std::partial_ordering _compare(size_t count, const TC* left, const TC* right);
        
#if KONGKONG_ENV_WINDOWS
        static void _c16rToMultiByte(std::u8string& u8str, char16_t c);
#endif

        /// @brief 文字列を複製
        /// @attention コピーされた文字列は::free()で開放してね！
        /// @tparam TC 文字の型
        /// @param str コピー元の文字列
        /// @return 複製された文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws CStdException: メモリの確保に失敗したとき
        template <class TC>
        static TC* _dump(const TC* str);

        template <class TC>
        static bool _isEqual(const TC* left, const TC* right);

        template <class TC>
        static bool _isEqual(size_t count, const TC* left, const TC* right);

        static void _toLowerUncehck(size_t length, char* str);
        static void _toLowerUncehck(size_t length, wchar_t* str);

        static void _toUpperUncehck(size_t length, char* str);
        static void _toUpperUncehck(size_t length, wchar_t* str);

    };
}

#endif //!KONGKONG_CSTD_CSTRING_H
