#ifndef KONGKONG_TEXT_JSON_JSONARRAY_H
#define KONGKONG_TEXT_JSON_JSONARRAY_H

#include "Base.h"
#include "Kongkong.Object.h"
#include "Kongkong.Collections.Turbo.FastArrayList.h"
#include "Kongkong.Text.Json.JsonValue.h"

namespace KONGKONG_NAMESPACE::Text::Json::IMPLEMENTATION
{
    struct JsonArray final : public ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object {

        JsonArray() = default;

        [[nodiscard]] constexpr JsonValue& operator[](ssize_t index) noexcept { return _list[index]; }

        [[nodiscard]] constexpr auto begin() noexcept { return _list.begin(); }
        [[nodiscard]] constexpr auto begin() const noexcept { return _list.begin(); }
        [[nodiscard]] constexpr auto end() noexcept { return _list.end(); }
        [[nodiscard]] constexpr auto end() const noexcept { return _list.end(); }

        void Append(JsonValue const& value);
        void Append(JsonValue&& value);

        [[nodiscard]]
        bool Contains(JsonValue const& value) const noexcept;

        [[nodiscard]]
        ssize_t IndexOf(JsonValue const& value) const noexcept;

        void Insert(ssize_t index, JsonValue const& value);
        void Insert(ssize_t index, JsonValue&& value);

        [[nodiscard]]
        constexpr ssize_t Length() const noexcept { return _list.Length(); }

        [[nodiscard]]
        String ToString() const override;

        private:
        Collections::Turbo::FastArrayList<JsonValue> _list;
    };
}

namespace KONGKONG_NAMESPACE::Text::Json
{
    class JsonArray final : public Object {
        public:
        using ImplType = IMPLEMENTATION::JsonArray;

        JsonArray();

        /// @brief nullptrとして作成
        constexpr JsonArray(::std::nullptr_t) noexcept : Object(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)

        JsonArray const& operator+=(JsonValue const& value) const;
        JsonArray const& operator+=(JsonValue&& value) const;

        [[nodiscard]]
        JsonValue& operator[](ssize_t index) const;

        [[nodiscard]]
        auto begin() const { return _getPtr<ImplType>()->begin(); }

        [[nodiscard]]
        auto end() const { return _getPtr<ImplType>()->end(); }
    };
}

#endif //!KONGKONG_TEXT_JSON_JSONARRAY_H
