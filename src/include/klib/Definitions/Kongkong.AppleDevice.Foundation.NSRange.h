#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_NSRANGE_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_NSRANGE_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    struct NSRange final : public ValueType {

        friend constexpr bool operator==(NSRange const& left, NSRange const& right) noexcept;
        friend constexpr bool operator!=(NSRange const& left, NSRange const& right) noexcept;

        /// @brief 文字列から作成
        /// @attention @@"Location(),Length()"
        /// @attention @@"{Location(),Length()}"
        /// @param str 文字列
        [[nodiscard]]
        NSRange FromNSString(NSString const& str) noexcept;

        constexpr NSRange() noexcept : _location(), _length() {}
        constexpr NSRange(size_t location, size_t length) noexcept : _location(location), _length(length) {}

        /// @brief 指定した位置が含まれるかを確認
        /// @param location 位置
        [[nodiscard]]
        bool Contains(size_t location) const noexcept { return _location <= location && (location - _location) < _length; }

        [[nodiscard]]
        constexpr size_t Length() const noexcept { return _length; }

        constexpr void Length(size_t value) noexcept { _length = value; }

        [[nodiscard]]
        constexpr size_t Location() const noexcept { return _location; }

        constexpr void Location(size_t value) noexcept { _location = value; }

        [[nodiscard]]
        constexpr size_t MaxRange() const noexcept { return _location + _length; }

        /// @brief 文字列表現を取得
        /// @return @"{ Location(), Length() }"
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        NSString ToNSString() const;

        /// @brief 文字列表現を取得
        /// @return u"{ Location(), Length() }"
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        size_t _location;
        size_t _length;
    };

    [[nodiscard]] constexpr bool operator==(NSRange const& left, NSRange const& right) noexcept { return left._location == right._length && left._length == right._length; }
    [[nodiscard]] constexpr bool operator!=(NSRange const& left, NSRange const& right) noexcept { return !(left == right); }
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_NSRANGE_H
