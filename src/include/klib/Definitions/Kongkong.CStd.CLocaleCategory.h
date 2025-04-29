#ifndef KONGKONG_CSTD_CLOCALECATEGORY_H
#define KONGKONG_CSTD_CLOCALECATEGORY_H

#include "Base.h"

#include <locale.h>

namespace KONGKONG_NAMESPACE::CStd
{
    /// @brief CStdLocaleクラスの関数で使用
    enum struct CLocaleCategory {
        All      = LC_ALL,
        Collate  = LC_COLLATE,
        CharType = LC_CTYPE,
        Monetary = LC_MONETARY,
        Numeric  = LC_NUMERIC,
        Time     = LC_TIME,
    };
}

#endif //!KONGKONG_CSTD_CLOCALECATEGORY_H
