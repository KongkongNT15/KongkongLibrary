#ifndef KONGKONG_CSTD_CMEMORYMANAGER_H
#define KONGKONG_CSTD_CMEMORYMANAGER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::CStd
{
    /// @brief C標準のメモリ操作API
    class CMemoryManager final {
        public:

        STATIC_CLASS(CMemoryManager)

        /// @brief メモリブロックを確保 確保に失敗した場合はCStdExceptionをスロー
        /// @param length 確保するバイト数
        /// @return 確保したメモリブロック
        /// @throws CStdException: メモリの確保に失敗したとき
        static void* AllocMemory(size_t length);

        /// @brief ふぁ！？っく
        static void FreeMemory(std::nullptr_t) = delete;

        /// @brief 確保したメモリブロックを開放
        /// @param p 開放するメモリブロック
        static void FreeMemory(void* p) noexcept;

        /// @brief ふぁ！？っく
        static void* ReallocMemory(size_t, std::nullptr_t) = delete;

        /// @brief メモリブロックの長さを変更
        /// @attention メモリの確保に失敗した場合は元のメモリブロックを解放しない
        /// @param newLength 変更後の長さ
        /// @param p 対象のメモリブロック
        /// @return 変更後のメモリブロック
        /// @throws CStdException: メモリの確保に失敗したとき
        static void* ReallocMemory(size_t newLength, void* p);
    };
}

#endif //!KONGKONG_CSTD_CMEMORYMANAGER_H
