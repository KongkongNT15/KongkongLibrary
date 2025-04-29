#ifndef KONGKONG_CSTD_CFILESTREAM_H
#define KONGKONG_CSTD_CFILESTREAM_H

#include "Base.h"
#include "Kongkong.ValueType.h"

#include <stdio.h>

namespace KONGKONG_NAMESPACE::CStd
{
    struct _cFileStream {

        _cFileStream(_cFileStream const&) = delete;
        _cFileStream(_cFileStream&& right) = delete;

        _cFileStream& operator=(_cFileStream const&) = delete;
        _cFileStream& operator=(_cFileStream&& right) = delete;

        void ClearError();
        void ClearErrorUnsafe() noexcept;

        void Close();
        int CloseUnsafe() noexcept;

        /// @brief ストリームのエラー状態を取得
        /// @throws IOException: ファイルが開かれていないとき
        [[nodiscard]] int ErrorCode() const;

        /// @brief ストリームのエラー状態を取得
        [[nodiscard]] int ErrorCodeUnsafe() const noexcept;

        /// @brief ファイルが開かれているか
        [[nodiscard]]
        constexpr bool IsOpen() const noexcept { return _fp != nullptr; }

        /// @brief ふぁ！？っく
        void Open(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void OpenUnsafe(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void Reopen(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void ReopenUnsafe(std::nullptr_t) = delete;

        protected:
        ::FILE* _fp;

        /// @brief ファイルが開かれているかを確認
        /// @throws IOException: ファイルが開かれていないとき
        void _checkIsOpen() const;

        private:

        constexpr _cFileStream() noexcept : _fp(nullptr) {}
        constexpr _cFileStream(std::nullptr_t) noexcept : _fp(nullptr) {}
        constexpr _cFileStream(::FILE* fp) noexcept : _fp(fp) {}

        friend _cFileReaderBase;
        friend _cFileWriterBase;

        friend CFileReader;
        friend CBinaryFileReader;
        friend CFileWriter;
        friend CBinaryFileWriter;
    };
}

#endif //!KONGKONG_CSTD_CFILESTREAM_H
