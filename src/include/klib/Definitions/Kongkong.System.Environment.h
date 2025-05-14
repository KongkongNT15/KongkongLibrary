#ifndef KONGKONG_SYSTEM_ENVIRONMENT_H
#define KONGKONG_SYSTEM_ENVIRONMENT_H

#include "Base.h"

#if KONGKONG_ENV_WINDOWS
    #include "Kongkong.Win32.Environment.h"
#elif KONGKONG_ENV_UNIX
    #include "Kongkong.Posix.Environment.h"
#else
namespace KONGKONG_NAMESPACE::System
{
    class Environment final {
        public:

        STATIC_CLASS(Environment)

        /// @brief カレントパスを取得
        static String CurrentDirectory();

        /// @brief ふぁ！？っく
        static void CurrentDirectory(std::nullptr_t) = delete;

        /// @brief カレントパスを設定
        /// @attention Windows以外の環境ではArgumentNullExceptionとIOExceptionのみスローされるよ
        /// @param path パス
        /// @throws ArgumentNullException: pathがnullptrのとき
        /// @throws ArgumentException: pathが不正な値のとき
        /// @throws DirectoryNotFoundException: 指定されたパスが見つからなかったとき
        /// @throws FormatException: パスの形式が正しくないとき
        /// @throws IOException: それ例外のエラー
        static void CurrentDirectory(const char16_t* path);

        /// @brief カレントパスを設定
        /// @param path パス
        /// @throws ArgumentException: pathが不正な値のとき
        /// @throws DirectoryNotFoundException: 指定されたパスが見つからなかったとき
        /// @throws FormatException: パスの形式が正しくないとき
        /// @throws IOException: それ例外のエラー
        static void CurrentDirectory(String const& path);

#if KONGKONG_OBJECTIVE_C_ENABLED
        static void CurrentDirectory(AppleDevice::Foundation::NSString const& path);
#endif

        /// @brief 終了コードを指定してこのプロセスを終了
        /// @param exitCode 終了コード
        static void Exit(int32_t exitCode = 0) noexcept;

        [[nodiscard]] static String const& NewLine();

    };
}

#endif
#endif //!KONGKONG_SYSTEM_ENVIRONMENT_H
