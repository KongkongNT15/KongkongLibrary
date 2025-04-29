#ifndef KONGKONG_TEXT_YAML_YAMLDATATYPE_H
#define KONGKONG_TEXT_YAML_YAMLDATATYPE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Text::Yaml
{
    enum struct YamlDataType : uint8_t {
        Boolean,
        Integer,
        Null,
        String,
    };
}

#endif //!KONGKONG_TEXT_YAML_YAMLDATATYPE_H
