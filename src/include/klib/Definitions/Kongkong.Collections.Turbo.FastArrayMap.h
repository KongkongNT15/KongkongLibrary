#ifndef KONGKONG_COLLETIONS_TURBO_FASTARRAYMAP_H
#define KONGKONG_COLLETIONS_TURBO_FASTARRAYMAP_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Collections.Turbo._fastArrayMapMethods.h"
#include "Kongkong.Collections.Turbo.FastArrayList.h"
#include "Kongkong.Collections.KeyValuePair.h"
#include "Kongkong.InvalidArgumentException.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class TKey, class TValue>
    struct FastArrayMap : public ValueType, public _fastArrayMapMethods {

        [[nodiscard]]
        TValue& operator[](TKey const& key)
        {
            for (auto&& pair : _list) {
                if (pair.Key() == key) return pair.Value();
            }

            if constexpr (::std::is_default_constructible_v<TValue>) {
                _list.Emplace(key, TValue());
                return _list.GetBackUnsafe().Value();
            }
            else {
                throw InvalidArgumentException(u"指定されたキーに一致する値は見つかりませんでした");
            }
        }

        [[nodiscard]]
        TValue& operator[](TKey&& key)
        {
            for (auto&& pair : _list) {
                if (pair.Key() == key) return pair.Value();
            }

            if constexpr (::std::is_default_constructible_v<TValue>) {
                _list.Emplace(::std::move(key), TValue());
                return _list.GetBackUnsafe().Value();
            }
            else {
                throw InvalidArgumentException(u"指定されたキーに一致する値は見つかりませんでした");
            }
        }

        [[nodiscard]]
        TValue const& operator[](TKey const& key) const
        {
            for (auto&& pair : _list) {
                if (pair.Key() == key) return pair.Value();
            }

            throw InvalidArgumentException(u"指定されたキーに一致する値は見つかりませんでした");
        }

        [[nodiscard]] constexpr auto begin() noexcept { return _list.begin(); }
        [[nodiscard]] constexpr auto begin() const noexcept { return _list.begin(); }
        [[nodiscard]] constexpr auto end() noexcept { return _list.end(); }
        [[nodiscard]] constexpr auto end() const noexcept { return _list.end(); }

        void Append(TKey const& key, TValue const& value)
        {
            if (Contains(key)) [[unlikely]] throw InvalidArgumentException(u"指定されたキーは既に存在します");

            _list.Emplace(key, value);
        }

        void Append(TKey const& key, TValue&& value)
        {
            if (Contains(key)) [[unlikely]] throw InvalidArgumentException(u"指定されたキーは既に存在します");

            _list.Emplace(key, ::std::move(value));
        }

        void Append(TKey&& key, TValue const& value)
        {
            if (Contains(key)) [[unlikely]] throw InvalidArgumentException(u"指定されたキーは既に存在します");

            _list.Emplace(::std::move(key), value);
        }

        void Append(TKey&& key, TValue&& value)
        {
            if (Contains(key)) [[unlikely]] throw InvalidArgumentException(u"指定されたキーは既に存在します");

            _list.Emplace(::std::move(key), ::std::move(value));
        }

        void Append(KeyValuePair<TKey, TValue> const& pair)
        {
            if (Contains(pair.Key())) [[unlikely]] throw InvalidArgumentException(u"指定されたキーは既に存在します");

            _list.Append(pair);
        }

        void Append(KeyValuePair<TKey, TValue>&& pair)
        {
            if (Contains(pair.Key())) [[unlikely]] throw InvalidArgumentException(u"指定されたキーは既に存在します");

            _list.Append(::std::move(pair));
        }

        [[nodiscard]]
        TValue& At(TKey const& key)
        {
            for (auto&& pair : _list) {
                if (pair.Key() == key) return pair.Value();
            }

            throw InvalidArgumentException(u"指定されたキーに一致する値は見つかりませんでした");
        }

        [[nodiscard]]
        TValue& At(TKey const& key) const
        {
            return operator[](key);
        }

        constexpr void Clear() noexcept
        {
            _list.Clear();
        }

        [[nodiscard]]
        constexpr bool Contains(TKey const& key) const noexcept
        {
            for (auto&& pair : _list) {
                if (pair.Key() == key) return true;
            }
            
            return false;
        }

        [[nodiscard]]
        constexpr ssize_t Length() const noexcept { return _list.Length(); }

        bool Remove(TKey const& key) noexcept
        {
            auto p = _list.begin();
            auto e = _list.end();

            while (p != e) {
                if (p->Key() == key) {
                    _list.RemoveAtUnsafe(p - _list.begin());

                    return true;
                }
                ++p;
            }

            return false;
        }

        template <class... Args>
        [[nodiscard]] KeyValuePair<TValue*, bool> TryEmplace(TKey const& key, Args&&... args)
        {
            for (auto&& pair : _list) {
                if (pair.Key() == key) return KeyValuePair<TValue*, bool>(&pair.Value(), false);
            }

            _list.Emplace(key, TValue(::std::forward<Args>(args)...));

            return  KeyValuePair<TValue*, bool>(&_list.GetBackUnsafe().Value(), true);
        }

        template <class... Args>
        [[nodiscard]] KeyValuePair<TValue*, bool> TryEmplace(TKey&& key, Args&&... args)
        {
            for (auto&& pair : _list) {
                if (pair.Key() == key) return KeyValuePair<TValue*, bool>(&pair.Value(), false);
            }

            _list.Emplace(::std::move(key), TValue(::std::forward<Args>(args)...));

            return  KeyValuePair<TValue*, bool>(&_list.GetBackUnsafe().Value(), true);
        }

        private:
        FastArrayList<KeyValuePair<TKey, TValue>> _list;
    };
}

#endif //!KONGKONG_COLLETIONS_TURBO_FASTARRAYMAP_H
