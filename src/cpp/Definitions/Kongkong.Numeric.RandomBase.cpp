//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Numeric::IMPLEMENTATION
{
    int32_t RandomBase::Next()
    {
        return Next(0, std::numeric_limits<int32_t>::max());
    }

    int32_t RandomBase::Next(int32_t maxValue)
    {
        return Next(0, maxValue);
    }

    int32_t RandomBase::Next(int32_t minValue, int32_t maxValue)
    {
        if (minValue > maxValue) [[unlikely]] throw ArgumentOutOfRangeException(u"'minValue' is larger than 'maxValue'.");
        if (minValue == maxValue) return minValue;
        return _nextUnsafe(minValue, maxValue);
    }

    int64_t RandomBase::NextInt64()
    {
        return NextInt64(0, std::numeric_limits<int64_t>::max());
    }

    int64_t RandomBase::NextInt64(int64_t maxValue)
    {
        return NextInt64(0, maxValue);
    }

    int64_t RandomBase::NextInt64(int64_t minValue, int64_t maxValue)
    {
        if (minValue > maxValue) [[unlikely]] throw ArgumentOutOfRangeException(u"'minValue' is larger than 'maxValue'.");
        if (minValue == maxValue) return minValue;
        return _nextInt64Unsafe(minValue, maxValue);
    }

    float RandomBase::NextSingle()
    {
        return (float)NextDouble();
    }

    int32_t RandomBase::_nextUnsafe(int32_t minValue, int32_t maxValue)
    {
        return (int32_t)_nextInt64Unsafe(minValue, maxValue);
    }
}
