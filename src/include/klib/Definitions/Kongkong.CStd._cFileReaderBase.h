#ifndef KONGKONG_CSTD_CFILEREADERBASE_H
#define KONGKONG_CSTD_CFILEREADERBASE_H

#include "Base.h"
#include "Kongkong.ArgumentNullException.h"
#include "Kongkong.FormatException.h"
#include "Kongkong.CStd._cFileStream.h"

namespace KONGKONG_NAMESPACE::CStd
{
    struct _cFileReaderBase : public _cFileStream {
        using _cFileStream::_cFileStream;

        _cFileReaderBase(_cFileReaderBase const&) = delete;
        _cFileReaderBase(_cFileReaderBase&& right) = delete;

        _cFileReaderBase& operator=(_cFileReaderBase const&) = delete;
        _cFileReaderBase& operator=(_cFileReaderBase&& right) = delete;

        [[nodiscard]] int Get();
        [[nodiscard]] int GetUnsafe() noexcept;
        [[nodiscard]] int Peek() const;
        [[nodiscard]] int PeekUnsafe() const noexcept;

        [[nodiscard]] bool EndOfStream() const;

        [[nodiscard]] bool EndOfStreamUnsafe() const noexcept;

        /// @brief ふぁ！？っく
        template <class... Args>
        void ScanFormat(std::nullptr_t, Args...) = delete;

        /// @brief fscanf()
        /// @param format 書式
        /// @param args 取り込んだ値の書き込み先
        /// @throws ArgumentNullException: formatがnullptrのとき
        /// @throws FormatException: 値を全て取り込むことができなかった時
        template <class... Args>
        void ScanFormat(const char* format, Args... args)
        {
            _checkIsOpen();
            ArgumentNullException::CheckNull(format, u"format");

            if (::fscanf(_fp, format, args...) != sizeof...(Args)) [[unlikely]] throw FormatException(EXCEPTION_MESSAGE);
        }

        /// @brief ふぁ！？っく
        template <class... Args>
        void ScanFormatUnsafe(std::nullptr_t, Args...) = delete;

        /// @brief fscanf()
        /// @param format 書式
        /// @param args 取り込んだ値の書き込み先
        /// @return 取り込んだ値の数
        template <class... Args>
        int ScanFormatUnsafe(const char* format, Args... args) noexcept
        {
            return ::fscanf(_fp, format, args...);
        }
    };
}

#endif //!KONGKONG_CSTD_CFILEREADERBASE_H
