#ifndef KONGKONG_DIAGNOSTICS_LIFECYCLEEVENTARGS_H
#define KONGKONG_DIAGNOSTICS_LIFECYCLEEVENTARGS_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Diagnostics.LifecycleEventType.h"

namespace KONGKONG_NAMESPACE::Diagnostics
{
    struct LifecycleEventArgs final : public ValueType {

        constexpr LifecycleEventArgs(LifecycleEventType eventType) noexcept : _eventType(eventType) {}

        [[nodiscard]]
        constexpr LifecycleEventType EventType() const noexcept { return _eventType; }

        [[nodiscard]]
        constexpr bool IsAssignmentOperator() const noexcept { return (bool)(_eventType & LifecycleEventType::AssignmentOperator); }

        [[nodiscard]]
        constexpr bool IsConstructor() const noexcept { return (bool)(_eventType & LifecycleEventType::Constructor); }

        [[nodiscard]]
        constexpr bool IsCopyAction() const noexcept { return (bool)(_eventType & LifecycleEventType::CopyAction); }

        [[nodiscard]]
        constexpr bool IsDefaultAction() const noexcept { return (bool)(_eventType & LifecycleEventType::DefaultAction); }

        [[nodiscard]]
        constexpr bool IsDestructor() const noexcept { return (bool)(_eventType & LifecycleEventType::Destructor); }

        [[nodiscard]]
        constexpr bool IsMoveAction() const noexcept { return (bool)(_eventType & LifecycleEventType::MoveAction); }

        [[nodiscard]]
        constexpr bool IsOtherAction() const noexcept { return (bool)(_eventType & LifecycleEventType::OtherAction); }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        LifecycleEventType _eventType;
    };
}

#endif //!KONGKONG_DIAGNOSTICS_LIFECYCLEEVENTARGS_H
