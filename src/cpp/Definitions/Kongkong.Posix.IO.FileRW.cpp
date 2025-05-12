//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::IO
{
    FileRW::FileRW(const char* fileName) : RWDevice(IOHelper::OpenFileRW(fileName))
    {
    }

    FileRW::FileRW(const char* fileName, FileOpen openMode) : RWDevice(IOHelper::OpenFileRW(fileName, openMode))
    {
    }

    FileRW::FileRW(const char* fileName, FileOpen openMode, FileMode mode) : RWDevice(IOHelper::OpenFileRW(fileName, openMode, mode))
    {
    }

    FileRW::FileRW(const char* fileName, FileMode mode) : RWDevice(IOHelper::OpenFileRW(fileName, mode))
    {
    }

    FileRW::FileRW(CharString const& fileName) : RWDevice(IOHelper::OpenFileRW(fileName.c_str()))
    {
    }

    FileRW::FileRW(CharString const& fileName, FileOpen openMode) : RWDevice(IOHelper::OpenFileRW(fileName.c_str(), openMode))
    {
    }

    FileRW::FileRW(CharString const& fileName, FileOpen openMode, FileMode mode) : RWDevice(IOHelper::OpenFileRW(fileName.c_str(), openMode, mode))
    {
    }

    FileRW::FileRW(CharString const& fileName, FileMode mode) : RWDevice(IOHelper::OpenFileRW(fileName.c_str(), mode))
    {
    }
}
