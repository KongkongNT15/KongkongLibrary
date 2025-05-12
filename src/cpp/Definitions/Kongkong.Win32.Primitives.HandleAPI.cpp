//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    void HandleAPI::Close(::HANDLE hObject)
    {
        if (::CloseHandle(hObject) == 0) [[unlikely]] throw HResultException();
    }

    HandleFrag HandleAPI::GetFrags(::HANDLE hObject)
    {
        DWORD frag;

        if (::GetHandleInformation(hObject, &frag) == 0) [[unlikely]] throw HResultException();

        return (HandleFrag)frag;
    }

    bool HandleAPI::IsEqual(::HANDLE left, ::HANDLE right) noexcept
    {
        //return (bool)::CompareObjectHandles(left, right);
        return false;
    }

}
