#ifndef KONGKONG_POSIX_IO_FILEREADER_H
#define KONGKONG_POSIX_IO_FILEREADER_H

#include "Base.h"
#include "Kongkong.Posix.IO.InputDevice.h"

namespace KONGKONG_NAMESPACE::Posix::IO
{
    struct FileReader : public InputDevice {

        using InputDevice::InputDevice;

        /// @brief ふぁ！？っく
        explicit FileReader(std::nullptr_t, FileOpen) = delete;

        /// @brief ふぁ！？っく
        explicit FileReader(std::nullptr_t, FileOpen, FileMode) = delete;

        /// @brief ふぁ！？っく
        explicit FileReader(std::nullptr_t, FileMode) = delete;

        explicit FileReader(const char* fileName);
        explicit FileReader(const char* fileName, FileOpen openMode);
        explicit FileReader(const char* fileName, FileOpen openMode, FileMode mode);
        explicit FileReader(const char* fileName, FileMode mode);
        explicit FileReader(CharString const& fileName);
        explicit FileReader(CharString const& fileName, FileOpen openMode);
        explicit FileReader(CharString const& fileName, FileOpen openMode, FileMode mode);
        explicit FileReader(CharString const& fileName, FileMode mode);
    };
}

#endif //!KONGKONG_POSIX_IO_FILEREADER_H
