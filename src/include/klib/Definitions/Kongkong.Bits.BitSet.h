#ifndef KONGKONG_BITS_BITSET_H
#define KONGKONG_BITS_BITSET_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Bits.BitSetElement.h"
#include "Kongkong.GenericString.h"
#include "Kongkong.GenericStringView.h"
#include "Kongkong.Bits.BitSetIterator.h"
#include "Kongkong.Bits.ConstBitSetIterator.h"
#include "Kongkong.Collections.CollectionHelper.h"
#include "Kongkong.Text.StringHelper.h"
#include "Kongkong.ArgumentNullException.h"
#include "Kongkong.InvalidArgumentException.h"

namespace KONGKONG_NAMESPACE::Bits
{
    template <ssize_t N> requires (N >= 1)
    struct BitSet final : public ValueType {

        template <CharType TChar>
        [[nodiscard]] static constexpr BitSet FromString(GenericString<TChar> const& str) { return FromStringUnsafe<TChar>(str.Length(), str.c_str()); }

        template <CharType TChar>
        [[nodiscard]] static constexpr BitSet FromString(GenericStringView<TChar> const& str) { return FromStringUnsafe<TChar>(str.Length(), str.c_str()); }

        template <CharType TChar>
        static BitSet FromString(const TChar* p)
        {
            ArgumentNullException::CheckNull(p, u"p");

            return FromStringUnsafe<TChar>(p);
        }

        template <CharType TChar>
        static BitSet FromString(ssize_t length, const TChar* p)
        {
            ArgumentNullException::CheckNull(p, u"p");
            Collections::CollectionHelper::CheckLength(length);

            return FromStringUnsafe<TChar>(length, p);
        }

        template <CharType TChar>
        static constexpr BitSet FromStringUnsafe(const TChar* p) { return FromStringUnsafe<TChar>(Text::StringHelper::GetLengthUnsafe(p), p); }

        template <CharType TChar>
        static constexpr BitSet FromStringUnsafe(ssize_t length, const TChar* p)
        {
            return FromStringUnsafe<TChar>(length, p, (TChar)'1', (TChar)'0');
        }

        template <CharType TChar>
        static constexpr BitSet FromStringUnsafe(ssize_t length, const TChar* p, TChar trueChar, TChar falseChar)
        {
            BitSet bitset;
            ssize_t copyLength;
            ssize_t i;

            if (length < N) {
                copyLength = length;
            }
            else {
                copyLength = N;
                p += length - N;
            }

            for (i = 0; i < copyLength; i++) {
                TChar c = p[copyLength - 1 - i];

                if (c == trueChar) {
                    bitset[i] = true;
                }
                else if (c == falseChar) {
                    bitset[i] = false;
                }
                else [[unlikely]] {
                    throw InvalidArgumentException(u"無効な文字が含まれています");
                }
            }

            return bitset;
        }

        /// @brief ゼロで作成
        constexpr BitSet() noexcept : _buffer{} {}

        /// @brief 整数値から作成
        /// @param value 整数値
        template <::std::integral TNum>
        constexpr BitSet(TNum value) noexcept
        {
            uint8_t* p = (uint8_t*)(&value);
            uint8_t* end;

            if constexpr (N > sizeof(TNum) * 8) {
                end = p + sizeof(TNum);
            }
            else {
                end = p + sizeof(_buffer);
            }

            uint8_t* bufferRef = _buffer;

            while (p != end) {
                *bufferRef = *p;
                p++;
                bufferRef++;
            }
        }

        /// @brief ゼロでないビットがあるかを判定
        [[nodiscard]]
        constexpr operator bool() const noexcept
        {
            if constexpr (N % 8) {
                const uint8_t* p = _buffer;
                const uint8_t* end = p + (sizeof(_buffer) - 1);
                constexpr ssize_t n = (sizeof(_buffer) - 1) * 8;

                while (p != end) {
                    if (*p) return true;
                }

                for (ssize_t i = n; i < N; i++) {
                    if (operator[](i)) return true;
                }

                return false;
            }
            else {
                for (uint8_t v : _buffer) {
                    if (v) return true;
                }
    
                return false;
            }
            
        }

        /// @brief ビットがすべてゼロであるかを判定
        [[nodiscard]]
        constexpr bool operator!() const noexcept
        {
            for (uint8_t v : _buffer) {
                if (v) return false;
            }

            return true;
        }

        /// @brief 指定した番号の要素を取得
        /// @param index 要素番号
        [[nodiscard]] constexpr BitSetElement operator[] (ssize_t index) noexcept { return BitSetElement(_buffer[index / 8], index % 8); }
        [[nodiscard]] constexpr bool operator[] (ssize_t index) const noexcept { return (bool)(_buffer[index / 8] & (1 << (index % 8))); }

        /// @brief ビットをすべて反転
        /// @return *this 
        BitSet& operator~() noexcept
        {
            int* p = reinterpret_cast<int*>(_buffer);
            int* end = p + (sizeof(_buffer) / sizeof(int));

            while (p != end) {
                *p = ~(*p);
                p++;
            }

            if constexpr (sizeof(_buffer) % sizeof(int) != 0) {
                uint8_t* p1 = reinterpret_cast<uint8_t*>(end);
                uint8_t* end1 = _buffer + sizeof(_buffer);

                while (p1 != end1) {
                    *p1 = (uint8_t)~(*p1);
                    p1++;
                }
            }

            return *this;
        }

#define CREATE_OP_BITSET(op)                            \
    int* p = (int*)_buffer;                             \
    int* end = p + (sizeof(_buffer) / sizeof(int));     \
    const int* pRight = (const int*)right._buffer;      \
    while (p != end) {                                  \
        (*p) op *pRight;                                \
        p++;                                            \
        pRight++;                                       \
    }                                                   \
    if constexpr (sizeof(_buffer) % sizeof(int) != 0) { \
        uint8_t* p1 = (uint8_t*)end;                    \
        uint8_t* end1 = _buffer + sizeof(_buffer);      \
        const uint8_t* pRight1 = (const uint8_t*)pRight;\
        while (p1 != end1) {                            \
            *p1 op *pRight;                             \
            p1++;                                       \
            pRight1++;                                  \
        }                                               \
    }                                                   \
    return *this

        constexpr BitSet& operator&=(BitSet const& right) noexcept
        {
            CREATE_OP_BITSET(&=);
        }

        constexpr BitSet& operator|=(BitSet const& right) noexcept
        {
            CREATE_OP_BITSET(|=);
        }

        constexpr BitSet& operator^=(BitSet const& right) noexcept
        {
            CREATE_OP_BITSET(^=);
        }

#undef CREATE_OP_BITSET

        [[nodiscard]] constexpr BitSetIterator begin() noexcept { return BitSetIterator(_buffer, 0); }
        [[nodiscard]] constexpr ConstBitSetIterator begin() const noexcept { return ConstBitSetIterator(_buffer, 0); }
        [[nodiscard]] constexpr BitSetIterator end() noexcept { return BitSetIterator(_buffer, N); }
        [[nodiscard]] constexpr ConstBitSetIterator end() const noexcept { return ConstBitSetIterator(_buffer, N); }

        /// @brief 指定した番号の要素を取得
        /// @param index 要素番号
        /// @throws InvalidArgumentException: indexが範囲外のとき
        [[nodiscard]]
        BitSetElement At(ssize_t index)
        {
            Collections::CollectionHelper::CheckIndex(index, N);
            return operator[](index);
        }

        /// @brief 指定した番号の要素を取得
        /// @param index 要素番号
        /// @throws InvalidArgumentException: indexが範囲外のとき
        [[nodiscard]]
        bool At(ssize_t index) const
        {
            Collections::CollectionHelper::CheckIndex(index, N);
            return operator[](index);
        }

        /// @brief ビット列を格納するバッファーの長さ
        /// @return 
        [[nodiscard]]
        constexpr ssize_t BufferLength() const noexcept { return sizeof(_buffer); }

        /// @brief バッファーへのポインター
        [[nodiscard]] constexpr uint8_t* Data() noexcept { return _buffer; }
        [[nodiscard]] constexpr const uint8_t* Data() const noexcept { return _buffer; }

        /// @brief ビット列の文字列表現を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        CharString ToCharString() const
        {
            return ToGenericString<CharString::ElementType>();
        }

        /// @brief ビット列の文字列表現を取得
        /// @param one 1を表す文字
        /// @param zero 0を表す文字
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        CharString ToCharString(char one, char zero) const
        {
            return ToGenericString<CharString::ElementType>(one, zero);
        }

        /// @brief ビット列の長さ
        [[nodiscard]]
        constexpr ssize_t Length() const noexcept { return N; }

        /// @brief ビット列の文字列表現を取得
        /// @tparam TChar 文字型
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        template <CharType TChar>
        [[nodiscard]] GenericString<TChar> ToGenericString() const
        {
            return ToGenericString<TChar>((TChar)'1', (TChar)'0');
        }

        /// @brief ビット列の文字列表現を取得
        /// @param one 1を表す文字
        /// @param zero 0を表す文字
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        template <CharType TChar>
        [[nodiscard]] GenericString<TChar> ToGenericString(TChar one, TChar zero) const
        {
            TChar* p = GenericString<TChar>::AllocMemoryUnsafe(N + 1);

            for (ssize_t i = 0; i < N; i++) {
                p[i] = operator[]((N - 1) - i) ? one : zero;
            }

            p[N] = (TChar)'\0';

            return GenericString<TChar>::WrapUnsafe(N + 1, N, p);
        }

        /// @brief ビット列の文字列表現を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const
        {
            return ToGenericString<String::ElementType>();
        }

        /// @brief ビット列の文字列表現を取得
        /// @param one 1を表す文字
        /// @param zero 0を表す文字
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString(char16_t one, char16_t zero) const
        {
            return ToGenericString<String::ElementType>(one, zero);
        }

        /// @brief uint8_tに変換
        [[nodiscard]]
        constexpr uint8_t ToUInt8() const noexcept
        {
            return ToUnsignedInteger<uint8_t>();
        }

        /// @brief uint16_tに変換
        [[nodiscard]]
        constexpr uint16_t ToUInt16() const noexcept
        {
            return ToUnsignedInteger<uint16_t>();
        }

        /// @brief uint32_tに変換
        [[nodiscard]]
        constexpr uint32_t ToUInt32() const noexcept
        {
            return ToUnsignedInteger<uint32_t>();
        }

        /// @brief uint64_tに変換
        [[nodiscard]]
        constexpr uint64_t ToUInt64() const noexcept
        {
            return ToUnsignedInteger<uint64_t>();
        }

        /// @brief 符号なし整数値に変換
        /// @tparam TUNum 整数型
        template <std::unsigned_integral TUNum>
        constexpr TUNum ToUnsignedInteger() const noexcept
        {
            if constexpr (N >= sizeof(TUNum) * 8) {
                return *(reinterpret_cast<const TUNum*>(_buffer));
            }
            else {
                TUNum result = 0;

                uint8_t* p = reinterpret_cast<uint8_t*>(&result);

                for (ssize_t i = 0; i < (sizeof(_buffer) - 1); i++) {
                    p[i] = _buffer[i];
                }

                p += (sizeof(_buffer) - 1);

                if constexpr (N % 8) {
                    constexpr uint8_t vv = (uint8_t)(255 >> (8 - (N % 8)));
                    *p = vv & _buffer[sizeof(_buffer) - 1];
                }
                else {
                    *p = _buffer[sizeof(_buffer) - 1];
                }

                return result;
            }
        }

        /// @brief ビット列の文字列表現を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        Utf8String ToUtf8String() const
        {
            return ToGenericString<Utf8String::ElementType>();
        }

        /// @brief ビット列の文字列表現を取得
        /// @param one 1を表す文字
        /// @param zero 0を表す文字
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        Utf8String ToUtf8String(char8_t one, char8_t zero) const
        {
            return ToGenericString<Utf8String::ElementType>(one, zero);
        }

        /// @brief ビット列の文字列表現を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        Utf32String ToUtf32String() const
        {
            return ToGenericString<Utf32String::ElementType>();
        }

        /// @brief ビット列の文字列表現を取得
        /// @param one 1を表す文字
        /// @param zero 0を表す文字
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        Utf32String ToUtf32String(char32_t one, char32_t zero) const
        {
            return ToGenericString<Utf32String::ElementType>(one, zero);
        }

        /// @brief ビット列の文字列表現を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        WideString ToWideString() const
        {
            return ToGenericString<WideString::ElementType>();
        }

        /// @brief ビット列の文字列表現を取得
        /// @param one 1を表す文字
        /// @param zero 0を表す文字
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        WideString ToWideString(wchar_t one, wchar_t zero) const
        {
            return ToGenericString<WideString::ElementType>(one, zero);
        }

        /// @brief ビットをすべてゼロにする
        constexpr void Reset() noexcept
        {
            for (uint8_t& v : _buffer) v = 0;
        }

        private:
        uint8_t _buffer[(N % 8) ? ((N / 8) + 1) : (N / 8)];
    };

    template <ssize_t N>
    [[nodiscard]] constexpr bool operator==(BitSet<N> const& left, BitSet<N> const& right) noexcept
    {
        const uint8_t* lData = left.Data();
        const uint8_t* rData = right.Data();

        constexpr ssize_t bufferLength = left.BufferLength() - 1;

        for (ssize_t i = 0; i < bufferLength; i++) {
            if (lData[i] != rData[i]) return false;
        }

        if constexpr (N % 8) {
            constexpr int nn = (left.BufferLength() - 1) * 8;

            for (int j = nn; j < N; j++) {
                if (left[j] != right[j]) return false;
            }

            return true;
        }
        else {
            return lData[bufferLength] != rData[bufferLength];
        }
    }

    template <ssize_t N>
    [[nodiscard]] constexpr bool operator!=(BitSet<N> const& left, BitSet<N> const& right) noexcept
    {
        return !(left == right);
    }

#define CREATE_OP_BITSET(op) \
    const uint8_t* pLeft = left.Data(); \
    const uint8_t* pRight = right.Data(); \
    constexpr ssize_t bufferLength = left.BufferLength(); \
    BitSet<N> bitset; \
    uint8_t* data = bitset.Data(); \
    for (ssize_t i = 0; i < bufferLength; i++) { \
        data[i] = pLeft[i] op pRight[i]; \
    } \
    return bitset

    template <ssize_t N>
    [[nodiscard]] constexpr BitSet<N> operator&(BitSet<N> const& left, BitSet<N> const& right) noexcept
    {
        CREATE_OP_BITSET(&);
    }

    template <ssize_t N>
    [[nodiscard]] constexpr BitSet<N> operator|(BitSet<N> const& left, BitSet<N> const& right) noexcept
    {
        CREATE_OP_BITSET(|);
    }

    template <ssize_t N>
    [[nodiscard]] constexpr BitSet<N> operator^(BitSet<N> const& left, BitSet<N> const& right) noexcept
    {
        CREATE_OP_BITSET(^);
    }

#undef CREATE_OP_BITSET
}

#endif //!KONGKONG_BITS_BITSET_H
