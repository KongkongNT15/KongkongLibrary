#ifndef KONGKONG_CSTD_CTHREADRESULT_H
#define KONGKONG_CSTD_CTHREADRESULT_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.CStd.CThreadStatus.h"

#include <threads.h>

namespace KONGKONG_NAMESPACE::CStd
{
    /// @brief スレッドの実行結果
    struct CThreadResult final : public ValueType {

        /// @brief スレッドの終了コード
        [[nodiscard]]
        constexpr int ReturnCode() const noexcept { return _returnCode; }

        /// @brief スレッドの状態
        [[nodiscard]]
        constexpr CThreadStatus Status() const noexcept { return _status; }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        int _returnCode;
        CThreadStatus _status;

        CThreadResult() = default;

        /// @brief 値から作成
        /// @param returnCode 終了コード
        /// @param status スレッドの状態
        constexpr CThreadResult(int returnCode, CThreadStatus status) noexcept : _returnCode(returnCode), _status(status) {}

        friend CThread;
    };
}

#endif //!KONGKONG_CSTD_CTHREADRESULT_H
