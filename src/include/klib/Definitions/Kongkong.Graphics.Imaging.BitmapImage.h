#ifndef KONGKONG_GRAPHICS_IMAGING_BITMAPIMAGE_H
#define KONGKONG_GRAPHICS_IMAGING_BITMAPIMAGE_H

#include "Base.h"
#include "Kongkong.PointerType.h"

#ifdef KONGKONG_ENV_WINDOWS
    #include <wincodec.h>
    #include <d2d1.h>
    #include <wrl/client.h>
#endif

namespace KONGKONG_NAMESPACE::Graphics::Imaging
{
    class BitmapImage : public PointerType {
        public:

        BitmapImage(uint32_t width, uint32_t height);

        void DrawCircle(Point2F point, float radius, float strokeWidth, ColorF const& color) const;
        void DrawEllipse(Point2F point, float radiusX, float radiusY, float strokeWidth, ColorF const& color) const;
        void DrawLine(Point2F point1, Point2F point2, float strokeWidth, ColorF const& color) const;
        void DrawText(const char16_t* text) const;

        void Fill(ColorF const& color) const;

        /// @brief ふぁ！？っく
        void SaveAs(::std::nullptr_t, ImageFormat) const = delete;

        void SaveAs(const char16_t* filePath, ImageFormat format) const;

        void SaveAs(String const& filePath, ImageFormat format) const;

        private:

#ifdef KONGKONG_ENV_WINDOWS

        ::Microsoft::WRL::ComPtr<::IWICBitmap> m_bitmap;
        ::Microsoft::WRL::ComPtr<::ID2D1RenderTarget> m_renderTarget;
        ::Microsoft::WRL::ComPtr<::ID2D1SolidColorBrush> m_brush;

        static thread_local ::Microsoft::WRL::ComPtr<::IWICImagingFactory> s_factory;
        static thread_local ::Microsoft::WRL::ComPtr<::ID2D1Factory> s_d2dFactory;

        static ::D2D1_RENDER_TARGET_PROPERTIES s_rtProps;

        static void s_checkFactory();
        static void s_destory() noexcept;
        

        static ::GUID s_convertFormat(ImageFormat format);

        friend _winComInitializer;
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)

#endif
    };
}

#endif //!KONGKONG_GRAPHICS_IMAGING_BITMAPIMAGE_H