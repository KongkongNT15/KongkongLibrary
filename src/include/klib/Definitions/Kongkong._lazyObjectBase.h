#ifndef KONGKONG_LASYOBJECTBASE_H
#define KONGKONG_LASYOBJECTBASE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE
{
    struct _lazyObjectBase {

        /// @brief 有効な値を持っているかを確認
        [[nodiscard]]
        constexpr operator bool() const noexcept { return _isInitialized; }

        [[nodiscard]]
        constexpr bool operator!() const noexcept { return !_isInitialized; }

        /// @brief 値を持っているかを確認
        [[nodiscard]]
        constexpr bool IsInitialized() const noexcept { return _isInitialized; }

        private:

        _lazyObjectBase() = default;
        constexpr _lazyObjectBase(bool isInitialized) noexcept : _isInitialized(isInitialized) {}
        _lazyObjectBase(_lazyObjectBase const&) = default;
        _lazyObjectBase(_lazyObjectBase&&) = default;

        _lazyObjectBase& operator=(_lazyObjectBase const&) = default;
        _lazyObjectBase& operator=(_lazyObjectBase&&) = default;

        void _checkIntialized() const;
        void _checkNotIntialized() const;

        String _toStringDefault() const;
        String _toStringNotInitialized() const;

        bool _isInitialized;

        template <class T>
        friend struct LazyObject;
    };
}

#endif //!KONGKONG_LASYOBJECTBASE_H
