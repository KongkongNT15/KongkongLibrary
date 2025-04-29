#ifndef KONGKONG_ALGORITHMS_SORTER_H
#define KONGKONG_ALGORITHMS_SORTER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Algorithms
{

    class Sorter final {
        public:

        STATIC_CLASS(Sorter)

        template <class T, size_t N>
        static void BubbleSort(T (&array)[N]) { _bubbleSort<T>(array, (ssize_t)N); }

        template <class T, size_t N>
        static void BubbleSort(std::array<T, N>& array) { _bubbleSort<T>(array, (ssize_t)N); }

        template <class T>
        static void BubbleSort(T* p, ssize_t length) { _bubbleSort<T>(p, length); }

        template <class T>
        static void BubbleSort(std::vector<T>& vector) { _bubbleSort<T>(vector, (ssize_t)vector.size()); }

        template <class T>
        static void BubbleSort(Collections::IArray<T> const& array) { _bubbleSort<T>(array, array.Length()); }

        private:

        template <class T, class ArrayType>
        static void _bubbleSort(ArrayType& array, ssize_t length)
        {
            for (ssize_t i = 0; i < length; i++) {
                for (ssize_t j = 1; j < length; j++) {
                    if (array[j] < array[j - 1]) {
                        T tmp = std::move(array[j]);
                        new (&array[j]) T(std::move(array[j - 1]));
                        new (&array[j - 1]) T(std::move(tmp));
                    }
                }
            }
        }

    };
}

#endif //!KONGKONG_ALGORITHMS_SORTER_H
