#ifndef KONGKONG_WIN32_IO_DIRECTORY_H
#define KONGKONG_WIN32_IO_DIRECTORY_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::IO
{
    //ディレクトリ操作
    class Directory final {
        public:

        STATIC_CLASS(Directory)

        /// @brief ふぁ！？っく
        static void Create(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static void Create(std::nullptr_t, ::SECURITY_ATTRIBUTES&) = delete;

        static void Create(const char16_t* path);
        static void Create(String const& path);
        static void Create(const char16_t* path, ::SECURITY_ATTRIBUTES& securityAttributes);
        static void Create(String const& path, ::SECURITY_ATTRIBUTES& securityAttributes);

        /// @brief ふぁ！？っく
        static bool Exists(std::nullptr_t) = delete;

        [[nodiscard]]
        static bool Exists(const char16_t* path) noexcept;

        [[nodiscard]]
        static bool Exists(String const& path) noexcept;

        /// @brief ふぁ！？っく
        static Collections::IArray<FileSystemInfo> GetChildren(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static Collections::IArray<FileSystemInfo> GetDirectories(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static Collections::IArray<FileSystemInfo> GetFiles(std::nullptr_t) = delete;

        [[nodiscard]] static Collections::IArray<FileSystemInfo> GetChildren(const char16_t* directoryPath);
        [[nodiscard]] static Collections::IArray<FileSystemInfo> GetChildren(String const& directoryPath);
        [[nodiscard]] static Collections::IArray<FileSystemInfo> GetDirectories(const char16_t* directoryPath);
        [[nodiscard]] static Collections::IArray<FileSystemInfo> GetDirectories(String const& directoryPath);
        [[nodiscard]] static Collections::IArray<FileSystemInfo> GetFiles(const char16_t* directoryPath);
        [[nodiscard]] static Collections::IArray<FileSystemInfo> GetFiles(String const& directoryPath);

        /// @brief ふぁ！？っく
        static bool Remove(std::nullptr_t) = delete;

        static void Remove(const char16_t* path);
        static void Remove(String const& path);

        private:
        static void _checkWildCard(String& str);
    };
}

#endif //!KONGKONG_WIN32_IO_DIRECTORY_H
