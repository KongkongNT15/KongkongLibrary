#ifndef KONGKONG_WIN32_MEMORYSTATUS_H
#define KONGKONG_WIN32_MEMORYSTATUS_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Win32
{
    struct MemoryStatus final : public ValueType {

        constexpr MemoryStatus(::MEMORYSTATUSEX const& status) noexcept : _status(status) {}

        constexpr operator ::MEMORYSTATUSEX() const noexcept { return _status; }

        constexpr MemoryStatus& operator=(::MEMORYSTATUSEX const& status) noexcept { _status = status; return *this; }

        [[nodiscard]] uint64_t AvailPageFile() const noexcept { return _status.ullAvailPageFile; }
        [[nodiscard]] uint64_t AvailPhysicalMemory() const noexcept { return _status.ullAvailPhys; }
        [[nodiscard]] uint64_t AvailVirtualMemory() const noexcept { return _status.ullAvailVirtual; }

        [[nodiscard]] uint32_t MemoryLoad() const noexcept { return _status.dwMemoryLoad; }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]] String ToString() const;

        [[nodiscard]] uint64_t TotalPageFile() const noexcept { return _status.ullTotalPageFile; }
        [[nodiscard]] uint64_t TotalPhysicalMemory() const noexcept { return _status.ullTotalPhys; }
        [[nodiscard]] uint64_t TotalVirtualMemory() const noexcept { return _status.ullTotalVirtual; }

        private:
        ::MEMORYSTATUSEX _status;
    };
}

#endif //!KONGKONG_WIN32_MEMORYSTATUS_H
