//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    uint32_t ProcessThreadAPI::GetExitCodeThread(::HANDLE hObject)
    {
        DWORD code;
        if (::GetExitCodeThread(hObject, &code) == 0) [[unlikely]] throw HResultException();

        return code;
    }

    uint32_t ProcessThreadAPI::GetExitCodeThreadUnsafe(::HANDLE hObject) noexcept
    {
        DWORD code;
        ::GetExitCodeThread(hObject, &code);

        return code;
    }

    uint32_t ProcessThreadAPI::GetThreadId(::HANDLE hThread)
    {
        DWORD result = ::GetThreadId(hThread);

        if (result == 0) [[unlikely]] throw HResultException();

        return result;
    }

    uint32_t ProcessThreadAPI::ResumeThread(::HANDLE hThread)
    {
        uint32_t v = ::ResumeThread(hThread);
        if (v == (uint32_t)-1) [[unlikely]] throw HResultException();

        return v;
    }

    uint32_t ProcessThreadAPI::SuspendThread(::HANDLE hThread)
    {
        uint32_t v = ::SuspendThread(hThread);
        if (v == (uint32_t)-1) [[unlikely]] throw HResultException();

        return v;
    }

    void ProcessThreadAPI::TerminateThread(::HANDLE hThread, uint32_t exitCode)
    {
        if (::TerminateThread(hThread, exitCode) == 0) [[unlikely]] throw HResultException();
    }

}
