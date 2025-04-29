#ifndef KONGKONG_TEXT_STATICSTRINGDATA_H
#define KONGKONG_TEXT_STATICSTRINGDATA_H

#include "Base.h"
#include "Kongkong.Text.StringType.h"
#include "Kongkong.Text._stringPointerBase.h"

namespace KONGKONG_NAMESPACE::Text
{
    template <CharType TChar, ssize_t N>
    struct StaticStringData final : public ValueType {
        public:

        constexpr StaticStringData(const TChar (&arr)[N]) noexcept
        {
            *(ssize_t*)((void*)(_arr + _stringPointerBase::__capacityIndex)) = N;
            *(ssize_t*)((void*)(_arr + _stringPointerBase::__countIndex)) = 1;
            *(StringType*)((void*)(_arr + _stringPointerBase::__typeIndex)) = StringType::Static;
            *(ssize_t*)((void*)(_arr + _stringPointerBase::__lengthIndex)) = N - 1;

            TChar* p = (TChar*)(_arr + _stringPointerBase::__stringIndex);

            for (ssize_t i = 0; i < N; i++) {
                p[i] = arr[i];
            }
        }

        private:

        uint8_t _arr[_stringPointerBase::__stringIndex + N * sizeof(TChar)];
    };
}

#endif //!KONGKONG_TEXT_STATICSTRINGDATA_H
