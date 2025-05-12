//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE
{
    TypeInfo::TypeInfo(TypeInfo const& right) :
        _hashCode(right._hashCode),
        _name(nullptr)
    {
        size_t length = ::strlen(right._name);

        delete[] _name;

        _name = new char[length + 1];

        ::memcpy(_name, right._name, length);
    }

    TypeInfo::TypeInfo(TypeInfo&& right) :
        _hashCode(right._hashCode),
        _name(right._name)
    {
        right._name = nullptr;
    }

    TypeInfo::TypeInfo(::std::type_info const& info) :
        _hashCode(info.hash_code()),
        _name(nullptr)
    {
        size_t length = ::strlen(info.name());

        _name = new char[length + 1];

        ::memcpy(_name, info.name(), length);
    }

    TypeInfo::~TypeInfo()
    {
        if (_name != nullptr) delete[] _name;
    }

    TypeInfo& TypeInfo::operator=(TypeInfo const& right)
    {
        size_t length = ::strlen(right._name);

        char* tmp = NEW char[length + 1];

        MemoryAllocationException::CheckNull(tmp);

        delete[] _name;

        ::memcpy(tmp, right._name, length);

        _hashCode = right._hashCode;
        _name = tmp;

        return *this;
    }

    TypeInfo& TypeInfo::operator=(TypeInfo&& right)
    {
        delete[] _name;

        _hashCode = right._hashCode;
        _name = right._name;

        right._name = nullptr;

        return *this;
    }

    String TypeInfo::ToString() const
    {
        return String(u"KONGKONG_NAMESPACE::TypeInfo", true);
    }
}
