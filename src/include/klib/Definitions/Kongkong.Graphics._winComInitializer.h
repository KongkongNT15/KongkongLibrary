#ifndef KONGKONG_GRAPHICS_WINCOMINITIALIZER_H
#define KONGKONG_GRAPHICS_WINCOMINITIALIZER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Graphics
{
    class _winComInitializer final {
        public:

        STATIC_CLASS(_winComInitializer)

        private:

        struct s_initializer {
            s_initializer();
            ~s_initializer();
        };
#ifndef KONGKONG_LIBRARY
        [[maybe_unused]] static inline thread_local s_initializer s_init;
#endif //!KONGKONG_LIBRARY
    };
}


#endif //!KONGKONG_GRAPHICS_WINCOMINITIALIZER_H