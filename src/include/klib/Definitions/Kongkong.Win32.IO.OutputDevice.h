#ifndef KONGKONG_WIN32_IO_OUTPUTDEVICE_H
#define KONGKONG_WIN32_IO_OUTPUTDEVICE_H

#include "Base.h"
#include "Kongkong.Win32.IO.IODevice.h"

#include "Kongkong.Win32.IO.FileShareMode.h"
#include "Kongkong.Win32.IO.FileAccessMode.h"
#include "Kongkong.Win32.IO.FileAttribute.h"
#include "Kongkong.Win32.IO.FileOpenMode.h"

namespace KONGKONG_NAMESPACE::Win32::IO
{
    class OutputDevice final : public IODevice {
        public:

        explicit OutputDevice(const char16_t* fileName, FileShareMode shareMode, ::SECURITY_ATTRIBUTES& securityAttributes, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile);
        explicit OutputDevice(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile);
        explicit OutputDevice(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag);
        explicit OutputDevice(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag);
        explicit OutputDevice(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode);
        explicit OutputDevice(const char16_t* fileName, FileOpenMode fileOpenMode);
        explicit OutputDevice(const char16_t* fileName, FileFlag flag);
        explicit OutputDevice(const char16_t* fileName);
        explicit OutputDevice(String const& fileName, FileShareMode shareMode, ::SECURITY_ATTRIBUTES& securityAttributes, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile);
        explicit OutputDevice(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile);
        explicit OutputDevice(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag);
        explicit OutputDevice(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag);
        explicit OutputDevice(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode);
        explicit OutputDevice(String const& fileName, FileOpenMode fileOpenMode);
        explicit OutputDevice(String const& fileName, FileFlag flag);
        explicit OutputDevice(String const& fileName);

        /// @brief nullptrとして作成
        constexpr OutputDevice(std::nullptr_t) noexcept : IODevice(nullptr) {}

        void Open(const char16_t* fileName, FileShareMode shareMode, ::SECURITY_ATTRIBUTES& securityAttributes, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile);
        void Open(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile);
        void Open(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag);
        void Open(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag);
        void Open(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode);
        void Open(const char16_t* fileName, FileOpenMode fileOpenMode);
        void Open(const char16_t* fileName, FileFlag flag);
        void Open(const char16_t* fileName);
        void Open(String const& fileName, FileShareMode shareMode, ::SECURITY_ATTRIBUTES& securityAttributes, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile);
        void Open(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile);
        void Open(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag);
        void Open(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag);
        void Open(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode);
        void Open(String const& fileName, FileOpenMode fileOpenMode);
        void Open(String const& fileName, FileFlag flag);
        void Open(String const& fileName);
    
        void Reopen(const char16_t* fileName, FileShareMode shareMode, ::SECURITY_ATTRIBUTES& securityAttributes, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile);
        void Reopen(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile);
        void Reopen(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag);
        void Reopen(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag);
        void Reopen(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode);
        void Reopen(const char16_t* fileName, FileOpenMode fileOpenMode);
        void Reopen(const char16_t* fileName);
        void Reopen(String const& fileName, FileShareMode shareMode, ::SECURITY_ATTRIBUTES& securityAttributes, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile);
        void Reopen(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile);
        void Reopen(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag);
        void Reopen(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag);
        void Reopen(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode);
        void Reopen(String const& fileName, FileOpenMode fileOpenMode);
        void Reopen(String const& fileName);

        /// @brief ふぁ！？っく
        void Write(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void Write(uint32_t, std::nullptr_t) = delete;

        /// @brief 1文字書き込む
        /// @attention u'\r'の場合はなにもしないよ
        /// @attention u'\n'の場合はu8"\r\n"を書き込むよ
        /// @param c 書き込む文字
        /// @throws HResultException: エラーが発生したとき
        void Write(char16_t c) const;

        /// @brief 文字列を書き込む
        /// @param str 書き込む文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws HResultException: エラーが発生したとき
        void Write(const char16_t* str) const;

        /// @brief 文字列を書き込む
        /// @param length 文字数
        /// @param str 書き込む文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws HResultException: エラーが発生したとき
        void Write(uint32_t length, const char16_t* str) const;

        /// @brief 文字列を書き込む
        /// @param view 文字列ビュー
        /// @throws HResultException: エラーが発生したとき
        void Write(StringView const& view) const;

        /// @brief 文字列を書き込む
        /// @param str 書き込む文字列
        /// @throws HResultException: エラーが発生したとき
        void Write(String const& str) const;

        /// @brief UTF-8文字を書き込む
        /// @attention u8'\r'の場合はなにもしないよ
        /// @attention u8'\n'の場合はu8"\r\n"を書き込むよ
        /// @param c 書き込む文字
        /// @throws HResultException: エラーが発生したとき
        void Write(char8_t c) const;

        /// @brief UTF-8文字列を書き込む
        /// @param str 書き込む文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws HResultException: エラーが発生したとき
        void Write(const char8_t* str) const;

        /// @brief UTF-8文字列を書き込む
        /// @param length 文字数
        /// @param str 書き込む文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws HResultException: エラーが発生したとき
        void Write(uint32_t length, const char8_t* str) const;

        /// @brief UTF-8文字列を書き込む
        /// @param str 書き込む文字列
        /// @throws HResultException: エラーが発生したとき
        void Write(std::u8string const& str) const;

        /// @brief UTF-8文字列を書き込む
        /// @param str 書き込む文字列
        /// @throws HResultException: エラーが発生したとき
        void Write(Utf8String const& str) const;

        /// @brief UTF-8文字列を書き込む
        /// @param str 書き込む文字列
        /// @throws HResultException: エラーが発生したとき
        void Write(Utf8StringView const& str) const;

        /// @brief データを1バイト書き込む
        /// @param value 書き込む値
        /// @throws HResultException: 操作に失敗したとき
        void WriteData(uint8_t value) const;

        /// @brief ふぁ！？っく
        void WriteData(std::nullptr_t, uint32_t) const = delete;

        /// @brief データを書き込む
        /// @param length 書き込む長さ
        /// @param buffer データ
        /// @throws ArgumentNullException: bufferがnullptrのとき
        /// @throws HResultException: 操作に失敗したとき
        void WriteData(uint32_t length, const void* buffer) const;

        /// @brief ふぁ！？っく
        void WriteDataUnsafe(std::nullptr_t, uint32_t) const = delete;

        /// @brief データを書き込む
        /// @param length 書き込む長さ
        /// @param buffer データ
        /// @throws HResultException: 操作に失敗したとき
        void WriteDataUnsafe(uint32_t length, const void* buffer) const;

        /// @brief ふぁ！？っく
        void WriteUncheckStrUnsafe(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void WriteUncheckStrUnsafe(uint32_t, std::nullptr_t) = delete;

        /// @brief 文字列を書き込む
        /// @param str 書き込む文字列
        /// @throws HResultException: エラーが発生したとき
        void WriteUncheckStrUnsafe(const char16_t* str) const;

        /// @brief UTF-8文字列を書き込む
        /// @param str 書き込む文字列
        /// @throws HResultException: エラーが発生したとき
        void WriteUncheckStrUnsafe(const char8_t* str) const;

        /// @brief UTF-8文字列を書き込む
        /// @param length 文字数
        /// @param str 書き込む文字列
        /// @throws HResultException: エラーが発生したとき
        void WriteUncheckStrUnsafe(uint32_t length, const char8_t* str) const;

        /// @brief 文字列を書き込む
        /// @param length 文字数
        /// @param str 書き込む文字列
        void WriteUncheckStrUnsafe(uint32_t length, const char16_t* str) const;

        /// @brief ふぁ！？っく
        void WriteUnsafe(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void WriteUnsafe(uint32_t, std::nullptr_t) = delete;

        /// @brief 1文字書き込む
        /// @attention u'\r'の場合はなにもしないよ
        /// @attention u'\n'の場合はu8"\r\n"を書き込むよ
        /// @param c 書き込む文字
        void WriteUnsafe(char16_t c) const noexcept;

        /// @brief 文字列を書き込む
        /// @param str 書き込む文字列
        /// @throws MemoryAllocationException: UTF-8文字列の作成に失敗したとき
        void WriteUnsafe(const char16_t* str) const;

        /// @brief 文字列を書き込む
        /// @param length 文字数
        /// @param str 書き込む文字列
        /// @throws MemoryAllocationException: UTF-8文字列の作成に失敗したとき
        void WriteUnsafe(uint32_t length, const char16_t* str) const;

        /// @brief 文字列を書き込む
        /// @param view 文字列ビュー
        /// @throws MemoryAllocationException: UTF-8文字列の作成に失敗したとき
        void WriteUnsafe(StringView const& view) const;

        /// @brief 文字列を書き込む
        /// @param str 書き込む文字列
        /// @throws MemoryAllocationException: UTF-8文字列の作成に失敗したとき
        void WriteUnsafe(String const& str) const;

        /// @brief UTF-8文字を書き込む
        /// @attention u8'\r'の場合はなにもしないよ
        /// @attention u8'\n'の場合はu8"\r\n"を書き込むよ
        /// @param c 書き込む文字
        /// @return 書き込みに成功したかどうか
        bool WriteUnsafe(char8_t c) const noexcept;

        /// @brief UTF-8文字列を書き込む
        /// @param str 書き込む文字列
        void WriteUnsafe(std::u8string const& str) const noexcept;

        /// @brief UTF-8文字列を書き込む
        /// @param str 書き込む文字列
        void WriteUnsafe(Utf8String const& str) const noexcept;

        /// @brief UTF-8文字列を書き込む
        /// @param str 書き込む文字列
        void WriteUnsafe(Utf8StringView const& str) const noexcept;

        /// @brief UTF-8文字列を書き込む
        /// @param str 書き込む文字列
        void WriteUnsafe(const char8_t* str) const noexcept;

        /// @brief UTF-8文字列を書き込む
        /// @param length 文字数
        /// @param str 書き込む文字列
        void WriteUnsafe(uint32_t length, const char8_t* str) const noexcept;

        /// @brief ふぁ！？っく
        void WriteLine(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void WriteLine(uint32_t, std::nullptr_t) = delete;

        /// @brief 改行文字を書き込む
        /// @throws HResultException: エラーが発生したとき
        void WriteLine() const;

        /// @brief 改行文字付きで文字を書き込む
        /// @attention u'\r'の場合はu8"\r\n"を書き込むよ
        /// @attention u'\n'の場合はu8"\r\n\r\n"を書き込むよ
        /// @param c 書き込む文字
        /// @throws HResultException: エラーが発生したとき
        void WriteLine(char16_t c) const;

        /// @brief 改行文字付きで文字列を書き込む
        /// @param str 書き込む文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws HResultException: エラーが発生したとき
        void WriteLine(const char16_t* str) const;

        /// @brief 改行文字付きで文字列を書き込む
        /// @param length 文字数
        /// @param str 書き込む文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws HResultException: エラーが発生したとき
        void WriteLine(uint32_t length, const char16_t* str) const;

        /// @brief 改行文字付きで文字列を書き込む
        /// @param view 文字列ビュー
        /// @throws HResultException: エラーが発生したとき
        void WriteLine(StringView const& view) const;

        /// @brief 改行文字付きで文字列を書き込む
        /// @param str 書き込む文字列
        /// @throws HResultException: エラーが発生したとき
        void WriteLine(String const& str) const;

        /// @brief 改行文字付きでUTF-8文字を書き込む
        /// @attention u8'\r'の場合はu8"\r\n"を書き込むよ
        /// @attention u8'\n'の場合はu8"\r\n\r\n"を書き込むよ
        /// @param c 書き込む文字
        /// @throws HResultException: エラーが発生したとき
        void WriteLine(char8_t c) const;

        /// @brief 改行文字付きでUTF-8文字列を書き込む
        /// @param str 書き込む文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws HResultException: エラーが発生したとき
        void WriteLine(const char8_t* str) const;

        /// @brief 改行文字付きでUTF-8文字列を書き込む
        /// @param length 文字数
        /// @param str 書き込む文字列
        /// @throws HResultException: エラーが発生したとき
        void WriteLine(uint32_t length, const char8_t* str) const;

        /// @brief 改行文字付きでUTF-8文字列を書き込む
        /// @param str 書き込む文字列
        /// @throws HResultException: エラーが発生したとき
        void WriteLine(Utf8String const& str) const;

        /// @brief 改行文字付きでUTF-8文字列を書き込む
        /// @param str 書き込む文字列
        /// @throws HResultException: エラーが発生したとき
        void WriteLine(Utf8StringView const& str) const;

        /// @brief 改行文字付きでUTF-8文字列を書き込む
        /// @param str 書き込む文字列
        /// @throws HResultException: エラーが発生したとき
        void WriteLine(std::u8string const& str) const;

        /// @brief ふぁ！？っく
        void WriteLineUnsafe(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void WriteLineUnsafe(uint32_t, std::nullptr_t) = delete;

        /// @brief 改行文字付きでUTF-8文字列を書き込む
        /// @param str 書き込む文字列
        /// @throws HResultException: エラーが発生したとき
        void WriteLineUnsafe(const char8_t* str) const;

        /// @brief 改行文字付きでUTF-8文字列を書き込む
        /// @param length 文字数
        /// @param str 書き込む文字列
        /// @throws HResultException: エラーが発生したとき
        void WriteLineUnsafe(uint32_t length, const char8_t* str) const;

        /// @brief UTF-8のBOMを書き込む
        /// @attention 必ずファイルの先頭に書いてね
        /// @throws HResultException: エラーが発生したとき
        void WriteBOM() const;

        private:
        static constexpr auto _shareMode = FileShareMode::Private;
        static constexpr auto _fileAccessMode = FileAccessMode::Write;
        static constexpr auto _fileAttribute = FileAttribute::Normal;
        static constexpr auto _fileOpenMode = FileOpenMode::CreateAlways;

        static constexpr ssize_t _maxMultiByteCharLength = 5;

        static String _toString(Handle const& handle);

        friend String Handle::ToString() const;
    };
}

#endif //!KONGKONG_WIN32_IO_OUTPUTDEVICE_H
