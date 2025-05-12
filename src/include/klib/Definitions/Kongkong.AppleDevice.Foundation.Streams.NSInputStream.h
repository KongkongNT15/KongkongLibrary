#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_STREAMS_NSINPUTSTREAM_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_STREAMS_NSINPUTSTREAM_H

#include "Base.h"
#include "Kongkong.AppleDevice.Foundation.Streams.NSStream.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Streams
{
    class NSInputStream : public NSStream {
        public:

        /// @brief ファイルストリームとして作成
        /// @param filePath ファイルパス
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        /// @throws IOException: 指定されたパスがディレクトリの時
        /// @throws IOException: ファイルを開けなかった時
        /// @throws IO::Storage::FileNotFoundException: 指定されたパスが見つからなかった時
        NSInputStream(NSString const& filePath);

        //NSInputStream(NSData);

        /// @brief nullptrとして作成
        constexpr NSInputStream(std::nullptr_t) noexcept : NSStream(nullptr) {}
    };
}


#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_STREAMS_NSINPUTSTREAM_H
