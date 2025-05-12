#ifndef KONGKONG_COLLECTIONS_SPAN_H
#define KONGKONG_COLLECTIONS_SPAN_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.GenericString.h"
#include "Kongkong.ArgumentOutOfRangeException.h"
#include "Kongkong.InvalidArgumentException.h"

namespace KONGKONG_NAMESPACE::Collections
{
    /// @brief 配列の参照
    /// @tparam T 要素型
    template <class T>
    struct Span final : public ValueType {
        using ElementType = T;

        /// @brief ふぁ！？っく
        Span(ssize_t, std::nullptr_t) = delete;

        /// @brief 作成
        /// @param length 長さ
        /// @param p 参照先
        /// @throws ArgumentNullException: pがnullptrのとき
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        constexpr Span(ssize_t length, const T* p) : _length(length), _p(p)
        {
            ArgumentNullException::CheckNull(p, u"p");
            _checkLength(length);
        }

        /// @brief 配列から作成
        /// @tparam N 配列の要素数
        /// @param arr 配列
        template <ssize_t N>
        constexpr Span(const T(&arr)[N]) noexcept : _length(N), _p(arr) {}

        /// @brief 指定した番号の要素を取得
        /// @attention 範囲外の要素を指定した場合の動作は未定義だよ
        /// @param index 要素番号
        [[nodiscard]]
        constexpr T const& operator[] (ssize_t index) const noexcept { return _p[index]; }

        [[nodiscard]] auto begin() const noexcept { return _p; }
        [[nodiscard]] auto end() const noexcept { return _p + _length; }

        /// @brief 指定した番号の要素を取得
        /// @param index 要素番号
        /// @throws ArgumentOutOfRangeException: 範囲外の要素を指定したとき
        [[nodiscard]]
        constexpr T const& At(ssize_t index) const
        {
            _checkIndex(index);

            return _p[index];
        }

        /// @brief 最後の要素を取得
        [[nodiscard]]
        T const& Back() const noexcept { return _p[_length - 1]; }

        /// @brief 指定した値が含まれるかを判定
        /// @param value 値
        [[nodiscard]]
        bool Contains(T const& value) const noexcept
        {
            for (T const& v : *this) {
                if (v == value) return true;
            }

            return false;
        }

        /// @brief 最初の要素を取得
        [[nodiscard]]
        T const& Front() const noexcept { return _p[0]; }

        /// @brief 指定した要素の番号を取得
        /// @param value 値
        /// @return 要素番号、要素が見つからなかった場合は(ssize_t)-1
        [[nodiscard]]
        ssize_t IndexOf(T const& value) const noexcept
        {
            for (ssize_t i = 0; i < _length; i++) {
                if (_p[i] == value) return i;
            }

            return -1;
        }

        /// @brief 要素数を取得
        [[nodiscard]]
        constexpr ssize_t Length() const noexcept { return _length; }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const { return String::FromPointerUnsafe(u"Kongkong::Collections::Span<T>", true); }
    
        private:
        const T* _p;
        ssize_t _length;

        static constexpr void _checkLength(ssize_t length) { if (length <= 0) [[unlikely]] throw InvalidArgumentException(u"要素数にゼロ以下が指定されました"); }
    
        constexpr void _checkIndex(ssize_t index) const { if (index < 0 || _length <= index) [[unlikely]] throw ArgumentOutOfRangeException(u"指定した要素が範囲外です"); }
    };
}

#endif //!KONGKONG_COLLECTIONS_SPAN_H
