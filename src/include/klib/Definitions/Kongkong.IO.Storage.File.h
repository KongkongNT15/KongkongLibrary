#ifndef KONGKONG_IO_STORAGE_FILE_H
#define KONGKONG_IO_STORAGE_FILE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::IO::Storage
{
    //ファイル管理
    class File final {
        public:

        STATIC_CLASS(File)

        /// @brief ふぁ！？っく
        static void Delete(std::nullptr_t) = delete;

        //ファイルを削除
        static void Delete(String const& path);
        static void Delete(const char16_t* path);
        static void Delete(const char* path);

        /// @brief ふぁ！？っく
        static bool Exists(std::nullptr_t) = delete;

        //指定したファイルが存在するか
        static bool Exists(const char16_t* path);
        static bool Exists(String const& path);
        static bool Exists(const char* path);
#ifdef KONGKONG_OBJECTIVE_C_ENABLED
        static bool Exists(AppleDevice::Foundation::NSString const& path);
#endif

    };
}

#endif //!KONGKONG_IO_STORAGE_FILE_H
