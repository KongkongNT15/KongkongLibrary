#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_NSSTRING_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_NSSTRING_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    /// @brief Objective-C文字列
    class NSString : public NSObject {
        public:

        /// @brief 空の文字列
        [[nodiscard]]
        static NSString Empty() noexcept;

        /// @brief 空の文字列を作成
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSString() noexcept;

        /// @param str 文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSString(const char* str);

        /// @param str 文字列
        NSString(std::string const& str);

        /// @param u16str 文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSString(const char16_t* u16str);

        /// @param str 文字列
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSString(String const& str);

        /// @brief nullptrとして作成
        constexpr NSString(std::nullptr_t) noexcept : NSObject(nullptr) {}

        /// @brief 指定された要素番号の文字を取得
        /// @param index 要素番号
        /// @return 指定した文字、インデックスが範囲外の場合はstd::char_traits<char16_t>::eof()
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        char16_t operator[] (size_t index) const;

        /// @brief 指定された要素番号の文字を取得
        /// @param index 要素番号、範囲外の場合はOutOfRangeException
        /// @return 指定した文字
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        char16_t At(size_t index) const;

        /// @brief ふぁ！？っく
        bool Contains(std::nullptr_t) = delete;

        /// @brief 指定した文字が含まれているかを判定
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool Contains(char16_t c) const;

        /// @brief 指定した文字列が含まれているかを判定
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool Contains(const char16_t* u16str) const;

        /// @brief 指定した文字列が含まれているかを判定
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool Contains(String const& str) const;

        /// @brief 指定した文字列が含まれているかを判定
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool Contains(NSString const& str) const;

        /// @brief 文字列のコピーを取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSString Copy() const;

        /// @brief ふぁ！？っく
        bool EndsWith(std::nullptr_t) = delete;

        /// @brief 文字列がcで終わるかどうかを判定
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool EndsWith(char16_t c) const;

        /// @brief 文字列がu16strで終わるかどうかを判定
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool EndsWith(const char16_t* u16str) const;

        /// @brief 文字列がcで終わるかどうかを判定
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool EndsWith(String const& str) const;

        /// @brief 文字列がstrで終わるかどうかを判定
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool EndsWith(NSString const& str) const;

        /// @brief 文字数
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        ssize_t Length() const;

        /// @brief ふぁ！？っく
        bool StartsWith(std::nullptr_t) = delete;

        /// @brief 文字列がcで始まるかどうかを判定
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool StartsWith(char16_t c) const;

        /// @brief 文字列がu16strで始まるかどうかを判定
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool StartsWith(const char16_t* u16str) const;

        /// @brief 文字列がcで始まるかどうかを判定
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool StartsWith(String const& str) const;

        /// @brief 文字列がstrで始まるかどうかを判定
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool StartsWith(NSString const& str) const;

        /// @brief CharStringに変換
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        CharString ToCharString() const;

        /// @brief Utf8Stringに変換
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        Utf8String ToUtf8String() const;

        /// @brief 
        /// @throws NullPointerException: このインスタンスがnullptrのとき 
        [[nodiscard]]
        const char* Utf8String() const;

        private:

        friend NSStringHelper;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_NSSTRING_H
