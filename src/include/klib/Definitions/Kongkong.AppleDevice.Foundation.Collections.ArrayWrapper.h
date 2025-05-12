#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_ARRAYWRAPPER_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_ARRAYWRAPPER_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.AppleDevice.Foundation.Collections.ArrayWrapperBase.h"
#include "Kongkong.AppleDevice.Foundation.Collections.EnumeratorWrapper.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    template <class T> //requires std::derived_from<T, NSObject>
    struct ArrayWrapper final : public ArrayWrapperBase, public ValueType {
        ArrayWrapper(NSArray const& nsArray) noexcept : ArrayWrapperBase(nsArray) {}
        ArrayWrapper(NSArray&& nsArray) noexcept : ArrayWrapperBase(std::move(nsArray)) {}

        /// @brief nullptrとして作成
        constexpr ArrayWrapper(std::nullptr_t) noexcept : ArrayWrapperBase(nullptr) {}

        /// @brief 指定した要素番号の要素を取得
        /// @param index 要素番号
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumerntOutOfRangeException: indexが範囲外の時
        [[nodiscard]]
        T operator[] (ssize_t index) const { return _nsArray[index].template As<T>(); }

        /// @brief 指定した値が配列に含まれるかを確認
        /// @param obj 確認する値
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool ContainsObject(T const& obj) const { return _nsArray.ContainsObject(obj); }

        /// @brief 要素数
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        ssize_t Count() const { return _nsArray.Count(); }

        /// @brief 最初のオブジェクトを取得
        /// @attention 空の場合はnullptrが返るよ！
        [[nodiscard]]
        T First() const { return _nsArray.First().template As<T>(); }

        /// @brief オブジェクトを検索
        /// @param nsObject オブジェクト
        /// @return 指定したオブジェクトがある要素番号
        /// @return 見つからなかった場合はGlobalVariables::NSNotFound()
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: nsObjectがnullptrの時
        [[nodiscard]]
        ssize_t IndexOfObject(T const& nsObject) const { return _nsArray.IndexOfObject(nsObject); }

        /// @brief オブジェクトを検索
        /// @param nsObject オブジェクト
        /// @param range 検索範囲
        /// @return 指定したオブジェクトがある要素番号
        /// @return 見つからなかった場合はGlobalVariables::NSNotFound()
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: nsObjectがnullptrの時
        /// @throws ArgumentOutOfRangeException: rangeが範囲外の時
        [[nodiscard]]
        ssize_t IndexOfObject(T const& nsObject, NSRange const& range) const { return _nsArray.IndexOfObject(nsObject, range); }

        /// @brief 最後のオブジェクトを取得
        /// @attention 空の場合はnullptrが返るよ！
        [[nodiscard]]
        T Last() const { return _nsArray.Last().template As<T>(); }

        /// @brief 列挙子を取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        EnumeratorWrapper<T> ObjectEnumerator() const { return EnumeratorWrapper<T>(_nsArray.ObjectEnumerator()); }

        /// @brief 逆方向列挙子を取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        EnumeratorWrapper<T> ReverseObjectEnumerator() const { return EnumeratorWrapper<T>(_nsArray.ReverseObjectEnumerator()); }
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_ARRAYWRAPPER_H
