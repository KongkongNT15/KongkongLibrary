#ifndef KONGKONG_MEMORYALLOCATIONEXCEPTION_H
#define KONGKONG_MEMORYALLOCATIONEXCEPTION_H

#include "Base.h"
#include "Kongkong.MemoryException.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief メモリ確保に失敗したときにスロー
    struct MemoryAllocationException : public MemoryException {
        
        /// @brief ふぁ！？っく
        static void CheckNull(std::nullptr_t) = delete;

        /// @brief ポインターがnullptrでないかを確認する
        /// @param p 対象のポインター
        /// @throws MemoryAllocationException: pがnullptrのとき
        static void CheckNull(const void* p);
        
        /// @brief デフォルトのメッセージで作成
        MemoryAllocationException();

        ~MemoryAllocationException();

        private:
        //ふぁ！？っく
        static char16_t _defaultMessage[14];
    
    };

}

#endif //!KONGKONG_MEMORYALLOCATIONEXCEPTION_H
