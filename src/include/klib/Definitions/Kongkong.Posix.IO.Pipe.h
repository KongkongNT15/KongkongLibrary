#ifndef KONGKONG_POSIX_IO_PIPE_H
#define KONGKONG_POSIX_IO_PIPE_H

#include "Base.h"
#include "Kongkong.HandleType.h"
#include "Kongkong.Posix.IO.InputDevice.h"
#include "Kongkong.Posix.IO.OutputDevice.h"

namespace KONGKONG_NAMESPACE::Posix::IO
{
    class Pipe final : public HandleType {
        public:

        Pipe();

        /// @brief nullptrとして作成
        constexpr Pipe(std::nullptr_t) noexcept : _in(nullptr), _out(nullptr) {}

        void Close();

        [[nodiscard]]
        constexpr bool IsOpen() const noexcept { return _in.IsOpen(); }

        [[nodiscard]]
        constexpr InputDevice const& In() const noexcept { return _in; }

        [[nodiscard]]
        constexpr OutputDevice const& Out() const noexcept { return _out; }

        [[nodiscard]]
        String ToString() const;

        private:
        InputDevice _in;
        OutputDevice _out;

        friend constexpr bool operator==(Pipe const&, std::nullptr_t) noexcept;
        friend constexpr bool operator==(std::nullptr_t, Pipe const&) noexcept;
        friend constexpr bool operator!=(Pipe const&, std::nullptr_t) noexcept;
        friend constexpr bool operator!=(std::nullptr_t, Pipe const&) noexcept;
    };

    [[nodiscard]] constexpr bool operator==(Pipe const& left, std::nullptr_t) noexcept { return left._in.IsOpen(); }
    [[nodiscard]] constexpr bool operator==(std::nullptr_t, Pipe const& right) noexcept { return right._in.IsOpen(); }
    [[nodiscard]] constexpr bool operator!=(Pipe const& left, std::nullptr_t) noexcept { return !left._in.IsOpen(); }
    [[nodiscard]] constexpr bool operator!=(std::nullptr_t, Pipe const& right) noexcept { return !right._in.IsOpen(); }
}

#endif //!KONGKONG_POSIX_IO_PIPE_H
