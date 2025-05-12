//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::IMPLEMENTATION
{
    Process::ProjType Process::_current = nullptr;

    Process::ProjType const& Process::Current()
    {
        if (_current == nullptr) _current = ProjType(false);

        return _current;
    }

    void Process::Exit(int status) noexcept
    {
        ::_exit(status);
    }

    String Process::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Posix::Process");
    }
}

namespace KONGKONG_NAMESPACE::Posix
{
    Process const& Process::Current()
    {
        return ImplType::Current();
    }

    void Process::Exit(int status) noexcept
    {
        ImplType::Exit(status);
    }

    Process::Process(bool) : Object(nullptr)
    {
        _setInstance(NEW ImplType(true));
    }
}
