#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_FILESYSTEM_NSFILEMANAGER_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_FILESYSTEM_NSFILEMANAGER_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::FileSystem
{
    struct NSFileManager final : public NSObject {
        static NSFileManager const& DefaultManager();

        static NSString UserName();
        static NSString FullUserName();

        /// @brief nullptrとして作成
        constexpr NSFileManager(std::nullptr_t) noexcept : NSObject(nullptr) {}

        NSString CurrentDirectory() const;
        bool CurrentDirectory(NSString const& path) const;

        bool DirectoryExistsAtPath(NSString const& path) const;

        bool FileExistsAtPath(NSString const& path) const;
        bool PathExists(NSString const& path, bool& isDirectory) const;

        bool PathExists(NSString const& path) const;

        private:

        static NSFileManager _defaultManager;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_FILESYSTEM_NSFILEMANAGER_H
