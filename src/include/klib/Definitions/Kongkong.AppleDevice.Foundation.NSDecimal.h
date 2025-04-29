#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_NSDECIMAL_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_NSDECIMAL_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    struct NSDecimal final : public ValueType {

        friend bool operator==(NSDecimal const& left, NSDecimal const& right) noexcept;
        friend bool operator!=(NSDecimal const& left, NSDecimal const& right) noexcept;
        friend bool operator<(NSDecimal const& left, NSDecimal const& right) noexcept;
        friend bool operator<=(NSDecimal const& left, NSDecimal const& right) noexcept;
        friend bool operator>(NSDecimal const& left, NSDecimal const& right) noexcept;
        friend bool operator>=(NSDecimal const& left, NSDecimal const& right) noexcept;
        friend std::strong_ordering operator<=>(NSDecimal const& left, NSDecimal const& right) noexcept;

        /// @brief 値を初期化せずに作成
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSDecimal();
        NSDecimal(NSDecimal const& right);
        NSDecimal(NSDecimal&& right) noexcept;

        ~NSDecimal();

        NSDecimal& operator=(NSDecimal const& right) noexcept;
        NSDecimal& operator=(NSDecimal&& right) noexcept;

        [[nodiscard]]
        NSString ToNSString() const;

        [[nodiscard]]
        String ToString() const;


        private:
        void* _p;

        friend NSNumber;
        friend Text::NSScanner;
    };

    [[nodiscard]] bool operator==(NSDecimal const& left, NSDecimal const& right) noexcept;
    [[nodiscard]] bool operator!=(NSDecimal const& left, NSDecimal const& right) noexcept;
    [[nodiscard]] bool operator<(NSDecimal const& left, NSDecimal const& right) noexcept;
    [[nodiscard]] bool operator<=(NSDecimal const& left, NSDecimal const& right) noexcept;
    [[nodiscard]] bool operator>(NSDecimal const& left, NSDecimal const& right) noexcept;
    [[nodiscard]] bool operator>=(NSDecimal const& left, NSDecimal const& right) noexcept;
    [[nodiscard]] std::strong_ordering operator<=>(NSDecimal const& left, NSDecimal const& right) noexcept;
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_NSDECIMAL_H
