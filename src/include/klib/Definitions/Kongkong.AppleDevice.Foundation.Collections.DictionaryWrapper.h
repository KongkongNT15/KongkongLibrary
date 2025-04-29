#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_DICTIONARYWRAPPER_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_DICTIONARYWRAPPER_H

#include "Base.h"
#include "Kongkong.AppleDevice.Foundation.Collections.ArrayWrapper.h"
#include "Kongkong.AppleDevice.Foundation.Collections.DictionaryWrapperBase.h"
#include "Kongkong.AppleDevice.Foundation.Collections.EnumeratorWrapper.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    template <class TKey, class TValue> //requires std::derived_from<TKey, NSObject> && std::derived_from<TValue, NSObject>
    struct DictionaryWrapper final : public DictionaryWrapperBase {
        DictionaryWrapper(NSDictionary const& dictionary) noexcept : DictionaryWrapperBase(dictionary) {}
        DictionaryWrapper(NSDictionary&& dictionary) noexcept : DictionaryWrapperBase(std::move(dictionary)) {}

        /// @brief 指定したキーに対応する値を取得
        /// @param key キー
        /// @return キーに対応する値
        /// @return 見つからない場合はnullptr
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        TValue operator[] (TKey const& key) const { return _dictionary[key].template As<TValue>(); }

        /// @brief キーのみをまとめた配列を取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]] 
        ArrayWrapper<TKey> AllKeys() const { return ArrayWrapper<TKey>(_dictionary.AllKeys()); }

        /// @brief 値のみをまとめた配列を取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]] 
        ArrayWrapper<TValue> AllValues() const { return ArrayWrapper<TValue>(_dictionary.AllValues()); }

        /// @brief 要素数
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        ssize_t Count() const { return _dictionary.Count(); }

        /// @brief 辞書同士を比較
        /// @param nsDictionary 比較するオブジェクト
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool IsEqualToDictionary(NSDictionary const& nsDictionary) const { return _dictionary.IsEqualToDictionary(nsDictionary); }

        /// @brief キーの列挙子を取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        EnumeratorWrapper<TKey> KeyEnumerator() const { return EnumeratorWrapper<TKey>(_dictionary.KeyEnumerator()); }

        /// @brief 値の列挙子を取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        EnumeratorWrapper<TValue> ObjectEnumerator() const { return EnumeratorWrapper<TValue>(_dictionary.ObjectEnumerator()); }
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_DICTIONARYWRAPPER_H
