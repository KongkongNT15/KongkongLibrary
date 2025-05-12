#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_NSMUTABLEARRAY_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_NSMUTABLEARRAY_H

#include "Base.h"
#include "Kongkong.AppleDevice.Foundation.Collections.NSArray.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    class NSMutableArray : public NSArray {
        public:

        /// @brief 空の配列を作成
        NSMutableArray();

        /// @brief 容量を指定して作成
        /// @param capacity 容量
        /// @throws InvalidArgumentException: capacityが無効な値の時
        NSMutableArray(ssize_t capacity);

        /// @brief nullptrとして作成
        constexpr NSMutableArray(std::nullptr_t) noexcept : NSArray(nullptr) {}

        /// @brief オブジェクトを末尾に追加
        /// @param value 追加するオブジェクト
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: valueがnullptrのとき
        void AddObject(NSObject const& value) const;

        /// @brief NSArrayの要素を末尾に追加
        /// @attention arrがnullptrでも例外はスローされないよ！
        /// @param arr 配列
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void AddObjectsFromArray(NSArray const& arr) const;

        /// @brief 要素を全て削除
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void RemoveAllObjects() const;

        /// @brief 末尾の要素を削除
        /// @attention 要素がない場合は何もしないよ！
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void RemoveLastObject() const;

        /// @brief 指定した値に一致する要素を全て削除します
        /// @param value 値
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void RemoveObject(NSObject const& value) const;

        /// @brief 指定した要素を削除
        /// @param index 要素番号
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外の時
        void RemoveObjectAtIndex(ssize_t index) const;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_NSMUTABLEARRAY_H
