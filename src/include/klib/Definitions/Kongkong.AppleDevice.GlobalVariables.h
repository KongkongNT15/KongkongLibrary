#ifndef KONGKONG_APPLEDEVICE_GLOBALVARIABLES_H
#define KONGKONG_APPLEDEVICE_GLOBALVARIABLES_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::AppleDevice
{
    /// @brief Objective-Cのグローバル変数
    class GlobalVariables final {
        public:
        STATIC_CLASS(GlobalVariables)

        /// @brief NSInvalidArgumentException
        [[nodiscard]]
        static Foundation::NSString NSInvalidArgumentException() noexcept;

        /// @brief IndexOfObject()で見つからなかった時の戻り値
        [[nodiscard]]
        static ssize_t NSNotFound() noexcept;
    };
}

#endif //!KONGKONG_APPLEDEVICE_GLOBALVARIABLES_H
