#ifndef KONGKONG_COLLECTIONS_ITERATORS_CONSTITERATOR_H
#define KONGKONG_COLLECTIONS_ITERATORS_CONSTITERATOR_H

#include "Base.h"
#include "Kongkong.Object.h"
#include "Kongkong.GenericString.h"

namespace KONGKONG_NAMESPACE::Collections::Iterators::IMPLEMENTATION
{
    //constイテレータ
    template <class T>
    struct ConstIterator : public ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object {
        using ProjType = ::KONGKONG_NAMESPACE::Collections::Iterators::ConstIterator<T>;
        virtual bool IsNotEqual(ConstIterator<T> const& right) const = 0;

        /// @brief const参照を取得
        virtual T const& Current() const = 0;
        //前置インクリメント
        //++iter
        virtual void Increment() = 0;
        //後置インクリメント
        //iter++
        virtual ProjType Increment(int) = 0;

        String ToString() const override { return String(u"Kongkong::Collections::Iterators::ConstIterator<T>", true); }
    };

}

namespace KONGKONG_NAMESPACE::Collections::Iterators
{
    /// @brief constイテレータ
    /// @tparam T 要素の型
    template <class T>
    class ConstIterator : public Object {
        public:
        using ImplType = IMPLEMENTATION::ConstIterator<T>;

        /// @brief nullptrとして作成
        constexpr ConstIterator(std::nullptr_t) noexcept : Object(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)

        /// @brief イテレータが異なるかを判定
        /// @param right 比較するイテレータ
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: rightがnullptrのとき
        [[nodiscard]]
        bool operator!=(ConstIterator<T> const& right) const { return Object::_getRef<ImplType>().IsNotEqual(GetInstance(right, u"right")); }
        
        /// @brief const参照を取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        T const& operator*() const { return Object::_getRef<ImplType>().Current(); }

        /// @brief 前置インクリメント
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        ConstIterator<T> const& operator++() const
        {
            Object::_getRef<ImplType>().Increment();
            return *this;
        }
        
        /// @brief 後置インクリメント
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        ConstIterator<T> operator++(int) const { return Object::_getRef<ImplType>().Increment(0); }

    };
    
}

#endif //!KONGKONG_COLLECTIONS_ITERATORS_CONSTITERATOR_H
