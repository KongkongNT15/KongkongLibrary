//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    int CRandomGenerator::Next() noexcept
    {
        return ::rand();
    }

    int CRandomGenerator::Next(int maxValue)
    {
        if (maxValue < MinValue()) [[unlikely]] throw InvalidArgumentException(u"負の値は指定できません");
        if (maxValue == 0) [[unlikely]] return 0;
        if (maxValue > MaxValue()) return ::rand();

        return ::rand() % maxValue;
    }

    int CRandomGenerator::Next(int minValue, int maxValue)
    {
        if (minValue <= MinValue()) throw InvalidOperationException(u"0以下の値は指定できません");
        if (minValue > maxValue) [[unlikely]] throw InvalidArgumentException(u"minValueがmaxValueよりも大きくなっています");
        if (minValue == maxValue) [[unlikely]] return minValue;

        return (::rand() % (maxValue - minValue)) + minValue;
    }

    void CRandomGenerator::Seed(unsigned seed) noexcept
    {
        ::srand(seed);
    }
}
