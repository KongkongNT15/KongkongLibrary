#ifndef KONGKONG_IOEXCEPTION_H
#define KONGKONG_IOEXCEPTION_H

#include "Base.h"
#include "Kongkong.Exception.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief 入出力エラー
    struct IOException : public Exception {
        using Exception::Exception;
    };

}

#endif //!KONGKONG_IOEXCEPTION_H
