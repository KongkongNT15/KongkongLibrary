#ifndef KONGKONG_IO_STORAGE_PATH_H
#define KONGKONG_IO_STORAGE_PATH_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::IO::Storage
{
    //
    class Path final {
        public:

        STATIC_CLASS(Path)

        //OS固有のパスの区切り文字
        static constexpr char16_t DirectorySeparatorChar() noexcept
        {
#ifdef KONGKONG_ENV_WINDOWS
            return u'\\';
#elif defined(KONGKONG_ENV_UNIX)
            return u'/';
#endif
        }

        //指定したパスが存在するか
        static bool Exists(const char16_t* path);
        static bool Exists(String const& path);
        static bool Exists(const char* path);
#ifdef KONGKONG_OBJECTIVE_C_ENABLED
        static bool Exists(AppleDevice::Foundation::NSString const& path);
#endif
    };
}

#endif //!KONGKONG_IO_STORAGE_PATH_H
