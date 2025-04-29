#ifndef KONGKONG_MEMORY_SHAREDPOINTER_H
#define KONGKONG_MEMORY_SHAREDPOINTER_H

#include "Base.h"
#include "Kongkong.PointerType.h"
#include "Kongkong.Memory._sharedPointerBase.h"
#include "Kongkong.ArgumentNullException.h"
#include "Kongkong.MemoryAllocationException.h"

namespace KONGKONG_NAMESPACE::Memory
{
    template <class T>
    struct SharedPointer final : public PointerType, public _sharedPointerBase {

        template <class... Args>
        [[nodiscard]] static SharedPointer Create(Args&&... args) requires (!std::is_abstract_v<T>)
        {
            T* p = NEW T(std::forward<Args>(args)...);
            SharedPointer sp = nullptr;
            sp._setInstance(p);

            return sp;
        }

        template <class U> requires std::convertible_to<U*, T*>
        static SharedPointer FromPointer(std::nullptr_t) = delete;

        template <class U> requires std::convertible_to<U*, T*>
        [[nodiscard]] static SharedPointer FromPointer(U* p)
        {
            ArgumentNullException::CheckNull(p, u"p");
            SharedPointer sp = nullptr;

            sp._setInstanceUnsafe(p);

            return sp;
        }

        template <class U> requires std::convertible_to<U*, T*>
        static SharedPointer FromPointerUnsafe(std::nullptr_t) = delete;

        template <class U> requires std::convertible_to<U*, T*>
        [[nodiscard]] static SharedPointer FromPointerUnsafe(U* p)
        {
            SharedPointer sp = nullptr;

            T* tp = static_cast<T*>(p);

            if ((void*)tp != (void*)p) {
                sp._setInstanceUnsafe(p, tp);
            }
            else {
                sp._setInstanceUnsafe(p);
            }

            return sp;
        }

        /// @brief nullptrとして作成
        constexpr SharedPointer(std::nullptr_t) noexcept {}

        SharedPointer& operator=(std::nullptr_t) noexcept
        {
            this->Release();
            return *this;
        }

        
        [[nodiscard]] constexpr T* operator->() noexcept { return (T*)this->_ptr._p; }
        [[nodiscard]] constexpr const T* operator->() const noexcept { return (const T*)this->_ptr._p; }
        [[nodiscard]] constexpr T& operator*() noexcept { return *((T*)this->_ptr._p); }
        [[nodiscard]] constexpr T const& operator*() const noexcept { return *((const T*)this->_ptr._p); }

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

        [[nodiscard]] constexpr T* RawPointer() noexcept { return (T*)this->_ptr._p; }
        [[nodiscard]] constexpr const T* RawPointer() const noexcept { return (const T*)this->_ptr._p; }

    };
}

#endif //!KONGKONG_MEMORY_SHAREDPOINTER_H
