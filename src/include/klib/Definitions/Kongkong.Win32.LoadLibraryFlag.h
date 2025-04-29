#ifndef KONGKONG_WIN32_LOADLIBRARYFLAG_H
#define KONGKONG_WIN32_LOADLIBRARYFLAG_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    enum struct LoadLibraryFlag {
        DontResolveDllReferences        = DONT_RESOLVE_DLL_REFERENCES,
        LoadLibraryAsDataFile           = LOAD_LIBRARY_AS_DATAFILE,
        LoadWithAlteredSearchPath       = LOAD_WITH_ALTERED_SEARCH_PATH,
        LoadIgnoreCodeAuthzLevel        = LOAD_IGNORE_CODE_AUTHZ_LEVEL,
        LoadLibraryAsImageResource      = LOAD_LIBRARY_AS_IMAGE_RESOURCE,
        LoadLibraryAsDataFileExcelusive = LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE,
        LoadLibraryRequireSignedTarget  = LOAD_LIBRARY_REQUIRE_SIGNED_TARGET,
        LoadLibrarySearchDllLoadDir     = LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR,
        LoadLibrarySearchApplicationDir = LOAD_LIBRARY_SEARCH_APPLICATION_DIR,
        LoadLibrarySearchUserDirs       = LOAD_LIBRARY_SEARCH_USER_DIRS,
        LoadLibrarySearchSystem32       = LOAD_LIBRARY_SEARCH_SYSTEM32,
        LoadLibrarySearchDefaultDirs    = LOAD_LIBRARY_SEARCH_DEFAULT_DIRS,
    };
}

#endif //!KONGKONG_WIN32_LOADLIBRARYFLAG_H
