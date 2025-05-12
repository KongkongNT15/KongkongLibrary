#ifndef KONGKONG_APPLEDEVICE_APPKIT_NSCOLOR_H
#define KONGKONG_APPLEDEVICE_APPKIT_NSCOLOR_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

namespace KONGKONG_NAMESPACE::AppleDevice::AppKit
{
    class NSColor : public NSObject {
        public:

        /// @brief ARGBを指定して作成
        /// @param a 不透明度
        /// @param r 赤
        /// @param g 緑
        /// @param b 青
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static NSColor FromArgb(double a, double r, double g, double b);
        
        /// @brief Display P3色空間を使用して作成
        /// @param a 不透明度
        /// @param r 赤
        /// @param g 緑
        /// @param b 青
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static NSColor FromDisplayP3(double a, double r, double g, double b);

        /// @brief sRGB色空間を使用して作成
        /// @param a 不透明度
        /// @param r 赤
        /// @param g 緑
        /// @param b 青
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static NSColor FromSrgb(double a, double r, double g, double b);

        /// @brief nullptrとして作成
        constexpr NSColor(std::nullptr_t) noexcept : NSObject(nullptr) {}

        double Alpha() const;
        double Black() const;
        double Blue() const;
        double Cyan() const;
        double Green() const;
        double Magenta() const;
        double Red() const;
        double White() const;
        double Yellow() const;

        double Brightness() const;
        double Hue() const;
        double Saturation() const;

        /// @brief 色のカタログ名
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws InvalidOperationException: *thisが定義済みでないNSColorの時
        [[nodiscard]]
        Foundation::NSString CatalogName() const;

        /// @brief 色の名前
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws InvalidOperationException: *thisが定義済みでないNSColorの時
        [[nodiscard]]
        Foundation::NSString ColorName() const;

        /// @brief 色のカタログ名
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws InvalidOperationException: *thisが定義済みでないNSColorの時
        [[nodiscard]]
        Foundation::NSString LocalizedCatalogName() const;

        /// @brief 色の名前
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws InvalidOperationException: *thisが定義済みでないNSColorの時
        [[nodiscard]]
        Foundation::NSString LocalizedColorName() const;
        
        NSColor HighlightWithLevel(double value) const;

        NSColor ShadowWithLevel(double value) const;
    };
}

#endif //!KONGKONG_APPLEDEVICE_APPKIT_NSCOLOR_H
