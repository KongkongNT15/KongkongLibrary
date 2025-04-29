#ifndef KONGKONG_MEMORY_MEMORYBLOCK_H
#define KONGKONG_MEMORY_MEMORYBLOCK_H

#include "Base.h"
#include "Kongkong.Object.h"

namespace KONGKONG_NAMESPACE::Memory::IMPLEMENTATION
{
    struct MemoryBlock final : public ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object {

        constexpr MemoryBlock() noexcept : _p(nullptr), _size(0) {}
        MemoryBlock(ssize_t size);
        MemoryBlock(MemoryBlock const& right);
        constexpr MemoryBlock(MemoryBlock&& right) noexcept : _p(right._p), _size(right._size) { right._p = nullptr; right._size = 0; }

        ~MemoryBlock();

        MemoryBlock& operator=(MemoryBlock const& right);
        MemoryBlock& operator=(MemoryBlock&& right);

        /// @brief 新たにメモリを割り当て
        /// @attention 前に割り当てていた領域を解放してから割り当ててね！
        /// @param size 割り当てるサイズ
        /// @throws InvalidArgumentException: sizeがゼロ以下のとき
        /// @throws MemoryAllocationException: メモリの割り当てに失敗したとき
        void Alloc(ssize_t size);

        /// @brief 新たにメモリを割り当て
        /// @attention 前に割り当てていた領域を解放してから割り当ててね！
        /// @param size 割り当てるサイズ
        /// @throws MemoryAllocationException: メモリの割り当てに失敗したとき
        void AllocUnsafe(ssize_t size);

        /// @brief 指定した位置の値を指定した型として取得
        /// @tparam T 型
        /// @param index 位置
        /// @throws InvalidArgumentException: 範囲外の位置を指定したとき
        template <class T>
        [[nodiscard]] T& At(ssize_t index);

        /// @brief 指定した位置の値を指定した型として取得
        /// @tparam T 型
        /// @param index 位置
        /// @throws InvalidArgumentException: 範囲外の位置を指定したとき
        template <class T>
        [[nodiscard]] T const& At(ssize_t index) const;

        /// @brief 指定した位置の値を指定した型として取得
        /// @tparam T 型
        /// @param index 位置
        template <class T>
        [[nodiscard]] T& AtUnsafe(ssize_t index) noexcept;

        /// @brief 指定した位置の値を指定した型として取得
        /// @tparam T 型
        /// @param index 位置
        template <class T>
        [[nodiscard]] T const& AtUnsafe(ssize_t index) const noexcept;

        /// @brief 指定した位置に指定した型のコンストラクタを実行
        /// @tparam T 型
        /// @param index 位置
        /// @throws NullPointerException: このインスタンスがnullptrのとき、MemoryBlockにメモリを割り当てていないとき
        template <class T> requires std::default_initializable<T>
        void Construct(ssize_t index);

        /// @brief 指定した位置に指定した型のコンストラクタを実行
        /// @tparam T 型
        /// @param index 位置
        template <class T> requires std::default_initializable<T>
        void ConstructUnsafe(ssize_t index);

        /// @brief 割り当てているメモリ領域を取得
        /// @attention メモリを割り当てていない場合はnullptrになるよ！
        [[nodiscard]] constexpr void* Data() noexcept { return _p; }
        [[nodiscard]] constexpr const void* Data() const noexcept { return _p; }

        /// @brief 割り当てているメモリ領域の指定した位置を取得
        /// @attention メモリを割り当てていない場合でも例外は発生しないよ！
        /// @attention indexが範囲外でも例外は発生しないよ
        /// @param index 位置
        [[nodiscard]] constexpr void* Data(ssize_t index) noexcept { return _p + index; }
        [[nodiscard]] constexpr const void* Data(ssize_t index) const noexcept { return _p + index; }

        /// @brief 指定した位置に指定した型のデストラクタを実行
        /// @tparam T 型
        /// @param index 位置
        /// @throws InvalidArgumentException: 範囲外の位置を指定したとき
        /// @throws NullPointerException: MemoryBlockにメモリを割り当てていないとき
        template <class T>
        void Destroy(ssize_t index);

        /// @brief 指定した位置に指定した型のデストラクタを実行
        /// @tparam T 型
        /// @param index 位置
        template <class T>
        void DestroyUnsafe(ssize_t index) noexcept;

        /// @brief 割り当てられているメモリ領域を指定した値で埋める
        /// @attention MemoryBlockにメモリが割り当てられていない場合はなにもしないよ！
        /// @param value 値
        void Fill(uint8_t value) noexcept;

        /// @brief メモリを解放
        /// @attention メモリが割り当てられていない場合はなにもしないよ！
        void Free() noexcept;

        /// @brief メモリ領域が割り当てられているか
        [[nodiscard]]
        constexpr bool HasMemoryBlock() const noexcept { return _p != nullptr; }

        /// @brief 領域サイズを変更
        /// @param size 変更後のサイズ
        /// @throws InvalidArgumentException: sizeがゼロ以下のとき
        /// @throws NullPointerException: MemoryBlockにメモリを割り当てていないとき
        void Realloc(ssize_t size);

        /// @brief 領域サイズを変更
        /// @param size 変更後のサイズ
        void ReallocUnsafe(ssize_t size);

        [[nodiscard]]
        String ToString() const override;

        /// @brief 割り当てられているメモリ領域のサイズ
        [[nodiscard]]
        constexpr ssize_t Size() const noexcept { return _size; }

        private:
        
        uint8_t* _p;
        ssize_t _size;

        void _checkIndex(ssize_t index) const;
        void _checkPointer() const;
        void _checkSize(ssize_t size) const;

    };
}

namespace KONGKONG_NAMESPACE::Memory
{
    /// @brief メモリブロック
    class MemoryBlock final : public Object {
        public:
        using ImplType = IMPLEMENTATION::MemoryBlock;

        /// @brief メモリブロックを割り当てずに作成
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        MemoryBlock();
        /// @brief メモリブロックのサイズを指定して作成
        /// @param size 割り当てるサイズ
        /// @throws InvalidArgumentException: sizeがゼロ以下のとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        MemoryBlock(ssize_t size);

        /// @brief nullptrとして作成
        constexpr MemoryBlock(std::nullptr_t) noexcept : Object(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
}

namespace KONGKONG_NAMESPACE::Memory::IMPLEMENTATION
{
    template <class T>
    T& MemoryBlock::At(ssize_t index)
    {
        _checkPointer();
        _checkIndex(index);
        
        return AtUnsafe<T>(index);
    }

    template <class T>
    T const& MemoryBlock::At(ssize_t index) const
    {
        _checkPointer();
        _checkIndex(index);

        return AtUnsafe<T>(index);
    }

    template <class T>
    T& MemoryBlock::AtUnsafe(ssize_t index) noexcept
    {
        void* p = _p + index;
        T* pT = (T*)p;

        return *pT;
    }

    template <class T>
    T const& MemoryBlock::AtUnsafe(ssize_t index) const noexcept
    {
        const void* p = _p + index;
        const T* pT = (const T*)p;

        return *pT;
    }

    template <class T> requires std::default_initializable<T>
    void MemoryBlock::Construct(ssize_t index)
    {
        _checkPointer();
        _checkIndex(index);
        ConstructUnsafe<T>(index);
    }

    template <class T> requires std::default_initializable<T>
    void MemoryBlock::ConstructUnsafe(ssize_t index)
    {
        void* p = _p + index;

        new(p) T();
    }

    template <class T>
    void MemoryBlock::Destroy(ssize_t index)
    {
        _checkPointer();
        _checkIndex(index);
        DestroyUnsafe<T>(index);
    }

    template <class T>
    void MemoryBlock::DestroyUnsafe(ssize_t index) noexcept
    {
        void* p = _p + index;
        T* tp = (T*)p;

        tp->~T();
    }
}

#endif //!KONGKONG_MEMORY_MEMORYBLOCK_H
