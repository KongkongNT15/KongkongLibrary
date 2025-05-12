#ifndef KONGKONG_TEXT_YAML_YAMLNODETYPE_H
#define KONGKONG_TEXT_YAML_YAMLNODETYPE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Text::Yaml
{
    enum struct YamlNodeType : uint8_t {
        Document,
        Text,
    };
}

#endif //!KONGKONG_TEXT_YAML_YAMLNODETYPE_H
