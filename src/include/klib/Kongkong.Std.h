#ifndef KONGKONG_STD_H
#define KONGKONG_STD_H

#include "Definitions/Base.h"

#include "Definitions/Kongkong.Std.GenericOutStringStream.h"
#include "Definitions/Kongkong.Std.GenericStringBuffer.h"
#include "Definitions/Kongkong.Std.StdString.h"
#include "Definitions/Kongkong.Std.StlThreadPool.h"

#if KONGKONG_ENV_UNIX
    #include "Definitions/Kongkong.Std.PosixFileIOBuffer.h"
    #include "Definitions/Kongkong.Std.PosixIOBuffer.h"

#endif //KONGKONG_ENV_UNIX

#endif //!KONGKONG_STD_H
