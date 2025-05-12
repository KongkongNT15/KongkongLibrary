#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSLOCK_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSLOCK_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"
#include "Kongkong.AppleDevice.Foundation.Threading.NSLocking.h"

#include <string>

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Threading
{
    class NSLock : public NSObject {
        public:

        /// @brief インスタンスを作成
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSLock();

        /// @brief 名前付きで作成
        /// @param name 名前
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSLock(const char16_t* name);

        /// @brief 名前付きで作成
        /// @param name 名前
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSLock(String const& name);

        /// @brief 名前付きで作成
        /// @param name 名前
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSLock(const char* name);

        /// @brief 名前付きで作成
        /// @param name 名前
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSLock(std::string const& name);

        /// @brief 名前付きで作成
        /// @param name 名前
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSLock(NSString const& name);

        /// @brief nullptrとして作成
        constexpr NSLock(std::nullptr_t) noexcept : NSObject(nullptr) {}

        [[nodiscard]]
        operator NSLocking() const noexcept;

        /// @brief 
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void Lock() const;

        /// @brief 
        /// @attention このメソッドは実装されていないよ！
        /// @param limit 
        /// @return 
        bool LockBeforeDate(NSDate const& limit) const;

        /// @brief 名前
        /// @attention nullptrかもしれないよ！
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSString Name() const;

        /// @brief 名前をnullptrに設定
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void Name(std::nullptr_t) const;

        /// @brief 名前を設定
        /// @param name 名前
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        void Name(const char16_t* name) const;

        /// @brief 名前を設定
        /// @param name 名前
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        void Name(String const& name) const;

        /// @brief 名前を設定
        /// @param name 名前
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        void Name(const char* name) const;

        /// @brief 名前を設定
        /// @param name 名前
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        void Name(std::string const& name) const;

        /// @brief 名前を設定
        /// @param name 名前
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        void Name(NSString const& name) const;

        [[nodiscard]]
        bool Trylock() const;
        
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void Unlock() const;

        private:
        void _setName(NSString const& str) const noexcept;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSLOCK_H
