#ifndef KONGKONG_POSIX_IO_RWDEVICE_H
#define KONGKONG_POSIX_IO_RWDEVICE_H

#include "Base.h"
#include "Kongkong.Posix.IO.IODevice.h"

namespace KONGKONG_NAMESPACE::Posix::IO
{
    class RWDevice : public IODevice {
        public:

        using IODevice::IODevice;

        /// @brief ふぁ！？っく
        ssize_t Read(size_t, std::nullptr_t) = delete;

        bool Read(uint8_t& target) const;
        ssize_t Read(size_t bufferCount, void* buffer) const;

        /// @brief ふぁ！？っく
        ssize_t ReadUnsafe(size_t, std::nullptr_t) = delete;

        bool ReadUnsafe(uint8_t& target) const noexcept;
        ssize_t ReadUnsafe(size_t bufferCount, void* buffer) const noexcept;

        /// @brief ふぁ！？っく
        ssize_t Write(size_t, std::nullptr_t) = delete;

        bool Write(uint8_t data) const;
        ssize_t Write(ssize_t bufferCount, const void* buffer) const;

        /// @brief ふぁ！？っく
        ssize_t WriteUnsafe(size_t, std::nullptr_t) = delete;

        bool WriteUnsafe(uint8_t data) const noexcept;
        ssize_t WriteUnsafe(ssize_t bufferCount, const void* buffer) const noexcept;
    };
}

#endif //!KONGKONG_POSIX_IO_RWDEVICE_H
