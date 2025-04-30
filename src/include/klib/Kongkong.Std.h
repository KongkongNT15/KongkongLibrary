#ifndef KONGKONG_STD_H
#define KONGKONG_STD_H

#include "Definitions/Base.h"

#include "Definitions/Kongkong.Std.GenericOutStringStream.h"
#include "Definitions/Kongkong.Std.GenericStringBuffer.h"
#include "Definitions/Kongkong.Std.StdString.h"
#include "Definitions/Kongkong.Std.StlThreadPool.h"

#ifdef __POSIX__
    #include "Definitions/Kongkong.Std.PosixFileIOBuffer.h"
    #include "Definitions/Kongkong.Std.PosixIOBuffer.h"

#endif //__POSIX__

#endif //!KONGKONG_STD_H
