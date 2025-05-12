//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Execution
{
    Module::Module(const char16_t* libraryFileName) : ModuleBase(Primitives::LibLoaderAPI::LoadLibrary(libraryFileName))
    {
    }

    Module::Module(String const& libraryFileName) : ModuleBase(Primitives::LibLoaderAPI::LoadLibrary(libraryFileName))
    {
    }

    Module::Module(const char16_t* libraryFileName, LoadLibraryFlag flag) : ModuleBase(Primitives::LibLoaderAPI::LoadLibrary(libraryFileName, flag))
    {
    }

    Module::Module(String const& libraryFileName, LoadLibraryFlag flag) : ModuleBase(Primitives::LibLoaderAPI::LoadLibrary(libraryFileName, flag))
    {
    }

    Module::Module(Module&& module) noexcept : ModuleBase(module._module)
    {
        module._module = nullptr;
    }

    Module::~Module()
    {
        if (IsLoaded()) ::FreeLibrary(_module);
    }

    Module& Module::operator=(Module&& module) noexcept
    {
        Module::~Module();

        _module = module._module;
        module._module = nullptr;

        return *this;
    }

    Module& Module::operator=(std::nullptr_t) noexcept
    {
        Module::~Module();
        _module = nullptr;
    }
}
