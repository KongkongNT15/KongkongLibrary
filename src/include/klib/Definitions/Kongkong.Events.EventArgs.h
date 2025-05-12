#ifndef KONGKONG_EVENTS_EVENTARGS_H
#define KONGKONG_EVENTS_EVENTARGS_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Events
{
    //イベントデータ
    //の基底クラス
    struct EventArgs : public ValueType {

        protected:
        EventArgs() = default;
    };
}

#endif //!KONGKONG_EVENTS_EVENTARGS_H
