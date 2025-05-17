#ifndef KONGKONG_IO_STREAMBUFFER_H
#define KONGKONG_IO_STREAMBUFFER_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::IO
{
    /// @brief ストリームバッファ
    struct StreamBuffer : public ValueType {

        /// @brief サイズが4096バイトのインスタンスを作成
        [[nodiscard]]
        static StreamBuffer Create4096();

        /// @brief サイズが8192バイトのインスタンスを作成
        [[nodiscard]]
        static StreamBuffer Create8192();

        /// @brief サイズを指定して作成
        /// @param capacity サイズ
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        explicit StreamBuffer(uint32_t capacity);
        StreamBuffer(StreamBuffer const& right);
        constexpr StreamBuffer(StreamBuffer&& right) noexcept : m_capacity(right.m_capacity), m_length(right.m_length), m_p(right.m_p) { right.m_p = nullptr; }

        ~StreamBuffer();

        StreamBuffer& operator=(StreamBuffer const& right);
        StreamBuffer& operator=(StreamBuffer&& right) noexcept;

        [[nodiscard]]
        constexpr uint8_t operator[](uint32_t index) const noexcept { return m_p[index]; }

        [[nodiscard]] constexpr const uint8_t* begin() const noexcept { return m_p; }
        [[nodiscard]] constexpr const uint8_t* end() const noexcept { return m_p + m_length; }

        /// @brief ふぁ！？っく
        uint32_t Append(ssize_t, ::std::nullptr_t) = delete;

        /// @brief データを追加
        /// @param data データ
        /// @return データを追加できたかどうか
        [[nodiscard]]
        bool Append(uint8_t data) noexcept;

        /// @brief データを追加
        /// @attention この関数は引数の安全性を確認しないよ！
        /// @param length データの長さ
        /// @param data データ
        /// @return 追加したデータ数
        [[nodiscard]]
        uint32_t Append(ssize_t length, const void* data) noexcept;

        [[nodiscard]]
        constexpr uint32_t Capacity() const noexcept { return m_capacity; }

        constexpr void Clear() noexcept { m_length = 0; }

        [[nodiscard]]
        constexpr const uint8_t* Data() const noexcept { return m_p; }

        [[nodiscard]]
        constexpr bool IsEmpty() const noexcept { return m_length == 0; }

        [[nodiscard]]
        constexpr uint32_t Length() const noexcept { return m_length; }

        uint32_t Load(IMPLEMENTATION::BufferedStream& stream);
        uint32_t LoadSafe(IMPLEMENTATION::BufferedStream& stream);

        /// @brief ふぁ！？っく
        uint32_t Read(ssize_t, ::std::nullptr_t) = delete;

        [[nodiscard]]
        bool Read(uint8_t& data);

        [[nodiscard]]
        uint32_t Read(ssize_t length, void* buffer);

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        uint32_t m_capacity;
        uint32_t m_length;
        uint32_t m_current;
        uint8_t* m_p;
        
        void m_copy(StreamBuffer const& right);
    };

    [[nodiscard]] constexpr bool operator==(StreamBuffer const& left, StreamBuffer const& right) noexcept
    {
        if (left.Length() != right.Length()) return false;

        const uint8_t* lp = left.begin();
        const uint8_t* le = left.end();
        const uint8_t* rp = right.begin();

        while (lp != le) {
            if (*lp != *rp) return false;

            ++lp;
            ++rp;
        }

        return true;
    }

    [[nodiscard]] constexpr bool operator!=(StreamBuffer const& left, StreamBuffer const& right) noexcept { return !(left == right); }
}

#endif // !KONGKONG_IO_STREAMBUFFER_H