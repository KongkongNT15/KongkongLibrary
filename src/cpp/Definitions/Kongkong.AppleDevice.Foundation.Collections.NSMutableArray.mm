//このObjective-C++ファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    NSMutableArray::NSMutableArray() : NSArray(nullptr)
    {
        _setInstance([[::NSMutableArray alloc] init]);
    }

    NSMutableArray::NSMutableArray(ssize_t capacity) : NSArray(nullptr)
    {
        ::NSMutableArray* p;
        @try {
            p = [::NSMutableArray arrayWithCapacity:(size_t)capacity];
        }
        @catch (::NSException* e) {
            NSString str = NSStringHelper::FromHandle(e.reason);

            throw InvalidArgumentException(str.ToString());
        }

        _setInstance(p);
    }

    void NSMutableArray::AddObject(NSObject const& value) const
    {
        auto p = (::NSMutableArray*)_instance();
        auto valuep = (::NSObject*)NSObjectHelper::GetPointer(value);

        @try {
            [p addObject:valuep];
        }
        @catch (::NSException* e) {

            NSString str = NSStringHelper::FromHandle(e.reason);

            throw ArgumentNullException(str.ToString());
        }
    }

    void NSMutableArray::AddObjectsFromArray(NSArray const& arr) const
    {
        auto p = (::NSMutableArray*)_instance();
        auto arrP = (::NSArray*)NSObjectHelper::GetPointer(arr);

        [p addObjectsFromArray:arrP];
    }

    void NSMutableArray::RemoveAllObjects() const
    {
        auto p = (::NSMutableArray*)_instance();

        [p removeAllObjects];
    }

    void NSMutableArray::RemoveLastObject() const
    {
        auto p = (::NSMutableArray*)_instance();

        [p removeLastObject];
    }

    void NSMutableArray::RemoveObject(NSObject const& value) const
    {
        auto p = (::NSMutableArray*)_instance();
        auto valueP = (::NSObject*)NSObjectHelper::GetPointer(value);

        [p removeObject:valueP];
    }

    void NSMutableArray::RemoveObjectAtIndex(ssize_t index) const
    {
        auto p = (::NSMutableArray*)_instance();

        @try {
            [p removeObjectAtIndex:(size_t)index];
        }
        @catch (::NSException* e) {
            NSString str = NSStringHelper::FromHandle(e.reason);

            throw ArgumentOutOfRangeException(str.ToString());
        }
    }

}

