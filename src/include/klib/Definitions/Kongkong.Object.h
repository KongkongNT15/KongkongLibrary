#ifndef KONGKONG_OBJECT_H
#define KONGKONG_OBJECT_H

#include "Base.h"
#include "Kongkong.PointerType.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.GC.h"
#include "Kongkong.Threading.ScopeLock.h"
#include "Kongkong.ArgumentNullException.h"
#include "Kongkong.InvalidCastException.h"
#include "Kongkong.MemoryAllocationException.h"
#include "Kongkong.NullPointerException.h"

#define OBJECT_GET_INSTANCE(implType) [[nodiscard]] implType* operator->() const { return Object::_getPtr<implType>(); }
#define OBJECT_GET_INSTANCE_TEMPLATE(implType) [[nodiscard]] implType* operator->() const { return Object::template _getPtr<implType>(); }

namespace KONGKONG_NAMESPACE::IMPLEMENTATION
{
    struct Object : public ValueType {
        using ProjType = ::KONGKONG_NAMESPACE::Object;

        virtual ~Object() noexcept {}

        /// @brief オブジェクトの文字列表現を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        virtual String ToString() const;

        size_t TypeHashCode() const noexcept;

        ::KONGKONG_NAMESPACE::TypeInfo TypeInfo() const noexcept;

#if KONGKONG_ENV_WINDOWS

        String TypeName() const;

#endif //KONGKONG_ENV_WINDOWS

        template <class T>
        bool Is() const
        {
            try {
                T const* value = dynamic_cast<T const*>(this);
                if (value == nullptr) return false;
                return true;
            }
            catch (...) {
                return false;
            }
        }

    };
}

namespace KONGKONG_NAMESPACE
{
    /// @brief スマートポインタ型
    /// @attention このクラスの派生クラスはnewでインスタンス化しないでね
    class Object : public PointerType {
    public:
        using ImplType = IMPLEMENTATION::Object;

        template <class T> requires (std::derived_from<T, Object> || std::derived_from<T, Interface>)
        static Object BoxValue(T& value) = delete;

        template <class T> requires (std::derived_from<T, Object> || std::derived_from<T, Interface>)
        static Object BoxValue(T const& value) = delete;

        template <class T> requires (std::derived_from<T, Object> || std::derived_from<T, Interface>)
            static Object BoxValue(T&& value) = delete;

        /// @brief 値をボックス化
        /// @attention 値のコピーを作成するよ
        /// @tparam T 値の型
        /// @param value 値
        /// @return ボックス化されたオブジェクト
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        template <class T>
        [[nodiscard]] static Object BoxValue(T& value);

        /// @brief 値をボックス化
        /// @attention 値のコピーを作成するよ
        /// @tparam T 値の型
        /// @param value 値
        /// @return ボックス化されたオブジェクト
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        template <class T>
        [[nodiscard]] static Object BoxValue(T const& value);

        /// @brief 値をボックス化
        /// @attention 値のコピーを作成するよ
        /// @tparam T 値の型
        /// @param value 値
        /// @return ボックス化されたオブジェクト
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        template <class T>
        [[nodiscard]] static Object BoxValue(T&& value);

        /// @brief オブジェクトのコピーを作成
        /// @attention valueがnullptrの場合は戻り値もnullptrになるよ
        /// @tparam T オブジェクト型
        /// @tparam TImpl インスタンス型
        /// @param value コピー元の値
        template <class T, class TImpl = typename T::ImplType> requires (std::derived_from<T, Object> || std::derived_from<T, Interface>)
        [[nodiscard]] static T CreateCopy(T const& value)
        {
            T result = nullptr;

            if (value == nullptr) return result;

            TImpl& implValue = GetInstanceUnsafe(value);

            result._setInstance(NEW TImpl(implValue));

            return result;
        }

        /// @brief インスタンス型のポインターからオブジェクトを作成
        /// @tparam T インスタンス型
        /// @param p インスタンスへのポインター
        /// @return 作成されたオブジェクト
        template <class T> requires std::derived_from<T, IMPLEMENTATION::Object>
        [[nodiscard]] static Object Make(T* p)
        {
            Object obj = nullptr;
            obj._setInstance(p);

            return obj;
        }

        /// @brief インスタンス型のポインターからオブジェクトを作成
        /// @tparam TProjection オブジェクト型
        /// @tparam TImplementation インスタンス型
        /// @param p インスタンスへのポインター
        /// @return 作成されたオブジェクト
        template <class TProjection, class TImplementation> requires
            std::derived_from<TImplementation, IMPLEMENTATION::Object>&&
            std::derived_from<TProjection, Object>
        [[nodiscard]] static TProjection Make(TImplementation* p)
        {
            TProjection obj = nullptr;

            if (GC::_gc.contains(p)) {
                new (&obj._ptr) GC::__objectPtr(p);
            }
            else obj._setInstance(p);

            return obj;
        }

        /// @brief KongkongObjectのインスタンスを取得
        /// @tparam TObj Object型
        /// @tparam TImpl インスタンス型
        /// @param obj 対象のオブジェクト
        /// @throws ArgumentNullException: objがnullptrのとき
        template <class TObj, class TImpl = typename TObj::ImplType> requires (std::derived_from<TObj, Object> || std::derived_from<TObj, Interface>)
        [[nodiscard]] static TImpl& GetInstance(TObj const& obj);

        /// @brief KongkongObjectのインスタンスを取得
        /// @tparam TObj Object型
        /// @tparam TImpl インスタンス型
        /// @param obj 対象のオブジェクト
        /// @param name 変数名
        /// @throws ArgumentNullException: objがnullptrのとき
        template <class TObj, class TImpl = typename TObj::ImplType> requires (std::derived_from<TObj, Object> || std::derived_from<TObj, Interface>)
        [[nodiscard]] static TImpl& GetInstance(TObj const& obj, const char16_t* name);

        /// @brief KongkongObjectのインスタンスを取得
        /// @tparam TObj Object型
        /// @tparam TImpl インスタンス型
        /// @param obj 対象のオブジェクト
        template <class TObj, class TImpl = typename TObj::ImplType> requires (std::derived_from<TObj, Object> || std::derived_from<TObj, Interface>)
        [[nodiscard]] static TImpl& GetInstanceUnsafe(TObj const& obj) noexcept
        {
            void* p = obj._ptr._p;
            return *((TImpl*)p);
        }

        /// @brief デフォルト構築
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        Object();

        Object(Interface const& iValue) noexcept;

        /// @brief nullptrとして作成
        constexpr Object(std::nullptr_t) noexcept {}

        //nullを突っ込む
        Object& operator=(std::nullptr_t) noexcept;

        Object& operator=(Interface const& iValue) noexcept;

        OBJECT_GET_INSTANCE(ImplType)

        /// @brief オブジェクトの参照カウント
        [[nodiscard]]
        ssize_t ReferenceCount() const noexcept;

        //型安全性を確認せずにキャスト
        template <class To> requires (std::derived_from<To, Object> || std::derived_from<To, Interface>)
        [[nodiscard]] To As() const noexcept;

        //型安全性を確認せずにキャスト
        template <class To>
        [[nodiscard]] To& As() const noexcept;

        template <class To> requires (std::derived_from<To, Object> || std::derived_from<To, Interface>)
        [[nodiscard]] To Cast() const;

        template <class To>
        [[nodiscard]] To& Cast() const;

        template <class To> requires (std::derived_from<To, Object> || std::derived_from<To, Interface>)
        [[nodiscard]] bool Is() const noexcept
        {
            //キャスト可能かを確認
            //環境によって例外がスローされたりキャストの結果がnullptrになったりする
            auto myP = _getRealPointer();
            try {
                if (dynamic_cast<To::ImplType*>(myP) == nullptr) { return false; }
            }
            catch (...) {
                return false;
            }
            return true;
        }

        //Toにキャストできるかを確認
        template <class To>
        [[nodiscard]] bool Is() const noexcept
        {
            //キャスト可能かを確認
            //環境によって例外がスローされたりキャストの結果がnullptrになったりする
            auto myP = _getRealPointer();
            try {
                if (dynamic_cast<IMPLEMENTATION::BoxValueObject<To>*>(myP) == nullptr) { return false; }
            }
            catch (...) {
                return false;
            }
            return true;
        }

        [[nodiscard]]
        constexpr void* RawPointer() const noexcept { return _ptr._p; }

        //型安全性を確認せずにキャスト
        template <class To> requires (std::derived_from<To, Object> || std::derived_from<To, Interface>)
        bool TryCast(To& to) const noexcept;

        //元からスマートポインタなのでnewしてはいけない
        //void* operator new(size_t) = delete;

    protected:

        //
        template <class Ty>
        void _setInstance(Ty* ptr)
        {
            MemoryAllocationException::CheckNull(ptr);

            _ptr._p = ptr;

            Threading::ScopeLock lock(GC::_mutex);
            GC::_gc.emplace((void*)ptr, GC::__objectCounter(GC::_deleteP<Ty>));
            //GC::_gc[(void*)ptr] = GC::__objectCounter(GC::_deleteP<Ty>);
        }

        //オブジェクトへのスマートポインタ
        GC::__objectPtr _ptr;

    protected:
        void _erase() { _ptr.__erase(); }

        template <class T>
        [[nodiscard]] T& _getRef() const
        {
            if (_ptr._p == nullptr) [[unlikely]] throw NullPointerException(u"参照先のアドレスがnullptrでした");
            return *static_cast<T*>(_ptr._p);
        }

        template <class T>
        [[nodiscard]] T* _getPtr() const
        {
            if (_ptr._p == nullptr) [[unlikely]] throw NullPointerException(u"参照先のアドレスがnullptrでした");
            return static_cast<T*>(_ptr._p);
        }

    private:

        ImplType* _getRealPointer() const noexcept;

        //同じオブジェクトを参照してるか否かを判定
        friend bool operator==(Object const& left, Object const& right) noexcept;
        friend bool operator!=(Object const& left, Object const& right) noexcept;

        //null判定
        friend constexpr bool operator==(Object const& left, std::nullptr_t) noexcept;
        friend constexpr bool operator==(std::nullptr_t, Object const& right) noexcept;
        friend constexpr bool operator!=(Object const& left, std::nullptr_t) noexcept;
        friend constexpr bool operator!=(std::nullptr_t, Object const& right) noexcept;
    };

    [[nodiscard]] bool operator==(Object const& left, Object const& right) noexcept;
    [[nodiscard]] bool operator!=(Object const& left, Object const& right) noexcept;

    [[nodiscard]] constexpr bool operator==(Object const& left, std::nullptr_t) noexcept { return left._ptr._p == nullptr; }
    [[nodiscard]] constexpr bool operator==(std::nullptr_t, Object const& right) noexcept { return nullptr == right._ptr._p; }
    [[nodiscard]] constexpr bool operator!=(Object const& left, std::nullptr_t) noexcept { return left._ptr._p != nullptr; }
    [[nodiscard]] constexpr bool operator!=(std::nullptr_t, Object const& right) noexcept { return nullptr != right._ptr._p; }
}

namespace KONGKONG_NAMESPACE
{
    template <class T>
    Object Object::BoxValue(T const& value)
    {
        return BoxValueObject<T>(value);
    }

    template <class T>
    Object Object::BoxValue(T& value)
    {
        return BoxValueObject<T>(value);
    }

    template <class T>
    Object Object::BoxValue(T&& value)
    {
        return BoxValueObject<T>(std::move(value));
    }

    template <class To> requires (std::derived_from<To, Object> || std::derived_from<To, Interface>)
    To Object::As() const noexcept
    {
        //キャスト可能かを確認
        //失敗した場合は環境によって例外がスローされたりキャストの結果がnullptrになったりする
        try {
            auto myP = _getRealPointer();
            auto p = dynamic_cast<To::ImplType*>(myP);
            if (p == nullptr) return nullptr;

            To ret = nullptr;
            bool value = (void*)p == (void*)myP;
            
            if (value) new (&ret._ptr) GC::__objectPtr(myP);
            else new (&ret._ptr) GC::__objectPtr((void*)p, myP);

            return ret;
        }
        catch (std::exception) {
            return nullptr;
        }
    }

    template <class To>
    To& Object::As() const noexcept
    {
        //キャスト可能かを確認
        //失敗した場合は環境によって例外がスローされたりキャストの結果がnullptrになったりする
        IMPLEMENTATION::BoxValueObject<To>* p;
        try {
            p = static_cast<IMPLEMENTATION::BoxValueObject<To>*>(_getRealPointer());
        }
        catch (...) {
            p = nullptr;
        } 
        
        return p->_value;
    }

    template <class To> requires (std::derived_from<To, Object> || std::derived_from<To, Interface>)
    To Object::Cast() const
    {
        //キャスト可能かを確認
        //失敗した場合は環境によって例外がスローされたりキャストの結果がnullptrになったりする
        try {
            auto myP = _getRealPointer();
            auto p = dynamic_cast<To::ImplType*>(myP);
            if (p == nullptr) { throw InvalidCastException(); }

            To ret = nullptr;
            bool value = (void*)p == (void*)myP;

            if (value) new (&ret._ptr) GC::__objectPtr(myP);
            else new (&ret._ptr) GC::__objectPtr((void*)p, myP);

            return ret;
        }
        catch (std::exception) {
            throw InvalidCastException();
        }
    }

    template <class To>
    To& Object::Cast() const
    { 
        //キャスト可能かを確認
        //失敗した場合は環境によって例外がスローされたりキャストの結果がnullptrになったりする
        IMPLEMENTATION::BoxValueObject<To>* p;
        try {
            if ((p = dynamic_cast<IMPLEMENTATION::BoxValueObject<To>*>(_getRealPointer())) == nullptr) { throw InvalidCastException(); }
        }
        catch (...) {
            throw InvalidCastException();
        }
        
        return p->_value;
    }

    template <class To> requires (std::derived_from<To, Object> || std::derived_from<To, Interface>)
    bool Object::TryCast(To& to) const noexcept
    {
        //キャスト可能かを確認
        //失敗した場合は環境によって例外がスローされたりキャストの結果がnullptrになったりする
        try {
            auto myP = _getRealPointer();
            auto p = dynamic_cast<To::ImplType*>(myP);
            if (p == nullptr) { return false; }

            if ((void*)p == (void*)myP) to._ptr = GC::__objectPtr(myP);
            else to._ptr = GC::__objectPtr((void*)p, myP);

            return true;
        }
        catch (std::exception) {
            return false;
        }

#if KONGKONG_HAS_CPP23
        ::std::unreachable();
#endif
    }

    template <class TObj, class TImpl> requires (std::derived_from<TObj, Object> || std::derived_from<TObj, Interface>)
    TImpl& Object::GetInstance(TObj const& obj)
    {
        return GetInstance(obj, u"obj");
    }

    template <class TObj, class TImpl> requires (std::derived_from<TObj, Object> || std::derived_from<TObj, Interface>)
    TImpl& Object::GetInstance(TObj const& obj, const char16_t* name)
    {
        void* p = obj._ptr._p;
        ArgumentNullException::CheckNull(p, name);
        
        return *((TImpl*)p);
    }
}

#endif //!KONGKONG_OBJECT_H
