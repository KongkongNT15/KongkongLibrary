#ifndef KONGKONG_TEXT_STRINGPOINTERBASE_H
#define KONGKONG_TEXT_STRINGPOINTERBASE_H

#include "Base.h"
#include "Kongkong.Text.StringType.h"
#include "Kongkong.Threading.Mutex.h"

namespace KONGKONG_NAMESPACE::Text
{
    struct _stringPointerBase {

        void __addCountUnsafe() noexcept { ++(*(ssize_t*)(__p + __countIndex)); }

        [[nodiscard]]
        constexpr ssize_t __getCapacityUnsafe() const noexcept { return *(ssize_t*)(__p + __capacityIndex); }

        [[nodiscard]]
        constexpr ssize_t __getCountUnsafe() const noexcept { return *(ssize_t*)(__p + __countIndex); }

        [[nodiscard]]
        constexpr StringType __getTypeUnsafe() const noexcept { return *(StringType*)(__p + __typeIndex); }

        [[nodiscard]]
        constexpr ssize_t __getLengthUnsafe() const noexcept { return *(ssize_t*)(__p + __lengthIndex); }

        [[nodiscard]]
        constexpr bool __isNull() const noexcept { return __p == nullptr; }

        void __removeCountUnsafe() noexcept { --(*(ssize_t*)(__p + __countIndex)); }

        protected:

        uint8_t* __p;
        static Threading::Mutex _mutex;

        void __destory() noexcept;

        private:

        constexpr _stringPointerBase(uint8_t* p) noexcept : __p(p) {}

        /// @brief nullptrとして作成
        constexpr _stringPointerBase(std::nullptr_t) noexcept : __p(nullptr) {}
        _stringPointerBase(_stringPointerBase const& right) noexcept;
        constexpr _stringPointerBase(_stringPointerBase&& right) noexcept : __p(right.__p) { right.__p = nullptr; }

        static constexpr ssize_t __countIndex = 0;
        static constexpr ssize_t __lengthIndex = __countIndex + sizeof(ssize_t);
        static constexpr ssize_t __capacityIndex = __lengthIndex + sizeof(ssize_t);
        static constexpr ssize_t __typeIndex = __capacityIndex + sizeof(ssize_t);
        static constexpr ssize_t __stringIndex = __typeIndex + sizeof(StringType);

        template <CharType TChar>
        friend struct _stringPointer;

        template <CharType TChar, ssize_t N>
        friend struct StaticStringData;

        template <CharType TChar>
        friend bool operator==(_stringPointer<TChar> const& left, _stringPointer<TChar> const& right) noexcept;

        template <CharType TChar>
        friend bool operator<(_stringPointer<TChar> const& left, _stringPointer<TChar> const& right) noexcept;

        template <CharType TChar>
        friend ::std::strong_ordering operator<=>(_stringPointer<TChar> const& left, _stringPointer<TChar> const& right) noexcept;
    };
}

#endif //!KONGKONG_TEXT_STRINGPOINTERBASE_H
