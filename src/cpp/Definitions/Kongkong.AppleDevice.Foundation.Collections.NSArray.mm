//このObjective-C++ファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    NSArray::NSArray() : NSObject(nullptr)
    {
        _setInstance([::NSArray array]);
    }

    NSArray::NSArray(std::initializer_list<NSObject> const& list) : NSObject(nullptr)
    {
        using pType = ::NSObject*;
        ssize_t i;
        auto itr = list.begin();
        auto end = list.end();

        pType* arr = NEW pType[list.size()];

        MemoryAllocationException::CheckNull(arr);

        for (i = 0; itr != end; ++i, ++itr) {
            arr[i] = (pType)NSObjectHelper::GetPointer(*itr);
        }

        @try {
            _setInstance([::NSArray arrayWithObjects:arr count:list.size()]);
        }
        @catch (::NSException* e) {
            delete[] arr;
            NSString str = NSStringHelper::FromHandle(e.reason);

            if ([e.name isEqualToString: ::NSInvalidArgumentException]) {
                throw InvalidArgumentException(str.ToString());
            }
            else {
                throw InitializationException(str.ToString());
            }
        }
        delete[] arr;
    }

    NSObject NSArray::operator[] (ssize_t index) const
    {
        auto p = (::NSArray*)_instance();

        @try {
            ::NSObject* obj = [p objectAtIndex:(size_t)index];
            [obj retain];

            NSObject result = nullptr;
            NSObjectHelper::SetPointer(result, obj);

            return result;
        }
        @catch (::NSException* e) {
            NSString str = NSStringHelper::FromHandle(e.reason);

            if ([e.name isEqualToString: ::NSRangeException]) throw ArgumentOutOfRangeException(str.ToString());
            else throw Exception(str.ToString());
        }
    }

    bool NSArray::ContainsObject(NSObject const& obj) const
    {
        auto instance = (::NSArray*)_instance();
        auto pbjP = (::NSObject*)NSObjectHelper::GetPointer(obj);

        return (bool)[instance containsObject:pbjP];
    }

    ssize_t NSArray::Count() const
    {
        return (ssize_t)((::NSArray*)_instance()).count;
    }

    NSObject NSArray::First() const
    {
        auto instance = (::NSArray*)_instance();
        ::NSObject* p = instance.firstObject;
        [p retain];

        NSObject obj = nullptr;
        NSObjectHelper::SetPointer(obj, p);

        return obj;
    }

    ssize_t NSArray::IndexOfObject(NSObject const& nsObject) const
    {
        auto ins = (::NSArray*)_instance();

        ::NSObject* p = (::NSObject*)NSObjectHelper::GetPointer(nsObject);

        @try {
            return (ssize_t)[ins indexOfObject:p];
        }
        @catch (::NSException* e) {
            NSString str = NSStringHelper::FromHandle(e.reason);

            if ([e.name isEqualToString: ::NSInvalidArgumentException]) {
                if (nsObject == nullptr) ArgumentNullException::ThrowWithName(u"nsObject");
                else throw InvalidArgumentException(str.ToString());
            }
            else {
                throw Exception(str.ToString());
            }
        }
    }

    ssize_t NSArray::IndexOfObject(NSObject const& nsObject, NSRange const& range) const
    {
        auto ins = (::NSArray*)_instance();

        ::NSObject* p = (::NSObject*)NSObjectHelper::GetPointer(nsObject);

        @try {
            return (ssize_t)[ins indexOfObject:p inRange:{range.Location(), range.Length()}];
        }
        @catch (::NSException* e) {
            NSString str = NSStringHelper::FromHandle(e.reason);

            if ([e.name isEqualToString: ::NSInvalidArgumentException]) {
                ArgumentNullException::ThrowWithName(u"nsObject");
            }
            else if ([e.name isEqualToString: ::NSRangeException]) {
                throw ArgumentOutOfRangeException(str.ToString());
            }
            else {
                throw Exception(str.ToString());
            }
        }
    }

    bool NSArray::IsEqualToArray(NSArray const& right) const
    {
        auto p = (::NSArray*)_instance();
        auto ri = (::NSArray*)right._instanceUnsafe();

        return (bool)[p isEqualToArray:ri];
    }

    NSObject NSArray::Last() const
    {
        auto instance = (::NSArray*)_instance();
        ::NSObject* p = instance.lastObject;
        [p retain];

        NSObject obj = nullptr;
        NSObjectHelper::SetPointer(obj, p);

        return obj;
    }

    NSEnumerator NSArray::ObjectEnumerator() const
    {
        auto ins = (::NSArray*)_instance();

        auto objEnum = [ins objectEnumerator];

        NSEnumerator result = nullptr;

        NSObjectHelper::SetPointer(result, objEnum);

        return result;
    }

    NSEnumerator NSArray::ReverseObjectEnumerator() const
    {
        auto ins = (::NSArray*)_instance();

        auto objEnum = [ins reverseObjectEnumerator];
        [objEnum retain];

        NSEnumerator result = nullptr;

        NSObjectHelper::SetPointer(result, objEnum);

        return result;
    }
}

