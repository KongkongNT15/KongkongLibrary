#ifndef KONGKONG_LAZYOBJECT_H
#define KONGKONG_LAZYOBJECT_H

#include "Base.h"
#include "Kongkong.GenericString.h"
#include "Kongkong.ValueType.h"
#include "Kongkong._lazyObjectBase.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief 遅延初期化可能なオブジェクト
    /// @tparam T 格納する型
    template <class T>
    struct LazyObject final : public ValueType, public _lazyObjectBase {

        /// @brief 値を格納したLazyObjectを作成
        /// @tparam Args 引数テンプレート
        /// @param args Tのコンストラクタ引数
        template <class... Args>
        [[nodiscard]] static LazyObject FromValue(Args&&... args)
        {
            LazyObject obj;
            obj.InitializeUnsafe<Args...>(::std::forward<Args>(args)...);

            return obj;
        }

        /// @brief 値を格納していない状態で作成
        constexpr LazyObject() noexcept : _lazyObjectBase(false) {}

        /// @brief 値を格納していない状態で作成
        constexpr LazyObject(::std::nullptr_t) noexcept : _lazyObjectBase(false) {}

        LazyObject(LazyObject const& right)
        {
            if (right._isInitialized) {
                new (GetPointerUnsafe()) T(right.GetValueUnsafe());
                this->_isInitialized = true;
                return;
            }

            this->_isInitialized = false;
        }

        LazyObject(LazyObject&& right) noexcept
        {
            if (right._isInitialized) {
                new (GetPointerUnsafe()) T(::std::move(right.GetValueUnsafe()));
                this->_isInitialized = true;
                return;
            }

            this->_isInitialized = false;
        }

        ~LazyObject()
        {
            if (this->_isInitialized) GetValueUnsafe().~T();
        }

        LazyObject& operator=(LazyObject const& right)
        {
            if (right._isInitialized) {
                SetValue<T const&>(right.GetValueUnsafe());
            }
            else {
                ResetUnsafe();
            }

            return *this;
        }

        LazyObject& operator=(LazyObject&& right) noexcept
        {
            if (right._isInitialized) {
                SetValue<T&&>(right.GetValueUnsafe());
            }
            else {
                if (this->_isInitialized) {
                    GetValueUnsafe().~T();
                    this->_isInitialized = false;
                }
            }

            return *this;
        }

        /// @brief 値を格納している場合は破棄
        LazyObject& operator=(::std::nullptr_t) noexcept
        {
            if (this->_isInitialized) ResetUnsafe();
            return *this;
        }

        /// @brief 値のメンバーアクセス
        /// @throws InvalidOperationException: このインスタンスが値を持っていないとき
        [[nodiscard]] T* operator->() { return Pointer(); }
        [[nodiscard]] const T* operator->() const { return Pointer(); }

        /// @brief 値の間接参照
        /// @throws InvalidOperationException: このインスタンスが値を持っていないとき
        [[nodiscard]] T& operator*() { return Value(); }
        [[nodiscard]] T const& operator*() const { return Value(); }

        /// @brief 値へのポインターを取得
        [[nodiscard]] constexpr T* GetPointerUnsafe() noexcept { return (T*)((void*)_placeHolder); }
        [[nodiscard]] constexpr T const* GetPointerUnsafe() const noexcept { return (const T*)((const void*)_placeHolder); }

        /// @brief 値の参照を取得
        [[nodiscard]] constexpr T& GetValueUnsafe() noexcept { return *((T*)((void*)_placeHolder)); }
        [[nodiscard]] constexpr T const& GetValueUnsafe() const noexcept { return *((const T*)((const void*)_placeHolder)); }

        /// @brief 値を格納
        /// @tparam Args 引数テンプレート
        /// @param args Tのコンストラクタ引数
        /// @throws InvalidOperationException: このインスタンスがすでに値を持っているとき
        template <class... Args>
        void Initialize(Args&&... args)
        {
            this->_checkNotIntialized();
            InitializeUnsafe<Args...>(::std::forward<Args>(args)...);
        }

        /// @brief 値を格納
        /// @tparam Args 引数テンプレート
        /// @param args Tのコンストラクタ引数
        template <class... Args>
        void InitializeUnsafe(Args&&... args) noexcept(noexcept(T(::std::forward<Args>(args)...)))
        {
            new (GetPointerUnsafe()) T(::std::forward<Args>(args)...);
            this->_isInitialized = true;
        }

        /// @brief 値へのポインター
        /// @throws InvalidOperationException: このインスタンスが値を持っていないとき
        [[nodiscard]]
        T* Pointer()
        {
            this->_checkIntialized();
            return GetPointerUnsafe();
        }

        /// @brief 値へのポインター
        /// @throws InvalidOperationException: このインスタンスが値を持っていないとき
        [[nodiscard]]
        const T* Pointer() const
        {
            this->_checkIntialized();
            return GetPointerUnsafe();
        }
        
        /// @brief 値の置き換え
        /// @tparam Args 引数テンプレート
        /// @param args Tの代入演算子の引数
        /// @throws InvalidOperationException: このインスタンスが値を持っていないとき
        template <class... Args>
        void Replace(Args&&... args)
        {
            this->_checkIntialized();

            ReplaceUnsafe<Args...>(::std::forward<Args>(args)...);
        }

        /// @brief 値の置き換え
        /// @tparam Args 引数テンプレート
        /// @param args Tの代入演算子の引数
        template <class... Args>
        void ReplaceUnsafe(Args&&... args) noexcept(noexcept(T(::std::forward<Args>(args)...)))
        {
            if constexpr (::std::is_class_v<T> || ::std::is_union_v<T>) GetValueUnsafe().operator=(::std::forward<Args>(args)...);
            else GetValueUnsafe() = T(::std::forward<Args>(args)...);
        }

        /// @brief 値を破棄
        /// @throws InvalidOperationException: このインスタンスが値を持っていないとき
        void Reset()
        {
            _checkIntialized();
            ResetUnsafe();
        }

        /// @brief 値を破棄
        void ResetUnsafe()
        {
            GetValueUnsafe().~T();
            this->_isInitialized = false;
        }

        /// @brief 値をセット
        /// @attention すでに値を持っている場合は置き換えるよ！
        /// @tparam Args 引数テンプレート
        /// @param args Tの代入演算子の引数
        template <class... Args>
        void SetValue(Args&&... args) noexcept(noexcept(T(::std::forward<Args>(args)...)))
        {
            if (this->_isInitialized) [[unlikely]] {
                ReplaceUnsafe<Args...>(::std::forward<Args>(args)...);
                return;
            }
            
            InitializeUnsafe<Args...>(::std::forward<Args>(args)...);
        }

        /// @brief 文字列表現を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const
        {
            if (_isInitialized) {
                if constexpr (::std::derived_from<T, KongkongTypeBase>) return GetValueUnsafe().ToString();
                else if constexpr (NumberType<T>) return String::ValueOf(GetValueUnsafe());
                else return this->_toStringDefault();
            }
            return this->_toStringNotInitialized();
        }

        [[nodiscard]]
        bool TryGetPointer(T*& pointer) noexcept
        {
            if (this->_isInitialized) {
                pointer = GetPointerUnsafe();
                return true;
            }

            return false;
        }

        [[nodiscard]]
        bool TryGetPointer(const T*& pointer) noexcept
        {
            if (this->_isInitialized) {
                pointer = GetPointerUnsafe();
                return true;
            }

            return false;
        }

        [[nodiscard]]
        bool TryGetPointer(const T*& pointer) const noexcept
        {
            if (this->_isInitialized) {
                pointer = GetPointerUnsafe();
                return true;
            }

            return false;
        }

        template <class... Args>
        [[nodiscard]] bool TryInitialize(Args&&... args)
        {
            if (!this->_isInitialized) {
                InitializeUnsafe<Args...>(::std::forward<Args>(args)...);
                return true;
            }

            return false;
        }

        [[nodiscard]]
        bool TryReset() noexcept
        {
            if (this->_isInitialized) {
                ResetUnsafe();
                return true;
            }

            return false;
        }

        /// @brief 値の参照
        /// @throws InvalidOperationException: このインスタンスが値を持っていないとき
        [[nodiscard]]
        T& Value()
        {
            this->_checkIntialized();
            return GetValueUnsafe();
        }

        /// @brief 値の参照
        /// @throws InvalidOperationException: このインスタンスが値を持っていないとき
        [[nodiscard]]
        T const& Value() const
        {
            this->_checkIntialized();
            return GetValueUnsafe();
        }
        
        private:
        uint8_t _placeHolder[sizeof(T)];
    };

    template <class T> requires ::std::equality_comparable<T>
    [[nodiscard]] bool operator==(LazyObject<T> const& left, LazyObject<T> const& right) noexcept
    {
        if (!left.IsInitialized()) return !right.IsInitialized();

        return left.GetValueUnsafe() == right.GetValueUnsafe();
    }

    template <class T> requires ::std::equality_comparable<T>
    [[nodiscard]] bool operator==(LazyObject<T> const& left, T const& right) noexcept
    {
        if (!left.IsInitialized()) return false;

        return left.GetValueUnsafe() == right;
    }

    template <class T> requires ::std::equality_comparable<T>
    [[nodiscard]] bool operator==(T const& left, LazyObject<T> const& right) noexcept
    {
        if (!right.IsInitialized()) return false;

        return left == right.GetValueUnsafe();
    }

    template <class T> requires ::std::equality_comparable<T>
    [[nodiscard]] bool operator!=(LazyObject<T> const& left, LazyObject<T> const& right) noexcept
    {
        if (!left.IsInitialized()) return right.IsInitialized();

        return left.GetValueUnsafe() != right.GetValueUnsafe();
    }

    template <class T> requires ::std::equality_comparable<T>
    [[nodiscard]] bool operator!=(LazyObject<T> const& left, T const& right) noexcept
    {
        if (!left.IsInitialized()) return true;

        return left.GetValueUnsafe() != right;
    }

    template <class T> requires ::std::equality_comparable<T>
    [[nodiscard]] bool operator!=(T const& left, LazyObject<T> const& right) noexcept
    {
        if (!right.IsInitialized()) return true;

        return left != right.GetValueUnsafe();
    }

    template <class T> requires ::std::totally_ordered<T>
    [[nodiscard]] ::std::strong_ordering operator<=>(LazyObject<T> const& left, LazyObject<T> const& right) noexcept
    {
        if (!left.IsInitialized()) {
            return right.IsInitialized() ? ::std::strong_ordering::less : ::std::strong_ordering::equal;
        }

        return left.GetValueUnsafe() <=> right.GetValueUnsafe();
    }

    template <class T> requires ::std::totally_ordered<T>
    [[nodiscard]] ::std::strong_ordering operator<=>(LazyObject<T> const& left, T const& right) noexcept
    {
        if (!left.IsInitialized()) return ::std::strong_ordering::less;

        return left.GetValueUnsafe() <=> right;
    }

    template <class T> requires ::std::totally_ordered<T>
    [[nodiscard]] ::std::strong_ordering operator<=>(T const& left, LazyObject<T> const& right) noexcept
    {
        if (!right.IsInitialized()) return ::std::strong_ordering::greater;

        return left <=> right.GetValueUnsafe();
    }
}

#endif //!KONGKONG_LAZYOBJECT_H
