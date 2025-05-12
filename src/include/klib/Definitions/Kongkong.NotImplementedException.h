#ifndef KONGKONG_NOTIMPLEMENTEDEXCEPTION_H
#define KONGKONG_NOTIMPLEMENTEDEXCEPTION_H

#include "Base.h"
#include "Kongkong.Exception.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief 関数が実装されていない例外
    struct NotImplementedException : public Exception {
        /// @brief デフォルトのメッセージで作成
        NotImplementedException();

        using Exception::Exception;
    };
    
}

#endif //!KONGKONG_NOTIMPLEMENTEDEXCEPTION_H
