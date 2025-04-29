#ifndef KONGKONG_WIN32_THRADING_CALLBACKENVIRONMENT_H
#define KONGKONG_WIN32_THRADING_CALLBACKENVIRONMENT_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Win32.Threading.ThreadPoolView.h"
#include "Kongkong.Win32.Threading.CleanupGroupView.h"

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    struct KONGKONG_INCOMPLETED_CLASS CallbackEnvironment final : public ValueType, private ::TP_CALLBACK_ENVIRON {
        private:
        using Base = ::TP_CALLBACK_ENVIRON;
        public:

        CallbackEnvironment() noexcept;
        CallbackEnvironment(CallbackEnvironment const&) = delete;

        CallbackEnvironment& operator=(CallbackEnvironment const&) = delete;

        [[nodiscard]]
        constexpr CleanupGroupView CleanupGroup() const noexcept { return Base::CleanupGroup; }

        [[nodiscard]]
        constexpr ThreadPoolView Pool() const noexcept { return Base::Pool; }

        void Pool(::std::nullptr_t) noexcept;
        void Pool(::PTP_POOL pool) noexcept;
        void Pool(ThreadPoolView const& pool) noexcept;
        void Pool(ThreadPool const& pool) noexcept;
        void Pool(ThreadPool&&) = delete;


        private:
        
    };
}

#endif //!KONGKONG_WIN32_THRADING_CALLBACKENVIRONMENT_H
