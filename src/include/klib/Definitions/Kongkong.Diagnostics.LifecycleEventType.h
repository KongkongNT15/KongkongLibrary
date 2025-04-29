#ifndef KONGKONG_DIAGNOSTICS_LIFECYCLEEVENTTYPE_H
#define KONGKONG_DIAGNOSTICS_LIFECYCLEEVENTTYPE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Diagnostics
{
    enum struct LifecycleEventType : uint8_t {
        DefaultAction           = 0x1,
        CopyAction              = 0x2,
        MoveAction              = 0x4,
        OtherAction             = 0x8,
        Constructor             = 0x10,
        AssignmentOperator      = 0x20,
        Destructor              = 0x40 | DefaultAction,
        DefaultConstructor      = Constructor | DefaultAction,
        CopyConstructor         = Constructor | CopyAction,
        MoveConstructor         = Constructor | MoveAction,
        OtherConstructor        = Constructor | OtherAction,
        CopyAssignmentOperator  = AssignmentOperator | CopyAction,
        MoveAssignmentOperator  = AssignmentOperator | MoveAction,
        OtherAssignmentOperator = AssignmentOperator | OtherAction,
    };

    CREATE_OPERATOR_AND_OR(LifecycleEventType)
}

#endif //!KONGKONG_DIAGNOSTICS_LIFECYCLEEVENTTYPE_H
