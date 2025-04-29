#ifndef KONGKONG_ALGORITHMS_OTHELLO_OTHELLOELEMENT_H
#define KONGKONG_ALGORITHMS_OTHELLO_OTHELLOELEMENT_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Algorithms.Othello.OthelloValue.h"

namespace KONGKONG_NAMESPACE::Algorithms::Othello
{
    struct OthelloElement final : public ValueType {

        /// @brief デフォルトの値で作成
        constexpr OthelloElement() noexcept : _canSet(false), _value(OthelloValue::None) {}

        /// @brief この位置に石を置けるかどうか
        [[nodiscard]]
        constexpr bool CanSet() const noexcept { return _canSet; }

        /// @brief 値を変更
        /// @param value 値
        constexpr void SetValueUnsafe(OthelloValue value) noexcept { _value = value; }

        /// @brief 値の文字列表現を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき 
        [[nodiscard]]
        String ToString() const;

        /// @brief 値
        [[nodiscard]]
        constexpr OthelloValue Value() const noexcept { return _value; }

        /// @brief 値を変更
        /// @param value 値
        /// @throws InvalidArgumentException: valueが無効な値の時
        void Value(OthelloValue value);

        private:

        bool _canSet;
        OthelloValue _value;

        constexpr void _reset() noexcept;

        friend OthelloField;
    };
}

namespace KONGKONG_NAMESPACE::Algorithms::Othello
{
    constexpr void OthelloElement::_reset() noexcept
    {
        _canSet = false;
        _value = OthelloValue::None;
    }
}

#endif //!KONGKONG_ALGORITHMS_OTHELLO_OTHELLOELEMENT_H
