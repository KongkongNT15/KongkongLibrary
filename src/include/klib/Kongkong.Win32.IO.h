#ifndef KONGKONG_WIN32_IO_H
#define KONGKONG_WIN32_IO_H

#include "Definitions/Base.h"

//Windowsのみ
#if KONGKONG_ENV_WINDOWS

#include "Definitions/Kongkong.Win32.IO.Directory.h"
#include "Definitions/Kongkong.Win32.IO.DriveKind.h"
#include "Definitions/Kongkong.Win32.IO.File.h"
#include "Definitions/Kongkong.Win32.IO.FileAccessMode.h"
#include "Definitions/Kongkong.Win32.IO.FileAttribute.h"
#include "Definitions/Kongkong.Win32.IO.FileFlag.h"
#include "Definitions/Kongkong.Win32.IO.FileOpenMode.h"
#include "Definitions/Kongkong.Win32.IO.FileShareMode.h"
#include "Definitions/Kongkong.Win32.IO.FileSystemInfo.h"
#include "Definitions/Kongkong.Win32.IO.FileNameKind.h"
#include "Definitions/Kongkong.Win32.IO.FileType.h"
#include "Definitions/Kongkong.Win32.IO.InputDevice.h"
#include "Definitions/Kongkong.Win32.IO.IODevice.h"
#include "Definitions/Kongkong.Win32.IO.OutputDevice.h"
#include "Definitions/Kongkong.Win32.IO.Path.h"
#include "Definitions/Kongkong.Win32.IO.VolumeNameKind.h"
#include "Definitions/Kongkong.Win32.IO.WinConsole.h"

#endif //KONGKONG_ENV_WINDOWS
#endif //!KONGKONG_WIN32_IO_H
