//このObjective-C++ファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Streams
{
    NSInputStream::NSInputStream(NSString const& filePath) : NSStream(nullptr)
    {
        ArgumentNullException::CheckNull(filePath, u"filePath");

        auto p = [::NSInputStream alloc];

        MemoryAllocationException::CheckNull(p);

        p = [p initWithFileAtPath:(::NSString*)NSObjectHelper::GetPointer(filePath)];

        if (p == nil) [[unlikely]] {
            bool isDirectory;
            if (FileSystem::NSFileManager::DefaultManager().PathExists(filePath, isDirectory)) {
                if (isDirectory) throw IOException(u"指定されたパスはディレクトリです");
                else throw IOException(u"ファイルを開けませんでした");
            }
            else {
                throw IO::Storage::FileNotFoundException(u"指定されたパスが見つかりませんでした");
            }
        }

        NSObjectHelper::SetPointer(*this, p);
    }
}

