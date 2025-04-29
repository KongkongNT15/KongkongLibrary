#ifndef KONGKONG_APPLEDEVICE_NSOBJECT_H
#define KONGKONG_APPLEDEVICE_NSOBJECT_H

#include "Base.h"
#include "Kongkong.PointerType.h"

namespace KONGKONG_NAMESPACE::AppleDevice
{
    class NSObject : public PointerType {
        public:

        friend bool operator==(NSObject const& left, NSObject const& right) noexcept;
        friend bool operator!=(NSObject const& left, NSObject const& right) noexcept;
        friend constexpr bool operator==(NSObject const& obj, std::nullptr_t) noexcept;
        friend constexpr bool operator!=(NSObject const& obj, std::nullptr_t) noexcept;
        friend constexpr bool operator==(std::nullptr_t, NSObject const& obj) noexcept;
        friend constexpr bool operator!=(std::nullptr_t, NSObject const& obj) noexcept;

        NSObject();
        /// @brief nullptrとして作成
        constexpr NSObject(std::nullptr_t) noexcept : _ptr(nullptr) {}

        void* operator new(size_t) = delete;

        [[nodiscard]]
        constexpr operator bool() const noexcept { return _ptr.__p != nullptr; }

        [[nodiscard]]
        constexpr bool operator!() const noexcept { return _ptr.__p == nullptr; }

        /// @brief 型安全性を確認せずにキャスト
        /// @tparam T キャスト後の型
        template <class T> requires ::std::derived_from<T, NSObject>
        [[nodiscard]] T As() const noexcept;

        /// @brief キャスト
        /// @tparam T キャスト後の型
        template <class T> requires ::std::derived_from<T, NSObject>
        [[nodiscard]] T Cast() const;

        /// @brief クラス名を取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        Foundation::NSString ClassName() const;

        /// @brief キャストできるかを確認
        /// @tparam T キャスト後の型
        template <class T>
        [[nodiscard]] bool Is() const noexcept;

        /// @brief オブジェクトが一致しているかを確認
        /// @param nsObject 比較するオブジェクト
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]] 
        bool IsEqual(NSObject const& nsObject) const;

        /// @brief 参照カウント
        [[nodiscard]]
        ssize_t RetainCount() const noexcept;

        [[nodiscard]]
        Foundation::NSString ToNSString() const;

        [[nodiscard]]
        Foundation::NSString ToNSStringUnsafe() const;

        template <class TBlock>
        [[nodiscard]] TBlock ToBlock() const noexcept;

        [[nodiscard]]
        String ToString() const;

        [[nodiscard]]
        String ToStringUnsafe() const;

        protected:

        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void _checkNull() const;

        /// @brief インスタンスをセット
        /// @param p インスタンスへのポインター
        /// @throws MemoryAllocationException: pがnullptrの時
        void _setInstance(void* p);

        //constexpr void* _instance() noexcept { return _ptr.__p; }
        void* _instance() const;
        constexpr void* _instanceUnsafe() const noexcept { return _ptr.__p; }

        private:

        class _objectPtr {
            public:

            constexpr _objectPtr(std::nullptr_t) noexcept : __p(nullptr) {}
            _objectPtr(_objectPtr const& right) noexcept;
            constexpr _objectPtr(_objectPtr&& right) noexcept : __p(right.__p) { right.__p = nullptr; }

            ~_objectPtr();

            _objectPtr& operator=(std::nullptr_t) noexcept;
            _objectPtr& operator=(_objectPtr const& right) noexcept;
            _objectPtr& operator=(_objectPtr&& right) noexcept;

            void* __p;
        };

        _objectPtr _ptr;

        friend Foundation::NSStringHelper;
        friend NSObjectHelper;
    };

    [[nodiscard]] bool operator==(NSObject const& left, NSObject const& right) noexcept;
    [[nodiscard]] bool operator!=(NSObject const& left, NSObject const& right) noexcept;
    [[nodiscard]] constexpr bool operator==(NSObject const& obj, std::nullptr_t) noexcept { return obj._ptr.__p == nullptr; }
    [[nodiscard]] constexpr bool operator!=(NSObject const& obj, std::nullptr_t) noexcept { return obj._ptr.__p != nullptr; }
    [[nodiscard]] constexpr bool operator==(std::nullptr_t, NSObject const& obj) noexcept { return obj._ptr.__p == nullptr; }
    [[nodiscard]] constexpr bool operator!=(std::nullptr_t, NSObject const& obj) noexcept { return obj._ptr.__p != nullptr; }
}

namespace KONGKONG_NAMESPACE::AppleDevice
{
    template <class T> requires ::std::derived_from<T, NSObject>
    T NSObject::As() const noexcept
    {
        T result = nullptr;
        new (&result._ptr) NSObject::_objectPtr(_ptr);

        return result;
    }

    template <class TBlock>
    TBlock NSObject::ToBlock() const noexcept
    {
        return (TBlock)(_ptr.__p);
    }

    template <>
    inline NSObject NSObject::Cast<NSObject>() const
    {
        return *this;
    }

    template <>
    constexpr bool NSObject::Is<NSObject>() const noexcept
    {
        return *this != nullptr;
    }

    template <>
    constexpr bool NSObject::Is<std::nullptr_t>() const noexcept
    {
        return *this == nullptr;
    }
}

#endif //!KONGKONG_APPLEDEVICE_NSOBJECT_H
