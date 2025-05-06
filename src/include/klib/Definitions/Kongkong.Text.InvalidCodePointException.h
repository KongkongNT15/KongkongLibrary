#ifndef KONGKONG_TEXT_INVALIDCODEPOINTEXCEPTION_H
#define KONGKONG_TEXT_INVALIDCODEPOINTEXCEPTION_H

#include "Base.h"
#include "Kongkong.Exception.h"

namespace KONGKONG_NAMESPACE::Text
{
    /// @brief 無効なコードポイントが見つかった時にスローされる例外
    struct InvalidCodePointException : public Exception {
        using Exception::Exception;

        InvalidCodePointException();
    };
}

#endif //!KONGKONG_TEXT_INVALIDCODEPOINTEXCEPTION_H