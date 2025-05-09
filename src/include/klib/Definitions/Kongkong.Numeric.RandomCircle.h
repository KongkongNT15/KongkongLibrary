#ifndef KONGKONG_NUMERIC_RANDOMCIRCLE_H
#define KONGKONG_NUMERIC_RANDOMCIRCLE_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Numeric.Vector.h"
#include "Kongkong.Numeric._randomCircleMethods.h"

#include <random>
#include <math.h>

namespace KONGKONG_NAMESPACE::Numeric
{
    /// @brief 円の中に一様な点を生成
    /// @tparam TNum 数値型
    /// @tparam TRandomEngine 乱数生成器
    template <::std::floating_point TNum, Std::RandomEngine TRandomEngine = ::std::mt19937>
    struct RandomCircle : public ValueType, public _randomCircleMethods {
        public:

        explicit RandomCircle(TNum radius)
            : m_radius(radius), m_generator(), m_ud(0, 1)
        {
        }

        explicit RandomCircle(TNum radius, TRandomEngine::result_type seed) requires Std::RandomSeedEngine<TRandomEngine>
            :  m_radius(radius), m_generator(seed), m_ud(0, 1)
        {
        }

        void Discard() noexcept
        {
            m_generator.discard(2);
        }

        [[nodiscard]]
        Numeric::Vector<TNum, 2> Next() const noexcept
        {
            TNum theta = m_ud(m_generator) * (TNum)(::std::numbers::pi * 2.0);
            TNum r = ::sqrt(m_ud(m_generator)) * m_radius;

            return Numeric::Vector<TNum, 2>(r * ::cos(theta), r * ::sin(theta));
        }

        [[nodiscard]]
        constexpr TNum Radius() const noexcept { return m_radius; }

        constexpr void Radius(TNum radius) noexcept { m_radius = radius; }

        void Seed() noexcept requires Std::RandomSeedEngine<TRandomEngine>
        {
            m_generator.seed();
        }

        void Seed(TRandomEngine::result_type seed) noexcept requires Std::RandomSeedEngine<TRandomEngine>
        {
            m_generator.seed(seed);
        }

        private:

        TNum m_radius;
        TRandomEngine m_generator;
        ::std::uniform_real_distribution<TNum> m_ud;
    };
}

#endif //!KONGKONG_NUMERIC_RANDOMCIRCLE_H
