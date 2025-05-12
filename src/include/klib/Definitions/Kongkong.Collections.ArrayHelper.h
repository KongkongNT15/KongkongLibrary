#ifndef KONGKONG_COLLECTIONS_ARRAYHELPER_H
#define KONGKONG_COLLECTIONS_ARRAYHELPER_H

#include "Base.h"
#include "Kongkong.Collections.Array.h"
#include "Kongkong.Collections.ArrayList.h"
#include "Kongkong.GenericString.h"

namespace KONGKONG_NAMESPACE::Collections
{
    class ArrayHelper final {
        public:

        STATIC_CLASS(ArrayHelper)

        template <class T> requires ::std::copy_constructible<T>
        [[nodiscard]] static Turbo::FastArrayList<T> ToFastArrayList(Turbo::FastArray<T> const& arr)
        {
            T* p = (T*)::malloc((arr._length) * sizeof(T));

            MemoryAllocationException::CheckNull(p);

            T* itr = p;

            try {
                for (T const& arrValue : arr) {
                    new (itr) T(arrValue);
                    p++;
                }
            }
            catch (...) {
                T* itr1 = p;
                while (itr1 != itr) {
                    itr1->~T();
                    itr1++;
                }

                ::free(p);

                ::std::rethrow_exception(::std::current_exception());
            }

            return Turbo::FastArrayList<T>(arr._length, arr._length, p);
        }

        template <class T>
        [[nodiscard]] static Turbo::FastArrayList<T> ToFastArrayList(Turbo::FastArray<T>&& arr) noexcept
        {
            T* p = arr._p;
            arr._p = nullptr;

            return Turbo::FastArrayList<T>(arr._length, arr._length, p);
        }
        
    };
}

#endif //!KONGKONG_COLLECTIONS_ARRAYHELPER_H
