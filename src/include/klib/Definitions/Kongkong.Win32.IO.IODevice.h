#ifndef KONGKONG_WIN32_IO_IODEVICE_H
#define KONGKONG_WIN32_IO_IODEVICE_H

#include "Base.h"
#include "Kongkong.Win32.Handle.h"

namespace KONGKONG_NAMESPACE::Win32::IO
{
    class IODevice : public Handle {
        public:

        /// @brief nullptrとして作成
        constexpr IODevice(std::nullptr_t) noexcept : Handle(nullptr) {}

        [[nodiscard]]
        IO::FileType FileType() const;

        [[nodiscard]]
        IO::FileType GetFileTypeUnsafe() const noexcept;
    };
}

#endif //!KONGKONG_WIN32_IO_IODEVICE_H
