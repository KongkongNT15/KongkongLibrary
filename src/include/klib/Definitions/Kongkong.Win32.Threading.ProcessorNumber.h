#ifndef KONGKONG_WIN32_THRADING_PROCESSOR_NUMBER_H
#define KONGKONG_WIN32_THRADING_PROCESSOR_NUMBER_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    struct ProcessorNumber final : public ValueType, private ::PROCESSOR_NUMBER {

        /// @brief プロセッサグループ
        [[nodiscard]]
        constexpr uint16_t Group() const noexcept { return ::PROCESSOR_NUMBER::Group; }

        /// @brief グループに対する論理プロセッサの相対数
        [[nodiscard]]
        constexpr uint8_t Number() const noexcept { return ::PROCESSOR_NUMBER::Number; }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        ProcessorNumber() = default;

        friend Thread;

    };
}

#endif //!KONGKONG_WIN32_THRADING_PROCESSOR_NUMBER_H
