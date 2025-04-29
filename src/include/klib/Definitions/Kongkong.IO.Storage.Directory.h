#ifndef KONGKONG_IO_STORAGE_DIRECTORY_H
#define KONGKONG_IO_STORAGE_DIRECTORY_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::IO::Storage
{
    //フォルダ管理
    class Directory final {
        public:

        STATIC_CLASS(Directory)

        static void Create(const char16_t* path);
        static void Create(String const& path);
        static void Create(const char* path);

        //フォルダーを削除
        KONGKONG_INCOMPLETED_FUNCTION
        static void Delete(String const& path, bool recursive);
        KONGKONG_INCOMPLETED_FUNCTION
        static void Delete(const char* path, bool recursive);

        //指定したフォルダーが存在するか
        static bool Exists(const char16_t* path);
        static bool Exists(String const& path);
        static bool Exists(const char* path);

#ifdef KONGKONG_OBJECTIVE_C_ENABLED
        static bool Exists(AppleDevice::Foundation::NSString const& path);
#endif //KONGKONG_OBJECTIVE_C_ENABLED
        //指定したパスのサブディレクトリを取得
        static Collections::IArray<String> GetDirectories(String const& path);

    };
}

#endif //!KONGKONG_IO_STORAGE_DIRECTORY_H
