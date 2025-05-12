#ifndef KONGKONG_WIN32_IO_FILEATTRIBUTE_H
#define KONGKONG_WIN32_IO_FILEATTRIBUTE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::IO
{
    enum struct FileAttribute {
        ReadOnly           = FILE_ATTRIBUTE_READONLY,
        Hidden             = FILE_ATTRIBUTE_HIDDEN,
        System             = FILE_ATTRIBUTE_SYSTEM,
        Directory          = FILE_ATTRIBUTE_DIRECTORY,
        Archive            = FILE_ATTRIBUTE_ARCHIVE,
        Device             = FILE_ATTRIBUTE_DEVICE,
        Normal             = FILE_ATTRIBUTE_NORMAL,
        Temporary          = FILE_ATTRIBUTE_TEMPORARY,
        SparseFile         = FILE_ATTRIBUTE_SPARSE_FILE,
        ReparsePoint       = FILE_ATTRIBUTE_REPARSE_POINT,
        Compressed         = FILE_ATTRIBUTE_COMPRESSED,
        Offline            = FILE_ATTRIBUTE_OFFLINE,
        NotContentIndexed  = FILE_ATTRIBUTE_NOT_CONTENT_INDEXED,
        Encrypted          = FILE_ATTRIBUTE_ENCRYPTED,
        IntegrityStream    = FILE_ATTRIBUTE_INTEGRITY_STREAM,
        Virtual            = FILE_ATTRIBUTE_VIRTUAL,
        NoScrubData        = FILE_ATTRIBUTE_NO_SCRUB_DATA,
        EA                 = FILE_ATTRIBUTE_EA,
        Pinned             = FILE_ATTRIBUTE_PINNED,
        Unpinned           = FILE_ATTRIBUTE_UNPINNED,
        RecallOnOpen       = FILE_ATTRIBUTE_RECALL_ON_OPEN,
        RecallOnDataAccess = FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS,

        File
    };

    CREATE_OPERATOR_AND_OR(FileAttribute)
}

#endif //!KONGKONG_WIN32_IO_FILEATTRIBUTE_H
