#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_NSSCANNER_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_NSSCANNER_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Text
{
    class NSScanner : public NSObject {
        public:

        /// @brief ふぁ！？っく
        NSScanner(std::nullptr_t, bool) = delete;

        /// @brief 作成
        /// @param str 対象の文字列
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき 
        NSScanner(NSString const& str);

        /// @brief 作成
        /// @param str 対象の文字列
        /// @param isLocalized ユーザーのロケールを使用するかどうか
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき 
        NSScanner(NSString const& str, bool isLocalized);

        /// @brief nullptrとして作成
        constexpr NSScanner(std::nullptr_t) noexcept : NSObject(nullptr) {}

        /// @brief スキャナーの文字列の末端に達したかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool AtEnd() const;

        /// @brief 大文字小文字を区別するかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool CaseSensitive() const;

        /// @brief 大文字小文字を区別するかどうかを設定
        /// @param value 設定する値
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void CaseSensitive(bool value) const;

        /// @brief NSDecimal型の値を取得
        /// @param target 値の格納先
        /// @return スキャンできたかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @return スキャンできたかどうか
        bool ScanDecimal(NSDecimal& target) const;

        /// @brief double型の値を取得
        /// @param target 値の格納先
        /// @return スキャンできたかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        bool ScanDouble(double& target) const;

        /// @brief float型の値を取得
        /// @param target 値の格納先
        /// @return スキャンできたかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        bool ScanFloat(float& target) const;

        /// @brief 16進数でdouble型の値を取得
        /// @param target 値の格納先
        /// @return スキャンできたかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        bool ScanHexDouble(double& target) const;

        /// @brief 16進数でfloat型の値を取得
        /// @param target 値の格納先
        /// @return スキャンできたかどうか
        bool ScanHexFloat(float& target) const;

        /// @brief 16進数でunsigned int型の値を取得
        /// @param target 値の格納先
        /// @return スキャンできたかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        bool ScanHexInt(unsigned int& target) const;

        /// @brief 16進数でunsigned long long型の値を取得
        /// @param target 値の格納先
        /// @return スキャンできたかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        bool ScanHexLongLong(unsigned long long& target) const;

        /// @brief int型の値を取得
        /// @param target 値の格納先
        /// @return スキャンできたかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        bool ScanInt(int& target) const;

        /// @brief ssize_t型の値を取得
        /// @param target 値の格納先
        /// @return スキャンできたかどうか
        bool ScanInteger(ssize_t& target) const;

        /// @brief 現在のスキャン位置
        /// @throws NullPointerException: このインスタンスがnullptrのとき 
        [[nodiscard]]
        ssize_t ScanLocation() const;

        /// @brief long long型の値を取得
        /// @param target 値の格納先
        /// @return スキャンできたかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        bool ScanLongLong(long long& target) const;

        /// @brief ふぁ！？っく
        bool ScanString(std::nullptr_t) const = delete;

        /// @brief ふぁ！？っく
        bool ScanString(std::nullptr_t, NSString&) const = delete;

        /// @brief スキャン位置に指定した文字列が存在するかを確認
        /// @param str 探す文字列
        /// @return スキャンできたかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: strがnullptrのとき
        bool ScanString(NSString const& str) const;

        /// @brief スキャン位置に指定した文字列が存在するかを確認
        /// @attention 戻り値がfalseの場合はresultの値は変更されないよ！
        /// @param str 探す文字列
        /// @param result strが見つかったときの書き込み先
        /// @return スキャンできたかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: strがnullptrのとき
        bool ScanString(NSString const& str, NSString& result) const;

        /// @brief ふぁ！？っく
        bool ScanUpToString(std::nullptr_t) const = delete;

        /// @brief ふぁ！？っく
        bool ScanUpToString(std::nullptr_t, NSString&) const = delete;

        /// @brief 文字列を検索
        /// @param str 探す文字列
        /// @return スキャンできたかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: strがnullptrのとき
        bool ScanUpToString(NSString const& str) const;

        /// @brief 文字列を検索
        /// @attention 戻り値がfalseの場合はresultの値は変更されないよ！
        /// @param str 探す文字列
        /// @param result strが見つかるまでにスキャンされた文字の集合
        /// @return スキャンできたかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: strがnullptrのとき
        bool ScanUpToString(NSString const& str, NSString& result) const;

        /// @brief unsigned long long型の値を取得
        /// @param target 値の格納先
        /// @return スキャンできたかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        bool ScanUnsignedLongLong(unsigned long long& target) const;

        /// @brief スキャン対象の文字列本体
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSString String() const;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_NSSCANNER_H
