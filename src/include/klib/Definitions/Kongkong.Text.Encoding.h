#ifndef KONGKONG_TEXT_ENCODING_H
#define KONGKONG_TEXT_ENCODING_H

#include "Base.h"
#include "Kongkong.Object.h"

namespace KONGKONG_NAMESPACE::Text::IMPLEMENTATION
{
    struct Encoding : public ::KONGKONG_NAMESPACE::Object {
        using ProjType = ::KONGKONG_NAMESPACE::Text::Encoding;

        [[nodiscard]]
        static ProjType GetEncoding(int32_t codePage);

        [[nodiscard]]
        virtual int32_t CodePage() const noexcept = 0;

        [[nodiscard]]
        virtual StringView EncodingName() const noexcept = 0;

        /// @brief ふぁ！？っく
        ssize_t GetByteCount(::std::nullptr_t) const = delete;

        /// @brief ふぁ！？っく
        ssize_t GetByteCount(ssize_t, ::std::nullptr_t) const = delete;

        [[nodiscard]]
        ssize_t GetByteCount(const char16_t* str) const;

        [[nodiscard]]
        ssize_t GetByteCount(ssize_t length, const char16_t* str) const;

        [[nodiscard]]
        ssize_t GetByteCount(String const& str) const noexcept;

        [[nodiscard]]
        ssize_t GetByteCount(StringView const& str) const noexcept;

        [[nodiscard]]
        ssize_t GetByteCount(Collections::Array<char16_t> const& chars) const;

        [[nodiscard]]
        ssize_t GetByteCount(Collections::ArrayList<char16_t> const& chars) const;

        [[nodiscard]]
        ssize_t GetByteCount(Collections::Turbo::FastArray<char16_t> const& chars) const noexcept;

        [[nodiscard]]
        ssize_t GetByteCount(Collections::Turbo::FastArrayList<char16_t> const& chars) const noexcept;

        /// @brief ふぁ！？っく
        ssize_t GetByteCountUnsafe(::std::nullptr_t) const = delete;

        /// @brief ふぁ！？っく
        ssize_t GetByteCountUnsafe(ssize_t, ::std::nullptr_t) const = delete;

        [[nodiscard]]
        ssize_t GetByteCountUnsafe(const char16_t* str) const noexcept;

        [[nodiscard]]
        virtual ssize_t GetByteCountUnsafe(ssize_t length, const char16_t* str) const noexcept = 0;

        [[nodiscard]]
        Collections::Turbo::FastArray<uint8_t> GetBytes(const char16_t* str) const;

        [[nodiscard]]
        Collections::Turbo::FastArray<uint8_t> GetBytes(ssize_t length, const char16_t* str) const;

        [[nodiscard]]
        Collections::Turbo::FastArray<uint8_t> GetBytes(String const& str) const;

        [[nodiscard]]
        Collections::Turbo::FastArray<uint8_t> GetBytes(StringView const& str) const;

        [[nodiscard]]
        Collections::Turbo::FastArray<uint8_t> GetBytes(Collections::Array<char16_t> const& chars) const;

        [[nodiscard]]
        Collections::Turbo::FastArray<uint8_t> GetBytes(Collections::ArrayList<char16_t> const& chars) const;

        [[nodiscard]]
        Collections::Turbo::FastArray<uint8_t> GetBytes(Collections::Turbo::FastArray<char16_t> const& chars) const;

        [[nodiscard]]
        Collections::Turbo::FastArray<uint8_t> GetBytes(Collections::Turbo::FastArrayList<char16_t> const& chars) const;

        [[nodiscard]]
        Collections::Turbo::FastArray<uint8_t> GetBytesUnsafe(const char16_t* str) const;

        [[nodiscard]]
        virtual Collections::Turbo::FastArray<uint8_t> GetBytesUnsafe(ssize_t length, const char16_t* str) const = 0;

        /// @brief ふぁ！？っく
        String GetString(::std::nullptr_t) const = delete;

        /// @brief ふぁ！？っく
        String GetString(ssize_t, ::std::nullptr_t) const = delete;

        [[nodiscard]]
        String GetString(const void* bytes) const;

        [[nodiscard]]
        String GetString(ssize_t length, const void* bytes) const;

        [[nodiscard]]
        String GetString(Collections::Array<uint8_t> const& bytes);

        [[nodiscard]]
        String GetString(Collections::ArrayList<uint8_t> const& bytes);

        [[nodiscard]]
        String GetString(Collections::Turbo::FastArray<uint8_t> const& bytes);

        [[nodiscard]]
        String GetString(Collections::Turbo::FastArrayList<uint8_t> const& bytes);

        /// @brief ふぁ！？っく
        String GetStringUnsafe(::std::nullptr_t) const = delete;

        /// @brief ふぁ！？っく
        String GetStringUnsafe(ssize_t, ::std::nullptr_t) const = delete;

        [[nodiscard]]
        String GetStringUnsafe(const void* str) const;

        [[nodiscard]]
        virtual String GetStringUnsafe(ssize_t length, const void* str) const = 0;

        /// @brief ふぁ！？っく
        String GetUtf8String(::std::nullptr_t) const = delete;

        /// @brief ふぁ！？っく
        String GetUtf8String(ssize_t, ::std::nullptr_t) const = delete;

        [[nodiscard]]
        Utf8String GetUtf8String(const void* bytes) const;

        [[nodiscard]]
        Utf8String GetUtf8String(ssize_t length, const void* bytes) const;

        [[nodiscard]]
        Utf8String GetUtf8String(Collections::Array<uint8_t> const& bytes);

        [[nodiscard]]
        Utf8String GetUtf8String(Collections::ArrayList<uint8_t> const& bytes);

        [[nodiscard]]
        Utf8String GetUtf8String(Collections::Turbo::FastArray<uint8_t> const& bytes);

        [[nodiscard]]
        Utf8String GetUtf8String(Collections::Turbo::FastArrayList<uint8_t> const& bytes);

        /// @brief ふぁ！？っく
        Utf8String GetUtf8StringUnsafe(::std::nullptr_t) const = delete;

        /// @brief ふぁ！？っく
        Utf8String GetUtf8StringUnsafe(ssize_t, ::std::nullptr_t) const = delete;

        [[nodiscard]]
        Utf8String GetUtf8StringUnsafe(const void* str) const;

        [[nodiscard]]
        virtual Utf8String GetUtf8StringUnsafe(ssize_t length, const void* str) const = 0;

        protected:


        private:
    };
}

namespace KONGKONG_NAMESPACE::Text
{
    class Encoding : public Object {
        public:
        using ImplType = IMPLEMENTATION::Encoding;

        [[nodiscard]]
        static Encoding GetEncoding(int32_t codePage) { return ImplType::GetEncoding(codePage); }

        /// @brief nullptrとして作成
        constexpr Encoding(::std::nullptr_t) noexcept : Object(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
}

#endif //!KONGKONG_TEXT_ENCODING_H