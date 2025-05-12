#ifndef KONGKONG_TEXT_JSON_JSONPARSER_H
#define KONGKONG_TEXT_JSON_JSONPARSER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Text::Json
{
    class JsonParser final {
        public:

        STATIC_CLASS(JsonParser)

        /// @brief ふぁ！？っく
        static JsonObject FromFile(::std::nullptr_t) = delete;

        /// @brief JSONファイルの読み込み
        /// @param filePath ファイルパス
        /// @return 最上位オブジェクト
        /// @throws ArgumentNullException: filePathがnullptrのとき
        /// @throws FormatException: ファイルの構文が正しくないとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static JsonObject FromFile(const char* filePath);

        /// @brief JSONファイルの読み込み
        /// @param filePath ファイルパス
        /// @return 最上位オブジェクト
        /// @throws ArgumentNullException: filePathがnullptrのとき
        /// @throws FormatException: ファイルの構文が正しくないとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static JsonObject FromFile(const char16_t* filePath);

        /// @brief JSONファイルの読み込み
        /// @param filePath ファイルパス
        /// @return 最上位オブジェクト
        /// @throws FormatException: ファイルの構文が正しくないとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static JsonObject FromFile(CharString const& filePath);

        /// @brief JSONファイルの読み込み
        /// @param filePath ファイルパス
        /// @return 最上位オブジェクト
        /// @throws FormatException: ファイルの構文が正しくないとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static JsonObject FromFile(String const& filePath);

        /// @brief ふぁ！？っく
        static JsonObject FromFileUnsafe(::std::nullptr_t) = delete;

        /// @brief JSONファイルの読み込み
        /// @param filePath ファイルパス
        /// @return 最上位オブジェクト
        /// @throws FormatException: ファイルの構文が正しくないとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static JsonObject FromFileUnsafe(const char* filePath);

        /// @brief JSONファイルの読み込み
        /// @param filePath ファイルパス
        /// @return 最上位オブジェクト
        /// @throws FormatException: ファイルの構文が正しくないとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static JsonObject FromFileUnsafe(const char16_t* filePath);

        private:

        enum struct syntax;

        static syntax _getChar(::FILE* fp, Utf8String& str, syntax current);

        /// @brief 
        /// @param fp 
        /// @param str 
        static void _getStringChar(::FILE* fp, Utf8String& str);

        static bool _hasUtf8BOM(::FILE* fp, Utf8String& str) noexcept;

        static syntax _parse(::FILE* fp, void* pObj, Utf8String& str, syntax synt);

        static JsonValue _createValue(::FILE* fp, Utf8String& str, syntax synt);

        static bool _isLastObjectValue(::FILE* fp, Utf8String& str, syntax synt);
        static bool _isLastArrayValue(::FILE* fp, Utf8String& str, syntax synt);

        enum struct syntax {
            arrayBegin,         //[
            arrayElement,
            arrayEnd,           //]
            objectBegin,        //{
            boolean,            //真偽値
            booleanBegin,
            colon,              //:
            comma,              //,
            objectEnd,          //}
            eof,                //文書の終わり
            floatingPoint,      //浮動小数点数
            floatingPointBegin,
            keyValuePairBegin,  //
            keyValuePairM,      //
            keyValuePairLast,   //
            keyValuePairEnd,
            null,               //null
            nullBegin,
            string,             //文字列値
            stringBegin,
            stringEnd,
            textBegin,
            
        };
    };
}

#endif //!KONGKONG_TEXT_JSON_JSONPARSER_H
