//このObjective-C++ファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice
{
    NSObject::NSObject() : _ptr(nullptr)
    {
        _setInstance([::NSObject alloc]);
    }

    Foundation::NSString NSObject::ClassName() const
    {
        _checkNull();

        Foundation::NSString str = nullptr;

        auto p = [(::NSObject*)_ptr.__p className];

        str._ptr.__p = p;

        return str;
    }

    bool NSObject::IsEqual(NSObject const& nsObject) const
    {
        _checkNull();

        auto p = (::NSObject*)_ptr.__p;

        return (bool)[p isEqual:(::NSObject*)nsObject._ptr.__p];
    }

    ssize_t NSObject::RetainCount() const noexcept
    {
        return (ssize_t)[(::NSObject*)_ptr.__p retainCount];
    }

    Foundation::NSString NSObject::ToNSString() const
    {
        _checkNull();
        return Foundation::NSStringHelper::FromHandle([(::NSObject*)_ptr.__p description]);
    }

    Foundation::NSString NSObject::ToNSStringUnsafe() const
    {
        return Foundation::NSStringHelper::FromHandle([(::NSObject*)_ptr.__p description]);
    }

    String NSObject::ToString() const
    {
        _checkNull();
        return ToStringUnsafe();
    }

    String NSObject::ToStringUnsafe() const
    {
        ::NSString* str;
        bool isNSString;

        if ((bool)[(::NSObject*)_ptr.__p isKindOfClass: NSString.class]) {
            str = (::NSString*)_ptr.__p;
            isNSString = true;
        }
        else {
            str = [(::NSObject*)_ptr.__p description];
            isNSString = false;
        }

        ssize_t length = [str length];
        ssize_t capacity = length + 1;

        char16_t* c16s = String::AllocMemoryUnsafe(capacity);

        [str getCString:(char*)c16s maxLength:(capacity) * sizeof(char16_t) encoding:NSUTF16StringEncoding];

        if (!isNSString) [str release];

        return String::WrapUnsafe(capacity, length, c16s);
    }

    void NSObject::_checkNull() const
    {
        if (_ptr.__p == nullptr) [[unlikely]] throw NullPointerException(u"オブジェクトがnullptrでした");
    }

    void NSObject::_setInstance(void* p)
    {
        MemoryAllocationException::CheckNull(p);
        _ptr.__p = p;
    }

    void* NSObject::_instance() const
    {
        _checkNull();
        return _instanceUnsafe();
    }

    NSObject::_objectPtr::_objectPtr(_objectPtr const& right) noexcept : __p(right.__p)
    {
        if (__p != nullptr) [(::NSObject*)__p retain];
    }

    NSObject::_objectPtr::~_objectPtr()
    {
        if (__p != nullptr) [(::NSObject*)__p release];
    }

    NSObject::_objectPtr& NSObject::_objectPtr::operator=(std::nullptr_t) noexcept
    {
        NSObject::_objectPtr::~_objectPtr();

        __p = nullptr;

        return *this;
    }

    NSObject::_objectPtr& NSObject::_objectPtr::operator=(_objectPtr const& right) noexcept
    {
        NSObject::_objectPtr::~_objectPtr();

        __p = right.__p;

        if (__p != nullptr) [(::NSObject*)__p retain];

        return *this;
    }

    NSObject::_objectPtr& NSObject::_objectPtr::operator=(_objectPtr&& right) noexcept
    {
        NSObject::_objectPtr::~_objectPtr();

        __p = right.__p;

        right.__p = nullptr;

        return *this;
    }

    bool operator==(NSObject const& left, NSObject const& right) noexcept
    {
        ::NSObject* pLeft = (::NSObject*)left._ptr.__p;
        ::NSObject* pRight = (::NSObject*)right._ptr.__p;

        if (pLeft == nullptr) {
            return pRight == nullptr;
        }

        return (bool)[pLeft isEqual:pRight];
    }

    bool operator!=(NSObject const& left, NSObject const& right) noexcept
    {
        return !(left == right);
    }
}
