#ifndef KONGKONG_TEXT_GENERICFIXEDSTRING_H
#define KONGKONG_TEXT_GENERICFIXEDSTRING_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.GenericString.h"
#include "Kongkong.GenericStringView.h"
#include "Kongkong.Text.StringHelper.h"
#include "Kongkong.Collections.CollectionHelper.h"
#include "Kongkong.ArgumentNullException.h"

namespace KONGKONG_NAMESPACE::Text
{
    template <CharType TChar, ssize_t N> requires (N >= 1)
    struct GenericFixedString final : public ValueType {
        using ElementType = TChar;

        constexpr GenericFixedString() noexcept : _arr{ (TChar)'\0' }, _length(0) {}
        constexpr GenericFixedString(GenericString<TChar> const& str) noexcept
        {
            _copyFromString(str.Length(), str.c_str());
        }
        constexpr GenericFixedString(GenericStringView<TChar> const& str) noexcept
        {
            _copyFromString(str.Length(), str.c_str());
        }

        template <ssize_t N1>
        constexpr GenericFixedString(GenericFixedString<TChar, N1> const& str) noexcept
        {
            _copyFromString(str.Length(), str.c_str());
        }

        constexpr GenericFixedString& operator=(GenericString<TChar> const& str) noexcept
        {
            _copyFromString(str.Length(), str.c_str());
            return *this;
        }
        constexpr GenericFixedString& operator=(GenericStringView<TChar> const& str) noexcept
        {
            _copyFromString(str.Length(), str.c_str());
            return *this;
        }

        template <ssize_t N1>
        constexpr GenericFixedString& operator=(GenericFixedString<TChar, N1> const& str) noexcept
        {
            _copyFromString(str.Length(), str.c_str());
            return *this;
        }

        /// @brief 指定した要素番号の文字を取得
        /// @attention 範囲外の要素を指定した場合の動作は未定義だよ
        /// @param index 要素番号
        [[nodiscard]] constexpr TChar& operator[](ssize_t index) noexcept { return _arr[index]; }
        [[nodiscard]] constexpr TChar const& operator[](ssize_t index) const noexcept { return _arr[index]; }

        /// @brief ふぁ！？っく
        GenericFixedString& operator+=(std::nullptr_t) = delete;

        /// @brief C文字列を末尾に追加
        /// @param p 追加するC文字列
        /// @throws ArgumentNullException: pがnullptrのとき
        GenericFixedString& operator+=(const TChar* p)
        {
            Append(p);
            return *this;
        }

        /// @brief StringViewが参照する文字列を追加
        /// @param right 追加する文字列
        /// @throws ArgumentNullException: rightがnullptrのとき
        constexpr GenericFixedString& operator+=(GenericStringView<TChar> const& right) noexcept
        {
            Append(right);
            return *this;
        }

        /// @brief 文字列を末尾に追加
        /// @param right 追加する文字列
        constexpr GenericFixedString& operator+=(GenericString<TChar> const& right) noexcept
        {
            Append(right);
            return *this;
        }

        [[nodiscard]] constexpr TChar* begin() noexcept { return _arr; }
        [[nodiscard]] constexpr const TChar* begin() const noexcept { return _arr; }
        [[nodiscard]] constexpr TChar* end() noexcept { return _arr + _length; }
        [[nodiscard]] constexpr const TChar* end() const noexcept { return _arr + _length; }

        [[nodiscard]]
        constexpr const TChar* c_str() const noexcept { return _arr; }

        /// @brief ふぁ！？っく
        void Append(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void Append(ssize_t, std::nullptr_t) = delete;

        /// @brief 文字を末尾に追加
        /// @attention 配列が埋まってる場合は何もしないよ！
        /// @param c 追加する文字
        constexpr void Append(TChar c) noexcept
        {
            if (_length == N) [[unlikely]] return;

            _arr[_length] = c;
            ++_length;
            _arr[_length] = (TChar)'\0';
        }

        /// @brief 複数文字を末尾に追加
        /// @param count 追加する文字数
        /// @param c 追加する文字
        /// @throws InvalidArgumentException: countがゼロ以下の時
        void Append(ssize_t count, TChar c)
        {
            Collections::CollectionHelper::CheckLength(count);
            AppendUnsafe(count, c);
        }

        /// @brief C文字列を末尾に追加
        /// @param p 追加するC文字列
        /// @throws ArgumentNullException: pがnullptrのとき
        void Append(const TChar* p)
        {
            ArgumentNullException::CheckNull(p, u"p");
            AppendUnsafe(p);
        }

        /// @brief C文字列を末尾に追加
        /// @param length 追加する最大文字数
        /// @param p 追加するC文字列
        /// @throws ArgumentNullException: pがnullptrのとき
        /// @throws InvalidArgumentException: countがゼロ以下の時
        void Append(ssize_t length, const TChar* p)
        {
            Collections::CollectionHelper::CheckLength(length);
            ArgumentNullException::CheckNull(p, u"p");
            AppendUnsafe(length, p);
        }

        /// @brief 文字列を末尾に追加
        /// @param str 追加する文字列
        constexpr void Append(GenericString<TChar> const& str) noexcept
        {
            AppendUnsafe(str.Length(), str.c_str());
        }

        /// @brief StringViewが参照する文字列を追加
        /// @param view 追加する文字列
        constexpr void Append(GenericStringView<TChar> const& view) noexcept
        {
            AppendUnsafe(view.Length(), view.c_str());
        }

        /// @brief ふぁ！？っく
        void AppendUnsafe(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void AppendUnsafe(ssize_t, std::nullptr_t) = delete;

        /// @brief 複数文字を末尾に追加
        /// @param count 追加する文字数
        /// @param c 追加する文字
        constexpr void AppendUnsafe(ssize_t count, TChar c) noexcept
        {
            ssize_t maxlen = count < (N - _length) ? count : (N - _length);

            TChar* pThis = _arr + _length;
            TChar* pEnd = pThis + maxlen;

            *pEnd = (TChar)'\0';

            while (pThis != pEnd) {
                *pThis = c;
                ++pThis;
            }

            _length += maxlen;
        }

        /// @brief C文字列を末尾に追加
        /// @param p 追加するC文字列
        constexpr void AppendUnsafe(const TChar* p) noexcept
        {
            AppendUnsafe(StringHelper::GetLengthUnsafe(p), p);
        }

        /// @brief C文字列を末尾に追加
        /// @param length 追加する文字数
        /// @param p 追加するC文字列
        constexpr void AppendUnsafe(ssize_t length, const TChar* p) noexcept
        {
            ssize_t maxlen = length < (N - _length) ? length : (N - _length);

            TChar* pThis = _arr + _length;
            TChar* pEnd = pThis + maxlen;

            *pEnd = (TChar)'\0';

            while (pThis != pEnd) {
                *pThis = *p;
                ++pThis;
                ++p;
            }

            _length += maxlen;
        }

        /// @brief NULL文字分を除いたメモリブロックの容量を取得
        [[nodiscard]]
        constexpr ssize_t Capacity() const noexcept { return N + 1; }

        /// @brief 要素を全て削除する
        constexpr void Clear() noexcept { _length = 0; _arr[0] = (TChar)'\0'; }

        /// @brief ふぁ！？っく
        bool Contains(std::nullptr_t) const = delete;

        /// @brief 文字列へのポインターを取得
        [[nodiscard]] constexpr TChar* Data() noexcept { return _arr; }
        [[nodiscard]] constexpr const TChar* Data() const noexcept { return _arr; }

        [[nodiscard]]
        constexpr GenericStringView<TChar> GetView() const noexcept { return GenericStringView<TChar>::FromPointerUnsafe(_length, _arr); }

        /// @brief 文字列が空であるかを確認
        [[nodiscard]]
        constexpr bool IsEmpty() const noexcept { return _length == 0; }

        [[nodiscard]]
        constexpr ssize_t Length() const noexcept { return _length; }

        [[nodiscard]]
        constexpr ssize_t MaxLength() const noexcept { return N; }

        /// @brief ふぁ！？っく
        bool StartsWith(std::nullptr_t) const = delete;

        /// @brief 指定したプレフィックスで文字列が始まるかを確認
        /// @param c 文字
        [[nodiscard]]
        constexpr bool StartsWith(TChar c) const noexcept { if (_length == 0) [[unlikely]] return false; return *_arr == c; }

        private:
        TChar _arr[N + 1];
        ssize_t _length;

        constexpr void _copyFromString(ssize_t length, const TChar* p) noexcept
        {
            const TChar* pStr = p;
            _length = N < length ? N : length;

            TChar* pThis = _arr;
            TChar* end = pThis + _length;
            *end = (TChar)'\0';

            while (pThis != end) {
                *pThis = *pStr;
                pThis++;
                pStr++;
            }
        }

    };
}

#endif //!KONGKONG_TEXT_GENERICFIXEDSTRING_H
