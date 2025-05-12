#ifndef KONGKONG_THREADING_ASYNCOPERATIONBASE_H
#define KONGKONG_THREADING_ASYNCOPERATIONBASE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Threading
{
    struct _asyncOperationBase {

        [[nodiscard]]
        String ToString() const;

        

        private:
        _asyncOperationBase() = default;
        _asyncOperationBase(_asyncOperationBase const&) = default;
        _asyncOperationBase(_asyncOperationBase&&) = default;

        _asyncOperationBase& operator=(_asyncOperationBase const&) = default;
        _asyncOperationBase& operator=(_asyncOperationBase&&) = default;

        static void _throw();

        template <class T> requires (::std::is_void_v<T> == false)
        friend struct AsyncOperation;
    };
}

#endif //!KONGKONG_THREADING_ASYNCOPERATIONBASE_H
