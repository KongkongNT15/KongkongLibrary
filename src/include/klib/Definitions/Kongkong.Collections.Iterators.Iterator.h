#ifndef KONGKONG_COLLECTIONS_ITERATORS_ITERATOR_H
#define KONGKONG_COLLECTIONS_ITERATORS_ITERATOR_H

#include "Base.h"
#include "Kongkong.NullPointerException.h"
#include "Kongkong.Object.h"
#include "Kongkong.GenericString.h"

namespace KONGKONG_NAMESPACE::Collections::Iterators::IMPLEMENTATION
{
    //イテレータ
    template <class T>
    struct Iterator : public ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object {
        using ProjType = ::KONGKONG_NAMESPACE::Collections::Iterators::Iterator<T>;
        virtual bool IsNotEqual(Iterator<T> const& right) const = 0;

        /// @brief 参照を取得
        virtual T& Current() = 0;

        //前置インクリメント
        //++iter
        virtual void Increment() = 0;
        //後置インクリメント
        //iter++
        virtual ProjType Increment(int) = 0;

        String ToString() const override { return String(u"Kongkong::Collections::Iterators::Iterator<T>", true); }
    };

}

namespace KONGKONG_NAMESPACE::Collections::Iterators
{
    /// @brief イテレータ
    /// @tparam T 要素の型
    template <class T>
    class Iterator : public Object {
        public:
        using ImplType = IMPLEMENTATION::Iterator<T>;

        Iterator() = delete;
        /// @brief nullptrとして作成
        constexpr Iterator(std::nullptr_t) noexcept : Object(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)

        /// @brief イテレータが異なるかを判定
        /// @param right 比較するイテレータ
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: rightがnullptrのとき
        [[nodiscard]]
        bool operator!=(Iterator<T> const& right) const { return Object::_getRef<ImplType>().IsNotEqual(GetInstance(right, u"right")); }
        
        /// @brief 参照を取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        T& operator*() const { return Object::_getRef<ImplType>().Current(); }
        
        /// @brief 前置インクリメント
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        Iterator<T> const& operator++() const
        {
            Object::_getRef<ImplType>().Increment();
            return *this;
        }
        
        /// @brief 後置インクリメント
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        Iterator<T> operator++(int) const { return Object::_getRef<ImplType>().Increment(0); }

    };
    
}

#endif //!KONGKONG_COLLECTIONS_ITERATORS_ITERATOR_H
