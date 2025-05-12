#ifndef KONGKONG_ALGORITHMS_RADIXCONVERTER_H
#define KONGKONG_ALGORITHMS_RADIXCONVERTER_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Algorithms
{
    /// @brief 進数変換器
    struct RadixConverter final : public ValueType {

        /// @brief 基数を変換
        /// @param numStr inputRadixで表現された値
        /// @param inputRadix 入力する値の基数
        /// @param outputRadix 出力する値の基数
        /// @return outputRadixで表現された値
        /// @throws FormatException: 入力された値が数値でないとき
        /// @throws InvalidArgumentException: inputRadixとoutputRadixに2~36の範囲外の値を指定したとき、入力された値がinputRadixで表現できないとき
        /// @throws MemoryAllocationException: 処理に必要なヒープの確保に失敗したとき
        [[nodiscard]]
        static String Convert(String const& numStr, uint8_t inputRadix, uint8_t outputRadix);

        /// @brief 基数を変換
        /// @param numStr inputRadixで表現された値
        /// @param inputRadix 入力する値の基数
        /// @param outputRadix 出力する値の基数
        /// @return outputRadixで表現された値
        /// @throws ArgumentNullException: numStrがnullptrのとき
        /// @throws FormatException: 入力された値が数値でないとき
        /// @throws InvalidArgumentException: inputRadixとoutputRadixに2~36の範囲外の値を指定したとき、入力された値がinputRadixで表現できないとき
        /// @throws MemoryAllocationException: 処理に必要なヒープの確保に失敗したとき
        [[nodiscard]]
        static String Convert(const char16_t* numStr, uint8_t inputRadix, uint8_t outputRadix);

        /// @brief 基数を変換
        /// @param length numStrの長さ
        /// @param numStr inputRadixで表現された値
        /// @param inputRadix 入力する値の基数
        /// @param outputRadix 出力する値の基数
        /// @return outputRadixで表現された値
        /// @throws ArgumentNullException: numStrがnullptrのとき
        /// @throws FormatException: 入力された値が数値でないとき
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき inputRadixとoutputRadixに2~36の範囲外の値を指定したとき、入力された値がinputRadixで表現できないとき
        /// @throws MemoryAllocationException: 処理に必要なヒープの確保に失敗したとき
        [[nodiscard]]
        static String Convert(ssize_t length, const char16_t* numStr, uint8_t inputRadix, uint8_t outputRadix);

        /// @brief 基数を変換
        /// @param numStr inputRadixで表現された値
        /// @param inputRadix 入力する値の基数
        /// @param outputRadix 出力する値の基数
        /// @param decimalPrecision 表示する少数部分の最大桁数
        /// @return outputRadixで表現された値
        /// @throws FormatException: 入力された値が数値でないとき
        /// @throws InvalidArgumentException: inputRadixとoutputRadixに2~36の範囲外の値を指定したとき、入力された値がinputRadixで表現できないとき、decimalPrecisionが負であるかMaxDecimalPrecision()より大きいとき
        /// @throws MemoryAllocationException: 処理に必要なヒープの確保に失敗したとき
        [[nodiscard]]
        static String Convert(String const& numStr, uint8_t inputRadix, uint8_t outputRadix, ssize_t decimalPrecision);

        /// @brief 基数を変換
        /// @param numStr inputRadixで表現された値
        /// @param inputRadix 入力する値の基数
        /// @param outputRadix 出力する値の基数
        /// @param decimalPrecision 表示する少数部分の最大桁数
        /// @return outputRadixで表現された値
        /// @throws ArgumentNullException: numStrがnullptrのとき
        /// @throws FormatException: 入力された値が数値でないとき
        /// @throws InvalidArgumentException: inputRadixとoutputRadixに2~36の範囲外の値を指定したとき、入力された値がinputRadixで表現できないとき、decimalPrecisionが負であるかMaxDecimalPrecision()より大きいとき
        /// @throws MemoryAllocationException: 処理に必要なヒープの確保に失敗したとき
        [[nodiscard]]
        static String Convert(const char16_t* numStr, uint8_t inputRadix, uint8_t outputRadix, ssize_t decimalPrecision);

        /// @brief 基数を変換
        /// @param length numStrの長さ
        /// @param numStr inputRadixで表現された値
        /// @param inputRadix 入力する値の基数
        /// @param outputRadix 出力する値の基数
        /// @param decimalPrecision 表示する少数部分の最大桁数
        /// @return outputRadixで表現された値
        /// @throws ArgumentNullException: numStrがnullptrのとき
        /// @throws FormatException: 入力された値が数値でないとき
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき、inputRadixとoutputRadixに2~36の範囲外の値を指定したとき、入力された値がinputRadixで表現できないとき、decimalPrecisionが負であるかMaxDecimalPrecision()より大きいとき
        [[nodiscard]]
        static String Convert(ssize_t length, const char16_t* numStr, uint8_t inputRadix, uint8_t outputRadix, ssize_t decimalPrecision);

        /// @brief 表示可能な小数点以下の桁数の最大値
        [[nodiscard]]
        static constexpr ssize_t MaxDecimalPrecision() noexcept { return 1048575; }

        /// @brief 基数の最大値
        [[nodiscard]]
        static constexpr uint8_t MaxRadix() noexcept { return 36; }

        /// @brief 基数の最小値
        [[nodiscard]]
        static constexpr uint8_t MinRadix() noexcept { return 2; }

        /// @brief デフォルトの値で作成
        RadixConverter() noexcept;

        /// @param inputRadix 入力する値の基数
        /// @param outputRadix 出力する値の基数
        /// @throws InvalidArgumentException: inputRadixとoutputRadixに2~36の範囲外の値を指定したとき
        RadixConverter(uint8_t inputRadix, uint8_t outputRadix);

        /// @param inputRadix 入力する値の基数
        /// @param outputRadix 出力する値の基数
        /// @param decimalPrecision 表示する少数部分の最大桁数
        /// @throws InvalidArgumentException: inputRadixとoutputRadixに2~36の範囲外の値を指定したとき decimalPrecisionが負であるかMaxDecimalPrecision()より大きいとき
        RadixConverter(uint8_t inputRadix, uint8_t outputRadix, ssize_t decimalPrecision);

        /// @brief 別の進数表記に変換
        /// @param numStr InputRadix()進数で表現された文字列
        /// @return OutputRadix()で表現された文字列
        /// @throws FormatException: 入力された値が数値でないとき
        /// @throws InvalidArgumentException: 入力された値がInputRadix()で表現できないとき
        /// @throws MemoryAllocationException: 処理に必要なヒープの確保に失敗したとき
        [[nodiscard]]
        String Convert(String const& numStr) const;

        /// @brief 別の進数表記に変換
        /// @param numStr InputRadix()進数で表現された文字列
        /// @return OutputRadix()で表現された文字列
        /// @throws ArgumentNullException: numStrがnullptrのとき
        /// @throws FormatException: 入力された値が数値でないとき
        /// @throws InvalidArgumentException: 入力された値がInputRadix()で表現できないとき
        /// @throws MemoryAllocationException: 処理に必要なヒープの確保に失敗したとき
        [[nodiscard]]
        String Convert(const char16_t* numStr) const;

        /// @brief 別の進数表記に変換
        /// @param length 文字列の長さ
        /// @param numStr InputRadix()進数で表現された文字列
        /// @return OutputRadix()で表現された文字列
        /// @throws FormatException: 入力された値が数値でないとき
        /// @throws InvalidArgumentException: lengthがゼロ以下の時、入力された値がInputRadix()で表現できないとき
        /// @throws MemoryAllocationException: 処理に必要なヒープの確保に失敗したとき
        [[nodiscard]]
        String Convert(ssize_t length, const char16_t* numStr) const;

        /// @brief 表示する少数部分の最大桁数
        [[nodiscard]]
        constexpr ssize_t DecimalPrecision() const noexcept { return _decimalPrecision; }

        /// @brief 表示する少数部分の最大桁数を設定
        /// @param value 設定する値
        /// @throws InvalidArgumentException: valueが負であるかMaxDecimalPrecision()より大きいとき
        void DecimalPrecision(ssize_t value);

        /// @brief 入力する値の基数
        /// @param value 設定する値
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        constexpr uint8_t InputRadix() const noexcept { return _inputRadix; }

        /// @brief 入力する値の基数を設定
        /// @param value 設定する値
        /// @throws InvalidArgumentException: 2~36の範囲外の値を指定したとき
        void InputRadix(uint8_t value);

        /// @brief 出力する値の基数
        /// @throws InvalidArgumentException: 2~36の範囲外の値を指定したとき
        [[nodiscard]]
        constexpr uint8_t OutputRadix() const noexcept { return _outputRadix; }

        /// @brief 出力する値の基数を設定
        /// @param value 設定する値
        /// @throws InvalidArgumentException: 2~36の範囲外の値を指定したとき
        void OutputRadix(uint8_t value);

        String ToString() const;

        private:
        static constexpr ssize_t _defaultDecimalPrecision = 32;
        static constexpr ssize_t _defaultInputRadix = 10;
        static constexpr ssize_t _defaultOutputRadix = 16;

        static void _checkDecimalPrecision(ssize_t value);
        static void _checkRadix(uint8_t radix);
        static Collections::Turbo::FastArrayList<uint8_t> _createNumVec(ssize_t length, const char16_t* numStr, uint8_t inputRadix, bool& hasDecimal);

        static void _irekae3(short* vec, unsigned ketasu, int sinsu);
        static void _irekae4(short* vec, unsigned ketasu, int sinsu);

        static void _printValue(String& str, const short* p, unsigned ketasu, unsigned power, int sinsu) noexcept;

        static char16_t _toChar(short num) noexcept;

        static uint8_t _toNumberFromLowerChar(char16_t c) noexcept;
        static uint8_t _toNumberFromNumChar(char16_t c) noexcept;
        static uint8_t _toNumberFromUpperChar(char16_t c) noexcept;

        /// @brief ToString()で使用
        /// @param str 書き込み先の文字列
        /// @param value 値
        static void _toString(String& str, ssize_t value) noexcept;
        
        ssize_t _decimalPrecision;
        uint8_t _inputRadix;
        uint8_t _outputRadix;

        String _convertUnsafeNoLengthCheck(ssize_t length, const char16_t* numStr) const;

    };

}

#endif //!KONGKONG_ALGORITHMS_RADIXCONVERTER_H
