#ifndef KONGKONG_WIN32_CLASSTYPEHELPER_H
#define KONGKONG_WIN32_CLASSTYPEHELPER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    class ClassTypeHelper final {
        public:

        STATIC_CLASS(ClassTypeHelper)

        template <class T> requires (std::derived_from<T, Handle> || std::same_as<T, Handle>)
        [[nodiscard]] static ::KONGKONG_NAMESPACE::Win32::ClassType ClassType() noexcept;
    };
}

#endif //!KONGKONG_WIN32_CLASSTYPEHELPER_H
