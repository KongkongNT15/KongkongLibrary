#ifndef KONGKONG_CSTD_CFILEWRITERBASE_H
#define KONGKONG_CSTD_CFILEWRITERBASE_H

#include "Base.h"
#include "Kongkong.CStd._cFileStream.h"

namespace KONGKONG_NAMESPACE::CStd
{
    struct _cFileWriterBase : public _cFileStream {

        using _cFileStream::_cFileStream;

        _cFileWriterBase(_cFileWriterBase const&) = delete;
        _cFileWriterBase(_cFileWriterBase&& right) = delete;

        _cFileWriterBase& operator=(_cFileWriterBase const&) = delete;
        _cFileWriterBase& operator=(_cFileWriterBase&& right) = delete;

        /// @brief バッファーにため込まれたデータをファイルにフラッシュする
        /// @throws IOException: ファイルが開かれていないとき
        /// @throws CStdException: 致命的なエラーが発生したとき
        void Flush();

        /// @brief バッファーにため込まれたデータをファイルにフラッシュする
        /// @return 操作に成功すれば0、失敗した場合はEOF
        int FlushUnsafe() noexcept;
    };
}

#endif //!KONGKONG_CSTD_CFILEWRITERBASE_H
