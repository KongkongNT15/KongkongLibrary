#ifndef KONGKONG_WIN32_PRIMITIVES_WINHTTP_H
#define KONGKONG_WIN32_PRIMITIVES_WINHTTP_H

#include "Base.h"

#include <winhttp.h>

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    class WinHttp final {
        public:
        STATIC_CLASS(WinHttp)

        /// @brief ふぁ！？っく
        static uint32_t ReadData(std::nullptr_t, std::nullptr_t, uint32_t) = delete;

        /// @brief ふぁ！？っく
        static uint32_t ReadData(::HINTERNET, std::nullptr_t, uint32_t) = delete;

        /// @brief ふぁ！？っく
        static uint32_t ReadData(std::nullptr_t, void*, uint32_t) = delete;

        /// @brief データの読み取り
        /// @param hInternet 読み取り元
        /// @param buffer 書き込み先バッファー
        /// @param bufferLength 読み取るバイト数
        /// @return 読み取ったバイト数
        /// @throws ArgumentNullException: bufferがnullptrのとき
        /// @throws HResultException: 操作に失敗したとき
        [[nodiscard]]
        static uint32_t ReadData(::HINTERNET hInternet, void* buffer, uint32_t bufferLength);

        /// @brief ふぁ！？っく
        static uint32_t ReadDataUncheckBufferUnsafe(std::nullptr_t, std::nullptr_t, uint32_t) = delete;

        /// @brief ふぁ！？っく
        static uint32_t ReadDataUncheckBufferUnsafe(::HINTERNET, std::nullptr_t, uint32_t) = delete;

        /// @brief ふぁ！？っく
        static uint32_t ReadDataUncheckBufferUnsafe(std::nullptr_t, void*, uint32_t) = delete;

        /// @brief データの読み取り
        /// @param hInternet 読み取り元
        /// @param buffer 書き込み先バッファー
        /// @param bufferLength 読み取るバイト数
        /// @return 読み取ったバイト数
        /// @throws HResultException: 操作に失敗したとき
        [[nodiscard]]
        static uint32_t ReadDataUncheckBufferUnsafe(::HINTERNET hInternet, void* buffer, uint32_t bufferLength);

        /// @brief ふぁ！？っく
        static uint32_t ReadDataUnsafe(std::nullptr_t, std::nullptr_t, uint32_t) = delete;

        /// @brief ふぁ！？っく
        static uint32_t ReadDataUnsafe(::HINTERNET, std::nullptr_t, uint32_t) = delete;

        /// @brief ふぁ！？っく
        static uint32_t ReadDataUnsafe(std::nullptr_t, void*, uint32_t) = delete;

        /// @brief データの読み取り
        /// @param hInternet 読み取り元
        /// @param buffer 書き込み先バッファー
        /// @param bufferLength 読み取るバイト数
        /// @return 読み取ったバイト数
        [[nodiscard]]
        static uint32_t ReadDataUnsafe(::HINTERNET hInternet, void* buffer, uint32_t bufferLength) noexcept;
    };
}

#endif //!KONGKONG_WIN32_PRIMITIVES_WINHTTP_H
