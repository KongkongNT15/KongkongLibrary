#ifndef KONGKONG_ALL_H
#define KONGKONG_ALL_H

#include <klib/Definitions/Base.h>

#ifdef KONGKONG_ENV_WINDOWS
    #include <Windows.h>
    #include <VersionHelpers.h>
    #include <Unknwn.h>
    #include <d2d1.h>
    #include <wincodec.h>
    #include <wrl/client.h>
#endif

#ifdef KONGKONG_ENV_UNIX
    #include <iconv.h>
#endif

#ifdef KONGKONG_CTHREAD_ENABLED
    #include <threads.h>
#endif //#ifdef KONGKONG_CTHREAD_ENABLED

#include <array>
#include <cctype>
#include <cerrno>
#include <chrono>
#include <cmath>
#include <compare>
#include <concepts>
#include <cstdint>
#include <cstring>
#include <ctime>
#include <cuchar>
#include <cwctype>
#include <filesystem>
#include <format>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <numbers>
#include <new>
#include <random>
#include <set>
#include <source_location>
#include <sstream>
#include <string>
#include <string_view>
#include <thread>
#include <tuple>
#include <utility>
#include <vector>

#include <klib/Kongkong.h>
#include <klib/Kongkong.Algorithms.h>
#include <klib/Kongkong.Algorithms.Othello.h>
#include <klib/Kongkong.Algorithms.Sudoku.h>
#include <klib/Kongkong.Bits.h>
#include <klib/Kongkong.Collections.h>
#include <klib/Kongkong.Collections.Iterators.h>
#include <klib/Kongkong.Collections.Turbo.h>
#include <klib/Kongkong.CStd.h>
#include <klib/Kongkong.Diagnostics.h>
#include <klib/Kongkong.Events.h>
#include <klib/Kongkong.Graphics.h>
#include <klib/Kongkong.Graphics.Imaging.h>
#include <klib/Kongkong.IO.Storage.h>
#include <klib/Kongkong.Memory.h>
#include <klib/Kongkong.Net.h>
#include <klib/Kongkong.Numeric.h>
//#include <klib/Kongkong.Numeric.NumberTypes.h>
#include <klib/Kongkong.Numeric.Statistics.h>
#include <klib/Kongkong.Std.h>
#include <klib/Kongkong.System.h>
#include <klib/Kongkong.Text.h>
#include <klib/Kongkong.Text.Json.h>
#include <klib/Kongkong.Text.Unicode.h>
//#include <klib/Kongkong.Text.Yaml.h>
//#include <klib/Kongkong.Text.Xml.h>
#include <klib/Kongkong.Threading.h>

#ifdef KONGKONG_OBJECTIVE_C_ENABLED

#include <klib/Kongkong.AppleDevice.h>
#include <klib/Kongkong.AppleDevice.AppKit.h>
#include <klib/Kongkong.AppleDevice.Foundation.h>
#include <klib/Kongkong.AppleDevice.Foundation.Collections.h>
#include <klib/Kongkong.AppleDevice.Foundation.FileSystem.h>
#include <klib/Kongkong.AppleDevice.Foundation.Streams.h>
#include <klib/Kongkong.AppleDevice.Foundation.Text.h>
#include <klib/Kongkong.AppleDevice.Foundation.Text.Xml.h>
#include <klib/Kongkong.AppleDevice.Foundation.Threading.h>
#include <klib/Kongkong.AppleDevice.Metal.h>

#endif //KONGKONG_OBJECTIVE_C_ENABLED

#ifdef KONGKONG_ENV_UNIX

#include <klib/Kongkong.Posix.h>
#include <klib/Kongkong.Posix.IO.h>
#include <klib/Kongkong.Posix.Threading.h>

#endif

#ifdef KONGKONG_ENV_WINDOWS

#include <klib/Kongkong.Win32.h>
#include <klib/Kongkong.Win32.Execution.h>
#include <klib/Kongkong.Win32.Gdi.h>
#include <klib/Kongkong.Win32.IO.h>
#include <klib/Kongkong.Win32.Net.Http.h>
#include <klib/Kongkong.Win32.Primitives.h>
#include <klib/Kongkong.Win32.Threading.h>
#include <klib/Kongkong.Win32.UI.h>

#endif //KONGKONG_ENV_WINDOWS

#endif //!KONGKONG_ALL_H