#ifndef KONGKONG_NUMERIC_RANDOMBASE_H
#define KONGKONG_NUMERIC_RANDOMBASE_H

#include "Base.h"
#include "Kongkong.Object.h"

namespace KONGKONG_NAMESPACE::Numeric::IMPLEMENTATION
{
    struct RandomBase : public ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object {
        
        [[nodiscard]] virtual int32_t Next();
        [[nodiscard]] virtual int32_t Next(int32_t maxValue);
        [[nodiscard]] int32_t Next(int32_t minValue, int32_t maxValue);
        [[nodiscard]] virtual int64_t NextInt64();
        [[nodiscard]] virtual int64_t NextInt64(int64_t maxValue);
        [[nodiscard]] int64_t NextInt64(int64_t minValue, int64_t maxValue);

        [[nodiscard]] virtual double NextDouble() = 0;
        [[nodiscard]] virtual float NextSingle();

        protected:
        //関数が呼ばれる時点で minValue < maxValue となっている
        virtual int32_t _nextUnsafe(int32_t minValue, int32_t maxValue);
        virtual int64_t _nextInt64Unsafe(int64_t minValue, int64_t maxValue) = 0;
    };
}

namespace KONGKONG_NAMESPACE::Numeric
{
    class RandomBase : public Object {
        public:
        using ImplType = IMPLEMENTATION::RandomBase;

        /// @brief nullptrとして作成
        constexpr RandomBase(std::nullptr_t) noexcept : Object(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
        
    };
}

#endif //!KONGKONG_NUMERIC_RANDOMBASE_H
