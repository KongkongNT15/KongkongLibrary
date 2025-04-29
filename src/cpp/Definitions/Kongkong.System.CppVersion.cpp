//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::System
{
    String CppVersion::ToString() const
    {
        switch (_version) {
            case KONGKONG_CPP03: return String::FromLiteral(u"C++03");
            case KONGKONG_CPP11: return String::FromLiteral(u"C++11");
            case KONGKONG_CPP14: return String::FromLiteral(u"C++14");
            case KONGKONG_CPP17: return String::FromLiteral(u"C++17");
            case KONGKONG_CPP20: return String::FromLiteral(u"C++20");
            case KONGKONG_CPP23: return String::FromLiteral(u"C++23");

            default: [[unlikely]] return String::FromLiteral(u"Unknown Version");
        }

        //C++23 ::std::unreachable();
    }
}
