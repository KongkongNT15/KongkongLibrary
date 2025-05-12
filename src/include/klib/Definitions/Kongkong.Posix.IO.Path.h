#ifndef KONGKONG_POSIX_IO_PATH_H
#define KONGKONG_POSIX_IO_PATH_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Posix::IO
{
    class Path final {
        public:

        STATIC_CLASS(Path)

        /// @brief Pathを結合
        /// @param left Path
        /// @param right Path
        /// @return 結合したPath
        [[nodiscard]]
        static CharString Combine(CharStringView const& left, CharStringView const& right);

        /// @brief ふぁ！？っく
        static bool Exists(std::nullptr_t) = delete;

        [[nodiscard]]
        static bool Exists(const char* path) noexcept;

        [[nodiscard]]
        static bool Exists(std::string const& path) noexcept;

        [[nodiscard]]
        static bool Exists(String const& path) noexcept;

        /// @brief ふぁ！？っく
        static FileMode GetFileType(std::nullptr_t) = delete;

        [[nodiscard]]
        static FileMode GetFileType(const char* path);

        [[nodiscard]]
        static FileMode GetFileType(std::string const& path);

        [[nodiscard]]
        static FileMode GetFileType(String const& path);

        [[nodiscard]]
        static constexpr size_t MaxPathLength() noexcept { return PATH_MAX; }

        private:
        static void _checkPath(CharStringView const& path);
    };
}

#endif //!KONGKONG_POSIX_IO_PATH_H
