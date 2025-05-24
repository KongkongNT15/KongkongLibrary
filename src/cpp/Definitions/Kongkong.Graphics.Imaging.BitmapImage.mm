//このObjective-C++ファイルをコンパイルに含めないでください

#define d_MTLCommandQueue ((id<::MTLCommandQueue>)(AppleDevice::NSObjectNelper::GetPointer(m_MTLCommandQueue)))
#define d_MTLTexture ((id<::MTLTexture>)(AppleDevice::NSObjectNelper::GetPointer(m_MTLTexture)))
#define d_MTLTextureDescriptor ((id<::MTLTextureDescriptor>)(AppleDevice::NSObjectNelper::GetPointer(m_MTLTextureDescriptor)))

namespace KONGKONG_NAMESPACE::Graphics::Imaging
{
    BitmapImage::BitmapImage(uint32_t width, uint32_t height)
        : m_MTLCommandQueue(nullptr)
        , m_MTLRenderPassDescriptor(nullptr)
        , m_MTLTexture(nullptr)
        , m_MTLTextureDescriptor(nullptr)
    {
        throw NotImplementedException(u"");
        id<::MTLDevice> device = ::MTLCreateSystemDefaultDevice();
        
        id<::MTLCommandQueue> commandQueue = [device newCommandQueue];

        if (commandQueue == nullptr) [[unlikely]] throw MemoryAllocationException();

        AppleDevice::NSObjectNelper::SetPointer(m_MTLCommandQueue, commandQueue);

        ::MTLTextureDescriptor* desc = [::MTLTextureDescriptor 
            texture2DDescriptorWithPixelFormat: ::MTLPixelFormat::MTLPixelFormatBGRA8Unorm
                                         width:width
                                        height:height
                                     mipmapped:NO
        ];

        

        if (desc == nullptr) [[unlikely]] throw MemoryAllocationException();
        AppleDevice::NSObjectNelper::SetPointer(m_MTLTextureDescriptor, desc);


    }

    void BitmapImage::SaveAs(const char16_t* filePath, ImageFormat format) const
    {
        m_saveAsUnsafe(AppleDevice::Foundation::NSString(filePath), format);
    }

    void BitmapImage::SaveAs(String const& filePath, ImageFormat format) const
    {
        m_saveAsUnsafe(AppleDevice::Foundation::NSString(filePath), format);
    }

    void BitmapImage::SaveAs(AppleDevice::Foundation::NSString const& filePath, ImageFormat format) const
    {
        ArgumentNullException::CheckNull(filePath, u"filePath");
        
        m_saveAsUnsafe(filePath, format);
    }

    void BitmapImage::m_saveAsUnsafe(AppleDevice::Foundation::NSString const& filePath, ImageFormat format) const
    [
        auto f = [] (ImageFormat format) {
            switch (format) {
                case ImageFormat::Bmp:  return ::NSBitmapImageFileType::NSBitmapImageFileTypeBMP;
                //case ImageFormat::Helf: return ::NSBitmapImageFileType::
                case ImageFormat::Gif:  return ::NSBitmapImageFileType::NSBitmapImageFileTypeGIF;
                case ImageFormat::Jpeg: return ::NSBitmapImageFileType::NSBitmapImageFileTypeJPEG;
                case ImageFormat::Png:  return ::NSBitmapImageFileType::NSBitmapImageFileTypePNG;

                default: [[unlikely]] throw NotSupportedException(u"このフォーマットはサポートされていません");
            }
        };
        size_t bytesPerRow = 4 * d_MTLTextureDescriptor.width;
        void* imageBytes = ::malloc(bytesPerRow * d_MTLTextureDescriptor.height);

        MemoryAllocationException::CheckNull(imageBytes);

        ::MTLRegion region = ::MTLRegionMake2D(0, 0, width, height);
        [d_MTLTexture getBytes:imageBytes bytesPerRow:bytesPerRow fromRegion:region mipmapLevel:0];

        // 6. NSBitmapImageRep に変換して PNG に保存
        ::NSBitmapImageRep* bitmap = [[::NSBitmapImageRep alloc]
            initWithBitmapDataPlanes:&imageBytes
                          pixelsWide:width
                          pixelsHigh:height
                       bitsPerSample:8
                     samplesPerPixel:4
                            hasAlpha:YES
                            isPlanar:NO
                      colorSpaceName:NSCalibratedRGBColorSpace
                         bytesPerRow:bytesPerRow
                        bitsPerPixel:32
        ];

        NSData* pngData = [bitmap representationUsingType:f(format) properties:@{}];
        [pngData writeToFile:(::NSString*)AppleDevice::NSObjectNelper::GetPointer(filePath) atomically:YES];

        [bitmap release];
        [pngData release];
        
        ::free(imageBytes);
    ]
}

#undef d_MTLCommandQueue
#undef d_MTLTexture
#undef d_MTLTextureDescriptor