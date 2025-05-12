//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::IO
{
    OutputDevice::OutputDevice(const char16_t* fileName, FileShareMode shareMode, ::SECURITY_ATTRIBUTES& securityAttributes, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile) : IODevice(nullptr)
    {
        Open(fileName, shareMode, securityAttributes, fileOpenMode, attribute, flag, securityFlag, hTemplateFile);
    }

    OutputDevice::OutputDevice(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile) : IODevice(nullptr)
    {
        Open(fileName, shareMode, fileOpenMode, attribute, flag, securityFlag, hTemplateFile);
    }

    OutputDevice::OutputDevice(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag) : IODevice(nullptr)
    {
        Open(fileName, shareMode, fileOpenMode, attribute, flag, securityFlag);
    }

    OutputDevice::OutputDevice(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag) : IODevice(nullptr)
    {
        Open(fileName, shareMode, fileOpenMode, attribute, flag);
    }

    OutputDevice::OutputDevice(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode) : IODevice(nullptr)
    {
        Open(fileName, shareMode, fileOpenMode);
    }

    OutputDevice::OutputDevice(const char16_t* fileName, FileOpenMode fileOpenMode) : IODevice(nullptr)
    {
        Open(fileName, fileOpenMode);
    }

    OutputDevice::OutputDevice(const char16_t* fileName, FileFlag flag) : IODevice(nullptr)
    {
        Open(fileName, flag);
    }

    OutputDevice::OutputDevice(const char16_t* fileName) : IODevice(nullptr)
    {
        Open(fileName);
    }

    OutputDevice::OutputDevice(String const& fileName, FileShareMode shareMode, ::SECURITY_ATTRIBUTES& securityAttributes, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile) : IODevice(nullptr)
    {
        Open(fileName, shareMode, securityAttributes, fileOpenMode, attribute, flag, securityFlag, hTemplateFile);
    }

    OutputDevice::OutputDevice(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile) : IODevice(nullptr)
    {
        Open(fileName, shareMode, fileOpenMode, attribute, flag, securityFlag, hTemplateFile);
    }

    OutputDevice::OutputDevice(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag) : IODevice(nullptr)
    {
        Open(fileName, shareMode, fileOpenMode, attribute, flag, securityFlag);
    }

    OutputDevice::OutputDevice(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag) : IODevice(nullptr)
    {
        Open(fileName, shareMode, fileOpenMode, attribute, flag);
    }

    OutputDevice::OutputDevice(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode) : IODevice(nullptr)
    {
        Open(fileName, shareMode, fileOpenMode);
    }

    OutputDevice::OutputDevice(String const& fileName, FileOpenMode fileOpenMode) : IODevice(nullptr)
    {
        Open(fileName, fileOpenMode);
    }

    OutputDevice::OutputDevice(String const& fileName, FileFlag flag) : IODevice(nullptr)
    {
        Open(fileName, flag);
    }

    OutputDevice::OutputDevice(String const& fileName) : IODevice(nullptr)
    {
        Open(fileName);
    }

    void OutputDevice::Open(const char16_t* fileName, FileShareMode shareMode, ::SECURITY_ATTRIBUTES& securityAttributes, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile)
    {
        _h.__rawHandle(Primitives::FileAPI::Create(fileName, _fileAccessMode, shareMode, securityAttributes, fileOpenMode, attribute, flag, securityFlag, hTemplateFile), ClassType::OutputDevice);
    }

    void OutputDevice::Open(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile)
    {
        _h.__rawHandle(Primitives::FileAPI::Create(fileName, _fileAccessMode, shareMode, fileOpenMode, attribute, flag, securityFlag, hTemplateFile), ClassType::OutputDevice);
    }

    void OutputDevice::Open(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag)
    {
        _h.__rawHandle(Primitives::FileAPI::Create(fileName, _fileAccessMode, shareMode, fileOpenMode, attribute, flag, securityFlag), ClassType::OutputDevice);
    }

    void OutputDevice::Open(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag)
    {
        _h.__rawHandle(Primitives::FileAPI::Create(fileName, _fileAccessMode, shareMode, fileOpenMode, attribute, flag), ClassType::OutputDevice);
    }

    void OutputDevice::Open(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode) 
    {
        _h.__rawHandle(Primitives::FileAPI::Create(fileName, _fileAccessMode, shareMode, fileOpenMode), ClassType::OutputDevice);
    }

    void OutputDevice::Open(const char16_t* fileName, FileOpenMode fileOpenMode)
    {
        _h.__rawHandle(Primitives::FileAPI::Create(fileName, _fileAccessMode, _shareMode, fileOpenMode), ClassType::OutputDevice);
    }

    void OutputDevice::Open(const char16_t* fileName, FileFlag flag)
    {
        _h.__rawHandle(Primitives::FileAPI::Create(fileName, _fileAccessMode, _shareMode, _fileOpenMode, _fileAttribute, flag), ClassType::OutputDevice);
    }

    void OutputDevice::Open(const char16_t* fileName)
    {
        _h.__rawHandle(Primitives::FileAPI::Create(fileName, _fileAccessMode, _shareMode, _fileOpenMode), ClassType::OutputDevice);
    }

    void OutputDevice::Open(String const& fileName, FileShareMode shareMode, ::SECURITY_ATTRIBUTES& securityAttributes, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile)
    {
        _h.__rawHandle(Primitives::FileAPI::Create(fileName, _fileAccessMode, shareMode, securityAttributes, fileOpenMode, attribute, flag, securityFlag, hTemplateFile), ClassType::OutputDevice);
    }

    void OutputDevice::Open(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile)
    {
        _h.__rawHandle(Primitives::FileAPI::Create(fileName, _fileAccessMode, shareMode, fileOpenMode, attribute, flag, securityFlag, hTemplateFile), ClassType::OutputDevice);
    }

    void OutputDevice::Open(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag)
    {
        _h.__rawHandle(Primitives::FileAPI::Create(fileName, _fileAccessMode, shareMode, fileOpenMode, attribute, flag, securityFlag), ClassType::OutputDevice);
    }

    void OutputDevice::Open(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag)
    {
        _h.__rawHandle(Primitives::FileAPI::Create(fileName, _fileAccessMode, shareMode, fileOpenMode, attribute, flag), ClassType::OutputDevice);
    }

    void OutputDevice::Open(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode) 
    {
        _h.__rawHandle(Primitives::FileAPI::Create(fileName, _fileAccessMode, shareMode, fileOpenMode), ClassType::OutputDevice);
    }

    void OutputDevice::Open(String const& fileName, FileOpenMode fileOpenMode)
    {
        _h.__rawHandle(Primitives::FileAPI::Create(fileName, _fileAccessMode, _shareMode, fileOpenMode), ClassType::OutputDevice);
    }

    void OutputDevice::Open(String const& fileName, FileFlag flag)
    {
        _h.__rawHandle(Primitives::FileAPI::Create(fileName, _fileAccessMode, _shareMode, _fileOpenMode, _fileAttribute, flag), ClassType::OutputDevice);
    }

    void OutputDevice::Open(String const& fileName)
    {
        _h.__rawHandle(Primitives::FileAPI::Create(fileName, _fileAccessMode, _shareMode, _fileOpenMode), ClassType::OutputDevice);
    }

    void OutputDevice::Reopen(const char16_t* fileName, FileShareMode shareMode, ::SECURITY_ATTRIBUTES& securityAttributes, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile)
    {
        Close();
        Open(fileName, shareMode, securityAttributes, fileOpenMode, attribute, flag, securityFlag, hTemplateFile);
    }

    void OutputDevice::Reopen(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile)
    {
        Close();
        Open(fileName, shareMode, fileOpenMode, attribute, flag, securityFlag, hTemplateFile);
    }

    void OutputDevice::Reopen(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag)
    {
        Close();
        Open(fileName, shareMode, fileOpenMode, attribute, flag, securityFlag);
    }
    
    void OutputDevice::Reopen(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag)
    {
        Close();
        Open(fileName, shareMode, fileOpenMode, attribute, flag);
    }
    
    void OutputDevice::Reopen(const char16_t* fileName, FileShareMode shareMode, FileOpenMode fileOpenMode)
    {
        Close();
        Open(fileName, shareMode, fileOpenMode);
    }

    void OutputDevice::Reopen(const char16_t* fileName, FileOpenMode fileOpenMode)
    {
        Close();
        Open(fileName, fileOpenMode);
    }

    void OutputDevice::Reopen(const char16_t* fileName)
    {
        Close();
        Open(fileName);
    }

    void OutputDevice::Reopen(String const& fileName, FileShareMode shareMode, ::SECURITY_ATTRIBUTES& securityAttributes, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile)
    {
        Close();
        Open(fileName, shareMode, securityAttributes, fileOpenMode, attribute, flag, securityFlag, hTemplateFile);
    }

    void OutputDevice::Reopen(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag, HANDLE hTemplateFile)
    {
        Close();
        Open(fileName, shareMode, fileOpenMode, attribute, flag, securityFlag, hTemplateFile);
    }

    void OutputDevice::Reopen(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag, SecurityFlag securityFlag)
    {
        Close();
        Open(fileName, shareMode, fileOpenMode, attribute, flag, securityFlag);
    }

    void OutputDevice::Reopen(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode, FileAttribute attribute, FileFlag flag)
    {
        Close();
        Open(fileName, shareMode, fileOpenMode, attribute, flag);
    
    }

    void OutputDevice::Reopen(String const& fileName, FileShareMode shareMode, FileOpenMode fileOpenMode)
    {
        Close();
        Open(fileName, shareMode, fileOpenMode);
    }

    void OutputDevice::Reopen(String const& fileName, FileOpenMode fileOpenMode)
    {
        Close();
        Open(fileName, fileOpenMode);
    }

    void OutputDevice::Reopen(String const& fileName)
    {
        Close();
        Open(fileName);
    }

    void OutputDevice::Write(char8_t c) const
    {
        if (!WriteUnsafe(c)) [[unlikely]] throw HResultException();
    }

    void OutputDevice::Write(char16_t c) const
    {
        constexpr ssize_t bufferLength = _maxMultiByteCharLength + 1;
        char8_t mb[bufferLength];

        int result = ::WideCharToMultiByte(CP_UTF8, 0, (const wchar_t*)&c, 1, (char*)mb, (int)bufferLength, nullptr, nullptr);
    
        if (result == 0) [[unlikely]] {
            Primitives::FileAPI::Write(_h.__rawHandle(), u8'?');
            return;
        }

        WriteUncheckStrUnsafe(mb);
    }

    void OutputDevice::Write(const char16_t* str) const
    {
        ArgumentNullException::CheckNull(str, u"str");
        WriteUncheckStrUnsafe((uint32_t)Text::StringHelper::GetLengthUnsafe(str), str);
    }

    void OutputDevice::Write(uint32_t length, const char16_t* str) const
    {
        ArgumentNullException::CheckNull(str, u"str");
        WriteUncheckStrUnsafe(length, str);
    }

    void OutputDevice::Write(StringView const& view) const
    {
        WriteUncheckStrUnsafe((uint32_t)view.Length(), view.c_str());
    }

    void OutputDevice::Write(String const& str) const
    {
        Write(StringView(str));
    }

    void OutputDevice::Write(const char8_t* str) const
    {
        ArgumentNullException::CheckNull(str, u"str");

        WriteUnsafe(str);
    }

    void OutputDevice::Write(uint32_t length, const char8_t* str) const
    {
        ArgumentNullException::CheckNull(str, u"str");
        WriteUnsafe(length, str);
    }

    void OutputDevice::Write(Utf8String const& str) const
    {
        WriteUnsafe((uint32_t)str.Length(), str.c_str());
    }

    void OutputDevice::Write(std::u8string const& str) const
    {
        WriteUncheckStrUnsafe((uint32_t)str.size(), str.c_str());
    }

    void OutputDevice::Write(Utf8StringView const& str) const
    {
        WriteUncheckStrUnsafe((uint32_t)str.Length(), str.c_str());
    }

    void OutputDevice::WriteUncheckStrUnsafe(const char8_t* str) const
    {
        WriteUncheckStrUnsafe((uint32_t)Text::StringHelper::GetLengthUnsafe(str), str);
    }

    void OutputDevice::WriteUncheckStrUnsafe(const char16_t* str) const
    {
        WriteUncheckStrUnsafe((uint32_t)Text::StringHelper::GetLengthUnsafe(str), str);
    }

    void OutputDevice::WriteUncheckStrUnsafe(uint32_t length, const char8_t* str) const
    {
#if true
        uint32_t current = 0;
        for (uint32_t i = 0; i < length; i++) {
            switch (str[i]) {
                case u8'\r':
                    if (i != current) Primitives::FileAPI::Write(_h.__rawHandle(), str + current, i - current);
                    //u8'\r'の次の文字から開始
                    current = i + 1;
                    continue;

                case u8'\n':
                    if (i != current) Primitives::FileAPI::Write(_h.__rawHandle(), str + current, i - current);
                    WriteLine();
                    //u8'\n'の次の文字から開始
                    current = i + 1;
                    continue;

                default: [[likely]] continue;
            }
        }

#elif false
        for (uint32_t i = 0; i < length; i++) {
            Write(str[i]);
        }
#else
        Collections::Turbo::FastArrayList<char8_t> vec;

        for (uint32_t i = 0; i < length; i++) {
            switch (str[i]) {
                case u8'\r': continue;

                case u8'\n':
                    vec.Append(u8'\r');
                    vec.Append(u8'\n');
                    continue;

                default: [[likely]]
                    vec.Append(str[i]);
                    continue;
            }
        }

        Primitives::FileAPI::Write(_h.__rawHandle(), vec.Data(), (uint32_t)vec.Length());
#endif
    }

    void OutputDevice::WriteUncheckStrUnsafe(uint32_t length, const char16_t* str) const
    {
        ssize_t length1 = length * _maxMultiByteCharLength + 1;

        char8_t* mbs = NEW char8_t[length1];

        MemoryAllocationException::CheckNull(mbs);

        int result = ::WideCharToMultiByte(CP_UTF8, 0, (const wchar_t*)str, (int)length, (char*)mbs, (int)length1, nullptr, nullptr);

        if (result == 0) [[unlikely]] {
            delete[] mbs;

            throw HResultException();
        }

        try {
            WriteUncheckStrUnsafe(mbs);
        }
        catch (...) {
            auto p = ::std::current_exception();

            delete[] mbs;

            ::std::rethrow_exception(p);
        }
        
        delete[] mbs;
    }

    void OutputDevice::WriteUnsafe(char16_t c) const noexcept
    {
        constexpr ssize_t bufferLength = _maxMultiByteCharLength + 1;
        char8_t mb[bufferLength];

        int result = ::WideCharToMultiByte(CP_UTF8, 0, (const wchar_t*)&c, 1, (char*)mb, (int)bufferLength, nullptr, nullptr);

        WriteUnsafe(mb);
    }

    void OutputDevice::WriteUnsafe(const char16_t* str) const
    {
        WriteUnsafe((uint32_t)Text::StringHelper::GetLengthUnsafe(str), str);
    }

    void OutputDevice::WriteUnsafe(uint32_t length, const char16_t* str) const
    {
        ssize_t length1 = length * _maxMultiByteCharLength + 1;

        char8_t* mbs = NEW char8_t[length1];

        MemoryAllocationException::CheckNull(mbs);

        ::WideCharToMultiByte(CP_UTF8, 0, (const wchar_t*)str, (int)length, (char*)mbs, (int)length1, nullptr, nullptr);

        WriteUnsafe(mbs);
        
        delete[] mbs;
    }

    void OutputDevice::WriteUnsafe(StringView const& view) const
    {
        WriteUnsafe((uint32_t)view.Length(), view.c_str());
    }

    void OutputDevice::WriteUnsafe(String const& str) const
    {
        WriteUnsafe((uint32_t)str.Length(), str.c_str());
    }

    bool OutputDevice::WriteUnsafe(char8_t c) const noexcept
    {
        switch (c) {
            case u8'\r': [[unlikely]] break;

            case u8'\n':
                return (bool)Primitives::FileAPI::WriteUnsafe(_h.__rawHandle(), u8"\r\n", 2);

            default: [[likely]]
                return Primitives::FileAPI::WriteUnsafe(_h.__rawHandle(), c);
        }
    }

    void OutputDevice::WriteUnsafe(std::u8string const& str) const noexcept
    {
        WriteUnsafe((uint32_t)str.size(), str.c_str());
    }

    void OutputDevice::WriteUnsafe(Utf8String const& str) const noexcept
    {
        WriteUnsafe((uint32_t)str.Length(), str.c_str());
    }

    void OutputDevice::WriteUnsafe(Utf8StringView const& str) const noexcept
    {
        WriteUnsafe((uint32_t)str.Length(), str.c_str());
    }

    void OutputDevice::WriteUnsafe(const char8_t* str) const noexcept
    {
        WriteUnsafe((uint32_t)Text::StringHelper::GetLengthUnsafe(str), str);
    }

    void OutputDevice::WriteUnsafe(uint32_t length, const char8_t* str) const noexcept
    {
        uint32_t current = 0;
        for (uint32_t i = 0; i < length; i++) {
            switch (str[i]) {
                case u8'\r':
                    if (i != current) Primitives::FileAPI::WriteUnsafe(_h.__rawHandle(), str + current, i - current);
                    //u8'\r'の次の文字から開始
                    current = i + 1;
                    continue;

                case u8'\n':
                    if (i != current) Primitives::FileAPI::WriteUnsafe(_h.__rawHandle(), str + current, i - current);
                    WriteLine();
                    //u8'\n'の次の文字から開始
                    current = i + 1;
                    continue;

                default: [[likely]] continue;
            }
        }
    }

    void OutputDevice::WriteData(uint8_t value) const
    {
        Primitives::FileAPI::Write(_h.__rawHandle(), value);
    }

    void OutputDevice::WriteData(uint32_t length, const void* buffer) const
    {
        ArgumentNullException::CheckNull(buffer, u"buffer");
        Primitives::FileAPI::Write(_h.__rawHandle(), buffer, length);
    }

    void OutputDevice::WriteDataUnsafe(uint32_t length, const void* buffer) const
    {
        Primitives::FileAPI::Write(_h.__rawHandle(), buffer, length);
    }

    void OutputDevice::WriteLine() const
    {
        Primitives::FileAPI::Write(_h.__rawHandle(), u8"\r\n", 2);
    }

    void OutputDevice::WriteLine(char16_t c) const
    {
        Write(c);
        WriteLine();
    }

    void OutputDevice::WriteLine(const char16_t* str) const
    {
        Write(str);
        WriteLine();
    }

    void OutputDevice::WriteLine(uint32_t length, const char16_t* str) const
    {
        Write(length, str);
        WriteLine(str);
    }

    void OutputDevice::WriteLine(StringView const& view) const
    {
        Write(view);
        WriteLine();
    }

    void OutputDevice::WriteLine(String const& str) const
    {
        Write(str);
        WriteLine();
    }

    void OutputDevice::WriteLine(char8_t c) const
    {
        Write(c);
        WriteLine();
    }

    void OutputDevice::WriteLine(const char8_t* str) const
    {
        Write(str);
        WriteLine();
    }

    void OutputDevice::WriteLine(uint32_t length, const char8_t* str) const
    {
        Write(length, str);
        WriteLine();
    }

    void OutputDevice::WriteLine(std::u8string const& str) const
    {
        Write(str);
        WriteLine();
    }

    void OutputDevice::WriteLine(Utf8String const& str) const
    {
        Write(str);
        WriteLine();
    }

    void OutputDevice::WriteLine(Utf8StringView const& str) const
    {
        Write(str);
        WriteLine();
    }

    void OutputDevice::WriteLineUnsafe(const char8_t* str) const
    {
        WriteUnsafe(str);
        WriteLine();
    }

    void OutputDevice::WriteLineUnsafe(uint32_t length, const char8_t* str) const
    {
        WriteUnsafe(length, str);
        WriteLine();
    }

    void OutputDevice::WriteBOM() const
    {
        uint8_t bom[]{ 0xEF, 0xBB, 0xBF };
        Primitives::FileAPI::Write(_h.__rawHandle(), bom, sizeof(bom));
    }

    String OutputDevice::_toString(Handle const& handle)
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Win32::IO::OutputDevice");
    }
}

CREATE_CLASS_TYPE(IO::OutputDevice, OutputDevice)
