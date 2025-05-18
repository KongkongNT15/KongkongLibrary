#ifndef KONGKONG_IO_INPUTSTREAMBUFFER_H
#define KONGKONG_IO_INPUTSTREAMBUFFER_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::IO
{
    struct InputStreamBuffer : public ValueType {

        /// @brief サイズが4096バイトのインスタンスを作成
        [[nodiscard]]
        static InputStreamBuffer Create4096();

        /// @brief サイズが8192バイトのインスタンスを作成
        [[nodiscard]]
        static InputStreamBuffer Create8192();

        explicit InputStreamBuffer(uint32_t capacity);
        InputStreamBuffer(InputStreamBuffer const& right);
        constexpr InputStreamBuffer(InputStreamBuffer&& right) noexcept : m_capacity(right.m_capacity), m_length(right.m_length), m_current(right.m_current), m_p(right.m_p) { right.m_p = nullptr; }

        ~InputStreamBuffer();

        InputStreamBuffer& operator=(InputStreamBuffer const& right);
        InputStreamBuffer& operator=(InputStreamBuffer&& right) noexcept;

        [[nodiscard]]
        constexpr uint8_t operator[](uint32_t index) const noexcept { return m_p[index]; }

        [[nodiscard]] constexpr const uint8_t* begin() const noexcept { return m_p; }
        [[nodiscard]] constexpr const uint8_t* end() const noexcept { return m_p + m_length; }

        [[nodiscard]]
        constexpr uint32_t Capacity() const noexcept { return m_capacity; }

        constexpr void Clear() noexcept { m_length = 0; m_current = 0; }

        uint32_t Load(IMPLEMENTATION::Stream& stream);
        uint32_t LoadSafe(IMPLEMENTATION::Stream& stream);

        /// @brief ふぁ！？っく
        uint32_t Read(ssize_t, ::std::nullptr_t) = delete;

        [[nodiscard]]
        bool Read(uint8_t& data);

        [[nodiscard]]
        uint32_t Read(ssize_t length, void* buffer);

        [[nodiscard]]
        String ToString() const;

        private:
        uint32_t m_capacity;
        uint32_t m_length;
        uint32_t m_current;
        uint8_t* m_p;
    };
}

#endif //!KONGKONG_IO_INPUTSTREAMBUFFER_H