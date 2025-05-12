#ifndef KONGKONG_POSIX_ENVIRONMENT_H
#define KONGKONG_POSIX_ENVIRONMENT_H

#include "Base.h"
#include "Kongkong.GenericString.h"

namespace KONGKONG_NAMESPACE::Posix
{
    class Environment final {
        public:

        STATIC_CLASS(Environment)

        [[nodiscard]]
        static String CurrentDirectory();

        [[nodiscard]]
        static CharString CurrentDirectoryCharString();

        /// @brief ふぁ！？っく
        static void CurrentDirectory(std::nullptr_t) = delete;

        static void CurrentDirectory(String const& value);
        static void CurrentDirectory(const char16_t* value);
        static void CurrentDirectory(std::string const& value);
        static void CurrentDirectory(const char* value);

        [[nodiscard]]
        static constexpr String const& NewLine() noexcept { return _newLine; }

        //ディレクトリの区切り文字
        [[nodiscard]]
        static constexpr char16_t PathSeparator() noexcept { return u'/'; }

        [[nodiscard]]
        static uint32_t PhysicalProcessorCount() noexcept;

        [[nodiscard]]
        static uint32_t ProcessorCount() noexcept;

        static String _newLine;
    };
}

#endif //!KONGKONG_POSIX_ENVIRONMENT_H
