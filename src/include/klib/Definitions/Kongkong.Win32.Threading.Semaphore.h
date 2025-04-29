#ifndef KONGKONG_WIN32_THRADING_SEMAPHORE_H
#define KONGKONG_WIN32_THRADING_SEMAPHORE_H

#include "Base.h"
#include "Kongkong.Win32.Threading.WaitHandle.h"

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    class KONGKONG_INCOMPLETED_CLASS Semaphore final : public WaitHandle {
        public:

        /// @brief nullptrとして作成
        constexpr Semaphore(std::nullptr_t) noexcept : WaitHandle(nullptr) {}

        private:

        /// @brief 型名を取得
        /// @param handle 使われない
        static String _toString(Handle const& handle);

        friend String Handle::ToString() const;
    };
}

#endif //!KONGKONG_WIN32_THRADING_SEMAPHORE_H
