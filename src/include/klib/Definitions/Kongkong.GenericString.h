#ifndef KONGKONG_STRING_H
#define KONGKONG_STRING_H

#include "Base.h"
#include "Kongkong.ValueType.h"

#include <string>

namespace KONGKONG_NAMESPACE
{
    template <class TChar> requires CharType<TChar>
    struct GenericString final : public ValueType {

        using ElementType = TChar;

        /// @brief String用のメモリブロックを確保
        /// @attention 破棄する場合はFreeMemory()を使ってね！
        /// @param capacity 要素数
        /// @throws InvalidArgumentException: capacityがゼロ以下の時
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        [[nodiscard]]
        static TChar* AllocMemory(ssize_t capacity);

        /// @brief GenericString用のメモリブロックを確保
        /// @param capacity 要素数
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        [[nodiscard]]
        static TChar* AllocMemoryUnsafe(ssize_t capacity);

        /// @brief 容量を指定して作成
        /// @param capacity 容量
        /// @return インスタンス
        /// @throws InvalidArgumentException: capacityがゼロ以下の時
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static GenericString CreateWithCapacity(ssize_t capacity);

        /// @brief 容量を指定して作成
        /// @param capacity 容量
        /// @return インスタンス
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static GenericString CreateWithCapacityUnsafe(ssize_t capacity);
        
        [[nodiscard]]
        static constexpr ssize_t ElementSize() noexcept { return sizeof(TChar); }

        /// @brief ふぁ！？っく
        static void FreeMemory(std::nullptr_t) = delete;

        /// @brief AllocMemory()で確保した領域を解放
        /// @param memoryBlock 開放するメモリブロック
        /// @throws ArgumentNullException: memoryBlockがnullptrのとき
        static void FreeMemory(TChar* memoryBlock);

        /// @brief ふぁ！？っく
        static void FreeMemoryUnsafe(std::nullptr_t) = delete;

        /// @brief AllocMemory()で確保した領域を解放
        /// @param memoryBlock 開放するメモリブロック
        static void FreeMemoryUnsafe(TChar* memoryBlock) noexcept;

        /// @brief ふぁ！？っく
        static GenericString FromAscii(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromAscii(ssize_t, std::nullptr_t) = delete;

        /// @brief アスキー文字列から作成
        /// @attention アスキーコードにない文字があっても例外は投げないよ
        /// @param str Ascii文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        [[nodiscard]]
        static GenericString FromAscii(const char* str);

        /// @brief アスキー文字列から作成
        /// @param length 参照する文字列の長さ
        /// @param str Ascii文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき、lengthがstrの実際の長さよりも大きいとき
        [[nodiscard]]
        static GenericString FromAscii(ssize_t length, const char* str);

        /// @brief アスキー文字列から作成
        /// @attention アスキーコードにない文字があっても例外は投げないよ
        /// @param str Ascii文字列
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        [[nodiscard]]
        static GenericString FromAscii(std::string const& str);

        /// @brief ふぁ！？っく
        static GenericString FromAsciiUnsafe(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromAsciiUnsafe(ssize_t, std::nullptr_t) = delete;

        /// @brief アスキー文字列から作成
        /// @attention アスキーコードにない文字があっても例外は投げないよ
        /// @param str Ascii文字列
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        [[nodiscard]]
        static GenericString FromAsciiUnsafe(const char* str);

        /// @brief アスキー文字列から作成
        /// @attention アスキーコードにない文字があっても例外は投げないよ
        /// @param length 参照する文字列の長さ
        /// @param str Ascii文字列
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        [[nodiscard]]
        static GenericString FromAsciiUnsafe(ssize_t length, const char* str);

#if 0 //考えるのだるい

        /// @brief ふぁ！？っく
        static GenericString FromChar(char32_t) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(char32_t, bool) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(short) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(short, bool) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(int) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(int, bool) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(long) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(long, bool) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(long long) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(long long, bool) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(unsigned short) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(unsigned short, bool) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(unsigned int) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(unsigned int, bool) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(unsigned long) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(unsigned long, bool) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(unsigned long long) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(unsigned long long, bool) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(float) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(float, bool) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(double) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(double, bool) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(long double) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromChar(long double, bool) = delete;

        /// @brief 1文字から作成
        /// @param c 文字
        /// @param isFited Capacity()をLength() + 1と一致させるか
        [[nodiscard]]
        static GenericString FromChar(char c, bool isFited = false);

        /// @brief 1文字から作成
        /// @param c 文字
        /// @param isFited Capacity()をLength() + 1と一致させるか
        [[nodiscard]]
        static GenericString FromChar(char8_t c, bool isFited = false);

        /// @brief 1文字から作成
        /// @param c 文字
        /// @param isFited Capacity()をLength() + 1と一致させるか
        [[nodiscard]]
        static GenericString FromChar(char16_t c, bool isFited = false);

#endif //0

        /// @brief C文字列を連結
        /// @param left C文字列
        /// @param right C文字列
        /// @param isFited Capacity()をLength() + 1と一致させるか
        /// @throws ArgumentNullException: left, rightがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static GenericString FromCStrings(const TChar* left, const TChar* right, bool isFited = false);

        /// @brief 文字列リテラルから作成
        /// @attention リテラル以外の配列は使わないでね！
        /// @tparam N 要素数
        /// @param arr 文字列リテラル
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        template <ssize_t N>
        [[nodiscard]] static GenericString FromLiteral(const TChar(&arr)[N]);

        /// @brief ふぁ！？っく
        static GenericString FromPointerUnsafe(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromPointerUnsafe(std::nullptr_t, bool) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromPointerUnsafe(ssize_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static GenericString FromPointerUnsafe(ssize_t, std::nullptr_t, bool) = delete;

        /// @brief ポインターからコピー
        /// @param p ポインター
        /// @param isFited Capacity()をLength() + 1と一致させるか
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        [[nodiscard]]
        static GenericString FromPointerUnsafe(const TChar* p, bool isFited = false);

        /// @brief ポインターからコピー
        /// @param length 要素数
        /// @param p ポインター
        /// @param isFited Capacity()をLength() + 1と一致させるか
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        [[nodiscard]]
        static GenericString FromPointerUnsafe(ssize_t length, const TChar* p, bool isFited = false);

        /// @brief Find()で見つからなかった時の戻り値
        [[nodiscard]]
        static ssize_t NotFound() noexcept { return -1; }

        /// @brief bool値から文字列を作成
        /// @param value bool値
        /// @return 作成された文字列
        [[nodiscard]] 
        static GenericString ValueOf(bool value);

        /// @brief 数値から文字列を作成
        /// @param value 数値
        /// @return 作成された文字列
        [[nodiscard]] 
        static GenericString ValueOf(signed char value);

        /// @brief 数値から文字列を作成
        /// @param value 数値
        /// @return 作成された文字列
        [[nodiscard]] 
        static GenericString ValueOf(short value);

        /// @brief 数値から文字列を作成
        /// @param value 数値
        /// @return 作成された文字列
        [[nodiscard]] 
        static GenericString ValueOf(int value);

        /// @brief 数値から文字列を作成
        /// @param value 数値
        /// @return 作成された文字列
        [[nodiscard]] 
        static GenericString ValueOf(long value);

        /// @brief 数値から文字列を作成
        /// @param value 数値
        /// @return 作成された文字列
        [[nodiscard]] 
        static GenericString ValueOf(long long value);

        /// @brief 数値から文字列を作成
        /// @param value 数値
        /// @return 作成された文字列
        [[nodiscard]] 
        static GenericString ValueOf(unsigned char value);

        /// @brief 数値から文字列を作成
        /// @param value 数値
        /// @return 作成された文字列
        [[nodiscard]] 
        static GenericString ValueOf(unsigned short value);

        /// @brief 数値から文字列を作成
        /// @param value 数値
        /// @return 作成された文字列
        [[nodiscard]] 
        static GenericString ValueOf(unsigned int value);

        /// @brief 数値から文字列を作成
        /// @param value 数値
        /// @return 作成された文字列
        [[nodiscard]] 
        static GenericString ValueOf(unsigned long value);

        /// @brief 数値から文字列を作成
        /// @param value 数値
        /// @return 作成された文字列
        [[nodiscard]] 
        static GenericString ValueOf(unsigned long long value);

        /// @brief 数値から文字列を作成
        /// @param value 数値
        /// @return 作成された文字列
        [[nodiscard]] 
        static GenericString ValueOf(float value);

        /// @brief 数値から文字列を作成
        /// @param value 数値
        /// @return 作成された文字列
        [[nodiscard]] 
        static GenericString ValueOf(double value);

        /// @brief 数値から文字列を作成
        /// @param value 数値
        /// @return 作成された文字列
        [[nodiscard]] 
        static GenericString ValueOf(long double value);

        /// @brief ポインターから文字列を作成
        /// @param value 数値
        /// @return 作成された文字列
        [[nodiscard]] 
        static GenericString ValueOf(const void* value);

        /// @brief ふぁ！？っく
        static GenericString Wrap(ssize_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static GenericString Wrap(ssize_t, ssize_t, std::nullptr_t) = delete;

        /// @brief ポインターが指す領域をそのままStringが保有するメモリブロックとして作成
        /// @attention AllocMemory()で作成された領域を使ってね！
        /// @attention あとpがnull文字で終わらない場合は勝手に末尾にnullを追加するよ！
        /// @param capacity 要素数
        /// @param p ポインター
        /// @throws ArgumentNullException: pがnullptrのとき
        /// @throws InvalidArgumentException: capacityがゼロ以下の時
        [[nodiscard]]
        static GenericString Wrap(ssize_t capacity, TChar* p);

        /// @brief ポインターが指す領域をそのままStringが保有するメモリブロックとして作成
        /// @attention AllocMemory()で作成された領域を使ってね！
        /// @attention あとpがnull文字で終わらない場合は勝手に末尾にnullを追加するよ！
        /// @param capacity 要素数
        /// @param length 長さ
        /// @param p ポインター
        /// @throws ArgumentNullException: pがnullptrのとき
        /// @throws ArgumentOutOfRangeException: length + 1がcapacityを超えたとき
        [[nodiscard]]
        static GenericString Wrap(ssize_t capacity, ssize_t length, TChar* p);

        /// @brief ふぁ！？っく
        static GenericString WrapUnsafe(ssize_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static GenericString WrapUnsafe(ssize_t, ssize_t, std::nullptr_t) = delete;

        /// @brief ポインターが指す領域をそのままStringが保有するメモリブロックとして作成
        /// @attention AllocMemory()で作成された領域を使ってね！
        /// @attention あとpがnull文字で終わらない場合は勝手に末尾にnullを追加するよ！
        /// @param capacity 要素数
        /// @param p ポインター
        [[nodiscard]]
        static GenericString WrapUnsafe(ssize_t capacity, TChar* p) noexcept;

        /// @brief ポインターが指す領域をそのままStringが保有するメモリブロックとして作成
        /// @attention AllocMemory()で作成された領域を使ってね！
        /// @attention p[length] == u'\0'になるようにしてね！
        /// @param capacity 要素数
        /// @param length 長さ
        /// @param p ポインター
        [[nodiscard]]
        static GenericString WrapUnsafe(ssize_t capacity, ssize_t length, TChar* p) noexcept;

        /// @brief ふぁ！？っく
        GenericString(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        GenericString(std::nullptr_t, bool) = delete;

        /// @brief 空の文字列を作成
        /// @param isFited Capacity()をLength() + 1と一致させるか
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        explicit GenericString(bool isFited = false);

        /// @brief 文字列のコピーを作成
        /// @param right コピー元の値
        /// @param isFited Capacity()をLength() + 1と一致させるか
        GenericString(GenericString const& right, bool isFited = false);

        /// @brief 文字列右辺値からデータを移行
        /// @param right 文字列右辺値
        constexpr GenericString(GenericString&& right) noexcept : _p(right._p), _length(right._length), _capacity(right._capacity) { right._p = nullptr; }

        /// @brief u16stringから作成
        /// @param right 文字列
        /// @param isFited Capacity()をLength() + 1と一致させるか
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        GenericString(std::basic_string<TChar, std::char_traits<TChar>> const& right, bool isFited = false);

        /// @brief StringViewから作成
        /// @param right 文字列ビュー
        /// @param isFited Capacity()をLength() + 1と一致させるか
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        GenericString(GenericStringView<TChar> const& right, bool isFited = false);

        /// @brief C文字列から作成
        /// @param p 文字列
        /// @param isFited Capacity()をLength() + 1と一致させるか
        /// @throws ArgumentNullException: pがnullptrのとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        GenericString(const TChar* p, bool isFited = false);

        /// @brief 指定した文字で埋めた状態で作成
        /// @param length 文字数
        /// @param c 文字
        /// @param isFited Capacity()をLength() + 1と一致させるか
        /// @throws InvalidArgumentException: lengthがゼロ以下の時
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        GenericString(ssize_t length, TChar c, bool isFited = false);

        /// @brief C文字列から作成
        /// @param length コピーする長さ
        /// @param p 文字列
        /// @param isFited Capacity()をLength() + 1と一致させるか
        /// @throws ArgumentNullException: pがnullptrのとき
        /// @throws InvalidArgumentException: lengthがゼロ以下の時
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        GenericString(ssize_t length, const TChar* p, bool isFited = false);

        /// @brief char配列から作成
        /// @param right C文字列
        /// @throws ArgumentNullException: rightがnullptrのとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        GenericString(const char* right) requires std::same_as<TChar, char16_t>;

        /// @brief char文字列から作成
        /// @param right char文字列
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        GenericString(std::string const& right) requires std::same_as<TChar, char16_t>;

        ~GenericString();

        /// @brief ふぁ！？っく
        GenericString& operator=(std::nullptr_t) = delete;

        /// @brief 文字列をコピー
        /// @param right コピー元の値
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        GenericString& operator=(GenericString const& right);

        /// @brief 文字列右辺値からデータを移行
        /// @param right 文字列右辺値
        GenericString& operator=(GenericString&& right) noexcept;

        /// @brief 文字列ビューからコピー
        /// @param view 文字列ビュー
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        GenericString& operator=(GenericStringView<TChar> const& view);

        /// @brief C文字列からコピー
        /// @param p 文字列
        /// @throws ArgumentNullException: pがnullptrのとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        GenericString& operator=(const TChar* p);

        /// @brief u16stringからコピー
        /// @param u16str 文字列
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        GenericString& operator=(std::basic_string<TChar, std::char_traits<TChar>> const& u16str);

        /// @brief std::basic_stringに変換
        [[nodiscard]]
        operator std::basic_string<TChar, std::char_traits<TChar>>() const;

        /// @brief 指定した要素番号の文字を取得
        /// @attention 範囲外の要素を指定した場合の動作は未定義だよ
        /// @param index 要素番号
        [[nodiscard]] constexpr TChar& operator[](ssize_t index) noexcept { return _p[index]; }
        [[nodiscard]] constexpr TChar const& operator[](ssize_t index) const noexcept { return _p[index]; }

        /// @brief ふぁ！？っく
        GenericString& operator+=(std::nullptr_t) = delete;

        /// @brief C文字列を末尾に追加
        /// @param p 追加するC文字列
        /// @throws ArgumentNullException: pがnullptrのとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        GenericString& operator+=(const TChar* p);

        /// @brief StringViewが参照する文字列を追加
        /// @param right 追加する文字列
        /// @throws ArgumentNullException: rightがnullptrのとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        GenericString& operator+=(GenericStringView<TChar> const& right);

        /// @brief 文字列を末尾に追加
        /// @param right 追加する文字列
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        GenericString& operator+=(GenericString const& right);

        [[nodiscard]] constexpr TChar* begin() noexcept { return _p; }
        [[nodiscard]] constexpr const TChar* begin() const noexcept { return _p; }
        [[nodiscard]] constexpr TChar* end() noexcept { return _p + _length; }
        [[nodiscard]] constexpr const TChar* end() const noexcept { return _p + _length; }

        /// @brief C文字列を取得
        [[nodiscard]]
        constexpr const TChar* c_str() const noexcept { return _p; }

        /// @brief ふぁ！？っく
        void Append(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void Append(ssize_t, std::nullptr_t) = delete;

        /// @brief 文字を末尾に追加
        /// @param c 追加する文字
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void Append(TChar c);

        /// @brief 複数文字を末尾に追加
        /// @param count 追加する文字数
        /// @param c 追加する文字
        /// @throws InvalidArgumentException: countがゼロ以下の時
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void Append(ssize_t count, TChar c);

        /// @brief C文字列を末尾に追加
        /// @param p 追加するC文字列
        /// @throws ArgumentNullException: pがnullptrのとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void Append(const TChar* p);

        /// @brief C文字列を末尾に追加
        /// @param length 追加する最大文字数
        /// @param p 追加するC文字列
        /// @throws ArgumentNullException: pがnullptrのとき
        /// @throws InvalidArgumentException: countがゼロ以下の時
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void Append(ssize_t length, const TChar* p);

        /// @brief StringViewが参照する文字列を追加
        /// @param value 追加する文字列
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void Append(GenericStringView<TChar> const& value);

        /// @brief 文字列を末尾に追加
        /// @param value 追加する文字列
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void Append(GenericString const& value);

        /// @brief 環境依存の改行文字を追加
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void AppendNewLine();

        /// @brief ふぁ！？っく
        void AppendUnsafe(std::nullptr_t) = delete;

        /// @brief 複数文字を末尾に追加
        /// @param count 追加する文字数
        /// @param c 追加する文字
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void AppendUnsafe(ssize_t count, TChar c);

        /// @brief C文字列を末尾に追加
        /// @param p 追加するC文字列
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void AppendUnsafe(const TChar* p);

        /// @brief C文字列を末尾に追加
        /// @param length 追加する文字数
        /// @param p 追加するC文字列
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void AppendUnsafe(ssize_t length, const TChar* p);

        /// @brief 指定した要素番号の文字を取得
        /// @param index 要素番号
        /// @throws InvalidArgumentException: 要素番号が負の値の時
        /// @throws ArgumentOutOfRangeException: 要素番号が範囲外の時
        [[nodiscard]] TChar& At(ssize_t index);
        [[nodiscard]] TChar const& At(ssize_t index) const;

        /// @brief 最後の文字を取得
        /// @throws InvalidOperationException: Length()がゼロの時
        [[nodiscard]] TChar& Back();
        [[nodiscard]] TChar const& Back() const;

        /// @brief 最後の文字を取得
        [[nodiscard]] constexpr TChar& BackUnsafe() noexcept { return _p[_length - 1]; }
        [[nodiscard]] constexpr TChar const& BackUnsafe() const noexcept { return _p[_length - 1]; }

        /// @brief NULL文字分を除いたメモリブロックの容量を取得
        [[nodiscard]]
        constexpr ssize_t Capacity() const noexcept { return _capacity; }

        /// @brief 容量を変更
        /// @attention Length()よりも小さい値を指定すると文字列が切り捨てられるよ！
        /// @param capacity 容量
        /// @throws InvalidArgumentException: capacityがゼロ以下のとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void Capacity(ssize_t capacity);

        /// @brief 要素を全て削除する
        constexpr void Clear() noexcept { _length = 0; *_p = (TChar)'\0'; }

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
        /// @throws ArgumentNullException: viewがnullptrのとき
        [[nodiscard]]
        bool Contains(GenericStringView<TChar> const& view) const;

        /// @brief 指定した文字列が含まれるかを確認
        /// @param value 文字列
        [[nodiscard]]
        bool Contains(GenericString const& value) const noexcept;
        
        /// @brief 文字列へのポインターを取得
        [[nodiscard]] constexpr TChar* Data() noexcept { return _p; }
        [[nodiscard]] constexpr const TChar* Data() const noexcept { return _p; }

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
        bool EndsWith(GenericStringView<TChar> const& view) const noexcept;

        /// @brief 指定したサフィックスで文字列が終わるかを確認
        /// @param value 文字列
        [[nodiscard]]
        bool EndsWith(GenericString const& value) const noexcept;

        /// @brief ふぁ！？っく
        ssize_t Find(std::nullptr_t) const = delete;

        /// @brief 文字を検索
        /// @param c 検索する文字
        /// @return 指定した文字が最初に現れるインデックス
        /// @return 見つからない場合はKongkong::Collections::CollectionHelper::NotFound()
        [[nodiscard]]
        ssize_t Find(TChar c) const noexcept;

        /// @brief 文字列を検索
        /// @param p 検索する文字列
        /// @return 指定した文字列が最初に現れるインデックス
        /// @return 見つからない場合はKongkong::Collections::CollectionHelper::NotFound()
        /// @throws ArgumentNullException: pがnullptrのとき
        [[nodiscard]]
        ssize_t Find(const TChar* p) const;

        /// @brief 文字列を検索
        /// @param view 検索する文字列
        /// @return 指定した文字列が最初に現れるインデックス
        /// @return 見つからない場合はKongkong::Collections::CollectionHelper::NotFound()
        [[nodiscard]]
        ssize_t Find(GenericStringView<TChar> const& view) const noexcept;

        /// @brief 文字列を検索
        /// @param value 検索する文字列
        /// @return 指定した文字列が最初に現れるインデックス
        /// @return 見つからない場合はKongkong::Collections::CollectionHelper::NotFound()
        [[nodiscard]]
        ssize_t Find(GenericString const& value) const noexcept;

        /// @brief 最初の文字を取得
        /// @throws InvalidOperationException: Length()がゼロの時
        [[nodiscard]] TChar& Front();
        [[nodiscard]] TChar const& Front() const;

        /// @brief 最初の文字を取得
        [[nodiscard]] constexpr TChar& FrontUnsafe() noexcept { return *_p; }
        [[nodiscard]] constexpr TChar const& FrontUnsafe() const noexcept { return *_p; }

        /// @brief 文字列が空であるかを確認
        [[nodiscard]]
        constexpr bool IsEmpty() const noexcept { return _length == 0; }

        /// @brief 文字列の長さを取得
        [[nodiscard]]
        constexpr ssize_t Length() const noexcept { return _length; }

        /// @brief ふぁ！？っく
        GenericString Replace(std::nullptr_t, std::nullptr_t) const = delete;
        /// @brief ふぁ！？っく
        GenericString Replace(TChar, std::nullptr_t) const = delete;
        /// @brief ふぁ！？っく
        GenericString Replace(std::nullptr_t, TChar) const = delete;

        /// @brief 文字列の一部を置き換えたものを取得
        /// @param oldValue 置き換え対象
        /// @param newValue 置き換え後の文字列
        /// @return oldValueがnewValueに置き換えられた文字列
        [[nodiscard]] GenericString Replace(GenericStringView<TChar> const& oldValue, GenericStringView<TChar> const& newValue) const;
        [[nodiscard]] GenericString Replace(GenericStringView<TChar> const& oldValue, TChar newValue) const;
        [[nodiscard]] GenericString Replace(TChar oldValue, GenericStringView<TChar> const& newValue) const;
        [[nodiscard]] GenericString Replace(TChar oldValue, TChar newValue) const;

        /// @brief 最後の文字を削除
        /// @throws InvalidOperationException: Length()がゼロの時
        void RemoveBack();

        /// @brief 最後の文字を削除
        constexpr void RemoveBackUnsafe() noexcept { _length--; _setEndNull(); }

        /// @brief 文字列の長さを変更
        /// @param newLength 長さ
        /// @throws InvalidArgumentException: newLengthが負の値のとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void Resize(ssize_t newLength);

        /// @brief 文字列の長さを変更
        /// @param newLength 長さ
        /// @param c 変更後に新たに作成された文字の初期値
        /// @throws InvalidArgumentException: newLengthが負の値のとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void Resize(ssize_t newLength, TChar c);

        /// @brief 文字列の長さを変更
        /// @param newLength 長さ
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void ResizeUnsafe(ssize_t newLength);

        /// @brief 文字列の長さを変更
        /// @param newLength 長さ
        /// @param c 変更後に新たに作成された文字の初期値
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void ResizeUnsafe(ssize_t newLength, TChar c);

        /// @brief 容量を変更
        /// @attention Length()よりも小さい値を指定すると文字列が切り捨てられるよ！
        /// @param capacity 容量
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void SetCapacityUnsafe(ssize_t capacity);

        /// @brief Capacity()を最適化
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void ShrinkToFit();

        /// @brief ふぁ！？っく
        Collections::IArray<GenericString> Split(std::nullptr_t) const = delete;

        /// @brief 文字列を分割
        /// @param del 区切り文字
        /// @return 分割された文字列ベクトル
        [[nodiscard]]
        Collections::IArray<GenericString> Split(TChar del) const;

        /// @brief 文字列を分割
        /// @param del 区切り文字列
        /// @return 分割された文字列ベクトル
        /// @throws ArgumentNullException: delがnullptrのとき
        [[nodiscard]]
        Collections::IArray<GenericString> Split(const TChar* del) const;

        /// @brief 文字列を分割
        /// @param del 区切り文字列
        /// @return 分割された文字列ベクトル
        /// @throws ArgumentNullException: delがnullptrのとき
        [[nodiscard]]
        Collections::IArray<GenericString> Split(GenericStringView<TChar> const& del) const;

        /// @brief 文字列を分割
        /// @param del 区切り文字列
        /// @return 分割された文字列ベクトル
        [[nodiscard]]
        Collections::IArray<GenericString> Split(GenericString const& del) const;

        /// @brief ふぁ！？っく
        bool StartsWith(std::nullptr_t) const = delete;

        /// @brief 指定したプレフィックスで文字列が始まるかを確認
        /// @param c 文字
        [[nodiscard]]
        constexpr bool StartsWith(TChar c) const noexcept { if (_length == 0) [[unlikely]] return false; return *_p == c; }

        /// @brief 指定したプレフィックスで文字列が始まるかを確認
        /// @param p 文字列
        /// @throws ArgumentNullException: pがnullptrのとき
        [[nodiscard]]
        bool StartsWith(const TChar* p) const;

        /// @brief 指定したプレフィックスで文字列が始まるかを確認
        /// @param view 文字列
        [[nodiscard]]
        bool StartsWith(GenericStringView<TChar> const& view) const noexcept;

        /// @brief 指定したプレフィックスで文字列が始まるかを確認
        /// @param value 文字列
        [[nodiscard]]
        bool StartsWith(GenericString const& value) const noexcept;

        /// @brief 部分文字列を取得
        /// @param count 最大文字数
        /// @param isFited Capacity()をLength() + 1と一致させるか
        /// @throws InvalidArgumentException: countがゼロ以下の時
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        [[nodiscard]]
		GenericString SubString(ssize_t count, bool isFited = false) const;

        /// @brief 部分文字列を取得
        /// @param offset 開始位置
        /// @param count 最大文字数
        /// @param isFited Capacity()をLength() + 1と一致させるか
        /// @throws InvalidArgumentException: offsetが範囲外の時、countがゼロ以下の時
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        [[nodiscard]]
        GenericString SubString(ssize_t offset, ssize_t count, bool isFited = false) const;

        /// @brief 部分文字列を取得
        /// @param count 最大文字数
        /// @param isFited Capacity()をLength() + 1と一致させるか
        /// @throws InvalidArgumentException: countがゼロ以下の時
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        [[nodiscard]]
		GenericString SubStringUnsafe(ssize_t count, bool isFited = false) const;

        /// @brief 部分文字列を取得
        /// @param offset 開始位置
        /// @param count 最大文字数
        /// @param isFited Capacity()をLength() + 1と一致させるか
        /// @throws InvalidArgumentException: offsetが範囲外の時、countがゼロ以下の時
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        [[nodiscard]]
        GenericString SubStringUnsafe(ssize_t offset, ssize_t count, bool isFited = false) const;

        /// @brief アスキー文字列に変換
        /// @attention アスキーコードに含まれない文字が含まれていても例外は投げないよ
        [[nodiscard]]
        CharString ToAscii() const;

        /// @brief 文字列をTChar配列に変換
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        Collections::Array<TChar> ToCharArray() const;

        /// @brief 全ての英大文字を小文字に変換した文字列を取得
        [[nodiscard]]
        GenericString ToLower() const;

        /// @brief 全ての英小文字を大文字に変換した文字列を取得
        [[nodiscard]]
        GenericString ToUpper() const;

        /// @brief CharStringに変換
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        CharString ToCharString() const;

        /// @brief Stringに変換
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:

        static constexpr ssize_t _defaultCapacity = 16;

        static constexpr ssize_t _createCapacity(ssize_t length) noexcept { return (((length + 1) / _defaultCapacity) + 1) * _defaultCapacity; }

        template <class TInt>
        static GenericString _valueOfInteger(TInt value);

        constexpr GenericString(int) noexcept : _p(nullptr), _length(0), _capacity(0) {}
        constexpr GenericString(TChar* p, ssize_t capacity, ssize_t length, int) noexcept : _p(p), _length(length), _capacity(capacity) {}

        GenericString(std::string_view const& right) requires std::same_as<TChar, char16_t>;

        /// @brief Capacity()が足りないときにCapacity() += _defaultCapacity
        /// @param size 増やす要素数
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void _increaseCapacity(ssize_t size);

        constexpr void _setEndNull() noexcept { _p[_length] = (TChar)'\0'; }

        Collections::IArray<GenericString> _splitUnsafe(GenericStringView<TChar> const& del) const;

        //
        ssize_t _capacity;
        ssize_t _length;
        TChar* _p;

        friend GenericStringView<TChar>;
        //ふぁ！？っく
        friend Exception;
        //ふぁ！？っく
        friend MemoryAllocationException;
    };

    /// @brief ふぁ！？っく
    bool operator==(String const&, std::nullptr_t) = delete;
    /// @brief ふぁ！？っく
    bool operator!=(std::nullptr_t, String const&) = delete;

    //等値判定
    template <class TChar> requires CharType<TChar>
    [[nodiscard]] bool operator==(GenericString<TChar> const& left, GenericString<TChar> const& right) noexcept;

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] bool operator!=(GenericString<TChar> const& left, GenericString<TChar> const& right) noexcept;

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] bool operator<(GenericString<TChar> const& left, GenericString<TChar> const& right) noexcept;

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] bool operator<=(GenericString<TChar> const& left, GenericString<TChar> const& right) noexcept;

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] bool operator>(GenericString<TChar> const& left, GenericString<TChar> const& right) noexcept;

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] bool operator>=(GenericString<TChar> const& left, GenericString<TChar> const& right) noexcept;

    /// @brief ふぁ！？っく
    template <class TChar> requires CharType<TChar>
    GenericString<TChar> operator+(GenericString<TChar> const&, std::nullptr_t) = delete;

    /// @brief ふぁ！？っく
    template <class TChar> requires CharType<TChar>
    GenericString<TChar> operator+(std::nullptr_t, GenericString<TChar> const&) = delete;

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] GenericString<TChar> operator+(GenericString<TChar> const& left, GenericString<TChar> const& right);

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] GenericString<TChar> operator+(GenericString<TChar>&& left, GenericString<TChar> const& right);

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] GenericString<TChar> operator+(GenericString<TChar> const& left, GenericString<TChar>&& right);

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] GenericString<TChar> operator+(GenericString<TChar>&& left, GenericString<TChar>&& right);

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] GenericString<TChar> operator+(GenericString<TChar> const& left, const TChar* right);

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] GenericString<TChar> operator+(GenericString<TChar>&& left, const TChar* right);

    template <class TChar> requires CharType<TChar>
    [[nodiscard]] GenericString<TChar> operator+(const TChar* left, GenericString<TChar> const& right);

    [[nodiscard]] String operator+(String const& left, Object const& right);
    [[nodiscard]] String operator+(String&& left, Object const& right);
    [[nodiscard]] String operator+(Object const& left, String const& right);
    [[nodiscard]] String operator+(String const& left, IMPLEMENTATION::Object const& right);
    [[nodiscard]] String operator+(String&& left, IMPLEMENTATION::Object const& right);
    [[nodiscard]] String operator+(IMPLEMENTATION::Object const& left, String const& right);

    template <KongkongValueType TValue> requires ((std::same_as<TValue, String> == false) && (std::same_as<TValue, StringView> == false))
    [[nodiscard]] String operator+(String const& left, TValue const& right);

    template <KongkongValueType TValue> requires ((std::same_as<TValue, String> == false) && (std::same_as<TValue, StringView> == false))
    [[nodiscard]] String operator+(String&& left, TValue const& right);

    template <KongkongValueType TValue> requires ((std::same_as<TValue, String> == false) && (std::same_as<TValue, StringView> == false))
    [[nodiscard]] String operator+(TValue const& left, String const& right);
}

namespace KONGKONG_NAMESPACE
{
    template <class TChar> requires CharType<TChar>
    template <ssize_t N>
    GenericString<TChar> GenericString<TChar>::FromLiteral(const TChar(&arr)[N])
    {
        TChar* p = AllocMemoryUnsafe(N);

        ::memcpy(p, arr, N * ElementSize());
        
        return GenericString<TChar>(p, N, N - 1, 0);
    }

    template <KongkongValueType TValue> requires ((std::same_as<TValue, String> == false) && (std::same_as<TValue, StringView> == false))
    String operator+(String const& left, TValue const& right)
    {

        String str = left;
        str.Append(right.ToString());

        return str;
    }

    template <KongkongValueType TValue> requires ((std::same_as<TValue, String> == false) && (std::same_as<TValue, StringView> == false))
    String operator+(String&& left, TValue const& right)
    {

        left.Append(right.ToString());

        return left;
    }

    template <KongkongValueType TValue> requires ((std::same_as<TValue, String> == false) && (std::same_as<TValue, StringView> == false))
    String operator+(TValue const& left, String const& right)
    {
        String str = left.ToString();
        str.Append(right);

        return str;
    }
}

#endif //!KONGKONG_STRING_H
