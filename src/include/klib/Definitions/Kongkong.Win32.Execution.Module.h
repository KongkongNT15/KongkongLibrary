#ifndef KONGKONG_WIN32_MODULE_H
#define KONGKONG_WIN32_MODULE_H

#include "Base.h"
#include "Kongkong.Win32.Execution.ModuleBase.h"

namespace KONGKONG_NAMESPACE::Win32::Execution
{
    class Module final : public ModuleBase {
        public:

        /// @brief ふぁ！？っく
        Module(std::nullptr_t, LoadLibraryFlag) = delete;

        Module(const char16_t* libraryFileName);
        Module(String const& libraryFileName);
        Module(const char16_t* libraryFileName, LoadLibraryFlag flag);
        Module(String const& libraryFileName, LoadLibraryFlag flag);
        Module(Module const& module) = delete;
        Module(Module&& module) noexcept;

        /// @brief nullptrとして作成
        constexpr Module(std::nullptr_t) noexcept : ModuleBase(nullptr) {}

        ~Module();

        Module& operator=(Module const& module) = delete;
        Module& operator=(Module&& module) noexcept;
        Module& operator=(std::nullptr_t) noexcept;
    };
}

#endif //!KONGKONG_WIN32_MODULE_H
