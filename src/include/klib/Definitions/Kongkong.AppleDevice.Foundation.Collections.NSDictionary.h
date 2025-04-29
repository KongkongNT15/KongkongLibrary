#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_NSDICTIONARY_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_NSDICTIONARY_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    class NSDictionary : public NSObject {
        public:

        /// @brief 空の辞書を作成
        NSDictionary();

        /// @brief 初期化リストから作成
        /// @param list 初期化リスト
        NSDictionary(std::initializer_list<::KONGKONG_NAMESPACE::Collections::KeyValuePair<NSObject, NSObject>> const& list);

        /// @brief nullptrとして作成
        constexpr NSDictionary(std::nullptr_t) noexcept : NSObject(nullptr) {}

        /// @brief 指定したキーに対応する値を取得
        /// @param key キー
        /// @return キーに対応する値
        /// @return 見つからない場合はnullptr
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSObject operator[] (NSObject const& key) const;

        /// @brief キーのみをまとめた配列を取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]] 
        NSArray AllKeys() const;

        /// @brief 値のみをまとめた配列を取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]] 
        NSArray AllValues() const;

        /// @brief 要素数
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        ssize_t Count() const;

        /// @brief 辞書同士を比較
        /// @param nsDictionary 比較するオブジェクト
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool IsEqualToDictionary(NSDictionary const& nsDictionary) const;

        /// @brief キーの列挙子を取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSEnumerator KeyEnumerator() const;

        /// @brief 値の列挙子を取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSEnumerator ObjectEnumerator() const;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_NSDICTIONARY_H
