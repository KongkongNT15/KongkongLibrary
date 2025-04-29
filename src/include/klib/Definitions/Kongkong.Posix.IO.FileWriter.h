#ifndef KONGKONG_POSIX_IO_FILEWRITER_H
#define KONGKONG_POSIX_IO_FILEWRITER_H

#include "Base.h"
#include "Kongkong.Posix.IO.OutputDevice.h"

namespace KONGKONG_NAMESPACE::Posix::IO
{
    class FileWriter final : public OutputDevice {

        using OutputDevice::OutputDevice;

        /// @brief ふぁ！？っく
        explicit FileWriter(std::nullptr_t, FileOpen) = delete;

        /// @brief ふぁ！？っく
        explicit FileWriter(std::nullptr_t, FileOpen, FileMode) = delete;

        /// @brief ふぁ！？っく
        explicit FileWriter(std::nullptr_t, FileMode) = delete;

        explicit FileWriter(const char* fileName);
        explicit FileWriter(const char* fileName, FileOpen openMode);
        explicit FileWriter(const char* fileName, FileOpen openMode, FileMode mode);
        explicit FileWriter(const char* fileName, FileMode mode);
        explicit FileWriter(CharString const& fileName);
        explicit FileWriter(CharString const& fileName, FileOpen openMode);
        explicit FileWriter(CharString const& fileName, FileOpen openMode, FileMode mode);
        explicit FileWriter(CharString const& fileName, FileMode mode);
    };
}

#endif //!KONGKONG_POSIX_IO_FILEWRITER_H
