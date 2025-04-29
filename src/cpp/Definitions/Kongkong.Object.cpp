//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::IMPLEMENTATION
{
    String Object::ToString() const
    {
        return String(u"KONGKONG_NAMESPACE::Object", true);
    }

    size_t Object::TypeHashCode() const noexcept
    {
        return typeid(*this).hash_code();
    }

    ::KONGKONG_NAMESPACE::TypeInfo Object::TypeInfo() const noexcept
    {
        return typeid(*this);
    }

#ifdef KONGKONG_ENV_WINDOWS

    String Object::TypeName() const
    {

        constexpr char implName[] = "implementation::";
        constexpr size_t implNameLength = sizeof(implName) - 1;
        
        //"struct "の長さ
        constexpr size_t prefixLength = 7;

        String str;

        std::type_info const& typeinfo = typeid(*this);

        const char* p = typeinfo.name() + prefixLength;

        std::string_view view = p;

        size_t implIndex = view.find(implName);

        for (size_t i = 0; p[i] != '\0'; i++) {
            if (i == implIndex) {
                i += implNameLength;
            }

            str.Append((char16_t)p[i]);
        }

        return str;
    }

#endif //KONGKONG_ENV_WINDOWS
}

namespace KONGKONG_NAMESPACE
{
    Object::Object()
    {
        _setInstance(NEW ImplType());
    }

    Object::Object(Interface const& iValue) noexcept : Object(iValue.As<Object>())
    {
    }

    Object& Object::operator=(std::nullptr_t) noexcept
    {
        _ptr.__erase();
        _ptr._p = nullptr;
        return *this;
    }

    Object& Object::operator=(Interface const& iValue) noexcept
    {
        return *this = iValue.As<Object>();
    }

    ssize_t Object::ReferenceCount() const noexcept
    {
        return GC::_userCount(_ptr._p);
    }

    Object::ImplType* Object::_getRealPointer() const noexcept
    {
        if (_ptr._p == nullptr) [[unlikely]] return nullptr;

        Threading::ScopeLock lock(GC::_mutex);

        auto& oc = GC::_gc[_ptr._p];

        if (oc.__isNotReal) return static_cast<ImplType*>(oc.__realPointer);
        
        return static_cast<ImplType*>(_ptr._p);
    }

    bool operator==(Object const& left, Object const& right) noexcept
    {
        return left._getRealPointer() == right._getRealPointer();
    }

    bool operator!=(Object const& left, Object const& right) noexcept
    {
        return left._getRealPointer() != right._getRealPointer();
    }
}
