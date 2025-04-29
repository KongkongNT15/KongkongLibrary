#ifndef KONGKONG_WIN32_IO_INPUTDEVICE_H
#define KONGKONG_WIN32_IO_INPUTDEVICE_H

#include "Base.h"
#include "Kongkong.Win32.IO.IODevice.h"

namespace KONGKONG_NAMESPACE::Win32::IO
{
    class InputDevice : public IODevice {
        public:

        /// @brief nullptrとして作成
        constexpr InputDevice(std::nullptr_t) noexcept : IODevice(nullptr) {}

        [[nodiscard]]
        int64_t GetLengthUnsafe() const noexcept;

        [[nodiscard]]
        int64_t Length() const;

        [[nodiscard]]
        uint8_t ReadData() const;

        [[nodiscard]]
        Collections::IArray<uint8_t> ReadData(uint32_t length) const;

        [[nodiscard]]
        uint8_t ReadDataUnsafe() const noexcept;
    };
}

#endif //!KONGKONG_WIN32_IO_INPUTDEVICE_H
