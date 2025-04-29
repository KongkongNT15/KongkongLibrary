#ifndef KONGKONG_DEVIDEDBYZEROEXCEPTION_H
#define KONGKONG_DEVIDEDBYZEROEXCEPTION_H

#include "Base.h"
#include "Kongkong.Exception.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief 0で割ろうとした結果
    struct DivideByZeroException : public Exception {
        /// @brief デフォルトメッセージで作成
        DivideByZeroException();

        using Exception::Exception;
    };
    
}

#endif //!KONGKONG_DEVIDEDBYZEROEXCEPTION_H
