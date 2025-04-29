#ifndef KONGKONG_WIN32_IO_FILE_H
#define KONGKONG_WIN32_IO_FILE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::IO
{
    class File final {
        public:

        STATIC_CLASS(File)

        /// @brief ふぁ！？っく
        static void Copy(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static void Copy(std::nullptr_t, String const&) = delete;

        /// @brief ふぁ！？っく
        static void Copy(String const&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static void Copy(std::nullptr_t, std::nullptr_t, bool) = delete;

        /// @brief ふぁ！？っく
        static void Copy(std::nullptr_t, String const&, bool) = delete;

        /// @brief ふぁ！？っく
        static void Copy(String const&, std::nullptr_t, bool) = delete;

        static void Copy(const char16_t* originalFilePath, const char16_t* newFilePath);
        static void Copy(const char16_t* originalFilePath, String const& newFilePath);
        static void Copy(String const& originalFilePath, const char16_t* newFilePath);
        static void Copy(String const& originalFilePath, String const& newFilePath);
        static void Copy(const char16_t* originalFilePath, const char16_t* newFilePath, bool failIfFileExists);
        static void Copy(const char16_t* originalFilePath, String const& newFilePath, bool failIfFileExists);
        static void Copy(String const& originalFilePath, const char16_t* newFilePath, bool failIfFileExists);
        static void Copy(String const& originalFilePath, String const& newFilePath, bool failIfFileExists);

        /// @brief ふぁ！？っく
        static void Delete(std::nullptr_t) = delete;

        static void Delete(const char16_t* fileName);
        static void Delete(String const& fileName);

        /// @brief ふぁ！？っく
        static void Exists(std::nullptr_t) = delete;
        
        /// @brief 指定したファイルが存在するかを確認
        /// @param filePath 
        /// @return 
        [[nodiscard]] static bool Exists(const char16_t* filePath) noexcept;
        [[nodiscard]] static bool Exists(String const& filePath) noexcept;
        

    };
}

#endif //!KONGKONG_WIN32_IO_FILE_H
