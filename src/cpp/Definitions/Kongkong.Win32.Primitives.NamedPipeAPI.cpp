//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    void NamedPipeAPI::Create(HANDLE& hReadPipe, HANDLE& hWritePipe)
    {
        Create(hReadPipe, hWritePipe, 0);
    }
    
    void NamedPipeAPI::Create(HANDLE& hReadPipe, HANDLE& hWritePipe, uint32_t bufferSize)
    {
        if (::CreatePipe(&hReadPipe, &hWritePipe, nullptr, bufferSize) == 0) [[unlikely]] throw HResultException();
    }

    void NamedPipeAPI::Create(HANDLE& hReadPipe, HANDLE& hWritePipe, ::SECURITY_ATTRIBUTES& securityAttributes)
    {
        Create(hReadPipe, hWritePipe, securityAttributes, 0);
    }

    void NamedPipeAPI::Create(HANDLE& hReadPipe, HANDLE& hWritePipe, ::SECURITY_ATTRIBUTES& securityAttributes, uint32_t bufferSize)
    {
        if (::CreatePipe(&hReadPipe, &hWritePipe, &securityAttributes, bufferSize) == 0) [[unlikely]] throw HResultException();
    }

    void NamedPipeAPI::WaitNamedPipe(const char16_t* pipeName)
    {
        WaitNamedPipe(pipeName, NMPWAIT_USE_DEFAULT_WAIT);
    }

    void NamedPipeAPI::WaitNamedPipe(String const& pipeName)
    {
        WaitNamedPipe(pipeName.c_str());
    }

    void NamedPipeAPI::WaitNamedPipe(const char16_t* pipeName, uint32_t wait)
    {
        if (::WaitNamedPipeW((const wchar_t*)pipeName, wait) == 0) throw HResultException();
    }

    void NamedPipeAPI::WaitNamedPipe(String const& pipeName, uint32_t wait)
    {
        WaitNamedPipe(pipeName.c_str(), wait);
    }

    void NamedPipeAPI::WaitNamedPipeForever(const char16_t* pipeName)
    {
        WaitNamedPipe(pipeName, NMPWAIT_WAIT_FOREVER);
    }

    void NamedPipeAPI::WaitNamedPipeForever(String const& pipeName)
    {
        WaitNamedPipeForever(pipeName.c_str());
    }

}
