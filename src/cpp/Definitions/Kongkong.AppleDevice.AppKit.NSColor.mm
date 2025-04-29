//このObjective-C++ファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice::AppKit
{
    NSColor NSColor::FromArgb(double a, double r, double g, double b)
    {
        ::NSColor* p = [::NSColor colorWithRed:r green:g blue:b alpha:a];
        
        NSColor color = nullptr;
        color._setInstance(p);

        return color;
    }

    NSColor NSColor::FromDisplayP3(double a, double r, double g, double b)
    {
        ::NSColor* p = [::NSColor colorWithDisplayP3Red:r green:g blue:b alpha:a];

        NSColor color = nullptr;
        color._setInstance(p);

        return color;
    }

    NSColor NSColor::FromSrgb(double a, double r, double g, double b)
    {
        ::NSColor* p = [::NSColor colorWithSRGBRed:r green:g blue:b alpha:a];

        NSColor color = nullptr;
        color._setInstance(p);

        return color;
    }

    double NSColor::Alpha() const
    {
        auto p = (::NSColor*)_instance();
        double result = [p alphaComponent];

        return result;
    }

    double NSColor::Black() const
    {
        auto p = (::NSColor*)_instance();
        double result = [p blackComponent];

        return result;
    }

    double NSColor::Blue() const
    {
        auto p = (::NSColor*)_instance();
        double result = [p blueComponent];

        return result;
    }

    double NSColor::Brightness() const
    {
        auto p = (::NSColor*)_instance();
        double result = [p brightnessComponent];

        return result;
    }

    Foundation::NSString NSColor::CatalogName() const
    {
        auto p = (::NSColor*)_instance();

        ::NSString* str = [p catalogNameComponent];

        return Foundation::NSStringHelper::FromHandle(str);
    }

    Foundation::NSString NSColor::ColorName() const
    {
        auto p = (::NSColor*)_instance();

        ::NSString* str;

        @try {
            str = [p colorNameComponent];
        }
        @catch (::NSException* e) {
            Foundation::NSString reason = Foundation::NSStringHelper::FromHandle(e.reason);

            throw InvalidOperationException(reason.ToString());
        }

        return Foundation::NSStringHelper::FromHandle(str);
    }

    double NSColor::Cyan() const
    {
        auto p = (::NSColor*)_instance();
        double result = [p cyanComponent];

        return result;
    }

    double NSColor::Hue() const
    {
        auto p = (::NSColor*)_instance();
        double result = [p hueComponent];

        return result;
    }

    double NSColor::Magenta() const
    {
        auto p = (::NSColor*)_instance();
        double result = [p magentaComponent];

        return result;
    }

    double NSColor::Green() const
    {
        auto p = (::NSColor*)_instance();
        double result = [p greenComponent];

        return result;
    }

    NSColor NSColor::HighlightWithLevel(double value) const
    {
        auto p = (::NSColor*)_instance();

        ::NSColor* result = [p highlightWithLevel:value];

        NSColor color = nullptr;

        NSObjectHelper::SetPointer(color, result);

        return color;
    }

    Foundation::NSString NSColor::LocalizedCatalogName() const
    {
        auto p = (::NSColor*)_instance();

        ::NSString* str = [p localizedCatalogNameComponent];

        return Foundation::NSStringHelper::FromHandle(str);
    }

    Foundation::NSString NSColor::LocalizedColorName() const
    {
        auto p = (::NSColor*)_instance();

        ::NSString* str;

        @try {
            str = [p localizedColorNameComponent];
        }
        @catch (::NSException* e) {
            Foundation::NSString reason = Foundation::NSStringHelper::FromHandle(e.reason);

            throw InvalidOperationException(reason.ToString());
        }

        return Foundation::NSStringHelper::FromHandle(str);
    }

    double NSColor::Red() const
    {
        auto p = (::NSColor*)_instance();
        double result = [p redComponent];

        return result;
    }

    double NSColor::Saturation() const
    {
        auto p = (::NSColor*)_instance();
        double result = [p saturationComponent];

        return result;
    }

    NSColor NSColor::ShadowWithLevel(double value) const
    {
        auto p = (::NSColor*)_instance();

        ::NSColor* result = [p shadowWithLevel:value];

        NSColor color = nullptr;

        NSObjectHelper::SetPointer(color, result);

        return color;
    }

    double NSColor::White() const
    {
        auto p = (::NSColor*)_instance();
        double result = [p whiteComponent];

        return result;
    }

    double NSColor::Yellow() const
    {
        auto p = (::NSColor*)_instance();
        double result = [p yellowComponent];

        return result;
    }

}
