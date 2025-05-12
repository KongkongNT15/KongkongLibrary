#ifndef KONGKONG_POSIX_IO_IOHELPER_H
#define KONGKONG_POSIX_IO_IOHELPER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Posix::IO
{
    class IOHelper final {
        public:

        STATIC_CLASS(IOHelper)

        /// @brief ふぁ！？っく
        static int OpenFileReader(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static int OpenFileReader(std::nullptr_t, FileOpen) = delete;

        /// @brief ふぁ！？っく
        static int OpenFileReader(std::nullptr_t, FileOpen, FileMode) = delete;

        /// @brief ふぁ！？っく
        static int OpenFileReader(std::nullptr_t, FileMode) = delete;

        [[nodiscard]]
        static int OpenFileReader(const char* fileName);

        [[nodiscard]]
        static int OpenFileReader(const char* fileName, FileOpen openMode);

        [[nodiscard]]
        static int OpenFileReader(const char* fileName, FileOpen openMode, FileMode mode);

        [[nodiscard]]
        static int OpenFileReader(const char* fileName, FileMode mode);

        [[nodiscard]]
        static int OpenFileReader(CharString const& fileName);

        [[nodiscard]]
        static int OpenFileReader(CharString const& fileName, FileOpen openMode);

        [[nodiscard]]
        static int OpenFileReader(CharString const& fileName, FileOpen openMode, FileMode mode);

        [[nodiscard]]
        static int OpenFileReader(CharString const& fileName, FileMode mode);

        /// @brief ふぁ！？っく
        static int OpenFileRW(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static int OpenFileRW(std::nullptr_t, FileOpen) = delete;

        /// @brief ふぁ！？っく
        static int OpenFileRW(std::nullptr_t, FileOpen, FileMode) = delete;

        /// @brief ふぁ！？っく
        static int OpenFileRW(std::nullptr_t, FileMode) = delete;

        [[nodiscard]]
        static int OpenFileRW(const char* fileName);

        [[nodiscard]]
        static int OpenFileRW(const char* fileName, FileOpen openMode);

        [[nodiscard]]
        static int OpenFileRW(const char* fileName, FileOpen openMode, FileMode mode);

        [[nodiscard]]
        static int OpenFileRW(const char* fileName, FileMode mode);

        [[nodiscard]]
        static int OpenFileRW(CharString const& fileName);

        [[nodiscard]]
        static int OpenFileRW(CharString const& fileName, FileOpen openMode);

        [[nodiscard]]
        static int OpenFileRW(CharString const& fileName, FileOpen openMode, FileMode mode);

        [[nodiscard]]
        static int OpenFileRW(CharString const& fileName, FileMode mode);

        /// @brief ふぁ！？っく
        static int OpenFileWriter(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static int OpenFileWriter(std::nullptr_t, FileOpen) = delete;

        /// @brief ふぁ！？っく
        static int OpenFileWriter(std::nullptr_t, FileOpen, FileMode) = delete;

        /// @brief ふぁ！？っく
        static int OpenFileWriter(std::nullptr_t, FileMode) = delete;

        [[nodiscard]]
        static int OpenFileWriter(const char* fileName);

        [[nodiscard]]
        static int OpenFileWriter(const char* fileName, FileOpen openMode);

        [[nodiscard]]
        static int OpenFileWriter(const char* fileName, FileOpen openMode, FileMode mode);

        [[nodiscard]]
        static int OpenFileWriter(const char* fileName, FileMode mode);

        [[nodiscard]]
        static int OpenFileWriter(CharString const& fileName);

        [[nodiscard]]
        static int OpenFileWriter(CharString const& fileName, FileOpen openMode);

        [[nodiscard]]
        static int OpenFileWriter(CharString const& fileName, FileOpen openMode, FileMode mode);

        [[nodiscard]]
        static int OpenFileWriter(CharString const& fileName, FileMode mode);

        /// @brief ふぁ！？っく
        static ssize_t Read(int, size_t, std::nullptr_t) = delete;

        static bool Read(int ioDevice, uint8_t& target);
        static ssize_t Read(int ioDevice, ssize_t bufferCount, void* buffer);

        /// @brief ふぁ！？っく
        static ssize_t ReadUnsafe(int, ssize_t, std::nullptr_t) = delete;

        static bool ReadUnsafe(int ioDevice, uint8_t& target) noexcept;
        static ssize_t ReadUnsafe(int ioDevice, ssize_t bufferCount, void* buffer) noexcept;

        /// @brief ふぁ！？っく
        static ssize_t Write(int, ssize_t, std::nullptr_t) = delete;

        static bool Write(int ioDevice, uint8_t data);
        static ssize_t Write(int ioDevice, ssize_t bufferCount, const void* buffer);

        /// @brief ふぁ！？っく
        static ssize_t WriteUnsafe(int, ssize_t, std::nullptr_t) = delete;

        static bool WriteUnsafe(int ioDevice, uint8_t data) noexcept;
        static ssize_t WriteUnsafe(int ioDevice, ssize_t bufferCount, const void* buffer) noexcept;
    };
}

#endif //!KONGKONG_POSIX_IO_IOHELPER_H
