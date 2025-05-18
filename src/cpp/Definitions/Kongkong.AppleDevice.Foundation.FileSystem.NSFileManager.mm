//このObjective-C++ファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::FileSystem
{
    NSFileManager NSFileManager::_defaultManager = NSFileManager(nullptr);

    NSFileManager const& NSFileManager::DefaultManager()
    {
        if (_defaultManager == nullptr) {
            _defaultManager._setInstance([::NSFileManager defaultManager]);
        }

        return _defaultManager;
    }

    NSString NSFileManager::FullUserName()
    {
        auto p = ::NSFullUserName();
        [p retain];

        return NSStringHelper::FromHandle(p);
    }

    NSString NSFileManager::UserName()
    {
        auto p = ::NSUserName();
        [p retain];

        return NSStringHelper::FromHandle(p);
    }

    NSString NSFileManager::CurrentDirectory() const
    {
        auto p = (::NSFileManager*)_instance();
        auto sp = p.currentDirectoryPath;
        [sp retain];

        return NSStringHelper::FromHandle(sp);
    }

    bool NSFileManager::CurrentDirectory(NSString const& path) const
    {
        ArgumentNullException::CheckNull(path, u"path");

        auto p = (::NSFileManager*)_instance();

        auto str = (::NSString*)NSObjectHelper::GetPointer(path);

        auto result = [p changeCurrentDirectoryPath:str];

        return (bool)result;
    }

    bool NSFileManager::DirectoryExistsAtPath(NSString const& path) const
    {
        bool isDirectory;
        bool result = PathExists(path, isDirectory);

        return result && isDirectory;
    }

    bool NSFileManager::FileExistsAtPath(NSString const& path) const
    {
        bool isDirectory;
        bool result = PathExists(path, isDirectory);

        return result && !isDirectory;
    }

    bool NSFileManager::PathExists(NSString const& path) const
    {
        ArgumentNullException::CheckNull(path, u"path");

        auto p = (::NSFileManager*)_instance();
        auto str = (::NSString*)NSObjectHelper::GetPointer(path);

        auto result = [p fileExistsAtPath:str];

        return (bool)result;
    }

    bool NSFileManager::PathExists(NSString const& path, bool& isDirectory) const
    {
        ArgumentNullException::CheckNull(path, u"path");

        auto p = (::NSFileManager*)_instance();
        auto str = (::NSString*)NSObjectHelper::GetPointer(path);
        ::BOOL boolValue;

        auto result = [p fileExistsAtPath:str isDirectory:&boolValue];

        isDirectory = (bool)boolValue;

        return (bool)result;
    }
}

