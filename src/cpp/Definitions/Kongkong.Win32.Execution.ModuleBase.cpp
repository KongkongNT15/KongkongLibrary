//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Execution
{
    String ModuleBase::FullPath() const
    {
        return Primitives::LibLoaderAPI::GetModuleFileName(_module);
    }

    void* ModuleBase::GetProcedureAdress(const char* procName) const
    {
        return Primitives::LibLoaderAPI::GetProcedureAdress(_module, procName);
    }

    void* ModuleBase::GetProcedureAdress(const char16_t* procName) const
    {
        return Primitives::LibLoaderAPI::GetProcedureAdress(_module, procName);
    }

    void* ModuleBase::GetProcedureAdress(String const& procName) const
    {
        return Primitives::LibLoaderAPI::GetProcedureAdress(_module, procName);
    }

    String ModuleBase::ToString() const
    {
        return IsLoaded() ? FullPath() : String::FromLiteral(u"Null");
    }
}
