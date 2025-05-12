#ifndef KONGKONG_WIN32_WAITOBJECTINFO_H
#define KONGKONG_WIN32_WAITOBJECTINFO_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Win32.WaitStatus.h"

namespace KONGKONG_NAMESPACE::Win32
{
    struct WaitObjectInfo final : public ValueType {

        constexpr WaitObjectInfo(uint32_t exitCode, ::KONGKONG_NAMESPACE::Win32::WaitStatus waitStatus) noexcept : _exitCode(exitCode), _waitStatus(waitStatus) {}

        [[nodiscard]] constexpr uint32_t ExitCode() const noexcept { return _exitCode; }
        [[nodiscard]] constexpr ::KONGKONG_NAMESPACE::Win32::WaitStatus WaitStatus() const noexcept { return _waitStatus; }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        ::KONGKONG_NAMESPACE::Win32::WaitStatus _waitStatus;
        uint32_t _exitCode;
    };
}

#endif //!KONGKONG_WIN32_WAITOBJECTINFO_H
