#ifndef KONGKONG_DIAGNOSTICS_LIFECYCLEOBJECT_H
#define KONGKONG_DIAGNOSTICS_LIFECYCLEOBJECT_H

#include "Base.h"
#include "Kongkong.Events.EventHandler.h"
#include "Kongkong.Diagnostics.LifecycleEventArgs.h"
#include "Kongkong.Diagnostics.LifecycleEventType.h"

namespace KONGKONG_NAMESPACE::Diagnostics
{
    struct LifecycleObject final : KongkongTypeBase {

        [[nodiscard]]
        static constexpr auto& CopyAssigning() noexcept { return _copyAssigning.List(); }

        [[nodiscard]]
        static constexpr auto& CopyConstructing() noexcept { return _copyConstructing.List(); }

        [[nodiscard]]
        static constexpr auto& DefaultConstructing() noexcept { return _defaultConstructing.List(); }

        [[nodiscard]]
        static constexpr auto& Destroying() noexcept { return _destroying.List(); }

        [[nodiscard]]
        static constexpr auto& MoveAssigning() noexcept { return _moveAssigning.List(); }

        [[nodiscard]]
        static constexpr auto& MoveConstructing() noexcept { return _moveConstructing.List(); }

        [[nodiscard]]
        static constexpr auto& OtherAssigning() noexcept { return _otherAssigning.List(); }

        [[nodiscard]]
        static constexpr auto& OtherConstructing() noexcept { return _otherConstructing.List(); }

        LifecycleObject()
        {
            _defaultConstructing.Call(*this, LifecycleEventType::DefaultConstructor);
        }

        template <class... Args>
        LifecycleObject(Args&&... args)
        {
            _otherConstructing.Call(*this, LifecycleEventType::OtherConstructor);
        }

        LifecycleObject(LifecycleObject const&)
        {
            _copyConstructing.Call(*this, LifecycleEventType::CopyConstructor);
        }

        LifecycleObject(LifecycleObject&&) noexcept
        {
            _moveConstructing.Call(*this, LifecycleEventType::MoveConstructor);
        }

        ~LifecycleObject()
        {
            _destroying.Call(*this, LifecycleEventType::Destructor);
        }

        LifecycleObject& operator=(LifecycleObject const&)
        {
            _copyAssigning.Call(*this, LifecycleEventType::CopyAssignmentOperator);
            return *this;
        }

        LifecycleObject& operator=(LifecycleObject&&) noexcept
        {
            _moveAssigning.Call(*this, LifecycleEventType::MoveAssignmentOperator);
            return *this;
        }

        template <class... Args>
        LifecycleObject& operator=(Args&&... args)
        {
            _otherAssigning.Call(*this, LifecycleEventType::OtherAssignmentOperator);
            return *this;
        }

        private:

        static inline LifecycleEventHandler _copyConstructing;
        static inline LifecycleEventHandler _defaultConstructing;
        static inline LifecycleEventHandler _moveConstructing;
        static inline LifecycleEventHandler _otherConstructing;

        static inline LifecycleEventHandler _destroying;

        static inline LifecycleEventHandler _copyAssigning;
        static inline LifecycleEventHandler _moveAssigning;
        static inline LifecycleEventHandler _otherAssigning;
    };
}

#endif //!KONGKONG_DIAGNOSTICS_LIFECYCLEOBJECT_H
