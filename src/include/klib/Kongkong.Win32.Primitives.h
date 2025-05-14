#ifndef KONGKONG_WIN32_PRIMITIVES_H
#define KONGKONG_WIN32_PRIMITIVES_H

#include "Definitions/Base.h"

#if KONGKONG_ENV_WINDOWS

#include "Definitions/Kongkong.Win32.Primitives.ConsoleAPI.h"
#include "Definitions/Kongkong.Win32.Primitives.DesktopWindowManager.h"
#include "Definitions/Kongkong.Win32.Primitives.ErrorChecker.h"
#include "Definitions/Kongkong.Win32.Primitives.FileAPI.h"
#include "Definitions/Kongkong.Win32.Primitives.HandleAPI.h"
#include "Definitions/Kongkong.Win32.Primitives.LibLoaderAPI.h"
#include "Definitions/Kongkong.Win32.Primitives.NamedPipeAPI.h"
#include "Definitions/Kongkong.Win32.Primitives.ProcessThreadAPI.h"
#include "Definitions/Kongkong.Win32.Primitives.SyncHAPI.h"
#include "Definitions/Kongkong.Win32.Primitives.SysInfoAPI.h"
#include "Definitions/Kongkong.Win32.Primitives.TimeZoneAPI.h"
#include "Definitions/Kongkong.Win32.Primitives.VersionHelper.h"
#include "Definitions/Kongkong.Win32.Primitives.WinBase.h"
#include "Definitions/Kongkong.Win32.Primitives.WinHttp.h"
#include "Definitions/Kongkong.Win32.Primitives.WinRegistry.h"
#include "Definitions/Kongkong.Win32.Primitives.WinUser.h"

#if 0
namespace KONGKONG_NAMESPACE::Win32
{
    

    enum struct ProcessCreation : unsigned {
        DebugProcess = DEBUG_PROCESS,
        DebugOnlyThisProcess = DEBUG_ONLY_THIS_PROCESS,
        CreateSuspended = CREATE_SUSPENDED,
        DetachedProcess = DETACHED_PROCESS,
        NewConsole = CREATE_NEW_CONSOLE,
        NormalPriorityClass = NORMAL_PRIORITY_CLASS,
        IdleProprityClass = IDLE_PRIORITY_CLASS,
        HighPriorityClass = HIGH_PRIORITY_CLASS,
        RealtimePriorityClass = REALTIME_PRIORITY_CLASS,
        NewProcessGroup = CREATE_NEW_PROCESS_GROUP,
        UnicodeEnvironment = CREATE_UNICODE_ENVIRONMENT,
        SeparateWOWVDM = CREATE_SEPARATE_WOW_VDM,
        SharedWOWVDM = CREATE_SHARED_WOW_VDM,
        ForceDOS = CREATE_FORCEDOS,
        BelowNormalPriorityClass = BELOW_NORMAL_PRIORITY_CLASS,
        AboveNormalPriorityClass = ABOVE_NORMAL_PRIORITY_CLASS,
        InheritParentAffinity = INHERIT_PARENT_AFFINITY,
        InheritCallerPriority = INHERIT_CALLER_PRIORITY,
        ProtectedProcess = CREATE_PROTECTED_PROCESS,
        ExtendedStartupinfoPresent = EXTENDED_STARTUPINFO_PRESENT,

    };

    enum struct ProcessMode : unsigned {
        BackgroundBegin = PROCESS_MODE_BACKGROUND_BEGIN,
        BackgroundEnd = PROCESS_MODE_BACKGROUND_END,
    };

    

}
#endif

#endif //KONGKONG_ENV_WINDOWS
#endif //!KONGKONG_WIN32_PRIMITIVES_H
