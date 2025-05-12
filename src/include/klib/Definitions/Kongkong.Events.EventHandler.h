#ifndef KONGKONG_EVENTS_EVENTHANDLER_H
#define KONGKONG_EVENTS_EVENTHANDLER_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.GenericString.h"
#include "Kongkong.NullPointerException.h"
#include "Kongkong.Events.EventFunctions.h"

namespace KONGKONG_NAMESPACE::Events
{
    //イベントハンドラー
    template <class TSender, class TArgs>
    struct EventHandler final : public ValueType {

        EventHandler() : _list() {}

        //登録された関数を呼ぶ
        void Call(TSender const& sender, TArgs const& args);
        
        constexpr EventFunctions<TSender, TArgs>& List() noexcept { return _list; }

        String ToString() const { return String::FromPointerUnsafe(u"Kongkong::Events::EventHandler", true); }

        EventFunctions<TSender, TArgs> _list;

    };
}

namespace KONGKONG_NAMESPACE::Events
{
    template <class TSender, class TArgs>
    void EventHandler<TSender, TArgs>::Call(TSender const& sender, TArgs const& args)
    {
        for (EventFunction<TSender, TArgs>& func : _list) {
            func.Call(sender, args);
        }
    }

}

#endif //!KONGKONG_EVENTS_EVENTHANDLER_H
