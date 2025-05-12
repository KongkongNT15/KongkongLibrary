#ifndef KONGKONG_WIN32_HANDLE_H
#define KONGKONG_WIN32_HANDLE_H

#include "Base.h"
#include "Kongkong.HandleType.h"
#include "Kongkong.InvalidCastException.h"
#include "Kongkong.Win32.ClassType.h"
#include "Kongkong.Win32.ClassTypeHelper.h"
#include "Kongkong.Threading.Mutex.h"

#include <handleapi.h>
#include <map>

namespace KONGKONG_NAMESPACE::Win32
{
    /// @brief オブジェクトハンドル
    class Handle : public HandleType {
        public:

        [[nodiscard]]
        static constexpr bool RawEqual(Handle const& left, Handle const& right) noexcept { return left._h.__rawHandle() == right._h.__rawHandle(); }

        [[nodiscard]]
        constexpr operator bool() const noexcept { return _h.__rawHandle() != INVALID_HANDLE_VALUE; }

        [[nodiscard]]
        constexpr bool operator!() const noexcept { return _h.__rawHandle() == INVALID_HANDLE_VALUE; }

        /// @brief nullptrとして作成
        constexpr Handle(std::nullptr_t) noexcept : _h(nullptr) {}

        template <class THandle> requires (::std::derived_from<THandle, Handle> || ::std::same_as<THandle, Handle>)
        THandle As() const noexcept
        {
            THandle obj = nullptr;
            obj._h = _h;

            return obj;
        }

        template <class THandle> requires (::std::derived_from<THandle, Handle> || ::std::same_as<THandle, Handle>)
        THandle Cast() const
        {
            if (Is<THandle>()) return As<THandle>();

            throw InvalidCastException();
        }

        template <class THandle> requires (::std::derived_from<THandle, Handle> || ::std::same_as<THandle, Handle>)
        bool Is() const noexcept
        {
            return _canCastHandle(Type(), ClassTypeHelper::ClassType<THandle>());
        }

        bool Close() noexcept;

        [[nodiscard]]
        String ToString() const;

        [[nodiscard]]
        ClassType Type() const noexcept;

        protected:

        struct _handleCounter final {

            _handleCounter() = default;
            constexpr _handleCounter(ClassType type) noexcept : __count(1), __type(type) {}

            constexpr _handleCounter& operator++() noexcept { ++__count; return *this; }
            constexpr _handleCounter& operator--() noexcept { --__count; return *this; }

            constexpr size_t __handleCount() const noexcept { return __count; }
            constexpr ClassType __classType() const noexcept { return __type; }

            constexpr bool __hasHandle() const noexcept { return __count != 0; }

            private:
            size_t __count;
            ClassType __type;
        };

        struct _handleWrapper final {

            constexpr _handleWrapper(std::nullptr_t) noexcept : __handle(nullptr) {}
            _handleWrapper(_handleWrapper const& right) noexcept;
            constexpr _handleWrapper(_handleWrapper&& right) noexcept : __handle(right.__handle) { right.__handle = INVALID_HANDLE_VALUE; }

            ~_handleWrapper();

            _handleWrapper& operator=(_handleWrapper const& right) noexcept;
            _handleWrapper& operator=(_handleWrapper&& right) noexcept;
            _handleWrapper& operator=(std::nullptr_t) noexcept;

            bool __close() noexcept;

            [[nodiscard]]
            constexpr ::HANDLE __rawHandle() const noexcept { return __handle; }

            std::pair<std::map<::HANDLE, _handleCounter>::iterator, bool> __rawHandle(::HANDLE handle, ClassType type);

            /// @brief すでに登録されているハンドルを指定した場合は参照カウントをインクリメント
            /// @param handle 
            /// @param type 
            void __setRawHandle(::HANDLE handle, ClassType type);

            private:
            ::HANDLE __handle;
        };

        _handleWrapper _h;

        private:
        
        static std::map<::HANDLE, _handleCounter> _typeMap;

        static bool _canCastHandle(ClassType from, ClassType to) noexcept;

        static ::KONGKONG_NAMESPACE::Threading::Mutex _mutex;

        friend bool operator==(Handle const& left, Handle const& right) noexcept;
        friend constexpr bool operator==(Handle const&, std::nullptr_t) noexcept;
        friend constexpr bool operator==(std::nullptr_t, Handle const&) noexcept;
        friend bool operator!=(Handle const& left, Handle const& right) noexcept;
        friend constexpr bool operator!=(Handle const&, std::nullptr_t) noexcept;
        friend constexpr bool operator!=(std::nullptr_t, Handle const&) noexcept;

    };

    template <>
    Handle Handle::As<Handle>() const noexcept;

    template <>
    bool Handle::Is<Handle>() const noexcept;

    [[nodiscard]] bool operator==(Handle const& left, Handle const& right) noexcept;
    [[nodiscard]] constexpr bool operator==(Handle const& left, std::nullptr_t) noexcept { return left._h.__rawHandle() == INVALID_HANDLE_VALUE; }
    [[nodiscard]] constexpr bool operator==(std::nullptr_t, Handle const& right) noexcept { return right._h.__rawHandle() == INVALID_HANDLE_VALUE; }
    [[nodiscard]] bool operator!=(Handle const& left, Handle const& right) noexcept;
    [[nodiscard]] constexpr bool operator!=(Handle const& left, std::nullptr_t) noexcept { return left._h.__rawHandle() != INVALID_HANDLE_VALUE; }
    [[nodiscard]] constexpr bool operator!=(std::nullptr_t, Handle const& right) noexcept { return right._h.__rawHandle() != INVALID_HANDLE_VALUE; }
}

#endif //!KONGKONG_WIN32_HANDLE_H
