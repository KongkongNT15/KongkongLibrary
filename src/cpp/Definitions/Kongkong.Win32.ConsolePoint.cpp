//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32
{
    String ConsolePoint::ToString() const
    {
        std::ostringstream sout;

        sout << X() << ", " << Y();

        return String::FromAscii(sout.str());
    }
}
