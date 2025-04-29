#ifndef KONGKONG_WIN32_PRIMITIVES_WINBASE_H
#define KONGKONG_WIN32_PRIMITIVES_WINBASE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    //<WinBase.h>
    class WinBase final {
        public:

        STATIC_CLASS(WinBase)

        static void CopyFile(const char16_t* originalFilePath, const char16_t* newFilePath, bool failIfFileExists);
        static void CopyFile(const char16_t* originalFilePath, String const& newFilePath, bool failIfFileExists);
        static void CopyFile(String const& originalFilePath, const char16_t* newFilePath, bool failIfFileExists);
        static void CopyFile(String const& originalFilePath, String const& newFilePath, bool failIfFileExists);
    };
}

#endif //!KONGKONG_WIN32_PRIMITIVES_WINBASE_H
