//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::IO
{
    FileWriter::FileWriter(const char* fileName) : OutputDevice(IOHelper::OpenFileWriter(fileName))
    {
    }

    FileWriter::FileWriter(const char* fileName, FileOpen openMode) : OutputDevice(IOHelper::OpenFileWriter(fileName, openMode))
    {
    }

    FileWriter::FileWriter(const char* fileName, FileOpen openMode, FileMode mode) : OutputDevice(IOHelper::OpenFileWriter(fileName, openMode, mode))
    {
    }

    FileWriter::FileWriter(const char* fileName, FileMode mode) : OutputDevice(IOHelper::OpenFileWriter(fileName, mode))
    {
    }

    FileWriter::FileWriter(CharString const& fileName) : OutputDevice(IOHelper::OpenFileWriter(fileName.c_str()))
    {
    }

    FileWriter::FileWriter(CharString const& fileName, FileOpen openMode) : OutputDevice(IOHelper::OpenFileWriter(fileName.c_str(), openMode))
    {
    }

    FileWriter::FileWriter(CharString const& fileName, FileOpen openMode, FileMode mode) : OutputDevice(IOHelper::OpenFileWriter(fileName.c_str(), openMode, mode))
    {
    }

    FileWriter::FileWriter(CharString const& fileName, FileMode mode) : OutputDevice(IOHelper::OpenFileWriter(fileName.c_str(), mode))
    {
    }
}
