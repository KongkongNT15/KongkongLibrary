#ifndef KONGKONG_WIN32_REGISTRYVALUETYPE_H
#define KONGKONG_WIN32_REGISTRYVALUETYPE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    enum struct RegistryValueType {
        None         = RRF_RT_REG_NONE,         //nullptr
        String       = RRF_RT_REG_SZ,           //String
        ExpandString = RRF_RT_REG_EXPAND_SZ,    //String
        Binary       = RRF_RT_REG_BINARY,       //IArray<uint8_t>
        DoubleWord   = RRF_RT_REG_DWORD,        //uint32_t
        MultiString  = RRF_RT_REG_MULTI_SZ,     //IArray<String>
        QuadWord     = RRF_RT_REG_QWORD,        //uint64_t
        Any          = RRF_RT_ANY,              //すべての型
    };
}

#endif //!KONGKONG_WIN32_REGISTRYVALUETYPE_H
