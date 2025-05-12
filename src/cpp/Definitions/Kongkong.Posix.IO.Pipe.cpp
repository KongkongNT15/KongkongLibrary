//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::IO
{
    Pipe::Pipe() : _in(nullptr), _out(nullptr)
    {
        int fds[2];

        if (::pipe(fds) == EOF) [[unlikely]] throw PosixException();

        _in._h.__fd = fds[0];
        _out._h.__fd = fds[1];
    }

    void Pipe::Close()
    {
        _in.Close();
        _out.Close();
    }

    String Pipe::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Posix::IO::Streams::Pipe");
    }

}
