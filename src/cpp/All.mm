#define KONGKONG_OBJECTIVE_C_METAL_DISABLED
#include "All.h"

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>
#import <Foundation/NSDebug.h>

#ifdef KONGKONG_OBJECTIVE_C_METAL_ENABLED
    #import <Metal/Metal.h>
    #import <QuartzCore/CAMetalLayer.h>
#endif //KONGKONG_OBJECTIVE_C_METAL_ENABLED

#define DEFINE_CAST_APPLEOBJECT(TKongkong, TPointer)                            \
    namespace Kongkong::AppleDevice                                             \
    {                                                                           \
        template <>                                                             \
        TKongkong NSObject::Cast() const                                        \
        {                                                                       \
            if ((bool)[(::NSObject*)_ptr.__p isKindOfClass:TPointer.class]) {   \
                TKongkong result = nullptr;                                     \
                result._ptr = _ptr;                                             \
                                                                                \
                return result;                                                  \
            }                                                                   \
                                                                                \
            throw InvalidCastException();                                       \
        }                                                                       \
        template <>                                                             \
        bool NSObject::Is<TKongkong>() const noexcept                           \
        {                                                                       \
            return (bool)[(::NSObject*)_ptr.__p isKindOfClass:TPointer.class];  \
        }                                                                       \
    }

#define DEFINE_PROTOCOL_CAST_APPLEOBJECT(TKongkong, TPointer)                   \
    namespace Kongkong::AppleDevice                                             \
    {                                                                           \
        template <>                                                             \
        TKongkong NSObject::Cast() const                                        \
        {                                                                       \
            if ((bool)[(::NSObject*)_ptr.__p conformsToProtocol:@protocol(TPointer)]) {   \
                TKongkong result = nullptr;                                     \
                result._ptr = _ptr;                                             \
                                                                                \
                return result;                                                  \
            }                                                                   \
                                                                                \
            throw InvalidCastException(u"不正なキャストです");                     \
        }                                                                       \
        template <>                                                             \
        bool NSObject::Is<TKongkong>() const noexcept                           \
        {                                                                       \
            return (bool)[(::NSObject*)_ptr.__p conformsToProtocol:@protocol(TPointer)];  \
        }                                                                       \
    }

namespace Kongkong::AppleDevice
{
    class NSObjectHelper final {
        public:
        STATIC_CLASS(NSObjectHelper)

        [[nodiscard]]
        static constexpr void* GetPointer(NSObject const& nsObject) noexcept { return nsObject._ptr.__p; }

        static constexpr void SetPointer(NSObject& nsObject, void* p) noexcept { nsObject._ptr.__p = p; }

        /// @brief NSExceptionをKongkongスタイル例外に変換してスロー
        /// @param e 例外オブジェクト
        /// @param throwInvalidOperationException eの種類がNSInvalidArgumentExceptionの時にInvalidOperationExceptionをスローするかどうか
        [[noreturn]]
        static void Throw(::NSException* e, bool throwInvalidOperationException = false);
    };

    class NSEnumHelper final {
        public:
        STATIC_CLASS(NSEnumHelper)

        static constexpr Foundation::NSCalculationError Convert(::NSCalculationError const& value) noexcept;
        static constexpr Foundation::Text::Xml::NSXmlNodeKind Convert(::NSXMLNodeKind const& value) noexcept;

#ifdef KONGKONG_OBJECTIVE_C_METAL_ENABLED
        static constexpr ::MTLLogLevel Convert(Metal::MetalLogLevel value) noexcept;
        static constexpr Metal::MetalLogLevel Convert(::MTLLogLevel value) noexcept;
#endif //!KONGKONG_OBJECTIVE_C_METAL_ENABLED
    };
}

namespace Kongkong::AppleDevice::Foundation
{
    class NSStringHelper final {
        public:
        STATIC_CLASS(NSStringHelper)

        static NSString FromHandle(std::nullptr_t) = delete;

        static NSString FromHandle(::NSString* p);
    };
}

#include "Definitions/Kongkong.Appledevice._castAppleObject.mm"

#include "All.cpp"

#include "Definitions/Kongkong.AppleDevice.GlobalVariables.mm"
#include "Definitions/Kongkong.AppleDevice.NSEnumHelper.mm"
#include "Definitions/Kongkong.AppleDevice.NSObject.mm"
#include "Definitions/Kongkong.AppleDevice.NSObjectHelper.mm"

#include "Definitions/Kongkong.AppleDevice.AppKit.NSColor.mm"

#include "Definitions/Kongkong.AppleDevice.Foundation.NSData.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.NSDebug.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.NSDecimal.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.NSDecimalNumber.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.NSError.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.NSNumber.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.NSRange.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.NSString.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.NSStringHelper.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.NSValue.mm"

#include "Definitions/Kongkong.AppleDevice.Foundation.Collections.ArrayWrapperBase.cpp"
#include "Definitions/Kongkong.AppleDevice.Foundation.Collections.EnumeratorWrapperBase.cpp"
#include "Definitions/Kongkong.AppleDevice.Foundation.Collections.NSArray.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.Collections.NSDictionary.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.Collections.NSEnumerator.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.Collections.NSMutableArray.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.Collections.NSNull.mm"

#include "Definitions/Kongkong.AppleDevice.Foundation.Streams.NSStream.mm"

#include "Definitions/Kongkong.AppleDevice.Foundation.Text.NSScanner.mm"

#include "Definitions/Kongkong.AppleDevice.Foundation.Text.Xml.NSXmlAttribute.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.Text.Xml.NSXmlDocument.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.Text.Xml.NSXmlElement.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.Text.Xml.NSXmlNode.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.Text.Xml.NSXmlText.mm"

#include "Definitions/Kongkong.AppleDevice.Foundation.Threading.NSBlockOperation.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.Threading.NSLock.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.Threading.NSLocking.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.Threading.NSOperation.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.Threading.NSOperationQueue.mm"
#include "Definitions/Kongkong.AppleDevice.Foundation.Threading.NSThread.mm"

#ifdef KONGKONG_OBJECTIVE_C_METAL_ENABLED
    #include "Definitions/Kongkong.AppleDevice.Metal.MetalDevice.mm"
    #include "Definitions/Kongkong.AppleDevice.Metal.MetalCommandQueueDescriptor.mm"
    #include "Definitions/Kongkong.AppleDevice.Metal.MetalLogState.mm"
#endif //KONGKONG_OBJECTIVE_C_METAL_ENABLED