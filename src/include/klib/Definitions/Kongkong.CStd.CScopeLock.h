#ifndef KONGKONG_CSTD_SCOPELOCK_H
#define KONGKONG_CSTD_SCOPELOCK_H

#include "Base.h"
#include "Kongkong.CStd.CMutex.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::CStd
{
    struct CScopeLock final : public ValueType {

        CScopeLock(CMutex& mutex) : _mutex(mutex) { _mutex.Lock(); }

        ~CScopeLock() { _mutex.UnlockUnsafe(); }

        private:
        CMutex& _mutex;
    };
}

#endif //!KONGKONG_CSTD_SCOPELOCK_H
