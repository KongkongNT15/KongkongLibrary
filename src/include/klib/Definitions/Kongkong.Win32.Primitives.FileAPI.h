#ifndef KONGKONG_WIN32_PRIMITIVES_FILEAPI_H
#define KONGKONG_WIN32_PRIMITIVES_FILEAPI_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    //<fileapi.h>
    //https://learn.microsoft.com/ja-jp/windows/win32/api/fileapi/
    class FileAPI final {
        public:

        STATIC_CLASS(FileAPI)

        [[nodiscard]] static constexpr uint32_t MaxPathLength() noexcept { return MAX_PATH; }

        [[nodiscard]] static bool AreFileApisANSI() noexcept;

        [[nodiscard]] static ::HANDLE Create(const char16_t* fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, ::SECURITY_ATTRIBUTES& securityAttributes, IO::FileOpenMode fileOpenMode, IO::FileAttribute attribute, IO::FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile);
        [[nodiscard]] static ::HANDLE Create(const char16_t* fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, IO::FileOpenMode fileOpenMode, IO::FileAttribute attribute, IO::FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile);
        [[nodiscard]] static ::HANDLE Create(const char16_t* fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, IO::FileOpenMode fileOpenMode, IO::FileAttribute attribute, IO::FileFlag flag, SecurityFlag securityFlag);
        [[nodiscard]] static ::HANDLE Create(const char16_t* fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, IO::FileOpenMode fileOpenMode, IO::FileAttribute attribute, IO::FileFlag flag);
        [[nodiscard]] static ::HANDLE Create(const char16_t* fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, IO::FileOpenMode fileOpenMode);
        [[nodiscard]] static ::HANDLE Create(const char16_t* fileName, IO::FileAccessMode fileAccessMode, IO::FileOpenMode fileOpenMode);
        [[nodiscard]] static ::HANDLE Create(String const& fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, ::SECURITY_ATTRIBUTES& securityAttributes, IO::FileOpenMode fileOpenMode, IO::FileAttribute attribute, IO::FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile);
        [[nodiscard]] static ::HANDLE Create(String const& fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, IO::FileOpenMode fileOpenMode, IO::FileAttribute attribute, IO::FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile);
        [[nodiscard]] static ::HANDLE Create(String const& fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, IO::FileOpenMode fileOpenMode, IO::FileAttribute attribute, IO::FileFlag flag, SecurityFlag securityFlag);
        [[nodiscard]] static ::HANDLE Create(String const& fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, IO::FileOpenMode fileOpenMode, IO::FileAttribute attribute, IO::FileFlag flag);
        [[nodiscard]] static ::HANDLE Create(String const& fileName, IO::FileAccessMode fileAccessMode, IO::FileShareMode shareMode, IO::FileOpenMode fileOpenMode);
        [[nodiscard]] static ::HANDLE Create(String const& fileName, IO::FileAccessMode fileAccessMode, IO::FileOpenMode fileOpenMode);

        /// @brief ふぁ！？っく
        static void Delete(std::nullptr_t) = delete;

        static void Delete(String const& fileName);
        static void Delete(char16_t const* fileName);

        /// @brief ふぁ！？っく
        static void FindClose(std::nullptr_t) = delete;

        static void FindClose(::HANDLE hFindFile);

        /// @brief ふぁ！？っく
        static void FlushBuffers(std::nullptr_t) = delete;

        static void FlushBuffers(::HANDLE hFile);

        [[nodiscard]] static IO::DriveKind GetCurrentDriveKind() noexcept;
        [[nodiscard]] static IO::DriveKind GetDriveKind(const char16_t* rootPathName) noexcept;
        [[nodiscard]] static IO::DriveKind GetDriveKind(String const& rootPathName) noexcept;

        [[nodiscard]] static IO::FileAttribute GetFileAttributes(const char16_t* fileName);
        [[nodiscard]] static IO::FileAttribute GetFileAttributes(String const& fileName);

        /// @brief ふぁ！？っく
        static int64_t GetFileSize(std::nullptr_t) = delete;

        [[nodiscard]]
        static int64_t GetFileSize(::HANDLE hFile);

        /// @brief ふぁ！？っく
        static int64_t GetFileSizeUnsafe(std::nullptr_t) = delete;

        [[nodiscard]]
        static int64_t GetFileSizeUnsafe(::HANDLE hFile) noexcept;

        static IO::FileType GetFileType(std::nullptr_t) = delete;

        [[nodiscard]]
        static IO::FileType GetFileType(::HANDLE hFile);

        static IO::FileType GetFileTypeUnsafe(std::nullptr_t) = delete;

        [[nodiscard]]
        static IO::FileType GetFileTypeUnsafe(::HANDLE hFile) noexcept;

        [[nodiscard]] static String GetFinalPathName(::HANDLE hFile);
        [[nodiscard]] static String GetFinalPathName(::HANDLE hFile, IO::FileNameKind fileNameType);
        [[nodiscard]] static String GetFinalPathName(::HANDLE hFile, IO::VolumeNameKind volumeNameType);
        [[nodiscard]] static String GetFinalPathName(::HANDLE hFile, IO::FileNameKind fileNameType, IO::VolumeNameKind volumeNameType);

        [[nodiscard]] static FILETIME LocalFileTimeToFileTime(::FILETIME const& value);

        [[nodiscard]] static Collections::IArray<String> LogicalDrives();

        /// @brief ふぁ！？っく
        static uint8_t Read(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static uint8_t Read(std::nullptr_t, ::OVERLAPPED&) = delete;

        [[nodiscard]] static uint8_t Read(::HANDLE hFileHandle);
        [[nodiscard]] static uint8_t Read(::HANDLE hFileHandle, ::OVERLAPPED& overlapped);

        [[nodiscard]] static Collections::IArray<uint8_t> Read(::HANDLE hFileHandle, uint32_t length);
        [[nodiscard]] static Collections::IArray<uint8_t> Read(::HANDLE hFileHandle, uint32_t length, ::OVERLAPPED& overlapped);

        /// @brief ふぁ！？っく
        static uint8_t ReadUnsafe(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static uint8_t ReadUnsafe(std::nullptr_t, ::OVERLAPPED&) = delete;

        [[nodiscard]] static uint8_t ReadUnsafe(::HANDLE hFileHandle) noexcept;
        [[nodiscard]] static uint8_t ReadUnsafe(::HANDLE hFileHandle, ::OVERLAPPED& overlapped) noexcept;

        //からのフォルダを削除
        static void RemoveDirectory(const char16_t* directoryName);
        static void RemoveDirectory(String const& directoryName);

        static void SetFileAttributes(const char16_t* fileName, IO::FileAttribute attributes);
        static void SetFileAttributes(String const& fileName, IO::FileAttribute attributes);

        [[nodiscard]] static String TempPath();

        static void Write(::HANDLE hFile, uint8_t value);
        static uint32_t Write(::HANDLE hFile, const void* buffer, uint32_t length);
        static void Write(::HANDLE hFile, uint8_t value, ::OVERLAPPED& overlapped);
        static uint32_t Write(::HANDLE hFile, const void* buffer, uint32_t length, ::OVERLAPPED& overlapped);

        static bool WriteUnsafe(::HANDLE hFile, uint8_t value) noexcept;
        static uint32_t WriteUnsafe(::HANDLE hFile, const void* buffer, uint32_t length) noexcept;

    };
}

#endif //!KONGKONG_WIN32_PRIMITIVES_FILEAPI_H
