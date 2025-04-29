//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    Event::Event(bool isManualReset, bool isSet) : Event(nullptr, isManualReset, isSet, nullptr)
    {
    }

    Event::Event(std::nullptr_t, bool isManualReset, bool isSet) : Event(nullptr, isManualReset, isSet, nullptr)
    {
    }

    Event::Event(const char16_t* name, bool isManualReset, bool isSet) : Event(name, isManualReset, isSet, nullptr)
    {
    }

    Event::Event(String const& name, bool isManualReset, bool isSet) : Event(name.c_str(), isManualReset, isSet, nullptr)
    {
    }

    Event::Event(bool isManualReset, bool isSet, ::SECURITY_ATTRIBUTES& sa) : Event(nullptr, isManualReset, isSet, &sa)
    {
    }

    Event::Event(std::nullptr_t, bool isManualReset, bool isSet, ::SECURITY_ATTRIBUTES& sa) : Event(nullptr, isManualReset, isSet, &sa)
    {
    }

    Event::Event(const char16_t* name, bool isManualReset, bool isSet, ::SECURITY_ATTRIBUTES& sa) : Event(name, isManualReset, isSet, &sa)
    {
    }

    Event::Event(String const& name, bool isManualReset, bool isSet, ::SECURITY_ATTRIBUTES& sa) : Event(name.c_str(), isManualReset, isSet, &sa)
    {
    }

    void Event::Reset() const
    {
        Primitives::SyncHAPI::ResetEvent(_h.__rawHandle());
    }

    bool Event::ResetUnsafe() const noexcept
    {
        return Primitives::SyncHAPI::ResetEventUnsafe(_h.__rawHandle());
    }

    void Event::Set() const
    {
        Primitives::SyncHAPI::SetEvent(_h.__rawHandle());
    }

    bool Event::SetUnsafe() const noexcept
    {
        return Primitives::SyncHAPI::SetEventUnsafe(_h.__rawHandle());
    }

    Event::Event(const char16_t* name, bool isManualReset, bool isSet, ::LPSECURITY_ATTRIBUTES sa) : WaitHandle(nullptr)
    {
        ::HANDLE h = ::CreateEventW(sa, isManualReset, isSet, (const wchar_t*)name);

        if (h == nullptr) [[unlikely]] throw HResultException();

        _h.__rawHandle(h, ClassType::Event);
    }

    String Event::_toString(Handle const&)
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Win32::Threading::Event");
    }
}

CREATE_CLASS_TYPE(Threading::Event, Event)
