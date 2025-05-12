//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Graphics::Imaging
{
#ifdef KONGKONG_ENV_WINDOWS
    thread_local ::Microsoft::WRL::ComPtr<::IWICImagingFactory> BitmapImage::s_factory;
    thread_local ::Microsoft::WRL::ComPtr<::ID2D1Factory> BitmapImage::s_d2dFactory;

    ::D2D1_RENDER_TARGET_PROPERTIES BitmapImage::s_rtProps = D2D1::RenderTargetProperties(
        ::D2D1_RENDER_TARGET_TYPE::D2D1_RENDER_TARGET_TYPE_DEFAULT,
        ::D2D1::PixelFormat(::DXGI_FORMAT::DXGI_FORMAT_UNKNOWN, ::D2D1_ALPHA_MODE::D2D1_ALPHA_MODE_PREMULTIPLIED),
        0.0f,
        0.0f
    );

    BitmapImage::BitmapImage(uint32_t width, uint32_t height)
    {
        s_checkFactory();
        if (FAILED(s_factory->CreateBitmap(width, height, ::GUID_WICPixelFormat32bppPBGRA, ::WICBitmapCreateCacheOption::WICBitmapCacheOnLoad, &m_bitmap))) [[unlikely]] throw MemoryAllocationException();

        if (FAILED(s_d2dFactory->CreateWicBitmapRenderTarget(m_bitmap.Get(), s_rtProps, &m_renderTarget))) [[unlikely]] throw MemoryAllocationException();
        if (FAILED(m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0, 0), &m_brush))) [[unlikely]] throw MemoryAllocationException();
    }

    void BitmapImage::DrawCircle(Point2F point, float radius, float strokeWidth, ColorF const& color) const
    {
        DrawEllipse(point, radius, radius, strokeWidth, color);
    }

    void BitmapImage::DrawEllipse(Point2F point, float radiusX, float radiusY, float strokeWidth, ColorF const& color) const
    {
        m_brush->SetColor(color.ToDirectXColorF());

        m_renderTarget->BeginDraw();
        m_renderTarget->DrawEllipse(::D2D1::Ellipse({ point.X(), point.Y() }, radiusX, radiusY), m_brush.Get(), strokeWidth);

        if (FAILED(m_renderTarget->EndDraw())) [[unlikely]] throw ImageRenderException();
    }

    void BitmapImage::DrawLine(Point2F point1, Point2F point2, float strokeWidth, ColorF const& color) const
    {
        m_brush->SetColor(color.ToDirectXColorF());

        m_renderTarget->BeginDraw();
        m_renderTarget->DrawLine({ point1.X(), point1.Y() }, { point2.X(), point2.Y() }, m_brush.Get(), strokeWidth);

        if (FAILED(m_renderTarget->EndDraw())) [[unlikely]] throw ImageRenderException();
    }

    void BitmapImage::Fill(ColorF const& color) const
    {
        m_renderTarget->BeginDraw();
        m_renderTarget->Clear(color.ToDirectXColorF());
        if (FAILED(m_renderTarget->EndDraw())) [[unlikely]] throw ImageRenderException();
    }

    void BitmapImage::SaveAs(const char16_t* filePath, ImageFormat format) const
    {
        ::Microsoft::WRL::ComPtr<IWICStream> stream;
        if (FAILED(s_factory->CreateStream(&stream))) [[unlikely]] throw MemoryAllocationException();

        if (FAILED(stream->InitializeFromFilename((const wchar_t*)filePath, GENERIC_WRITE))) [[unlikely]] throw IOException(u"ファイルを開けませんでした");

        ::Microsoft::WRL::ComPtr<IWICBitmapEncoder> encoder;
        if (FAILED(s_factory->CreateEncoder(s_convertFormat(format), nullptr, &encoder))) [[unlikely]] throw MemoryAllocationException();

        if (FAILED(encoder->Initialize(stream.Get(), ::WICBitmapEncoderCacheOption::WICBitmapEncoderNoCache))) [[unlikely]] throw InitializationException();

        ::Microsoft::WRL::ComPtr<::IWICBitmapFrameEncode> frame;
        ::Microsoft::WRL::ComPtr<::IPropertyBag2> props;
        if (FAILED(encoder->CreateNewFrame(&frame, &props))) [[unlikely]] throw MemoryAllocationException();

        if (FAILED(frame->Initialize(props.Get()))) [[unlikely]] throw InitializationException();
        UINT width, height;
        m_bitmap->GetSize(&width, &height);
        frame->SetSize(width, height);
        ::WICPixelFormatGUID format1 = GUID_WICPixelFormat32bppPBGRA;
        frame->SetPixelFormat(&format1);
        frame->WriteSource(m_bitmap.Get(), nullptr);
        frame->Commit();
        encoder->Commit();
    }

    void BitmapImage::SaveAs(String const& filePath, ImageFormat format) const
    {
        SaveAs(filePath.c_str(), format);
    }

    void BitmapImage::s_checkFactory()
    {
        if (s_factory == nullptr) {
            ::CoCreateInstance(CLSID_WICImagingFactory, nullptr, ::tagCLSCTX::CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&s_factory));
            ::D2D1CreateFactory(::D2D1_FACTORY_TYPE::D2D1_FACTORY_TYPE_SINGLE_THREADED, s_d2dFactory.GetAddressOf());
        }
    }

    ::GUID BitmapImage::s_convertFormat(ImageFormat format)
    {
        switch (format) {
            case ImageFormat::Bmp:  return ::GUID_ContainerFormatBmp;
            case ImageFormat::Gif:  return ::GUID_ContainerFormatGif;
            case ImageFormat::Ico:  return ::GUID_ContainerFormatIco;
            case ImageFormat::Jpeg: return ::GUID_ContainerFormatJpeg;
            case ImageFormat::Png:  return ::GUID_ContainerFormatPng;
            case ImageFormat::Tiff: return ::GUID_ContainerFormatTiff;

            default: [[unlikely]] throw NotSupportedException(u"このフォーマットはサポートされていません");
        }

#if KONGKONG_HAS_CPP23
        ::std::unreachable();
#endif
    }

    void BitmapImage::s_destory() noexcept
    {
        s_factory = nullptr;
    }
#endif
}