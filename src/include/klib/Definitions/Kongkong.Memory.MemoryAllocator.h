#ifndef KONGKONG_MEMORY_MEMORYALLOCATOR_H
#define KONGKONG_MEMORY_MEMORYALLOCATOR_H

#include "Base.h"

#include <new>

namespace KONGKONG_NAMESPACE::Memory
{
    /// @brief メモリの割り当てと解放
    class MemoryAllocator final {
        public:
        STATIC_CLASS(MemoryAllocator)

        /// @brief メモリを確保
        /// @tparam T 要素型
        /// @param elementCount 要素数
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        template <class T>
        [[nodiscard]] static T* AllocMemory(ssize_t elementCount);

        /// @brief メモリを確保し、すべての要素を指定した値で埋めます
        /// @tparam T 要素型
        /// @param elementCount 要素数
        /// @param defaultValue コピー元の値
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        template <class T>
        [[nodiscard]] static T* AllocMemory(ssize_t elementCount, T const& defaultValue);

        /// @brief メモリを確保
        /// @tparam T 要素型
        /// @param elementCount 要素数
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        template <class T>
        [[nodiscard]] static T* AllocMemoryUnsafe(ssize_t elementCount);

        /// @brief メモリを確保し、すべての要素を指定した値で埋めます
        /// @tparam T 要素型
        /// @param elementCount 要素数
        /// @param defaultValue コピー元の値
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        template <class T>
        [[nodiscard]] static T* AllocMemoryUnsafe(ssize_t elementCount, T const& defaultValue);

        /// @brief ふぁ！？っく
        static void FreeMemory(std::nullptr_t) = delete;

        /// @brief MemoryAllocatorで確保したメモリを解放
        /// @attention 要素のデストラクタは実行しないよ！
        /// @param p 開放するメモリブロック
        /// @throws ArgumentNullException: pがnullptrのとき
        static void FreeMemory(void* p);

        /// @brief ふぁ！？っく
        static void FreeMemoryUnsafe(std::nullptr_t) = delete;

        /// @brief MemoryAllocatorで確保したメモリを解放
        /// @attention 要素のデストラクタは実行しないよ！
        /// @param p 開放するメモリブロック
        static void FreeMemoryUnsafe(void* p) noexcept;

        template <class T>
        static T* ReallocMemory(ssize_t, std::nullptr_t) = delete;

        /// @brief メモリブロックの長さを変更
        /// @attention 要素のムーブコンストラクタとでデストラクタは実行しないよ！
        /// @tparam T 要素型
        /// @param newElementCount 変更後の要素数
        /// @param p ターゲットのメモリブロック
        /// @throws ArgumentNullException: pがnullptrのとき
        /// @throws InvalidArgumentException: newElementCountがゼロ以下のとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        template <class T>
        [[nodiscard]] static T* ReallocMemory(ssize_t newElementCount, T* p);

        template <class T>
        static T* ReallocMemoryUnsafe(ssize_t, std::nullptr_t) = delete;

        /// @brief メモリブロックの長さを変更
        /// @attention 要素のムーブコンストラクタとでデストラクタは実行しないよ！
        /// @tparam T 要素型
        /// @param newElementCount 変更後の要素数
        /// @param p ターゲットのメモリブロック
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        template <class T>
        [[nodiscard]] static T* ReallocMemoryUnsafe(ssize_t newElementCount, T* p);

        private:
        /// @brief メモリを確保
        /// @param length 確保する長さ
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        static void* _allocMemory(ssize_t length);

        /// @brief メモリを確保
        /// @param length 確保する長さ
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        static void* _allocMemoryUnsafe(ssize_t length);

        /// @brief 長さが適切かどうかを確認
        /// @param length 長さ
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        static void _checkLength(ssize_t length);

        /// @brief メモリブロックの長さを変更
        /// @param newLength 変更後の長さ
        /// @param p 元のメモリブロック
        /// @throws ArgumentNullException: pがnullptrのとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        static void* _reallocMemory(ssize_t newLength, void* p);

        /// @brief メモリブロックの長さを変更
        /// @param newLength 変更後の長さ
        /// @param p 元のメモリブロック
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        static void* _reallocMemoryUnsafe(ssize_t newLength, void* p);
    };
}

namespace KONGKONG_NAMESPACE::Memory
{
    template <class T>
    T* MemoryAllocator::AllocMemory(ssize_t elementCount)
    {
        _checkLength(elementCount);

        return (T*)_allocMemoryUnsafe(elementCount * sizeof(T));
    }

    template <class T>
    T* MemoryAllocator::AllocMemory(ssize_t elementCount, T const& defaultValue)
    {
        _checkLength(elementCount);

        return AllocMemoryUnsafe<T>(elementCount, defaultValue);
    }

    template <class T>
    T* MemoryAllocator::AllocMemoryUnsafe(ssize_t elementCount)
    {
        return (T*)_allocMemoryUnsafe(elementCount * sizeof(T));
    }

    template <class T>
    T* MemoryAllocator::AllocMemoryUnsafe(ssize_t elementCount, T const& defaultValue)
    {
        T* p = (T*)_allocMemoryUnsafe(elementCount * sizeof(T));

        T* itr = p;
        T* end = itr + elementCount;

        try {
            while (itr != end) {

                new(itr) T(defaultValue);

                itr++;
            }
        }
        catch (...) {
            T* tmp = p;

            while (tmp != itr) {
                tmp->~T();
                tmp++;
            }

            FreeMemoryUnsafe(p);

            ::std::rethrow_exception(::std::current_exception());
        }

        return p;
    }

    template <class T>
    T* MemoryAllocator::ReallocMemory(ssize_t newElementCount, T* p)
    {
        return (T*)_reallocMemory(newElementCount * sizeof(T), p);
    }

    template <class T>
    T* MemoryAllocator::ReallocMemoryUnsafe(ssize_t newElementCount, T* p)
    {
        return (T*)_reallocMemoryUnsafe(newElementCount * sizeof(T), p);
    }

}

#endif //!KONGKONG_MEMORY_MEMORYALLOCATOR_H
