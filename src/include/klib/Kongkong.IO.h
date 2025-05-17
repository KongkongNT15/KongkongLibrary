#ifndef KONGKONG_IO_H
#define KONGKONG_IO_H

#include "Definitions/Base.h"

#if KONGKONG_LIBRARY
    #include "Definitions/Kongkong.IO.c_ioHelper.h"
#endif

#include "Definitions/Kongkong.IO.BufferedStream.h"
#include "Definitions/Kongkong.IO.DeviceStream.h"
#include "Definitions/Kongkong.IO.SeekOrigin.h"
#include "Definitions/Kongkong.IO.Stream.h"
#include "Definitions/Kongkong.IO.StreamBuffer.h"

#if KONGKONG_IO_PIPE_SUPPORTED
    #include "Definitions/Kongkong.IO.PipeDirection.h"
    #include "Definitions/Kongkong.IO.PipeStream.h"
#endif //KONGKONG_IO_PIPE_SUPPORTED

#endif //!KONGKONG_IO_H