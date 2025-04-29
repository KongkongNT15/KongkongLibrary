#ifndef KONGKONG_WIN32_SOUNDFLAG_H
#define KONGKONG_WIN32_SOUNDFLAG_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    enum struct SoundFlag {
        Sync        = SND_SYNC,        //同期的に再生（デフォルト）
        Async       = SND_ASYNC,       //非同期的に再生
        NoDefault   = SND_NODEFAULT,   //サウンドが見つからない場合は無音にする（デフォルトサウンドは再生しない）
        Memory      = SND_MEMORY,      //pszSoundがメモリ内のファイルを指している
        Loop        = SND_LOOP,        //次のsndPlaySoundが呼ばれるまでサウンドをループ再生
        NoStop      = SND_NOSTOP,      //現在再生中のサウンドを停止しない
        NoWait      = SND_NOWAIT,      //ドライバがビジー状態の場合は待機しない
        Alias       = SND_ALIAS,       //名前はレジストリエイリアス
        AliasId     = SND_ALIAS_ID,    //エイリアスは事前定義されたID
        FileName    = SND_FILENAME,    //名前はファイル名
        Resouece    = SND_RESOURCE,    //名前はリソース名またはアトム
        Sentry      = SND_SENTRY,      //このサウンドでSoundSentryイベントを生成する
        Ring        = SND_RING,        //通信アプリケーションの「着信音」として扱う - サウンドを下げない
        System      = SND_SYSTEM,      //システムサウンドとして扱う
#if (WINVER >= 0x400)
        Purge       = SND_PURGE,       //タスクの非静的イベントを消去
        Application = SND_APPLICATION, //アプリケーション固有の関連付けを探す
#endif //WINVER >= 0x400
    };
}

#endif //!KONGKONG_WIN32_SOUNDFLAG_H
