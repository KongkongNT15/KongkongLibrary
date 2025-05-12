#ifndef KONGKONG_BITS_BITMANAGER_H
#define KONGKONG_BITS_BITMANAGER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Bits
{
    class BitManager final {
        public:

        STATIC_CLASS(BitManager)

        [[nodiscard]]
        static constexpr ssize_t BytesToBits() noexcept { return 8; }

        [[nodiscard]]
        static constexpr ssize_t BytesToBits(ssize_t byteSize) noexcept { return byteSize * BytesToBits(); }

        template <class T>
        [[nodiscard]]
        static constexpr ssize_t BitSize() noexcept { return sizeof(T) * BytesToBits(); }

        /// @brief ビットをコピーして別の型に変換
        /// @tparam TFrom コピー元の型
        /// @tparam TTo コピー先の型
        /// @param from コピー元の値
        /// @return キャストされた値
        template <class TFrom, class TTo> requires (sizeof(TFrom) == sizeof(TTo)) && std::is_trivially_copyable_v<TTo> && std::is_trivially_copyable_v<TFrom>
        [[nodiscard]]
        static TTo Cast(TFrom const& from) noexcept;

        [[nodiscard]]
        static std::partial_ordering Compare(size_t nBits, const void* p1, const void* p2);

        /// @brief ビットをコピー
        /// @tparam TFrom コピー元の型
        /// @tparam TTo コピー先の型
        /// @param from コピー元の値
        /// @param to コピー先の値
        template <class TFrom, class TTo> requires (sizeof(TFrom) == sizeof(TTo)) && std::is_trivially_copyable_v<TTo> && std::is_trivially_copyable_v<TFrom>
        static void Copy(TFrom const& from, TTo& to) noexcept;

        /// @brief *p1と*p2がnBitsビット分だけ等しいかを確認
        /// @param nBits 比較する長さ
        /// @param p1 比較対象のオブジェクトへのポインター
        /// @param p2 比較対象のオブジェクトへのポインター
        [[nodiscard]]
        static bool IsEqual(size_t nBits, const void* p1, const void* p2);

        private:
        static constexpr uint8_t _bitValues[] = { 0x1, 0x2, 0x4, 0x8, 0xF, 0x10, 0x20, 0x40, 0x80 };
        
    };
}

namespace KONGKONG_NAMESPACE::Bits
{
    template <class TFrom, class TTo> requires (sizeof(TFrom) == sizeof(TTo)) && std::is_trivially_copyable_v<TTo> && std::is_trivially_copyable_v<TFrom>
    TTo BitManager::Cast(TFrom const& from) noexcept
    {
        uint8_t arr[sizeof(TTo)];
        TTo* pTo = (TTo*)arr;

        const uint8_t* p = (const uint8_t*)&from;

        for (uint8_t& c : arr) {
            c = *p;
            ++p;
        }

        return *pTo;
    }

    template <class TFrom, class TTo> requires (sizeof(TFrom) == sizeof(TTo)) && std::is_trivially_copyable_v<TTo> && std::is_trivially_copyable_v<TFrom>
    void BitManager::Copy(TFrom const& from, TTo& to) noexcept
    {
        const uint8_t* pFrom = (const uint8_t*)&from;
        const uint8_t* eFrom = pFrom + sizeof(TFrom);

        uint8_t* p = (uint8_t*)&to;

        while (pFrom != eFrom) {
            *p = *pFrom;

            ++p;
            ++pFrom;
        }
    }

}

#endif //!KONGKONG_BITS_BITMANAGER_H
