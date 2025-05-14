#ifndef KONGKONG_WIN32_THRADING_H
#define KONGKONG_WIN32_THRADING_H

#include "Definitions/Base.h"

//Windowsのみ
#if KONGKONG_ENV_WINDOWS

#include "Definitions/Kongkong.Win32.Threading._cleanupGroupBase.h"
#include "Definitions/Kongkong.Win32.Threading._threadPoolBase.h"
#include "Definitions/Kongkong.Win32.Threading.CallbackEnvironment.h"
#include "Definitions/Kongkong.Win32.Threading.CleanupGroup.h"
#include "Definitions/Kongkong.Win32.Threading.CleanupGroupView.h"
#include "Definitions/Kongkong.Win32.Threading.Event.h"
#include "Definitions/Kongkong.Win32.Threading.Mutex.h"
#include "Definitions/Kongkong.Win32.Threading.ProcessorNumber.h"
#include "Definitions/Kongkong.Win32.Threading.Semaphore.h"
#include "Definitions/Kongkong.Win32.Threading.StackInfo.h"
#include "Definitions/Kongkong.Win32.Threading.Thread.h"
#include "Definitions/Kongkong.Win32.Threading.ThreadPool.h"
#include "Definitions/Kongkong.Win32.Threading.ThreadPoolView.h"
#include "Definitions/Kongkong.Win32.Threading.ThreadStart.h"
#include "Definitions/Kongkong.Win32.Threading.WaitHandle.h"

#endif //KONGKONG_ENV_WINDOWS
#endif //!KONGKONG_WIN32_THRADING_H
