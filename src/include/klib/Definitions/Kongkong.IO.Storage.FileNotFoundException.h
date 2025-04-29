#ifndef KONGKONG_IO_STORAGE_FILENOTFOUNDEXCEPTION_H
#define KONGKONG_IO_STORAGE_FILENOTFOUNDEXCEPTION_H

#include "Base.h"
#include "Definitions/Kongkong.IO.Storage.PathNotFoundException.h"

namespace KONGKONG_NAMESPACE::IO::Storage
{
    struct FileNotFoundException : public PathNotFoundException {
        using PathNotFoundException::PathNotFoundException;
    };
}

#endif //!KONGKONG_IO_STORAGE_FILENOTFOUNDEXCEPTION_H
