#ifndef KONGKONG_COLLECTIONS_KEYVALUEPAIR_H
#define KONGKONG_COLLECTIONS_KEYVALUEPAIR_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Collections._keyValuePairMethods.h"

namespace KONGKONG_NAMESPACE::Collections
{
    template <class TKey, class TValue>
    struct KeyValuePair final : public ValueType, public _keyValuePairMethods {

        KeyValuePair(TKey const& key, TValue const& value) requires std::copy_constructible<TKey> && std::copy_constructible<TValue>
            : _key(key), _value(value)
        {
        }

        KeyValuePair(TKey&& key, TValue const& value) requires std::copy_constructible<TValue>
            : _key(std::move(key)), _value(value)
        {
        }

        KeyValuePair(TKey const& key, TValue&& value) requires std::copy_constructible<TKey>
            : _key(key), _value(std::move(value))
        {
        }

        KeyValuePair(TKey&& key, TValue&& value) : _key(std::move(key)), _value(std::move(value)) {}

        // コピーではなく参照を取得
        [[nodiscard]] constexpr TKey& Key() noexcept { return _key; }
        [[nodiscard]] constexpr TKey const& Key() const noexcept { return _key; }

        void Key(TKey const& key) requires std::copyable<TKey>
        {
            _key = key;
        }

        void Key(TKey&& key) noexcept { _key = std::move(key); }

        // コピーではなく参照を取得
        [[nodiscard]] constexpr TValue& Value() noexcept { return _value; }
        [[nodiscard]] constexpr TValue const& Value() const noexcept { return _value; }

        void Value(TValue const& value) requires std::copyable<TValue>
        {
            _value = value;
        }

        void Value(TValue&& value) noexcept { _value = std::move(value); }

        friend bool operator==(KeyValuePair<TKey, TValue> const& left, KeyValuePair<TKey, TValue> const& right)
            requires std::equality_comparable<TKey> && std::equality_comparable<TValue>
        {
            return left.Key() == right.Key() && left.Value() == right.Value();
        }

        friend bool operator<(KeyValuePair<TKey, TValue> const& left, KeyValuePair<TKey, TValue> const& right) requires std::three_way_comparable<TKey>
        {
            return left._key < right._key;
        }

        friend bool operator<(KeyValuePair<TKey, TValue> const& left, KeyValuePair<TKey, TValue> const& right) noexcept
        {
            const uint8_t* pLeft = reinterpret_cast<const uint8_t*>(&left._key);
            const uint8_t* pRight = reinterpret_cast<const uint8_t*>(&right._key);

            const uint8_t* const pLeftEnd = pLeft + sizeof(TKey);

            while (pLeft != pLeftEnd) {

                if (*pLeft < *pRight) return true;
                
                if (*pLeft == *pRight) {
                    ++pLeft;
                    ++pRight;

                    continue;
                }

                return false;
            }

            return false;
        }

    private:
        TKey _key;
        TValue _value;
    };
}

#endif //!KONGKONG_COLLECTIONS_KEYVALUEPAIR_H
