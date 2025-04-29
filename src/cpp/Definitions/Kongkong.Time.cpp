//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Time
{

    DateTime::DateTime(std::time_t time, DateTimeKind kind) : _kind(kind)
    {
        switch (kind) {
            case DateTimeKind::Utc: _tm = *(std::gmtime(&time)); break;
            case DateTimeKind::Local: _tm = *(std::localtime(&time)); break;
            default: [[unlikely]] throw InvalidArgumentException(u"An invalid value was passed to 'kind'.");
        }
    }

    String DateTime::ToString() const
    {
        constexpr ssize_t size = 20;
        char str[size];

        std::snprintf(str, size, "%04d/%02d/%02d %02d:%02d:%02d", _tm.tm_year + 1900, _tm.tm_mon, _tm.tm_mday, _tm.tm_hour, _tm.tm_min, _tm.tm_sec);

        return String::FromAsciiUnsafe(str);
    }

    DateTime DateTime::AddSeconds(int64_t seconds) const
    {
        time_t t = mktime((tm*)&_tm);
        
        t += seconds;

        return DateTime(*(localtime(&t)), Kind());
    }

    time_t DateTime::_lgDifference()
    {
        time_t t = time(nullptr);
        tm current = *(localtime(&t));
        tm gcurrent = *(gmtime(&t));
        time_t tl = mktime(&current);
        time_t tg = mktime(&gcurrent);
        return tl - tg;
    }
    
}
