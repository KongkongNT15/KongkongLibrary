#ifndef KONGKONG_TEXT_JSON_JSONOBJECT_H
#define KONGKONG_TEXT_JSON_JSONOBJECT_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Text.Json.JsonValue.h"
#include "Kongkong.Object.h"
#include "Kongkong.Collections.Turbo.FastArrayMap.h"

namespace KONGKONG_NAMESPACE::Text::Json::IMPLEMENTATION
{
    struct JsonObject final : public ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object {
        using ProjType = ::KONGKONG_NAMESPACE::Text::Json::JsonObject;

        [[nodiscard]] auto begin() noexcept { return _map.begin(); }
        [[nodiscard]] auto begin() const noexcept { return _map.begin(); }
        [[nodiscard]] auto end() noexcept { return _map.end(); }
        [[nodiscard]] auto end() const noexcept { return _map.end(); }

        [[nodiscard]]
        JsonValue& operator[](String const& name);

        constexpr void Clear() noexcept { _map.Clear(); }

        [[nodiscard]]
        constexpr bool Contains(String const& name) const noexcept { return _map.Contains(name); }

        void Insert(String const& key, JsonValue const& value);
        void Insert(String const& key, JsonValue&& value);
        void Insert(String&& key, JsonValue const& value);
        void Insert(String&& key, JsonValue&& value);

        [[nodiscard]]
        constexpr ssize_t Length() const noexcept { return _map.Length(); }

        bool Remove(String const& name) noexcept;

        private:

        Collections::Turbo::FastArrayMap<String, JsonValue> _map;
    };
}

namespace KONGKONG_NAMESPACE::Text::Json
{
    class JsonObject final : public Object {
        public:
        using ImplType = IMPLEMENTATION::JsonObject;

        JsonObject();

        /// @brief nullptrとして作成
        constexpr JsonObject(::std::nullptr_t) noexcept : Object(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)

        [[nodiscard]]
        JsonValue& operator[](String const& name) const { return _getPtr<ImplType>()->operator[](name); }

        [[nodiscard]] auto begin() noexcept { return _getPtr<ImplType>()->begin(); }
        [[nodiscard]] auto begin() const noexcept { return _getPtr<ImplType>()->begin(); }
        [[nodiscard]] auto end() noexcept { return _getPtr<ImplType>()->end(); }
        [[nodiscard]] auto end() const noexcept { return _getPtr<ImplType>()->end(); }
    };
}

#endif //!KONGKONG_TEXT_JSON_JSONOBJECT_H
