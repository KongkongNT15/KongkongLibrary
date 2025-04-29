#ifndef KONGKONG_CSTD_CSTDCRRORCHECKER_H
#define KONGKONG_CSTD_CSTDCRRORCHECKER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::CStd
{
    class CStdErrorChecker final {

        STATIC_CLASS(CStdErrorChecker)

        /// @brief 標準ライブラリ関数の戻り値を確認
        /// @param value APIの戻り値
        /// @throws CStdException: valueがEOFのとき
        static void CheckInt(int value);

        /// @brief 標準ライブラリ関数の戻り値を確認
        /// @param value APIの戻り値
        /// @throws CStdException: valueが(size_t)EOFのとき
        static void CheckSize(size_t value);

        /// @brief 標準ライブラリ関数の戻り値を確認
        /// @param value APIの戻り値
        /// @throws CStdException: valueがEOFのとき
        static void CheckError(int value);

        /// @brief 標準ライブラリ関数の戻り値を確認
        /// @param value APIの戻り値
        /// @throws CStdException: valueが(size_t)EOFのとき
        static void CheckError(size_t value);

        /// @brief errnoを取得
        [[nodiscard]]
        static int LastError() noexcept;

        /// @brief errnoを設定
        /// @param value 設定する値
        static void LastError(int value) noexcept;
    };
}

#endif //!KONGKONG_CSTD_CSTDCRRORCHECKER_H
