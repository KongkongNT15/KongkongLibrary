#ifndef KONGKONG_STRINGVIEW_H
#define KONGKONG_STRINGVIEW_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include <string>

namespace KONGKONG_NAMESPACE
{
    /// @brief 文字列ビュー
    template <class TChar> requires CharType<TChar>
    struct GenericStringView final : public ValueType {

        /// @brief 空のビューを取得
        [[nodiscard]]
        static constexpr GenericStringView const& Empty() noexcept { return _empty; }

        /// @brief 右辺値はすぐに消えてしまうので参照してはいけない
        static GenericStringView FromChar(TChar&&) = delete;

        [[nodiscard]]
        static constexpr GenericStringView FromChar(TChar const& c) noexcept { return GenericStringView(&c, 1, 0); }

        template <ssize_t N>
        [[nodiscard]] static consteval GenericStringView FromLiteral(const char16_t (&arr)[N]) noexcept { return GenericStringView(arr, N - 1, 0); }

        /// @brief ふぁ！？っく
        static GenericStringView FromPointerUnsafe(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static GenericStringView FromPointerUnsafe(ssize_t, std::nullptr_t) = delete;

        [[nodiscard]]
        static GenericStringView FromPointerUnsafe(const TChar* p) noexcept;

        [[nodiscard]]
        static constexpr GenericStringView FromPointerUnsafe(ssize_t length, const TChar* p) noexcept { return GenericStringView(p, length, 0); }

        /// @brief 2つのStringViewが同じ場所を参照していてかつ同じ長さであるかを判定
        /// @param left StringView
        /// @param right StringView
        [[nodiscard]]
        static constexpr bool IsEqual(GenericStringView const& left, GenericStringView const& right) noexcept { return left._p == right._p && left._length == right._length; }

        /// @brief 2つのStringViewが参照してる文字列の値が一致しているかを判定
        /// @param left StringView
        /// @param right StringView
        [[nodiscard]]
        static bool IsWeakEqual(GenericStringView const& left, GenericStringView const& right) noexcept;

        /// @brief Find()で見つからなかった時の戻り値
        [[nodiscard]]
        static constexpr ssize_t NotFound() noexcept { return -1; }

        /// @brief ふぁ！？っく
        GenericStringView(std::nullptr_t) = delete;

        /// @brief 文字列の長さを指定して作成
        /// @param length 長さ
        /// @param p 文字列へのポインター
        /// @throws ArgumentNullException: pがnullptrのとき
        /// @throws ArgumentOutOfRangeException: lengthがpの実際の長さよりも大きい時
        /// @throws InvalidArgumentException: lengthがゼロ以下の時
        GenericStringView(ssize_t length, const TChar* p);

        /// @brief C文字列から作成
        /// @param p C文字列へのポインター
        /// @throws ArgumentNullException: pがnullptrのとき
        GenericStringView(const TChar* p);

        /// @brief Stringから作成
        /// @param str 文字列
        constexpr GenericStringView(GenericString<TChar> const& str) noexcept : _p(str.Data()), _length(str.Length()) {}

        /// @brief std::u16stringから作成
        /// @param str 文字列
        constexpr GenericStringView(std::basic_string<TChar, std::char_traits<TChar>> const& str) noexcept : _p(str.data()), _length((ssize_t)str.size()) {}

        /// @brief std::basic_string_viewに変換
        [[nodiscard]]
        constexpr operator std::basic_string_view<TChar, std::char_traits<TChar>>() const noexcept { return std::basic_string_view<TChar, std::char_traits<TChar>>(_p, (size_t)_length); }

        /// @brief 指定した要素番号の文字を取得
        /// @param index 要素番号
        /// @attention 範囲外の要素番号を指定した時の動作は未定義
        [[nodiscard]]
        constexpr TChar operator[] (ssize_t index) const noexcept { return _p[index]; }

        constexpr const TChar* begin() const noexcept { return _p; }
        constexpr const TChar* end() const noexcept { return _p + _length; }

        /// @brief 参照先のポインターを取得
        /// @attention nullptrを返す可能性がある
        [[nodiscard]]
        constexpr const TChar* c_str() const noexcept { return _p; }

        /// @brief 指定した要素番号の文字を取得
        /// @param index 要素番号
        /// @throws InvalidArgumentException: indexが負の値の時
        /// @throws ArgumentOutOfRangeException: 範囲外の要素を指定した時
        [[nodiscard]]
        TChar At(ssize_t index) const;

        /// @brief 最後の文字を取得
        /// @throws InvalidOperationException: Length()がゼロの時
        [[nodiscard]]
        TChar Back() const;

        /// @brief ふぁ！？っく
        bool Contains(std::nullptr_t) const = delete;

        /// @brief 指定した文字が含まれるかを確認
        /// @param c 文字
        [[nodiscard]]
        bool Contains(TChar c) const noexcept;
        
        /// @brief 指定した文字列が含まれるかを確認
        /// @param p 文字列
        /// @throws ArgumentNullException: pがnullptrのとき
        [[nodiscard]]
        bool Contains(const TChar* p) const;

        /// @brief 指定した文字列が含まれるかを確認
        /// @param view 文字列
        [[nodiscard]]
        bool Contains(GenericStringView const& view) const noexcept;

        /// @brief 指定した文字列が含まれるかを確認
        /// @param str 文字列
        [[nodiscard]]
        bool Contains(GenericString<TChar> const& str) const noexcept;

        /// @brief ふぁ！？っく
        bool EndsWith(std::nullptr_t) const = delete;

        /// @brief 指定したサフィックスで文字列が終わるかを確認
        /// @param c 文字
        [[nodiscard]]
        bool EndsWith(TChar c) const noexcept;

        /// @brief 指定したサフィックスで文字列が終わるかを確認
        /// @param p 文字列
        /// @throws ArgumentNullException: pがnullptrのとき
        [[nodiscard]]
        bool EndsWith(const TChar* p) const;

        /// @brief 指定したサフィックスで文字列が終わるかを確認
        /// @param view 文字列
        [[nodiscard]]
        bool EndsWith(GenericStringView const& view) const noexcept;
        
        /// @brief 指定したサフィックスで文字列が終わるかを確認
        /// @param str 文字列
        [[nodiscard]]
        bool EndsWith(GenericString<TChar> const& str) const noexcept;

        /// @brief ふぁ！？っく
        ssize_t Find(std::nullptr_t) = delete;
        /// @brief ふぁ！？っく
        ssize_t Find(std::nullptr_t, ssize_t offset) = delete;
        /// @brief ふぁ！？っく
        ssize_t FindUnsafe(std::nullptr_t) = delete;
        /// @brief ふぁ！？っく
        ssize_t FindUnsafePointer(std::nullptr_t, ssize_t offset) = delete;
        /// @brief ふぁ！？っく
        ssize_t FindUnsafeOffset(std::nullptr_t, ssize_t offset) = delete;

        /// @brief 文字を検索
        /// @param c 検索する文字
        /// @return 指定した文字が最初に現れる要素番号、見つからない場合はNotFound()
        [[nodiscard]]
        ssize_t Find(TChar c) const noexcept;

        /// @brief 文字列を検索
        /// @param p 検索する文字列
        /// @throws ArgumentNullException: pがnullptrのとき
        /// @return 指定した文字列が最初に現れる要素番号、見つからない場合はNotFound()
        [[nodiscard]]
        ssize_t Find(const TChar* p) const;

        /// @brief 文字列を検索
        /// @param view 検索する文字列
        /// @return 指定した文字列が最初に現れる要素番号、見つからない場合はNotFound()
        [[nodiscard]]
        ssize_t Find(GenericStringView const& view) const noexcept;

        /// @brief 文字列を検索
        /// @param str 検索する文字列
        /// @return 指定した文字列が最初に現れる要素番号、見つからない場合はNotFound()
        [[nodiscard]]
        ssize_t Find(GenericString<TChar> const& str) const noexcept;

        /// @brief 文字を検索
        /// @param c 検索する文字
        /// @param offset 検索する文字列
        /// @return 指定した文字が最初に現れる要素番号、見つからない場合はNotFound()
        /// @throws InvalidArgumentException: offsetが参照する文字数を超えているとき
        [[nodiscard]]
        ssize_t Find(TChar c, ssize_t offset) const;

        /// @brief 文字列を検索
        /// @param p 検索する文字列
        /// @param offset 検索する文字列
        /// @throws ArgumentNullException: pがnullptrのとき
        /// @return 指定した文字列が最初に現れる要素番号、見つからない場合はNotFound()
        /// @throws InvalidArgumentException: offsetが参照する文字数を超えているとき
        [[nodiscard]]
        ssize_t Find(const TChar* p, ssize_t offset) const;

        /// @brief 文字列を検索
        /// @param view 検索する文字列
        /// @param offset 検索する文字列
        /// @return 指定した文字列が最初に現れる要素番号、見つからない場合はNotFound()
        /// @throws InvalidArgumentException: offsetが参照する文字数を超えているとき
        [[nodiscard]]
        ssize_t Find(GenericStringView const& view, ssize_t offset) const;

        /// @brief 文字列を検索
        /// @param str 検索する文字列
        /// @param offset 検索する文字列
        /// @return 指定した文字列が最初に現れる要素番号、見つからない場合はNotFound()
        /// @throws InvalidArgumentException: offsetが参照する文字数を超えているとき
        [[nodiscard]]
        ssize_t Find(GenericString<TChar> const& str, ssize_t offset) const;

        /// @brief 文字を検索
        /// @param c 検索する文字
        /// @param offset 検索する文字列
        /// @return 指定した文字が最初に現れる要素番号、見つからない場合はNotFound()
        [[nodiscard]]
        ssize_t FindUnsafe(TChar c, ssize_t offset) const noexcept;

        /// @brief 文字列を検索
        /// @param p 検索する文字列
        /// @param offset 検索する文字列
        /// @return 指定した文字列が最初に現れる要素番号、見つからない場合はNotFound()
        [[nodiscard]]
        ssize_t FindUnsafe(const TChar* p, ssize_t offset) const noexcept;

        /// @brief 文字列を検索
        /// @param p 検索する文字列
        /// @param offset 検索する文字列
        /// @throws ArgumentNullException: pがnullptrのとき
        /// @return 指定した文字列が最初に現れる要素番号、見つからない場合はNotFound()
        [[nodiscard]]
        ssize_t FindUncheckOffsetUnsafe(const TChar* p, ssize_t offset) const;

        /// @brief 文字列を検索
        /// @param p 検索する文字列
        /// @param offset 検索する文字列
        /// @return 指定した文字列が最初に現れる要素番号、見つからない場合はNotFound()
        /// @throws InvalidArgumentException: offsetが参照する文字数を超えているとき
        [[nodiscard]]
        ssize_t FindUncheckPointerUnsafe(const TChar* p, ssize_t offset) const;

        /// @brief 文字列を検索
        /// @param view 検索する文字列
        /// @param offset 検索する文字列
        /// @return 指定した文字列が最初に現れる要素番号、見つからない場合はNotFound()
        [[nodiscard]]
        ssize_t FindUnsafe(GenericStringView const& view, ssize_t offset) const noexcept;

        /// @brief 文字列を検索
        /// @param str 検索する文字列
        /// @param offset 検索する文字列
        /// @return 指定した文字列が最初に現れる要素番号、見つからない場合はNotFound()
        [[nodiscard]]
        ssize_t FindUnsafe(GenericString<TChar> const& str, ssize_t offset) const noexcept;

        /// @brief ビューが空であるかを確認
        [[nodiscard]]
        constexpr bool IsEmpty() const noexcept { return _length == 0; }

        /// @brief StringViewが同じ場所を参照していてかつ同じ長さであるかを判定
        /// @param right StringView
        [[nodiscard]]
        constexpr bool IsEqual(GenericStringView const& right) const noexcept { return IsEqual(*this, right); }

        /// @brief StringViewが参照してる文字列の値が一致しているかを判定
        /// @param right StringView
        [[nodiscard]]
        bool IsWeakEqual(GenericStringView const& right) const noexcept;

        /// @brief 文字列の長さを取得
        /// @brief nullptrを参照している場合は-1
        [[nodiscard]]
        constexpr ssize_t Length() const noexcept { return _length; }

        /// @brief ふぁ！？っく
        bool StartsWith(std::nullptr_t) = delete;

        /// @brief 指定したプレフィックスで文字列が始まるかを確認
        /// @param c 文字
        [[nodiscard]]
        bool StartsWith(TChar c) const noexcept;
        
        /// @brief 指定したプレフィックスで文字列が始まるかを確認
        /// @param p 文字列
        /// @throws ArgumentNullException: pがnullptrのとき
        [[nodiscard]]
        bool StartsWith(const TChar* p) const;

        /// @brief 指定したプレフィックスで文字列が始まるかを確認
        /// @param view 文字列
        [[nodiscard]]
        bool StartsWith(GenericStringView const& view) const noexcept;

        /// @brief 指定したプレフィックスで文字列が始まるかを確認
        /// @param str 文字列
        [[nodiscard]]
        bool StartsWith(GenericString<TChar> const& str) const;

        /// @brief 部分文字列ビューを取得
        /// @param count 文字数
        /// @throws InvalidArgumentException: countがゼロ以下の時
        /// @throws ArgumentOutOfRangeException: 文字列ビューの終了位置が範囲外の時
        [[nodiscard]] GenericStringView SubString(ssize_t count) const;

        /// @brief 部分文字列ビューを取得
        /// @param offset 開始位置
        /// @param count 文字数
        /// @throws InvalidArgumentException: countがゼロ以下の時
        /// @throws ArgumentOutOfRangeException: 文字列ビューの開始位置または終了位置が範囲外の時
        [[nodiscard]] GenericStringView SubString(ssize_t offset, ssize_t count) const;

        /// @brief CharStringに変換
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        CharString ToCharString() const;

        /// @brief Stringに変換
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;
        
        private:
        /// @brief Empty()が参照する値
        static const TChar _emptyHolder;
        static const GenericStringView _empty;

        /// @brief Emptyとして作成
        constexpr GenericStringView() noexcept : _p(&_emptyHolder), _length(0) {}
        constexpr GenericStringView(int) noexcept : _p(), _length() {}
        constexpr GenericStringView(const TChar* p, ssize_t length, int) noexcept : _p(p), _length(length) {}

        const TChar* _p;
        ssize_t _length;

        void _checkCount(ssize_t offset, ssize_t count) const;
        void _checkOffset(ssize_t offset) const;

        friend GenericString<TChar>;
    };

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] constexpr bool operator==(GenericStringView<TChar> const& left, GenericStringView<TChar> const& right) noexcept { return GenericStringView<TChar>::IsEqual(left, right); }

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] constexpr bool operator!=(GenericStringView<TChar> const& left, GenericStringView<TChar> const& right) noexcept { return !GenericStringView<TChar>::IsEqual(left, right); }

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] GenericString<TChar> operator+(GenericStringView<TChar> const& left, GenericStringView<TChar> const& right);

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] GenericString<TChar> operator+(GenericString<TChar> const& left, GenericStringView<TChar> const& right);

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] GenericString<TChar> operator+(GenericString<TChar>&& left, GenericStringView<TChar> const& right);

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] GenericString<TChar> operator+(GenericStringView<TChar> const& left, GenericString<TChar> const& right);

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] GenericString<TChar> operator+(GenericStringView<TChar> const& left, const TChar* right);

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] GenericString<TChar> operator+(const TChar* left, GenericStringView<TChar> const& right);
}

#endif //!KONGKONG_STRINGVIEW_H
