//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    ArrayWrapperBase::ArrayWrapperBase(NSArray const& nsArray) noexcept : _nsArray(nsArray)
    {
    }

    ArrayWrapperBase::ArrayWrapperBase(NSArray&& nsArray) noexcept : _nsArray(std::move(nsArray))
    {
    }
    
    String ArrayWrapperBase::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections::ArrayWrapper<T>");
    }

    bool operator==(ArrayWrapperBase const& left, ArrayWrapperBase const& right) noexcept
    {
        return left._nsArray == right._nsArray;
    }

    bool operator!=(ArrayWrapperBase const& left, ArrayWrapperBase const& right) noexcept
    {
        return left._nsArray != right._nsArray;
    }
}
