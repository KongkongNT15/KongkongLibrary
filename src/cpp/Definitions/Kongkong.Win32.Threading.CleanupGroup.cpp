//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    CleanupGroup::CleanupGroup() : _cleanupGroupBase(::CreateThreadpoolCleanupGroup())
    {
        if (_cleanupGroup == nullptr) [[unlikely]] throw HResultException();
    }

    CleanupGroup::~CleanupGroup()
    {
        if (_cleanupGroup != nullptr) ::CloseThreadpoolCleanupGroup(_cleanupGroup);
    }

    CleanupGroup& CleanupGroup::operator=(CleanupGroup&& right) noexcept
    {
        CleanupGroup::~CleanupGroup();

        _cleanupGroup = right._cleanupGroup;
        right._cleanupGroup = nullptr;

        return *this;
    }

    CleanupGroup& CleanupGroup::operator=(::std::nullptr_t) noexcept
    {
        CleanupGroup::~CleanupGroup();

        _cleanupGroup = nullptr;

        return *this;
    }

    String CleanupGroup::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Win32::Threading::CleanupGroup");
    }
}
