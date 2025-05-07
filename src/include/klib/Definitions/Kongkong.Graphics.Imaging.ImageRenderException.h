#ifndef KONGKONG_GRAPHICS_IMAGING_IMAGERENDAREXCEPTION_H
#define KONGKONG_GRAPHICS_IMAGING_IMAGERENDAREXCEPTION_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Graphics::Imaging
{
    struct ImageRenderException : public Exception {
        using Exception::Exception;

        ImageRenderException();
    };
}

#endif //!KONGKONG_GRAPHICS_IMAGING_IMAGERENDAREXCEPTION_H