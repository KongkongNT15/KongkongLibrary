#ifndef KONGKONG_ALGORITHMS_OTHELLO_OTHELLOVALUE_H
#define KONGKONG_ALGORITHMS_OTHELLO_OTHELLOVALUE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Algorithms::Othello
{
    enum struct OthelloValue : uint8_t {
        None,
        White,
        Black,
    };
}

#endif //!KONGKONG_ALGORITHMS_OTHELLO_OTHELLOVALUE_H
