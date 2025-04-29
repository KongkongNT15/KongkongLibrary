//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Json
{
    JsonObject JsonParser::FromFile(const char* filePath)
    {
        ArgumentNullException::CheckNull(filePath, u"filePath");

        return FromFileUnsafe(filePath);
    }

    JsonObject JsonParser::FromFile(const char16_t* filePath)
    {
        ArgumentNullException::CheckNull(filePath, u"filePath");

        return FromFileUnsafe(StringHelper::ToCharStringUnsafe(StringHelper::GetLengthUnsafe(filePath), filePath).c_str());
    }

    JsonObject JsonParser::FromFile(CharString const& filePath)
    {
        return FromFileUnsafe(filePath.c_str());
    }

    JsonObject JsonParser::FromFile(String const& filePath)
    {
        return FromFileUnsafe(filePath.ToCharString().c_str());
    }

    JsonObject JsonParser::FromFileUnsafe(const char* filePath)
    {
        struct fileCloser {

            constexpr fileCloser(::FILE* fp) noexcept : m_fp(fp) {}
            
            ~fileCloser() { ::fclose(m_fp); }

            private:
            ::FILE* m_fp;
        };
        ::FILE* fp = ::fopen(filePath, "rb");
        ssize_t i;
        constexpr char16_t errorMessage[] = u"";

        if (fp == nullptr) [[unlikely]] throw IOException(u"指定されたファイルを開けませんでした");

        fileCloser closer(fp);

        //bom
        int bomArr[3];
        constexpr int utf8Bom[3] { 0xEF, 0xBB, 0xBF };
        bool hasBom = true;

        for (int& v : bomArr) v = ::fgetc(fp);

        for (i = 0; i != 3; i++) {
            if (bomArr[i] == EOF) [[unlikely]] {
                if (i != 0) throw FormatException(errorMessage);

                return nullptr;
            }

            if (bomArr[i] != utf8Bom[i]) {
                hasBom = false;
                break;
            }
        }

        if (hasBom == false) {
            for (i = 2; i >= 0; i--) ::ungetc(bomArr[i], fp);
        }

        JsonObject obj;
        Utf8String str;

        _parse(fp, obj.RawPointer(), str, syntax::textBegin);

        return obj;
    }

    JsonObject JsonParser::FromFileUnsafe(const char16_t* filePath)
    {
        return FromFileUnsafe(StringHelper::ToCharStringUnsafe(StringHelper::GetLengthUnsafe(filePath), filePath).c_str());
    }

    JsonParser::syntax JsonParser::_parse(::FILE* fp, void* pObj, Utf8String& str, syntax synt)
    {
        switch (synt) {
            case syntax::arrayBegin:
            {
                auto& jsonArray = *static_cast<JsonArray::ImplType*>(pObj);

                while (_parse(fp, &jsonArray, str, syntax::arrayElement) != syntax::arrayEnd);

                return syntax::arrayEnd;
            }
            case syntax::arrayElement:
            {
                auto& jsonArray = *static_cast<JsonArray::ImplType*>(pObj);
                auto syntac = _getChar(fp, str, syntax::arrayElement);

                switch (syntac) {
                    case syntax::arrayBegin:
                    {
                        JsonArray jsonArray2;
                        _parse(fp, jsonArray2.RawPointer(), str, syntax::arrayBegin);

                        jsonArray.Append(::std::move(jsonArray2));
                        break;
                    }
                    case syntax::booleanBegin:
                    case syntax::floatingPointBegin:
                    {
                        jsonArray.Append(_createValue(fp, str, syntac));
                        break;
                    }
                    case syntax::objectBegin:
                    {
                        JsonObject obj2;
                        _parse(fp, obj2.RawPointer(), str, syntax::objectBegin);

                        jsonArray.Append(::std::move(obj2));
                        break;
                    }
                    case syntax::stringBegin:
                    {
                        _getStringChar(fp, str);
                        jsonArray.Append(str.ToString());
                        str.Clear();
                        break;
                    }

                    default: [[unlikely]] throw FormatException(u"無効な構文ですねぇ");
                }

                return _isLastArrayValue(fp, str, syntax::arrayEnd) ? syntax::arrayEnd : syntax::arrayElement;
            }
            case syntax::comma: [[unlikely]] throw FormatException(u"','の位置が無効です");
            case syntax::keyValuePairBegin:
            {
                auto& obj = *static_cast<JsonObject::ImplType*>(pObj);
                
                if (_getChar(fp, str, syntax::keyValuePairBegin) != syntax::stringBegin) [[unlikely]] throw FormatException(u"オブジェクトの値が無効です");
                _getStringChar(fp, str);

                String key = str.ToString();
                str.Clear();

                if (_getChar(fp, str, syntax::keyValuePairM) != syntax::colon) [[unlikely]] throw FormatException(u"ペアの構文が正しくありません");

                auto syntac = _getChar(fp, str, syntax::keyValuePairLast);
                

                switch (syntac) {
                    case syntax::arrayBegin:
                    {
                        JsonArray jsonArray;
                        _parse(fp, jsonArray.RawPointer(), str, syntax::arrayBegin);
                        obj.Insert(::std::move(key), ::std::move(jsonArray));
                        break;
                    }
                    case syntax::booleanBegin:
                    case syntax::floatingPointBegin:
                    case syntax::nullBegin:
                    {
                        obj.Insert(::std::move(key), _createValue(fp, str, syntac));
                        break;
                    }
                    case syntax::stringBegin:
                    {
                        _getStringChar(fp, str);
                        obj.Insert(::std::move(key), str.ToString());
                        str.Clear();
                        break;
                    }
                    case syntax::objectBegin:
                    {
                        JsonObject obj2;
                        _parse(fp, obj2.RawPointer(), str, syntax::objectBegin);

                        obj.Insert(::std::move(key), ::std::move(obj2));
                        break;
                    }

                    default: [[unlikely]] throw FormatException(u"形式が正しくありません");
                }

                return _isLastObjectValue(fp, str, syntac) ? syntax::objectEnd : syntax::keyValuePairBegin;
            }
            case syntax::objectBegin:
            {
                while (_parse(fp, pObj, str, syntax::keyValuePairBegin) == syntax::keyValuePairBegin);
                
                return syntax::objectEnd;
            }
            case syntax::textBegin:
            {
                if (_getChar(fp, str, synt) != syntax::objectBegin) [[unlikely]] throw FormatException(u"先頭の型はオブジェクトである必要があります");
                return _parse(fp, pObj, str, syntax::objectBegin);
            }

            default: [[unlikely]] return syntax::eof;
        }

#if KONGKONG_HAS_CPP23
        ::std::unreachable();
#endif
    }

    JsonValue JsonParser::_createValue(::FILE* fp, Utf8String& str, syntax synt)
    {
        ::std::istringstream sin((const char*)str.c_str());
        switch (synt) {
            case syntax::booleanBegin:
            {
                constexpr char trueChars[] = "true";
                constexpr char falseChars[] = "false";

                char chars[5];

                for (char& c : chars) {
                    int v = ::fgetc(fp);
                    if (v == EOF) [[unlikely]] throw FormatException(u"文書が途中で終了しています");
                    c = (char)v;
                }

                if (::memcmp(trueChars, chars, 4) == 0) {
                    ::ungetc(chars[4], fp);
                    return true;
                }

                if (::memcmp(falseChars, chars, 5) == 0) {
                    return false;
                }

                throw FormatException(u"文書内に無効な値が見つかりました");
            }
            case syntax::floatingPoint:
            {
                bool flag = true;

                while (flag) {
                    int c = ::fgetc(fp);
                    switch (c) {
                        // JSONの末尾は必ず'}'
                        case EOF: [[unlikely]] throw FormatException(u"文書が途中で終了しています");
                        
                        case '-':
                        case '.':
                        case '+':
                        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                        {
                            str.Append((char8_t)c);
                            break;
                        }

                        default:
                        {
                            flag = false;
                            ::ungetc(c, fp);
                            break;
                        }
                    }
                }

                ::std::istringstream sin((const char*)str.c_str());
                
                double value;
                sin >> value;

                if (!sin || sin.tellg() != str.Length()) [[unlikely]] throw FormatException(u"数値が無効です");
                str.Clear();

                return value;
            }
            case syntax::nullBegin:
            {
                constexpr char charsNull[] = "null";
                char chars[4];

                for (char& c : chars) {
                    int v = ::fgetc(fp);

                    if (v == EOF) [[unlikely]] throw FormatException(u"文書が途中で終了しています");

                    c = (char)v;
                }

                if (memcmp(charsNull, chars, 4) != 0) [[unlikely]] throw FormatException(u"無効な値です");

                return nullptr;
            }
        }
    }

    bool JsonParser::_isLastArrayValue(::FILE* fp, Utf8String& str, syntax synt)
    {
        switch (_getChar(fp, str, synt)) {
            case syntax::eof: [[unlikely]] throw FormatException(u"文書が途中で終了しています");
            case syntax::comma:
            {
                if (synt == syntax::comma) [[unlikely]] throw FormatException(u"コンマが2回続いています");
                return _isLastArrayValue(fp, str, syntax::comma);
            }
            case syntax::arrayEnd:
            {
                return true;
            }
            case syntax::booleanBegin:
            case syntax::floatingPointBegin:
            {
                return false;
            }
            case syntax::stringBegin:
            {
                ::ungetc('"', fp);
                return false;
            }
            case syntax::objectBegin:
            {
                ::ungetc('{', fp);
                return false;
            }

            default: [[unlikely]] throw FormatException(u"構文が無効です");
        }
    }

    bool JsonParser::_isLastObjectValue(::FILE* fp, Utf8String& str, syntax synt)
    {
        switch (_getChar(fp, str, synt)) {
            case syntax::eof: [[unlikely]] throw FormatException(u"文書が途中で終了しています");
            case syntax::comma:
            {
                if (synt == syntax::comma) [[unlikely]] throw FormatException(u"コンマが2回続いています");
                return _isLastObjectValue(fp, str, syntax::comma);
            }
            case syntax::objectEnd:
            {
                return true;
            }
            case syntax::stringBegin:
            {
                ::ungetc('"', fp);
                return false;
            }

            default: [[unlikely]] throw FormatException(u"構文が無効です");
        }
    }

    JsonParser::syntax JsonParser::_getChar(::FILE* fp, Utf8String& str, syntax current)
    {
#if KONGKONG_HAS_CPP23
        [[assume(fp != nullptr)]];
#endif  
        while (true) {
            int c = ::fgetc(fp);

            switch (c) {
                case EOF: return syntax::eof;

                case '\r':
                {
                    int cc = ::fgetc(fp);
                    
                    switch (cc) {
                        case EOF:  //CR 文書の終端
                            return syntax::eof;
                        case '\n': //CRLF
                            break;
    
                        default:
                            break;
                    }
    
                    break;
                }
                // 改行文字と空白文字は無視
                case '\n':
                case '\t':
                case ' ':
                    break;

                // コメント文
                case '/':
                {
                    switch (::fgetc(fp)) {
                        // 行の末尾まで
                        case '/':
                        {
                            int cc;
                            bool flag = true;

                            while (flag) {
                                cc = ::fgetc(fp);
                                switch (cc) {
                                    case EOF: return syntax::eof;
                                    case '\n':
                                        flag = false;
                                        break;
                                    case '\r':
                                    {
                                        cc = ::fgetc(fp);
                                        switch (cc) {
                                            case EOF: return syntax::eof;
                                            case '\n':
                                                flag = false;
                                                break;
                                            
                                            //次の行へ
                                            default:
                                                ::ungetc(cc, fp);
                                                flag = false;
                                                break;
                                        }

                                        break;
                                    }
                                    default: break;
                                }
                            }

                            break;
                        }
                        /* このスタイルのコメント文 */
                        case '*':
                        {
                            bool flag = true;

                            while (flag) {
                                switch (::fgetc(fp)) {
                                    case EOF: [[unlikely]] throw FormatException(u"コメント文の形式が正しくありません");
                                    case '*':
                                    {
                                        // "*/"の形式でなければまだコメント文
                                        if (::fgetc(fp) != '/') break;
                                        flag = false;
                                        break;
                                    }
                                    default: break;
                                }
                            }
                            break;
                        }
                        default: [[unlikely]] throw FormatException(u"コメント文の形式が正しくありません");
                    }

                    break;
                }

                case '[': return syntax::arrayBegin;
                case ']': return syntax::arrayEnd;
                case ',': return syntax::comma;
                case '"': return syntax::stringBegin;
                case ':': return syntax::colon;
                case '{': return syntax::objectBegin;
                case '}': return syntax::objectEnd;

                //bool値の可能性大
                case 'f':
                case 't':
                {
                    ::ungetc(c, fp);
                    return syntax::booleanBegin;
                }

                //nullの可能性大
                case 'n':
                {
                    ::ungetc('n', fp);
                    return syntax::nullBegin;
                }
                
                case '-':
                case '+':
                {
                    ::ungetc(c, fp);
                    return syntax::floatingPointBegin;
                }
                default:
                {
                    if (::isdigit(c)) {
                        ::ungetc(c, fp);
                        return syntax::floatingPointBegin;
                    }

                    printf("c = %d, '%c'\n", c, (char)c);
                    throw FormatException(u"文書の形式が無効です");
                }
            }
        }
#if KONGKONG_HAS_CPP23
        ::std::unreachable();
#endif
    }

    void JsonParser::_getStringChar(::FILE* fp,  Utf8String& str)
    {
#if KONGKONG_HAS_CPP23
        [[assume(fp != nullptr)]];
#endif  


        while (true) {
            int c = ::fgetc(fp);

            switch (c) {
                case EOF: throw FormatException(u"文字列値の途中でテキストが終了しています");

                //エスケープ文字
                case '\\':
                {
                    int cc = ::fgetc(fp);

                    switch (cc) {
                        case '\\': str.Append(u8'\\'); break; // "\\"
                        case '"': str.Append(u8'"'); break;
                        case 'b': str.Append(u8'\b'); break;
                        case 'f': str.Append(u8'\f'); break;
                        case 'n': str.Append(u8'\n'); break;
                        case 'r': str.Append(u8'\r'); break;
                        case 't': str.Append(u8'\t'); break;
                        case 'u':
                        {
                            char32_t c32{};
                            for (int i = 0; i != 4; i++) {
                                cc = ::fgetc(fp);
                                if (!::isxdigit(cc)) [[unlikely]] throw FormatException(u"文字コードの形式が正しくありません");

                                c32 *= 0x10;
                                c32 += (char32_t)(cc - '0');
                            }

                            if (c32 < 0x80) {
                                str.Append((char8_t)c32);
                                break;
                            }
                            if (c32 < 0x800) {
                                str.Append((char8_t)(0xC0 | ((c32 >> 6) & 0x1F)));
                                str.Append((char8_t)(0x80 | (c32 & 0x3F)));
                                break;
                            }
                            if (c32 < 0x10000) {
                                str.Append((char8_t)(0xE0 | ((c32 >> 12) & 0x0F)));
                                str.Append((char8_t)(0x80 | ((c32 >> 6) & 0x3F)));
                                str.Append((char8_t)(0x80 | (c32 & 0x3F)));
                                break;
                            }
                            if (c32 < 0x110000) {
                                str.Append((char8_t)(0xF0 | ((c32 >> 18) & 0x07)));
                                str.Append((char8_t)(0x80 | ((c32 >> 12) & 0x3F)));
                                str.Append((char8_t)(0x80 | ((c32 >> 6) & 0x3F)));
                                str.Append((char8_t)(0x80 | (c32 & 0x3F)));
                                break;
                            }
                            
                            throw FormatException(u"無効なコードポイントです");
                        }
                    }

                    break;
                }

                case '"': return;
                
                case '\n':
                case '\r':
                {
                    throw FormatException(u"文字列中に無効な文字が検出されました");
                }

                default:
                {
                    str.Append((char8_t)c);
                    break;
                }
            }
        }

#if KONGKONG_HAS_CPP23
        ::std::unreachable();
#endif
    }
}
