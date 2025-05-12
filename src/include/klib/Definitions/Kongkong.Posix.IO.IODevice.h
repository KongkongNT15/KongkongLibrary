#ifndef KONGKONG_POSIX_IO_IODEVICE_H
#define KONGKONG_POSIX_IO_IODEVICE_H

#include "Base.h"
#include "Kongkong.HandleType.h"
#include "Kongkong.InvalidCastException.h"

namespace KONGKONG_NAMESPACE::Posix::IO
{
    class IODevice : public HandleType {
        public:
        /// @brief nullptrとして作成
        constexpr IODevice(std::nullptr_t) noexcept : _h(nullptr) {}

        [[nodiscard]]
        constexpr operator bool() const noexcept { return _h.__fd != _ioDeviceHandle::__closedFd; }

        [[nodiscard]]
        constexpr bool operator!() const noexcept { return _h.__fd == _ioDeviceHandle::__closedFd; }

        template <class TIODevice> requires ::std::derived_from<TIODevice, IODevice>
        [[nodiscard]] TIODevice As() const noexcept
        {
            TIODevice ioDevice = nullptr;

            ioDevice._h = _h;

            return ioDevice;
        }

        template <class TIODevice> requires ::std::derived_from<TIODevice, IODevice>
        [[nodiscard]] TIODevice Cast() const
        {
            if (!Is<TIODevice>()) throw InvalidCastException();

            return As<TIODevice>();
        }

        [[nodiscard]]
        ::off_t CurrentPosition() const;

        [[nodiscard]]
        FileMode Mode() const;

        template <class TIODevice> requires ::std::derived_from<TIODevice, IODevice>
        bool Is() const noexcept;

        ::off_t Seek(::off_t offset, Standard::CFilePosition position) const;

        void Close();

        [[nodiscard]]
        constexpr bool IsOpen() const noexcept { return _h.__fd != _ioDeviceHandle::__closedFd; }

        String ToString() const;

        protected:

        struct _ioDeviceHandle final {

            constexpr _ioDeviceHandle(std::nullptr_t) : __fd(__closedFd) {}
            constexpr _ioDeviceHandle(int fd) noexcept : __fd(fd) {}
            _ioDeviceHandle(_ioDeviceHandle const& right);
            constexpr _ioDeviceHandle(_ioDeviceHandle&& right) noexcept : __fd(right.__fd) { right.__fd = __closedFd; }

            ~_ioDeviceHandle();

            _ioDeviceHandle& operator=(_ioDeviceHandle const& right);
            _ioDeviceHandle& operator=(_ioDeviceHandle&& right) noexcept;

            int __fd;

            static constexpr int __closedFd = EOF;
        };

        _ioDeviceHandle _h;

        constexpr IODevice(int fd) noexcept : _h(fd) {}

        private:

        FileOpen _mode() const noexcept;

        static bool _isInputDevice(FileMode mode) noexcept;
        static bool _isOutputDevice(FileMode mode) noexcept;
        static bool _isRWDevice(FileMode mode) noexcept;

        static bool _isFileDevice(FileMode mode) noexcept;


        friend Pipe;

        friend constexpr bool operator==(IODevice const&, std::nullptr_t) noexcept;
        friend constexpr bool operator==(std::nullptr_t, IODevice const&) noexcept;
        friend constexpr bool operator!=(IODevice const&, std::nullptr_t) noexcept;
        friend constexpr bool operator!=(std::nullptr_t, IODevice const&) noexcept;
    };

    [[nodiscard]] constexpr bool operator==(IODevice const& left, std::nullptr_t) noexcept { return left._h.__fd == IODevice::_ioDeviceHandle::__closedFd; }
    [[nodiscard]] constexpr bool operator==(std::nullptr_t, IODevice const& right) noexcept { return right._h.__fd == IODevice::_ioDeviceHandle::__closedFd; }
    [[nodiscard]] constexpr bool operator!=(IODevice const& left, std::nullptr_t) noexcept { return left._h.__fd != IODevice::_ioDeviceHandle::__closedFd; }
    [[nodiscard]] constexpr bool operator!=(std::nullptr_t, IODevice const& right) noexcept { return right._h.__fd != IODevice::_ioDeviceHandle::__closedFd; }
}

#endif //!KONGKONG_POSIX_IO_IODEVICE_H
