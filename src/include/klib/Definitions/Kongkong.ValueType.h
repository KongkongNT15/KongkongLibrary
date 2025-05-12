#ifndef KONGKONG_VALUETYPE_H
#define KONGKONG_VALUETYPE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief 値の保管庫
    /// @attention 派生クラスで必ずString ToString() const;を実装してね！
    struct ValueType : public KongkongTypeBase {
        protected:
        ValueType() = default;
    };
}

#endif //!KONGKONG_VALUETYPE_H
