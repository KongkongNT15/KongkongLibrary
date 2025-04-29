//このObjective-C++ファイルをコンパイルに含めないでください

#define INSTANCE (::NSLock*)_instance()
#define INSTANCE_Unsafe (::NSLock*)_instanceUnsafe()

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Threading
{
    NSLock::NSLock() : NSObject(nullptr)
    {
        _setInstance([[::NSLock alloc] init]);
    }

    NSLock::NSLock(const char16_t* name) : NSLock()
    {
        try {
            _setName(NSString(name));
        }
        catch (ArgumentNullException) {
            ArgumentNullException::ThrowWithName(u"name");
        }
    }

    NSLock::NSLock(String const& name) : NSLock()
    {
        _setName(NSString(name));
    }

    NSLock::NSLock(const char* name) : NSLock()
    {
        try {
            _setName(NSString(name));
        }
        catch (ArgumentNullException) {
            ArgumentNullException::ThrowWithName(u"name");
        }
    }

    NSLock::NSLock(std::string const& name) : NSLock()
    {
        _setName(NSString(name));
    }

    NSLock::NSLock(NSString const& name) : NSLock()
    {
        try {
            _setName(name.Copy());
        }
        catch (ArgumentNullException) {
            ArgumentNullException::ThrowWithName(u"name");
        }
    }

    NSLock::operator NSLocking() const noexcept
    {
        return As<NSLocking>();
    }

    void NSLock::Lock() const
    {
        auto d = INSTANCE;

        [d lock];
    }

    NSString NSLock::Name() const
    {
        auto p = INSTANCE;

        auto str = p.name;
        if (str != nil) [str retain];

        return NSStringHelper::FromHandle(str);
    }

    void NSLock::Name(std::nullptr_t) const
    {
        auto p = INSTANCE;

        if (p.name == nil) return;

        [p release];
        p.name = nil;
    }

    void NSLock::Name(const char16_t* name) const
    {
        _checkNull();
        try {
            _setName(NSString(name));
        }
        catch (ArgumentNullException) {
            ArgumentNullException::ThrowWithName(u"name");
        }
    }

    void NSLock::Name(String const& name) const
    {
        _checkNull();
        _setName(NSString(name));
    }

    void NSLock::Name(const char* name) const
    {
        _checkNull();
        try {
            _setName(NSString(name));
        }
        catch (ArgumentNullException) {
            ArgumentNullException::ThrowWithName(u"name");
        }
    }

    void NSLock::Name(NSString const& name) const
    {
        _checkNull();
        try {
            _setName(name.Copy());
        }
        catch (ArgumentNullException) {
            ArgumentNullException::ThrowWithName(u"name");
        }
    }

    void NSLock::Name(std::string const& name) const
    {
        _checkNull();
        _setName(NSString(name));
    }

    bool NSLock::Trylock() const
    {
        auto p = INSTANCE;

        return (bool)[p tryLock];
    }

    void NSLock::Unlock() const
    {
        auto d = INSTANCE;

        [d unlock];
    }

    void NSLock::_setName(NSString const& str) const noexcept
    {
        auto p = INSTANCE_Unsafe;
        auto pStr = (::NSString*)NSObjectHelper::GetPointer(str);

        [pStr retain];

        if (p.name != nil) [p.name release];

        p.name = pStr;
    }
}

#undef INSTANCE
#undef INSTANCE_Unsafe
