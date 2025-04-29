#ifndef KONGKONG_WIN32_THRADING_MUTEX_H
#define KONGKONG_WIN32_THRADING_MUTEX_H

#include "Base.h"
#include "Kongkong.Win32.Threading.WaitHandle.h"

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    class Mutex final : public WaitHandle {
        public:

        /// @brief ふぁ！？っく
        static Mutex Open(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static Mutex Open(std::nullptr_t, bool) = delete;

        [[nodiscard]]
        static Mutex Open(const char16_t* name);

        [[nodiscard]]
        static Mutex Open(String const& name);

        [[nodiscard]]
        static Mutex Open(const char16_t* name, bool isInheritHandle);

        [[nodiscard]]
        static Mutex Open(String const& name, bool isInheritHandle);

        explicit Mutex();
        explicit Mutex(bool isInitialOwner);
        explicit Mutex(::SECURITY_ATTRIBUTES& securityAttributes);
        explicit Mutex(bool isInitialOwner, ::SECURITY_ATTRIBUTES& securityAttributes);
        explicit Mutex(const char16_t* name);
        explicit Mutex(const char16_t* name, bool isInitialOwner);
        explicit Mutex(const char16_t* name, bool isInitialOwner, ::SECURITY_ATTRIBUTES& securityAttributes);
        explicit Mutex(const char16_t* name, ::SECURITY_ATTRIBUTES& securityAttributes);
        explicit Mutex(String const& name);
        explicit Mutex(String const& name, bool isInitialOwner);
        explicit Mutex(String const& name, bool isInitialOwner, ::SECURITY_ATTRIBUTES& securityAttributes);
        explicit Mutex(String const& name, ::SECURITY_ATTRIBUTES& securityAttributes);
        explicit Mutex(std::nullptr_t, bool isInitialOwner);
        explicit Mutex(std::nullptr_t, bool isInitialOwner, ::SECURITY_ATTRIBUTES& securityAttributes);
        explicit Mutex(std::nullptr_t, ::SECURITY_ATTRIBUTES& securityAttributes);

        /// @brief nullptrとして作成
        constexpr Mutex(std::nullptr_t) noexcept : WaitHandle(nullptr) {}

        WaitStatus Wait() const;
        WaitStatus Wait(uint32_t milliSeconds) const;

        WaitStatus LockUnsafe() const noexcept;
        WaitStatus LockUnsafe(uint32_t milliSeconds) const noexcept;

        void Release() const;

        bool ReleaseUnsafe() const noexcept;

        private:
        Mutex(const char16_t* name, bool isInitialOwner, ::LPSECURITY_ATTRIBUTES lpSecurityAttributes);

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static String _toString(Handle const& handle);

        friend String Handle::ToString() const;
    };
}

#endif //!KONGKONG_WIN32_THRADING_MUTEX_H
