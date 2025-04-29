//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::IO
{
    FileReader::FileReader(const char* fileName) : InputDevice(IOHelper::OpenFileReader(fileName))
    {
    }

    FileReader::FileReader(const char* fileName, FileOpen openMode) : InputDevice(IOHelper::OpenFileReader(fileName, openMode))
    {
    }

    FileReader::FileReader(const char* fileName, FileOpen openMode, FileMode mode) : InputDevice(IOHelper::OpenFileReader(fileName, openMode, mode))
    {
    }

    FileReader::FileReader(const char* fileName, FileMode mode) : InputDevice(IOHelper::OpenFileReader(fileName, mode))
    {
    }

    FileReader::FileReader(CharString const& fileName) : InputDevice(IOHelper::OpenFileReader(fileName))
    {
    }

    FileReader::FileReader(CharString const& fileName, FileOpen openMode) : InputDevice(IOHelper::OpenFileReader(fileName, openMode))
    {
    }

    FileReader::FileReader(CharString const& fileName, FileOpen openMode, FileMode mode) : InputDevice(IOHelper::OpenFileReader(fileName, openMode, mode))
    {
    }

    FileReader::FileReader(CharString const& fileName, FileMode mode) : InputDevice(IOHelper::OpenFileReader(fileName, mode))
    {
    }
}
