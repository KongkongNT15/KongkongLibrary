#ifndef KONGKONG_MEMORY_WEAKPOINTER_H
#define KONGKONG_MEMORY_WEAKPOINTER_H

#include "Base.h"
#include "Kongkong.Memory.SharedPointer.h"
#include "Kongkong.Memory._weakPointerBase.h"

namespace KONGKONG_NAMESPACE::Memory
{
    template <class T>
    struct WeakPointer final : public PointerType, public _weakPointerBase {

        constexpr WeakPointer(SharedPointer<T> const& p) noexcept : _weakPointerBase(p.RawPointer()) {}

        /// @brief nullptrとして作成
        constexpr WeakPointer(std::nullptr_t) noexcept : _weakPointerBase(nullptr) {}

        [[nodiscard]] constexpr T* operator->() noexcept { return (T*)this->_p; }
        [[nodiscard]] constexpr const T* operator->() const noexcept { return (const T*)this->_p; }
        [[nodiscard]] constexpr T& operator*() noexcept { return *((T*)this->_p); }
        [[nodiscard]] constexpr T const& operator*() const noexcept { return *((const T*)this->_p); }

        [[nodiscard]]
        T& Instance()
        {
            this->_checkNull();
            return operator*();
        }

        [[nodiscard]]
        T const& Instance() const
        {
            this->_checkNull();
            return operator*();
        }

        [[nodiscard]] constexpr T& InstanceUnsafe() noexcept { return operator*(); }
        [[nodiscard]] constexpr T const& InstanceUnsafe() const noexcept { return operator*(); }

        [[nodiscard]] constexpr T* RawPointer() noexcept { return (T*)this->_p; }
        [[nodiscard]] constexpr const T* RawPointer() const noexcept { return (const T*)this->_p; }

        private:
    };
}

#endif //!KONGKONG_MEMORY_WEAKPOINTER_H
