#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_NSERROR_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_NSERROR_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"
#include "Kongkong.AppleDevice.Foundation.NSString.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    class NSError : public NSObject {
        public:

        /// @brief Cocoaエラー 
        [[nodiscard]]
        NSString CocoaErrorDomain() noexcept;

        /// @brief Posixエラー 
        [[nodiscard]]
        NSString PosixErrorDomain() noexcept;
        
        /// @brief ふぁ！？っく
        NSError(std::nullptr_t, ssize_t) = delete;

        /// @brief ふぁ！？っく
        NSError(std::nullptr_t, ssize_t, std::nullptr_t) = delete;

        /// @brief 情報を指定して作成
        /// @param domain エラードメイン
        /// @param code エラーコード
        /// @throws ArgumentNullException: domainがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSError(NSString const& domain, ssize_t code);

        /// @brief 情報を指定して作成
        /// @param domain エラードメイン
        /// @param code エラーコード
        /// @throws ArgumentNullException: domainがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSError(NSString const& domain, ssize_t code, std::nullptr_t);

        /// @brief 全ての情報を指定して作成
        /// @param domain エラードメイン
        /// @param code エラーコード
        /// @param userInfo 追加情報
        /// @throws ArgumentNullException: domainがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSError(NSString const& domain, ssize_t code, Collections::DictionaryWrapper<NSString, NSObject> const& userInfo);

        /// @brief nullptrとして作成
        constexpr NSError(std::nullptr_t) noexcept : NSObject(nullptr) {}

        /// @brief エラーコード
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        ssize_t Code() const;

        /// @brief エラードメイン
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSString Domain() const;

        /// @brief エラーの説明
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSString LocalizedDescription() const;

        /// @brief リカバリーオプション
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        Collections::ArrayWrapper<NSString> LocalizedRecoveryOptions() const;

        /// @brief エラーの追加情報
        [[nodiscard]]
        Collections::DictionaryWrapper<NSString, NSObject> UserInfo() const;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_NSERROR_H
