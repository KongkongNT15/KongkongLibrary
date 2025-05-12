#ifndef KONGKONG_MEMORYEXCEPTION_H
#define KONGKONG_MEMORYEXCEPTION_H

#include "Base.h"
#include "Kongkong.Exception.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief メモリ関連のエラー
    struct MemoryException : public Exception {
        using Exception::Exception;

        
    };
    
}

#endif //!KONGKONG_MEMORYEXCEPTION_H
