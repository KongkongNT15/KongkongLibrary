#ifndef KONGKONG_INVALIDCASTEXCEPTION_H
#define KONGKONG_INVALIDCASTEXCEPTION_H

#include "Base.h"
#include "Kongkong.Exception.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief 不正なキャスト
    struct InvalidCastException : public Exception {
        /// @brief デフォルトメッセージで作成
        InvalidCastException();

        using Exception::Exception;
    };

}

#endif //!KONGKONG_INVALIDCASTEXCEPTION_H
