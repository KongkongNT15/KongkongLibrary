//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE
{
    Exception::Exception(::KONGKONG_NAMESPACE::String const& errorMessage) :
        _errorMessage(errorMessage, true)
    {
        _checkMessage();
    }

    Exception::Exception(::KONGKONG_NAMESPACE::String&& errorMessage) :
        _errorMessage(std::move(errorMessage))
    {
        _checkMessage();
    }

    Exception::Exception(const char16_t* errorMessage) :
        _errorMessage(errorMessage, true)
    {
        _checkMessage();
    }

    String Exception::ToString() const
    {
        return _errorMessage;
    }

    void Exception::_checkMessage()
    {
        if (_errorMessage.IsEmpty()) [[unlikely]] {
            _errorMessage = String(u"ふぁ！？っく", true);
        }
    }

    String operator+(String const& left, Exception const& right)
    {
        String str = left;
        str.Append(right.Message());

        return str;
    }

    String operator+(String&& left, Exception const& right)
    {
        left.Append(right.Message());

        return left;
    }
    
}
