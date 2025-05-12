#ifndef KONGKONG_TEXT_STRINGPOINTER_H
#define KONGKONG_TEXT_STRINGPOINTER_H

#include "Base.h"
#include "Kongkong.Text._stringPointerBase.h"
#include "Kongkong.Text.StaticStringData.h"

#include <set>

namespace KONGKONG_NAMESPACE::Text
{
    /// @brief _stringGCで使用する
    template <CharType TChar>
    struct _stringPointer final : public _stringPointerBase {
        using Base = _stringPointerBase;

        template <ssize_t N>
        constexpr _stringPointer(StaticStringData<TChar, N>& data) : Base(reinterpret_cast<uint8_t*>(&data)) {}

        /// @brief nullptrとして作成
        constexpr _stringPointer(std::nullptr_t) noexcept : Base(nullptr) {}

        _stringPointer(_stringPointer const& right) = default;
        _stringPointer(_stringPointer&& right) = default;

        ~_stringPointer();

        [[nodiscard]] constexpr TChar* __getStringUnsafe() const noexcept { return (TChar*)(this->__p + Base::__stringIndex); }

        private:

        static ::std::set<_stringPointer> _set;
    };

    template <CharType TChar>
    [[nodiscard]] bool operator==(_stringPointer<TChar> const& left, _stringPointer<TChar> const& right) noexcept;

    template <CharType TChar>
    [[nodiscard]] bool operator!=(_stringPointer<TChar> const& left, _stringPointer<TChar> const& right) noexcept;

    template <CharType TChar>
    [[nodiscard]] bool operator<(_stringPointer<TChar> const& left, _stringPointer<TChar> const& right) noexcept;

    template <CharType TChar>
    [[nodiscard]] bool operator<=(_stringPointer<TChar> const& left, _stringPointer<TChar> const& right) noexcept;

    template <CharType TChar>
    [[nodiscard]] bool operator>(_stringPointer<TChar> const& left, _stringPointer<TChar> const& right) noexcept;

    template <CharType TChar>
    [[nodiscard]] bool operator>=(_stringPointer<TChar> const& left, _stringPointer<TChar> const& right) noexcept;

    template <CharType TChar>
    [[nodiscard]] ::std::strong_ordering operator<=>(_stringPointer<TChar> const& left, _stringPointer<TChar> const& right) noexcept;
}

#endif //!KONGKONG_TEXT_STRINGPOINTER_H
