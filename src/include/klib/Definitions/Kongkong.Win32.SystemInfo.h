#ifndef KONGKONG_WIN32_SYSTEMINFO_H
#define KONGKONG_WIN32_SYSTEMINFO_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Win32.ProcessorArchitecture.h"

namespace KONGKONG_NAMESPACE::Win32
{
    //::SYSTEM_INFOのラッパー
    struct SystemInfo final : public ValueType, private ::SYSTEM_INFO {

        SystemInfo() = default;

        constexpr SystemInfo& operator=(::SYSTEM_INFO const& right) noexcept { static_cast<::SYSTEM_INFO&>(*this) = right; return *this; }

        [[nodiscard]] constexpr ::SYSTEM_INFO* BasePointer() noexcept { return this; }
        [[nodiscard]] constexpr const ::SYSTEM_INFO* BasePointer() const noexcept { return this; }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]] String ToString() const;

        [[nodiscard]] constexpr uint64_t ActiveProcessorMask() const noexcept { return ::SYSTEM_INFO::dwActiveProcessorMask; }

        [[nodiscard]] constexpr uint32_t AllocationGranularity() const noexcept { return ::SYSTEM_INFO::dwAllocationGranularity; }

        [[nodiscard]] constexpr void* MaximumApplicationAddress() const noexcept { return ::SYSTEM_INFO::lpMaximumApplicationAddress; }
        [[nodiscard]] constexpr void* MinimumApplicationAddress() const noexcept { return ::SYSTEM_INFO::lpMinimumApplicationAddress; }

        [[nodiscard]] constexpr uint32_t NumberOfProcessors() const noexcept { return ::SYSTEM_INFO::dwNumberOfProcessors; }

        [[nodiscard]] constexpr uint32_t PageSize() const noexcept { return ::SYSTEM_INFO::dwPageSize; }

        [[nodiscard]] constexpr ::KONGKONG_NAMESPACE::Win32::ProcessorArchitecture ProcessorArchitecture() const noexcept { return (::KONGKONG_NAMESPACE::Win32::ProcessorArchitecture)::SYSTEM_INFO::wProcessorArchitecture; }

        [[nodiscard]] constexpr uint16_t ProcessorLevel() const noexcept { return ::SYSTEM_INFO::wProcessorLevel; }

        [[nodiscard]] constexpr uint16_t ProcessorRevision() const noexcept { return ::SYSTEM_INFO::wProcessorRevision; }

    };
}

#endif //!KONGKONG_WIN32_SYSTEMINFO_H
