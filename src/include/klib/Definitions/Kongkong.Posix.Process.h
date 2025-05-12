#ifndef KONGKONG_POSIX_PROCESS_H
#define KONGKONG_POSIX_PROCESS_H

#include "Base.h"
#include "Kongkong.Object.h"

namespace KONGKONG_NAMESPACE::Posix::IMPLEMENTATION
{
    struct Process final : public ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object {
        using ProjType = ::KONGKONG_NAMESPACE::Posix::Process;

        [[nodiscard]]
        static Process::ProjType const& Current();

        [[noreturn]]
        static void Exit(int status) noexcept;

        

        int Run();

        String ToString() const override;

        private:
        static Process::ProjType _current;

        //Current用
        Process(bool);

        friend ProjType;
    };
}

namespace KONGKONG_NAMESPACE::Posix
{
    class Process final : public Object {
        public:
        using ImplType = IMPLEMENTATION::Process;

        [[nodiscard]]
        static Process const& Current();

        [[noreturn]]
        static void Exit(int status) noexcept;

        /// @brief nullptrとして作成
        constexpr Process(std::nullptr_t) noexcept : Object(nullptr) {}

        

        private:
        //Current用
        Process(bool);

        friend ImplType;
    };
}

#endif //!KONGKONG_POSIX_PROCESS_H
