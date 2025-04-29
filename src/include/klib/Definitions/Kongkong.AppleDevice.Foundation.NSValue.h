#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_NSVALUE_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_NSVALUE_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    class NSValue : public NSObject {
        public:

        /// @brief ふぁ！？っく
        NSValue(const void*, std::nullptr_t) = delete;

        /// @brief ポインターから作成
        /// @param pointer ポインター
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        /// @throws ArgumentNullException: pointerがnullptrのとき
        NSValue(const void* pointer);

        /// @brief ポインターから作成
        /// @param pointer ポインター
        /// @param objCType 型名
        /// @throws ArgumentNullException: pointerがnullptrのとき
        /// @throws ArgumentNullException: objCTypeがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSValue(const void* pointer, const char* objCType);

        /// @brief NSRangeのラッパーとして作成
        /// @param nsRange 値
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSValue(NSRange const& nsRange);

        /// @brief nullptrとして作成
        constexpr NSValue(std::nullptr_t) noexcept : NSObject(nullptr) {}

        /// @brief 値が一致しているかを確認
        /// @param nsValue 値
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool IsEqualToValue(NSValue const& nsValue) const;

        /// @brief 
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        const char* ObjCType() const;

        /// @brief 値へのポインター
        [[nodiscard]] 
        void* PointerValue() const;

        [[nodiscard]]
        NSRange RangeValue() const;

    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_NSVALUE_H
