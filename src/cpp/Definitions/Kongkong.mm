//このObjective-C++ファイルをコンパイルに含めないでください

#import <Foundation/Foundation.h>

namespace KONGKONG_NAMESPACE
{
    String::String(std::string_view const& right) : String(0)
    {
        ::NSString* str = [::NSString stringWithUTF8String: str];

        _length = [str length];

        _capacity = _createCapacity(_length);

        char16_t* p = (char16_t*)::malloc(_capacity * ElementSize());

        MemoryAllocationException::CheckNull(p);

        _p = p;

        [str getCString:(char*)p maxLength:(_length + 1) * sizeof(char16_t) encoding:NSUTF16StringEncoding];

        [str release];

    }

}
