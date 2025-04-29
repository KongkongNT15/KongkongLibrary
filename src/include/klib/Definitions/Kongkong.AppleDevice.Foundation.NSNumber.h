#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_NSNUMBER_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_NSNUMBER_H

#include "Base.h"
#include "Kongkong.AppleDevice.Foundation.NSValue.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    class NSNumber : public NSValue {
        public:

        /// @brief APIがないよ！
        NSNumber(long double) = delete;

        /// @brief bool値から作成
        /// @param value 値
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSNumber(bool value);

        /// @brief char値から作成
        /// @param value 値
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSNumber(char value);

        /// @brief short値から作成
        /// @param value 値
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSNumber(short value);

        /// @brief int値から作成
        /// @param value 値
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSNumber(int value);

        /// @brief long値から作成
        /// @param value 値
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSNumber(long value);

        /// @brief long long値から作成
        /// @param value 値
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSNumber(long long value);

        /// @brief unsigned char値から作成
        /// @param value 値
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSNumber(unsigned char value);

        /// @brief unsigned short値から作成
        /// @param value 値
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSNumber(unsigned short value);

        /// @brief unsigned int値から作成
        /// @param value 値
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSNumber(unsigned int value);

        /// @brief unsigned long値から作成
        /// @param value 値
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSNumber(unsigned long value);

        /// @brief unsigned long long値から作成
        /// @param value 値
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSNumber(unsigned long long value);

        /// @brief float値から作成
        /// @param value 値
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSNumber(float value);

        /// @brief double値から作成
        /// @param value 値
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSNumber(double value);

        /// @brief nullptrとして作成
        constexpr NSNumber(std::nullptr_t) noexcept : NSValue(nullptr) {}

        /// @brief APIがないよ！
        [[nodiscard]]
        operator long double() const = delete;

        [[nodiscard]]
        operator bool() const;

        [[nodiscard]]
        operator char() const;

        [[nodiscard]]
        operator short() const;

        [[nodiscard]]
        operator int() const;

        [[nodiscard]]
        operator long() const;

        [[nodiscard]]
        operator long long() const;

        [[nodiscard]]
        operator unsigned char() const;

        [[nodiscard]]
        operator unsigned short() const;

        [[nodiscard]]
        operator unsigned int() const;

        [[nodiscard]]
        operator unsigned long() const;

        [[nodiscard]]
        operator unsigned long long() const;

        [[nodiscard]]
        operator float() const;

        [[nodiscard]]
        operator double() const;

        [[nodiscard]]
        operator NSDecimal() const;

        /// @brief 値をbool値をして取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool BoolValue() const;

        /// @brief 値をchar値をして取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        char CharValue() const;

        /// @brief 値を比較
        /// @param value 値
        /// @return *this <=> value
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: valueがnullptrのとき
        [[nodiscard]]
        std::strong_ordering Compare(NSNumber const& value);

        /// @brief 値をNSDecimal値をして取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        NSDecimal DecimalValue() const;

        /// @brief 値をdouble値をして取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        double DoubleValue() const;

        /// @brief 値をfloat値をして取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        float FloatValue() const;

        /// @brief 値をint値をして取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        int IntValue() const;

        /// @brief 値をlong long値をして取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        long long LongLongValue() const;

        /// @brief 値をlong値をして取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        long LongValue() const;

        /// @brief 値をshort値をして取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        short ShortValue() const;

        /// @brief 値の文字列表現を取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき 
        [[nodiscard]]
        NSString StringValue() const;

        /// @brief 値をunsigned char値をして取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        unsigned char UnsignedCharValue() const;

        /// @brief 値をunsigned int値をして取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        unsigned int UnsignedIntValue() const;

        /// @brief 値をunsigned long long値をして取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        unsigned long long UnsignedLongLongValue() const;

        /// @brief 値をunsigned long値をして取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        unsigned long UnsignedLongValue() const;

        /// @brief 値をunsigned short値をして取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        unsigned short UnsignedShortValue() const;

    };

    [[nodiscard]] bool operator==(NSNumber const& left, NSNumber const& right);
    [[nodiscard]] bool operator!=(NSNumber const& left, NSNumber const& right);
    [[nodiscard]] bool operator<(NSNumber const& left, NSNumber const& right);
    [[nodiscard]] bool operator<=(NSNumber const& left, NSNumber const& right);
    [[nodiscard]] bool operator>(NSNumber const& left, NSNumber const& right);
    [[nodiscard]] bool operator>=(NSNumber const& left, NSNumber const& right);
    [[nodiscard]] ::std::strong_ordering operator<=>(NSNumber const& left, NSNumber const& right);
    [[nodiscard]] constexpr bool operator==(NSNumber const& left, std::nullptr_t) noexcept { return static_cast<NSObject const&>(left) == nullptr; }
    [[nodiscard]] constexpr bool operator!=(NSNumber const& left, std::nullptr_t) noexcept { return static_cast<NSObject const&>(left) != nullptr; }
    [[nodiscard]] constexpr bool operator==(std::nullptr_t, NSNumber const& right) noexcept { return nullptr == static_cast<NSObject const&>(right); }
    [[nodiscard]] constexpr bool operator!=(std::nullptr_t, NSNumber const& right) noexcept { return nullptr == static_cast<NSObject const&>(right); }
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_NSNUMBER_H
