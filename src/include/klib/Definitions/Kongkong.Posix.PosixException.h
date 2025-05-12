#ifndef KONGKONG_POSIX_POSIXEXCEPTION_H
#define KONGKONG_POSIX_POSIXEXCEPTION_H

#include "Base.h"
#include "Kongkong.CStd.CStdException.h"

namespace KONGKONG_NAMESPACE::Posix
{
    struct PosixException : public CStd::CStdException {
        using CStdException::CStdException;
    };
}

#endif //!KONGKONG_POSIX_POSIXEXCEPTION_H
