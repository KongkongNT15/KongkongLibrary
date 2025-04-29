#ifndef KONGKONG_POSIX_IO_DIRECTORYITERATOR_H
#define KONGKONG_POSIX_IO_DIRECTORYITERATOR_H

#include "Base.h"
#include "Kongkong.Collections.Iterators.ConstArrayIterator.h"
#include "Kongkong.Posix.IO.DirectoryEntry.h"

namespace KONGKONG_NAMESPACE::Posix::IO::IMPLEMENTATION
{
    struct DirectoryIterator final : public Collections::Iterators::IMPLEMENTATION::ConstIterator<DirectoryEntry> {
        
        DirectoryIterator();
        DirectoryIterator(::dirent* dirent, ::DIR* dir, const char* directoryName);

        ~DirectoryIterator();

        bool IsNotEqual(ConstIterator<DirectoryEntry> const& right) const override;
        constexpr DirectoryEntry const& Current() const override { return _entry; }

        void Increment() override;

        [[noreturn]]
        ::KONGKONG_NAMESPACE::Collections::Iterators::ConstIterator<DirectoryEntry> Increment(int) override;

        String ToString() const override;

        private:
        DirectoryEntry _entry;
        ::DIR* _dir;
    };

}

namespace KONGKONG_NAMESPACE::Posix::IO
{
    class DirectoryIterator final : public Collections::Iterators::ConstIterator<DirectoryEntry> {
        public:
        using ImplType = IMPLEMENTATION::DirectoryIterator;

        DirectoryIterator();
        DirectoryIterator(::dirent* dirent, ::DIR* dir, const char* directoryName);
        
        /// @brief nullptrとして作成
        constexpr DirectoryIterator(std::nullptr_t) noexcept : ConstIterator(nullptr) {}
    };
}

#endif //!KONGKONG_POSIX_IO_DIRECTORYITERATOR_H
