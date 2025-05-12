#ifndef KONGKONG_INVALIDOPERATIONEXCEPTION_H
#define KONGKONG_INVALIDOPERATIONEXCEPTION_H

#include "Base.h"
#include "Kongkong.Exception.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief 不正な操作
    struct InvalidOperationException : public Exception {

        /// @brief 長さがゼロでないかを判定
        /// @param length 長さ
        /// @throw InvalidOperationException: lengthがゼロのとき
        static void CheckZeroLength(ssize_t length);

        using Exception::Exception;
    };

}

#endif //!KONGKONG_INVALIDOPERATIONEXCEPTION_H
