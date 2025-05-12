#ifndef KONGKONG_CSTD_H
#define KONGKONG_CSTD_H

#include "Definitions/Base.h"

#include "Definitions/Kongkong.CStd._cFileReaderBase.h"
#include "Definitions/Kongkong.CStd._cFileStream.h"
#include "Definitions/Kongkong.CStd._cFileWriterBase.h"
#include "Definitions/Kongkong.CStd.BuiltInArray.h"
#include "Definitions/Kongkong.CStd.CBinaryFileReader.h"
#include "Definitions/Kongkong.CStd.CBinaryFileWriter.h"
#include "Definitions/Kongkong.CStd.CConsole.h"
#include "Definitions/Kongkong.CStd.CFile.h"
#include "Definitions/Kongkong.CStd.CFilePosition.h"
#include "Definitions/Kongkong.CStd.CFileReader.h"
#include "Definitions/Kongkong.CStd.CFileWriter.h"
#include "Definitions/Kongkong.CStd.CLocale.h"
#include "Definitions/Kongkong.CStd.CLocaleCategory.h"
#include "Definitions/Kongkong.CStd.CMemoryManager.h"
#include "Definitions/Kongkong.CStd.CRandomGenerator.h"
#include "Definitions/Kongkong.CStd.CStdErrorChecker.h"
#include "Definitions/Kongkong.CStd.CStdException.h"
#include "Definitions/Kongkong.CStd.CString.h"

// Apple Clangは<threads.h>を実装していない
#ifdef KONGKONG_CTHREAD_ENABLED
    #include "Definitions/Kongkong.CStd.CConditionVariable.h"
    #include "Definitions/Kongkong.CStd.CMutex.h"
    #include "Definitions/Kongkong.CStd.CMutexKind.h"
    #include "Definitions/Kongkong.CStd.CScopeLock.h"
    #include "Definitions/Kongkong.CStd.CThread.h"
    #include "Definitions/Kongkong.CStd.CThreadException.h"
    #include "Definitions/Kongkong.CStd.CThreadPool.h"
    #include "Definitions/Kongkong.CStd.CThreadResult.h"
    #include "Definitions/Kongkong.CStd.CThreadSleepResult.h"
    #include "Definitions/Kongkong.CStd.CThreadStatus.h"
#endif //KONGKONG_CTHREAD_ENABLED

#endif //!KONGKONG_CSTD_H
