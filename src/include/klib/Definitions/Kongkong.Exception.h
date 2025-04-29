#ifndef KONGKONG_EXCEPTION_H
#define KONGKONG_EXCEPTION_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.GenericString.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief すべてのKongkong例外の基底クラス
    struct Exception : public ValueType {

        /// @brief ふぁ！？っく
        Exception(std::nullptr_t) = delete;

        /// @param errorMessage 例外メッセージ
        /// @attention errorMessageを空の文字列にすると例外メッセージが「ふぁ！？っく」になるよ
        explicit Exception(String const& errorMessage);

        /// @param errorMessage 例外メッセージ
        /// @attention errorMessageを空の文字列にすると例外メッセージが「ふぁ！？っく」になるよ
        explicit Exception(String&& errorMessage);

        /// @param errorMessage 例外メッセージ
        /// @attention errorMessageを空の文字列にすると例外メッセージが「ふぁ！？っく」になるよ
        explicit Exception(const char16_t* errorMessage);

        /// @brief コピーする意味あるんですか？？？
        Exception& operator=(Exception const&) = delete;

        /// @brief 例外メッセージを取得
        String ToString() const;

        /// @brief 例外メッセージを取得
        constexpr String const& Message() const noexcept { return _errorMessage; }

        private:
        /// @brief 例外メッセージ
        String _errorMessage;

        //ふぁ！？っく
        constexpr Exception(int) : _errorMessage(0) {}

        void _checkMessage();

        //ふぁ！？っく
        friend MemoryException;
        //ふぁ！？っく
        friend MemoryAllocationException;
    };

    [[nodiscard]] String operator+(String const& left, Exception const& right);
    [[nodiscard]] String operator+(String&& left, Exception const& right);
}

#endif //!KONGKONG_EXCEPTION_H
