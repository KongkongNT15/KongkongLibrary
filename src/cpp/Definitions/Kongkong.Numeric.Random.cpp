//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Numeric::IMPLEMENTATION
{
    Random::Random() :
        _mt64(),
        _urd(0.0, 1.0)
    {
    }

    Random::Random(int64_t seed) :
        _mt64(seed),
        _urd(0.0, 1.0)
    {
    }

    double Random::NextDouble() noexcept
    {
        return _urd(_mt64);
    }

    String Random::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Numeric::Random");
    }

    int64_t Random::_nextInt64Unsafe(int64_t minValue, int64_t maxValue) noexcept
    {
        int64_t randomValue = (int64_t)_mt64();

        if (randomValue < minValue || maxValue <= randomValue) {
            int64_t sa = maxValue - minValue;
            return randomValue < 0 ? (minValue - (randomValue % sa)) : (minValue + (randomValue % sa));
        }

        return randomValue;

    }
}

namespace KONGKONG_NAMESPACE::Numeric
{
    Random::Random() : RandomBase(nullptr)
    {
        _setInstance(NEW ImplType());
    }

    Random::Random(int64_t seed) : RandomBase(nullptr)
    {
        _setInstance(NEW ImplType(seed));
    }
}
