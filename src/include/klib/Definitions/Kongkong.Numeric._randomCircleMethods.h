#ifndef KONGKONG_NUMERIC_RANDOMCIRCLEMETHODS_H
#define KONGKONG_NUMERIC_RANDOMCIRCLEMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Numeric
{
    struct _randomCircleMethods {

        [[nodiscard]]
        String ToString() const;

        private:
        _randomCircleMethods() = default;
        _randomCircleMethods(_randomCircleMethods const&) = default;
        _randomCircleMethods(_randomCircleMethods&&) = default;

        _randomCircleMethods& operator=(_randomCircleMethods const&) = default;
        _randomCircleMethods& operator=(_randomCircleMethods&&) = default;

        template <::std::floating_point TNum, Std::RandomEngine TRandomGenerator>
        friend struct RandomCircle;
    };
}

#endif //!KONGKONG_NUMERIC_RANDOMCIRCLEMETHODS_H