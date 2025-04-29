#ifndef KONGKONG_WIN32_SOUND_H
#define KONGKONG_WIN32_SOUND_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    class Sound final {
        public:

        /// @brief ビープ音を再生します
        /// @param frequency 周波数
        /// @param milliseconds 再生する時間
        /// @throws HResultException: 操作に失敗したとき
        static void Beep(uint16_t frequency, uint32_t milliseconds);

        /// @brief ふぁ！？っく
        static void Play(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static void Play(std::nullptr_t, bool) = delete;

        /// @brief システムサウンドを再生
        /// @param kind サウンドの種類
        /// @param async 非同期的に処理するか
        /// @throws InvalidArgumentException: kindがふぁ！？っくなとき
        /// @throws HResultException: 操作に失敗したとき
        static void Play(SoundKind kind, bool async = false);

        /// @brief メッセージサウンドを再生
        /// @param kind 種類
        /// @throws HResultException: 操作に失敗したとき
        static void PlayMessageBeep(MessageBeepKind kind);

        /// @brief メッセージサウンドを再生
        /// @param kind 種類
        /// @return 操作に成功すればtrue
        /// @return 失敗すればfalse
        static bool PlayMessageBeepUnsafe(MessageBeepKind kind) noexcept;

        /// @brief 指定した.wavファイルを再生
        /// @param path ファイルパス
        /// @param async 非同期的に処理するか
        /// @throws HResultException: 操作に失敗したとき
        static void PlayWave(const char16_t* path, bool async = false);

        /// @brief 指定した.wavファイルを再生
        /// @param path ファイルパス
        /// @param async 非同期的に処理するか
        /// @throws HResultException: 操作に失敗したとき
        static void PlayWave(String const& path, bool async = false);
    };
}

#endif //!KONGKONG_WIN32_SOUND_H
