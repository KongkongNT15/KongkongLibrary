#ifndef KONGKONG_WIN32_ENVIRONMENT_H
#define KONGKONG_WIN32_ENVIRONMENT_H

#include "Base.h"
#include "Kongkong.GenericString.h"

namespace KONGKONG_NAMESPACE::Win32
{
    class Environment final {
        public:

        STATIC_CLASS(Environment)

        /// @brief ふぁ！？っく
        static void CurrentDirectory(std::nullptr_t) = delete;

        [[nodiscard]] static String CurrentDirectory();
        static void CurrentDirectory(const char16_t* path);
        static void CurrentDirectory(String const& path);

        //すべての環境変数の値を取得
        [[nodiscard]] static Collections::IArray<String> GetStrings();

        /// @brief ふぁ！？っく
        static Collections::IArray<String> GetVariable(std::nullptr_t) = delete;

        //変数の値を取得
        [[nodiscard]] static Collections::IArray<String> GetVariable(const char16_t* name);
        [[nodiscard]] static Collections::IArray<String> GetVariable(String const& name);

        //32bitプロセスかどうか
        [[nodiscard]] static constexpr bool Is32BitProcess() noexcept { return sizeof(size_t) == sizeof(uint32_t); }
        //64bitプロセスかどうか
        [[nodiscard]] static constexpr bool Is64BitProcess() noexcept { return sizeof(size_t) == sizeof(uint64_t); }

        //改行文字
        [[nodiscard]] 
        static constexpr String const& NewLine() noexcept { return _newLine; }

        //ディレクトリの区切り文字
        [[nodiscard]] static constexpr char16_t PathSeparator() noexcept { return u'\\'; }

        [[nodiscard]]
        static uint32_t PhysicalProcessorCount();

        [[nodiscard]]
        static uint32_t ProcessorCount() noexcept;

        /// @brief ふぁ！？っく
        static void SetVariable(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static void SetVariable(String const&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static void SetVariable(std::nullptr_t, String const&) = delete;

        //変数に値を追加
        static void SetVariable(const char16_t* name, const char16_t* value);
        static void SetVariable(String const& name, const char16_t* value);
        static void SetVariable(const char16_t* name, String const& value);
        static void SetVariable(String const& name, String const& value);

        [[nodiscard]] static String SystemDirectory();

        //OSのバージョン情報
        [[nodiscard]] static OSVersionInfo SystemVersion();

        //Windowsフォルダのパスを取得
        //C:\Windows
        [[nodiscard]] static String WindowsDirectory();

        private:
        static String _newLine;
        
    };
}

#endif //!KONGKONG_WIN32_ENVIRONMENT_H
