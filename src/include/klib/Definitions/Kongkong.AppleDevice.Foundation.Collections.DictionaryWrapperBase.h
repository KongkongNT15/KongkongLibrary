#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_DICTIONARYWRAPPERBASE_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_DICTIONARYWRAPPERBASE_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.AppleDevice.Foundation.Collections.NSDictionary.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    struct DictionaryWrapperBase : public ValueType {

        [[nodiscard]]
        constexpr NSDictionary const& Dictionary() const noexcept { return _dictionary; }

        private:

        NSDictionary _dictionary;

        DictionaryWrapperBase(NSDictionary const& dictionary) noexcept : _dictionary(dictionary) {}
        DictionaryWrapperBase(NSDictionary&& dictionary) noexcept : _dictionary(std::move(dictionary)) {}

        template <class TKey, class TValue> //requires std::derived_from<TKey, NSObject> && std::derived_from<TValue, NSObject>
        friend struct DictionaryWrapper;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_DICTIONARYWRAPPERBASE_H
