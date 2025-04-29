#ifndef KONGKONG_POSIX_IO_DIRECTORY_H
#define KONGKONG_POSIX_IO_DIRECTORY_H

#include "Base.h"

#include <string>

namespace KONGKONG_NAMESPACE::Posix::IO
{
    class Directory final {
        public:
        STATIC_CLASS(Directory)

        /// @brief ふぁ！？っく
        static void Create(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static void Create(std::nullptr_t, FileMode) = delete;

        static void Create(const char* directoryName);
        static void Create(std::string const& directoryName);
        static void Create(String const& directoryName);
        static void Create(const char* directoryName, FileMode mode);
        static void Create(std::string const& directoryName, FileMode mode);
        static void Create(String const& directoryName, FileMode mode);

        /// @brief ふぁ！？っく
        static bool Exists(std::nullptr_t) = delete;

        static bool Exists(const char* path) noexcept;
        static bool Exists(std::string const& path) noexcept;
        static bool Exists(String const& path);

        /// @brief ふぁ！？っく
        static Collections::IArray<FileInfo> GetChildren(std::nullptr_t) = delete;
    
        static Collections::IArray<FileInfo> GetChildren(const char* directoryName);
        static Collections::IArray<FileInfo> GetChildren(std::string const& directoryName);
        static Collections::IArray<FileInfo> GetChildren(String const& directoryName);

        /// @brief ふぁ！？っく
        static Collections::IArray<FileInfo> GetDirectories(std::nullptr_t) = delete;

        static Collections::IArray<FileInfo> GetDirectories(const char* directoryName);
        static Collections::IArray<FileInfo> GetDirectories(std::string const& directoryName);
        static Collections::IArray<FileInfo> GetDirectories(String const& directoryName);

        /// @brief ふぁ！？っく
        static Collections::IArray<FileInfo> GetFiles(std::nullptr_t) = delete;

        static Collections::IArray<FileInfo> GetFiles(const char* directoryName);
        static Collections::IArray<FileInfo> GetFiles(std::string const& directoryName);
        static Collections::IArray<FileInfo> GetFiles(String const& directoryName);

        /// @brief ふぁ！？っく
        static void Remove(std::nullptr_t) = delete;
    
        static void Remove(const char* directoryName);
        static void Remove(const char16_t* directoryName);
        static void Remove(String const& directoryName);
    };
}

#endif //!KONGKONG_POSIX_IO_DIRECTORY_H
