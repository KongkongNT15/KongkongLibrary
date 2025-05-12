#ifndef KONGKONG_CSTD_CMUTEXKIND_H
#define KONGKONG_CSTD_CMUTEXKIND_H

#include "Base.h"

#include <threads.h>

namespace KONGKONG_NAMESPACE::CStd
{
    enum struct CMutexKind {
        Plain     = ::mtx_plain,     //何の変哲もないやつ
        Recursive = ::mtx_recursive, //再帰的ロックのサポート
        Timed     = ::mtx_timed,     //タイムアウトのサポート
    };

    CREATE_OPERATOR_AND_OR(CMutexKind)
}

#endif //!KONGKONG_CSTD_CMUTEXKIND_H
