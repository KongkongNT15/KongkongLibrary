#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_NSARRAY_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_NSARRAY_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    class NSArray : public NSObject {
        public:

        /// @brief 空の配列を作成
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSArray();

        /// @brief 
        /// @param list 
        NSArray(std::initializer_list<NSObject> const& list);

        /// @brief nullptrとして作成
        constexpr NSArray(std::nullptr_t) noexcept : NSObject(nullptr) {}

        /// @brief 指定した要素番号の要素を取得
        /// @param index 要素番号
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumerntOutOfRangeException: indexが範囲外の時
        [[nodiscard]]
        NSObject operator[] (ssize_t index) const;

        /// @brief 指定した値が配列に含まれるかを確認
        /// @param obj 確認する値
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool ContainsObject(NSObject const& obj) const;

        /// @brief 要素数
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        ssize_t Count() const;

        /// @brief 最初のオブジェクトを取得
        /// @attention 空の場合はnullptrが返るよ！
        [[nodiscard]]
        NSObject First() const;

        /// @brief オブジェクトを検索
        /// @param nsObject オブジェクト
        /// @return 指定したオブジェクトがある要素番号
        /// @return 見つからなかった場合はGlobalVariables::NSNotFound()
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: nsObjectがnullptrの時
        [[nodiscard]]
        ssize_t IndexOfObject(NSObject const& nsObject) const;

        /// @brief オブジェクトを検索
        /// @param nsObject オブジェクト
        /// @param range 検索範囲
        /// @return 指定したオブジェクトがある要素番号
        /// @return 見つからなかった場合はGlobalVariables::NSNotFound()
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: nsObjectがnullptrの時
        /// @throws ArgumentOutOfRangeException: rangeが範囲外の時
        [[nodiscard]]
        ssize_t IndexOfObject(NSObject const& nsObject, NSRange const& range) const;

        /// @brief NSArrayが一致しているかを確認
        /// @attention rightがnullptrでも例外はスローされないよ！
        /// @param right 比較するオブジェクト
        /// @throws NullPointerException: このインスタンスがnullptrのとき 
        [[nodiscard]]
        bool IsEqualToArray(NSArray const& right) const;

        /// @brief 最後のオブジェクトを取得
        /// @attention 空の場合はnullptrが返るよ！
        [[nodiscard]]
        NSObject Last() const;

        /// @brief 列挙子を取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSEnumerator ObjectEnumerator() const;

        /// @brief 逆方向列挙子を取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSEnumerator ReverseObjectEnumerator() const;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_NSARRAY_H
