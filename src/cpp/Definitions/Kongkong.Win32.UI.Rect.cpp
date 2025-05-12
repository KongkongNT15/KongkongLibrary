//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::UI
{
    String Rect::ToString() const
    {
        std::ostringstream sout;

        sout << Left() << ", " << Top() << ", " << Right() << ", " << Bottom();

        return String::FromAscii(sout.str());
    }
}
