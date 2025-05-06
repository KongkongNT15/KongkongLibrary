#ifndef KONGKONG_TEXT_ASCIIENCODING_H
#define KONGKONG_TEXT_ASCIIENCODING_H

#include "Base.h"
#include "Kongkong.Text.Encoding.h"
#include "Kongkong.GenericStringView.h"

namespace KONGKONG_NAMESPACE::Text::IMPLEMENTATION
{
    struct AsciiEncoding : public Encoding {
        using ProjType = ::KONGKONG_NAMESPACE::Text::AsciiEncoding;

        [[nodiscard]]
        constexpr int32_t CodePage() const noexcept { return s_codePage; }

        [[nodiscard]]
        constexpr StringView EncodingName() const noexcept { return s_encodingName; }

        [[nodiscard]]
        constexpr ssize_t GetByteCountUnsafe(ssize_t length, const char16_t*) const noexcept override { return length; }

        [[nodiscard]]
        Collections::Turbo::FastArray<uint8_t> GetBytesUnsafe(ssize_t length, const char16_t* str) const override;

        [[nodiscard]]
        String GetStringUnsafe(ssize_t length, const void* str) const override;

        [[nodiscard]]
        Utf8String GetUtf8StringUnsafe(ssize_t length, const void* str) const override;

        private:
        static StringView s_encodingName;
        static constexpr int32_t s_codePage = 20127;

        friend Encoding::ProjType Encoding::GetEncoding(int32_t);
    };
}

namespace KONGKONG_NAMESPACE::Text
{
    /// @brief 
    class AsciiEncoding : public Encoding {
        public:
        using ImplType = IMPLEMENTATION::AsciiEncoding;

        /// @brief 
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        AsciiEncoding();

        /// @brief nullptrとして作成
        constexpr AsciiEncoding(::std::nullptr_t) noexcept : Encoding(nullptr) {}
    };
}

#endif //!KONGKONG_TEXT_ASCIIENCODING_H