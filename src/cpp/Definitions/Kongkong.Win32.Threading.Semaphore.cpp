//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    String Semaphore::_toString(Handle const&)
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Win32::Threading::Semaphore");
    }
}

CREATE_CLASS_TYPE(Threading::Semaphore, Semaphore)
