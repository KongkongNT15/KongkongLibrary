//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Threading
{
    String _asyncOperationBase::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Threading::AsyncOperation<T>");
    }

    void _asyncOperationBase::_throw()
    {
        throw InvalidOperationException(u"失敗したコルーチンから値を取得しようとしました");
    }
}
