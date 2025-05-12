#ifndef KONGKONG_IO_STORAGE_DIRECTORYNOTFOUNDEXCEPTION_H
#define KONGKONG_IO_STORAGE_DIRECTORYNOTFOUNDEXCEPTION_H

#include "Base.h"
#include "Kongkong.IO.Storage.PathNotFoundException.h"

namespace KONGKONG_NAMESPACE::IO::Storage
{
    struct DirectoryNotFoundException : public PathNotFoundException {
        using PathNotFoundException::PathNotFoundException;
    };
}

#endif //!KONGKONG_IO_STORAGE_DIRECTORYNOTFOUNDEXCEPTION_H
