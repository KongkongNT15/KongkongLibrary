#ifndef KONGKONG_EVENTS_EVENTFUNCTIONS_H
#define KONGKONG_EVENTS_EVENTFUNCTIONS_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.GenericString.h"
#include "Kongkong.Events.EventFunction.h"
#include "Kongkong.Collections.Turbo.FastArrayList.h"

namespace KONGKONG_NAMESPACE::Events
{
    template <class TSender, class TArgs>
    struct EventFunctions final : public ValueType {

        EventFunctions() = default;
        EventFunctions(EventFunctions const&) = delete;

        EventFunctions& operator=(EventFunctions const&) = delete;

        /// @brief 実行する関数を登録
        /// @param func 追加する関数
        EventFunctions& operator+=(EventFunction<TSender, TArgs> const& func) noexcept
        {
            Append(func);
            return *this;
        }

        /// @brief 関数を登録解除
        /// @param func 解除する関数
        EventFunctions& operator-=(EventFunction<TSender, TArgs> const& func) noexcept
        {
            Remove(func);
            return *this;
        }

        [[nodiscard]] EventFunction<TSender, TArgs>* begin() noexcept { return _vec.begin(); }
        [[nodiscard]] EventFunction<TSender, TArgs>* end() noexcept { return _vec.end(); }
        [[nodiscard]] const EventFunction<TSender, TArgs>* begin() const noexcept { return _vec.begin(); }
        [[nodiscard]] const EventFunction<TSender, TArgs>* end() const noexcept { return _vec.end(); }

        /// @brief 実行する関数を登録
        /// @param func 追加する関数
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void Append(EventFunction<TSender, TArgs> const& func) { _vec.Append(func); }

        /// @brief 関数を登録解除
        /// @param func 解除する関数
        /// @return 削除したかどうか
        bool Remove(EventFunction<TSender, TArgs> const& func) noexcept { return _vec.Remove(func); }

        [[nodiscard]]
        String ToString() const { return String::FromLiteral(u"Kongkong::Events::EventFunctions<T>"); }

        private:
        Collections::Turbo::FastArrayList<EventFunction<TSender, TArgs>> _vec;
    };
}

#endif //!KONGKONG_EVENTS_EVENTFUNCTIONS_H
