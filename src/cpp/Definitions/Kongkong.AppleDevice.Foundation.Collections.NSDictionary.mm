//このObjective-C++ファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    NSDictionary::NSDictionary() : NSObject(nullptr)
    {
        _setInstance([::NSDictionary dictionary]);
    }

    NSDictionary::NSDictionary(std::initializer_list<::KONGKONG_NAMESPACE::Collections::KeyValuePair<NSObject, NSObject>> const& list) : NSObject(nullptr)
    {
        Memory::Buffer<::NSObject*> keys;
        Memory::Buffer<::NSObject*> values;

        keys.AllocUnsafe(list.size());
        values.AllocUnsafe(list.size());

        ssize_t i = 0;

        for (auto const& pair : list) {
            ::NSObject* key = (::NSObject*)NSObjectHelper::GetPointer(pair.Key());
            ::NSObject* value = (::NSObject*)NSObjectHelper::GetPointer(pair.Value());

            keys[i] = key;
            values[i] = value;

            i++;
        }

        @try {
            _setInstance([::NSDictionary dictionaryWithObjects:(id*)values.Data() forKeys:(id*)keys.Data() count:list.size()]);
        }
        @catch (::NSException* e) {
            NSString str = NSStringHelper::FromHandle(e.reason);

            throw InvalidArgumentException(str.ToString());
        }
    }

    NSObject NSDictionary::operator[] (NSObject const& key) const
    {
        auto p = (::NSDictionary*)_instance();
        auto pKey = (::NSObject*)NSObjectHelper::GetPointer(key);
        ::NSObject* rp = [p objectForKey:pKey];

        if (rp != nil) [[unlikely]] [rp retain];

        NSObject result = nullptr;
        NSObjectHelper::SetPointer(result, rp);

        return result;
    }

    NSArray NSDictionary::AllKeys() const
    {
        auto p = (::NSDictionary*)_instance();
        //arrは新しいインスタンス
        ::NSArray* arr = p.allKeys;

        NSArray result = nullptr;
        NSObjectHelper::SetPointer(result, arr);

        return result;
    }

    NSArray NSDictionary::AllValues() const
    {
        auto p = (::NSDictionary*)_instance();
        //arrは新しいインスタンス
        ::NSArray* arr = p.allValues;

        NSArray result = nullptr;
        NSObjectHelper::SetPointer(result, arr);

        return result;
    }

    ssize_t NSDictionary::Count() const
    {
        return (ssize_t)((::NSDictionary*)_instance()).count;
    }

    bool NSDictionary::IsEqualToDictionary(NSDictionary const& nsDictionary) const
    {
        auto p = (::NSDictionary*)_instance();
        auto rightP = (::NSDictionary*)NSObjectHelper::GetPointer(nsDictionary);

        return (bool)[p isEqualToDictionary:rightP];
    }

    NSEnumerator NSDictionary::KeyEnumerator() const
    {
        auto p = (::NSDictionary*)_instance();
        //eは新しいインスタンス
        auto e = [p keyEnumerator];

        NSEnumerator result = nullptr;
        NSObjectHelper::SetPointer(result, e);

        return result;
    }

    NSEnumerator NSDictionary::ObjectEnumerator() const
    {
        auto p = (::NSDictionary*)_instance();
        //eは新しいインスタンス
        auto e = [p objectEnumerator];

        NSEnumerator result = nullptr;
        NSObjectHelper::SetPointer(result, e);

        return result;
    }

}
