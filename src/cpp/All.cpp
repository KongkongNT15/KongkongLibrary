#define KONGKONG_LIBRARY 1

#include <klib/Definitions/Base.h>

#ifdef KONGKONG_COMPILER_MSVC
    #pragma warning(disable:4996)
#endif

#include "All.h"

#include "Definitions/Kongkong._lazyObjectBase.cpp"
#include "Definitions/Kongkong._unsafeLazyObjectBase.cpp"
#include "Definitions/Kongkong.ArgumentNullException.cpp"
#include "Definitions/Kongkong.DivideByZeroException.cpp"
#include "Definitions/Kongkong.Exception.cpp"
#include "Definitions/Kongkong.FormatException.cpp"
#include "Definitions/Kongkong.GC.cpp"
#include "Definitions/Kongkong.GenericString.cpp"
#include "Definitions/Kongkong.GenericStringView.cpp"
#include "Definitions/Kongkong.InitializationException.cpp"
#include "Definitions/Kongkong.InvalidCastException.cpp"
#include "Definitions/Kongkong.InvalidOperationException.cpp"
#include "Definitions/Kongkong.MemoryAllocationException.cpp"
#include "Definitions/Kongkong.NotImplementedException.cpp"
#include "Definitions/Kongkong.NullPointerException.cpp"
#include "Definitions/Kongkong.Object.cpp"
#include "Definitions/Kongkong.TypeInfo.cpp"
#include "Definitions/Kongkong.Std_Namespace.cpp"

#include "Definitions/Kongkong.Algorithms.RadixConverter.cpp"
#include "Definitions/Kongkong.Algorithms.Range.cpp"

#include "Definitions/Kongkong.Algorithms.Othello.OthelloElement.cpp"
#include "Definitions/Kongkong.Algorithms.Othello.OthelloField.cpp"

#include "Definitions/Kongkong.Algorithms.Sudoku.Std.cpp"
#include "Definitions/Kongkong.Algorithms.Sudoku.SudokuField.cpp"
#include "Definitions/Kongkong.Algorithms.Sudoku.SudokuElement.cpp"

#include "Definitions/Kongkong.Bits.BitSet.cpp"
#include "Definitions/Kongkong.Bits.BitSetElement.cpp"
#include "Definitions/Kongkong.Bits.BitSetIterator.cpp"
#include "Definitions/Kongkong.Bits.Byte.cpp"
#include "Definitions/Kongkong.Bits.ConstBitSetIterator.cpp"

#include "Definitions/Kongkong.Collections._keyValuePairMethods.cpp"
#include "Definitions/Kongkong.Collections._stackElementMethods.cpp"
#include "Definitions/Kongkong.Collections._treeNodeMethods.cpp"
#include "Definitions/Kongkong.Collections.ArrayChangingEventArgs.cpp"
#include "Definitions/Kongkong.Collections.CollectionHelper.cpp"

#include "Definitions/Kongkong.Collections.Turbo._builtInArrayBase.cpp"
#include "Definitions/Kongkong.Collections.Turbo._constFastLinkedListIteratorMethods.cpp"
#include "Definitions/Kongkong.Collections.Turbo._constFastPointerArrayIteratorMethods.cpp"
#include "Definitions/Kongkong.Collections.Turbo._fastArrayListMethods.cpp"
#include "Definitions/Kongkong.Collections.Turbo._fastArrayMapMethods.cpp"
#include "Definitions/Kongkong.Collections.Turbo._fastArrayMethods.cpp"
#include "Definitions/Kongkong.Collections.Turbo._fastArrayQueueBase.cpp"
#include "Definitions/Kongkong.Collections.Turbo._fastBinarySearchTreeMethods.cpp"
#include "Definitions/Kongkong.Collections.Turbo._fastBuiltInArrayListMethods.cpp"
#include "Definitions/Kongkong.Collections.Turbo._fastLinkedListIteratorMethods.cpp"
#include "Definitions/Kongkong.Collections.Turbo._fastLinkedListMethods.cpp"
#include "Definitions/Kongkong.Collections.Turbo._fastLinkedQueueMethods.cpp"
#include "Definitions/Kongkong.Collections.Turbo._fastMapMethods.cpp"
#include "Definitions/Kongkong.Collections.Turbo._fastPointerArrayIteratorMethods.cpp"
#include "Definitions/Kongkong.Collections.Turbo._fastPointerListMethods.cpp"
#include "Definitions/Kongkong.Collections.Turbo._fastThreadSafeArrayListMethods.cpp"
#include "Definitions/Kongkong.Collections.Turbo._fastThreadSafeArrayMethods.cpp"

#include "Definitions/Kongkong.CStd._cFileReaderBase.cpp"
#include "Definitions/Kongkong.CStd._cFileStream.cpp"
#include "Definitions/Kongkong.CStd._cFileWriterBase.cpp"
#include "Definitions/Kongkong.CStd.CBinaryFileReader.cpp"
#include "Definitions/Kongkong.CStd.CBinaryFileWriter.cpp"
#include "Definitions/Kongkong.CStd.CConsole.cpp"
#include "Definitions/Kongkong.CStd.CFile.cpp"
#include "Definitions/Kongkong.CStd.CFileReader.cpp"
#include "Definitions/Kongkong.CStd.CFileWriter.cpp"
#include "Definitions/Kongkong.CStd.CLocale.cpp"
#include "Definitions/Kongkong.CStd.CMemoryManager.cpp"
#include "Definitions/Kongkong.CStd.CRandomGenerator.cpp"
#include "Definitions/Kongkong.CStd.CStdErrorChecker.cpp"
#include "Definitions/Kongkong.CStd.CStdException.cpp"
#include "Definitions/Kongkong.CStd.CString.cpp"

#if __has_include(<threads.h>)
    #include "Definitions/Kongkong.CStd.CConditionVariable.cpp"
    #include "Definitions/Kongkong.CStd.CMutex.cpp"
    #include "Definitions/Kongkong.CStd.CThread.cpp"
    #include "Definitions/Kongkong.CStd.CThreadException.cpp"
    #include "Definitions/Kongkong.CStd.CThreadPool.cpp"
    #include "Definitions/Kongkong.CStd.CThreadResult.cpp"
#endif //__has_include(<threads.h>)

#include "Definitions/Kongkong.Diagnostics.LifecycleEventArgs.cpp"
#include "Definitions/Kongkong.Diagnostics.StopWatch.cpp"

#ifdef KONGKONG_ENV_WINDOWS
    #include "Definitions/Kongkong.Graphics._winComInitializer.cpp"
#endif

#include "Definitions/Kongkong.Graphics.Color.cpp"

#include "Definitions/Kongkong.Graphics.Imaging.BitmapImage.cpp"
#include "Definitions/Kongkong.Graphics.Imaging.ImageRenderException.cpp"

#include "Definitions/Kongkong.Memory._sharedHandleBase.cpp"
#include "Definitions/Kongkong.Memory._sharedPointerBase.cpp"
#include "Definitions/Kongkong.Memory._weakPointerBase.cpp"
#include "Definitions/Kongkong.Memory.BufferBase.cpp"
#include "Definitions/Kongkong.Memory.MemoryAllocator.cpp"
#include "Definitions/Kongkong.Memory.MemoryBlock.cpp"

#include "Definitions/Kongkong.Net.IPv4Address.cpp"

#include "Definitions/Kongkong.Numeric.BigInteger.cpp"
#include "Definitions/Kongkong.Numeric.Complex.cpp"
#include "Definitions/Kongkong.Numeric.Math.cpp"
#include "Definitions/Kongkong.Numeric.PolarComplex.cpp"
#include "Definitions/Kongkong.Numeric.Random.cpp"
#include "Definitions/Kongkong.Numeric.RandomBase.cpp"
#include "Definitions/Kongkong.Numeric.RandomCircle.cpp"
#include "Definitions/Kongkong.Numeric.RandomCircleBase.cpp"

#include "Definitions/Kongkong.Numeric.Statistics._binBase.cpp"
#include "Definitions/Kongkong.Numeric.Statistics._histogramIteratorBase.cpp"
#include "Definitions/Kongkong.Numeric.Statistics._normalDistributionBase.cpp"
#include "Definitions/Kongkong.Numeric.Statistics.HistogramBase.cpp"
#include "Definitions/Kongkong.Numeric.Statistics.NormalDistribution.cpp"
#include "Definitions/Kongkong.Numeric.Statistics.PoissonDistribution.cpp"
#include "Definitions/Kongkong.Numeric.Statistics.StandardNormalDistribution.cpp"
#include "Definitions/Kongkong.Numeric.Statistics.UniformDistribution.cpp"
#include "Definitions/Kongkong.Numeric.Statistics.ZeroMeanNormalDistribution.cpp"

#include "Definitions/Kongkong.IO.Storage.Directory.cpp"
#include "Definitions/Kongkong.IO.Storage.File.cpp"
#include "Definitions/Kongkong.IO.Storage.Path.cpp"

#include "Definitions/Kongkong.System.Environment.cpp"

#include "Definitions/Kongkong.Std.GenericStringBuffer.cpp"
#include "Definitions/Kongkong.Std.StdString.cpp"
#include "Definitions/Kongkong.Std.StlThreadPool.cpp"

#ifdef KONGKONG_ENV_UNIX
    #include "Definitions/Kongkong.Std.PosixFileIOBuffer.cpp"
    #include "Definitions/Kongkong.Std.PosixIOBuffer.cpp"

#endif //KONGKONG_ENV_UNIX

#include "Definitions/Kongkong.System.CppVersion.cpp"
#include "Definitions/Kongkong.System.BuildVersion.cpp"

#include "Definitions/Kongkong.Text._stringPointer.cpp"
#include "Definitions/Kongkong.Text._stringPointerBase.cpp"
#include "Definitions/Kongkong.Text.AsciiEncoding.cpp"
#include "Definitions/Kongkong.Text.Encoding.cpp"
#include "Definitions/Kongkong.Text.InvalidCodePointException.cpp"
#include "Definitions/Kongkong.Text.StringHelper.cpp"

#include "Definitions/Kongkong.Text.Json.JsonArray.cpp"
#include "Definitions/Kongkong.Text.Json.JsonObject.cpp"
#include "Definitions/Kongkong.Text.Json.JsonParser.cpp"
#include "Definitions/Kongkong.Text.Json.JsonValue.cpp"

#include "Definitions/Kongkong.Text.Unicode.SurrogatePair.cpp"
#include "Definitions/Kongkong.Text.Unicode.UnicodeConverter.cpp"
#include "Definitions/Kongkong.Text.Unicode.UnicodeRange.cpp"
#include "Definitions/Kongkong.Text.Unicode.UnicodeRangeIterator.cpp"
#include "Definitions/Kongkong.Text.Unicode.Utf8Char.cpp"

#if false
#include "Definitions/Kongkong.Text.Yaml.YamlNode.cpp"
#include "Definitions/Kongkong.Text.Yaml.YamlText.cpp"

#include "Definitions/Kongkong.Text.Xml._xmlContent.cpp"
#include "Definitions/Kongkong.Text.Xml._xmlName.cpp"
#include "Definitions/Kongkong.Text.Xml.XmlAttribute.cpp"
#include "Definitions/Kongkong.Text.Xml.XmlComment.cpp"
#include "Definitions/Kongkong.Text.Xml.XmlContainer.cpp"
#include "Definitions/Kongkong.Text.Xml.XmlDeclaration.cpp"
#include "Definitions/Kongkong.Text.Xml.XmlElement.cpp"
#include "Definitions/Kongkong.Text.Xml.XmlEntities.cpp"
#include "Definitions/Kongkong.Text.Xml.XmlNode.cpp"
#include "Definitions/Kongkong.Text.Xml.XmlObject.cpp"
#endif //false

#include "Definitions/Kongkong.Threading._asyncOperationBase.cpp"
#include "Definitions/Kongkong.Threading._awaiterBase.cpp"
#include "Definitions/Kongkong.Threading.AsyncAction.cpp"
#include "Definitions/Kongkong.Threading.Mutex.cpp"
#include "Definitions/Kongkong.Threading.ParallelFor.cpp"
#include "Definitions/Kongkong.Threading.ScopeLock.cpp"
#include "Definitions/Kongkong.Threading.Thread.cpp"
#include "Definitions/Kongkong.Threading.ThreadPool.cpp"

#ifdef KONGKONG_ENV_UNIX

#include "Definitions/Kongkong.Posix.Environment.cpp"
#include "Definitions/Kongkong.Posix.Process.cpp"

#include "Definitions/Kongkong.Posix.IO.Directory.cpp"
#include "Definitions/Kongkong.Posix.IO.DirectoryEntry.cpp"
#include "Definitions/Kongkong.Posix.IO.DirectoryInfo.cpp"
#include "Definitions/Kongkong.Posix.IO.DirectoryIterator.cpp"
#include "Definitions/Kongkong.Posix.IO.FileInfo.cpp"
#include "Definitions/Kongkong.Posix.IO.FileReader.cpp"
#include "Definitions/Kongkong.Posix.IO.FileRW.cpp"
#include "Definitions/Kongkong.Posix.IO.FileWriter.cpp"
#include "Definitions/Kongkong.Posix.IO.InputDevice.cpp"
#include "Definitions/Kongkong.Posix.IO.IODevice.cpp"
#include "Definitions/Kongkong.Posix.IO.IOHelper.cpp"
#include "Definitions/Kongkong.Posix.IO.OutputDevice.cpp"
#include "Definitions/Kongkong.Posix.IO.Pipe.cpp"
#include "Definitions/Kongkong.Posix.IO.Path.cpp"
#include "Definitions/Kongkong.Posix.IO.RWDevice.cpp"

#include "Definitions/Kongkong.Posix.Threading.Mutex.cpp"
#include "Definitions/Kongkong.Posix.Threading.Thread.cpp"
#include "Definitions/Kongkong.Posix.Threading.ThreadAttribute.cpp"
#include "Definitions/Kongkong.Posix.Threading.ThreadPool.cpp"

#endif //KONGKONG_ENV_UNIX

#ifdef KONGKONG_ENV_WINDOWS

#include "Definitions/Kongkong.Win32.CharHelper.cpp"
#include "Definitions/Kongkong.Win32.ComputerName.cpp"
#include "Definitions/Kongkong.Win32.ConsolePoint.cpp"
#include "Definitions/Kongkong.Win32.Environment.cpp"
#include "Definitions/Kongkong.Win32.Handle.cpp"
#include "Definitions/Kongkong.Win32.HResultException.cpp"
#include "Definitions/Kongkong.Win32.LocalTime.cpp"
#include "Definitions/Kongkong.Win32.MemoryStatus.cpp"
#include "Definitions/Kongkong.Win32.MessageBox.cpp"
#include "Definitions/Kongkong.Win32.MinWinHelper.cpp"
#include "Definitions/Kongkong.Win32.OSVersionInfo.cpp"
#include "Definitions/Kongkong.Win32.RegistryKey.cpp"
#include "Definitions/Kongkong.Win32.RegistryKeyBase.cpp"
#include "Definitions/Kongkong.Win32.RegistryValue.cpp"
#include "Definitions/Kongkong.Win32.Sound.cpp"
#include "Definitions/Kongkong.Win32.StringHelper.cpp"
#include "Definitions/Kongkong.Win32.SystemInfo.cpp"
#include "Definitions/Kongkong.Win32.SystemTime.cpp"
#include "Definitions/Kongkong.Win32.SystemTimeBase.cpp"
#include "Definitions/Kongkong.Win32.WaitObjectInfo.cpp"

#include "Definitions/Kongkong.Win32.Execution.ModuleBase.cpp"
#include "Definitions/Kongkong.Win32.Execution.Module.cpp"

#include "Definitions/Kongkong.Win32.Gdi.DeviceContext.cpp"

#include "Definitions/Kongkong.Win32.IO.Directory.cpp"
#include "Definitions/Kongkong.Win32.IO.File.cpp"
#include "Definitions/Kongkong.Win32.IO.FileSystemInfo.cpp"
#include "Definitions/Kongkong.Win32.IO.InputDevice.cpp"
#include "Definitions/Kongkong.Win32.IO.IODevice.cpp"
#include "Definitions/Kongkong.Win32.IO.OutputDevice.cpp"
#include "Definitions/Kongkong.Win32.IO.Path.cpp"
#include "Definitions/Kongkong.Win32.IO.WinConsole.cpp"

#include "Definitions/Kongkong.Win32.Primitives.ConsoleAPI.cpp"
#include "Definitions/Kongkong.Win32.Primitives.DesktopWindowManager.cpp"
#include "Definitions/Kongkong.Win32.Primitives.ErrorChecker.cpp"
#include "Definitions/Kongkong.Win32.Primitives.FileAPI.cpp"
#include "Definitions/Kongkong.Win32.Primitives.HandleAPI.cpp"
#include "Definitions/Kongkong.Win32.Primitives.LibLoaderAPI.cpp"
#include "Definitions/Kongkong.Win32.Primitives.NamedPipeAPI.cpp"
#include "Definitions/Kongkong.Win32.Primitives.ProcessThreadAPI.cpp"
#include "Definitions/Kongkong.Win32.Primitives.SyncHAPI.cpp"
#include "Definitions/Kongkong.Win32.Primitives.SysInfoAPI.cpp"
#include "Definitions/Kongkong.Win32.Primitives.TimeZoneAPI.cpp"
#include "Definitions/Kongkong.Win32.Primitives.VersionHelper.cpp"
#include "Definitions/Kongkong.Win32.Primitives.WinBase.cpp"
#include "Definitions/Kongkong.Win32.Primitives.WinHttp.cpp"
#include "Definitions/Kongkong.Win32.Primitives.WinRegistry.cpp"
#include "Definitions/Kongkong.Win32.Primitives.WinUser.cpp"

#include "Definitions/Kongkong.Win32.Threading._cleanupGroupBase.cpp"
#include "Definitions/Kongkong.Win32.Threading._threadPoolBase.cpp"
#include "Definitions/Kongkong.Win32.Threading.CallbackEnvironment.cpp"
#include "Definitions/Kongkong.Win32.Threading.CleanupGroup.cpp"
#include "Definitions/Kongkong.Win32.Threading.CleanupGroupView.cpp"
#include "Definitions/Kongkong.Win32.Threading.Event.cpp"
#include "Definitions/Kongkong.Win32.Threading.Mutex.cpp"
#include "Definitions/Kongkong.Win32.Threading.ProcessorNumber.cpp"
#include "Definitions/Kongkong.Win32.Threading.Semaphore.cpp"
#include "Definitions/Kongkong.Win32.Threading.Thread.cpp"
#include "Definitions/Kongkong.Win32.Threading.ThreadPool.cpp"
#include "Definitions/Kongkong.Win32.Threading.ThreadPoolView.cpp"
#include "Definitions/Kongkong.Win32.Threading.WaitHandle.cpp"

#include "Definitions/Kongkong.Win32.UI.Button.cpp"
#include "Definitions/Kongkong.Win32.UI.ButtonBase.cpp"
#include "Definitions/Kongkong.Win32.UI.Color.cpp"
#include "Definitions/Kongkong.Win32.UI.Control.cpp"
#include "Definitions/Kongkong.Win32.UI.DpiChangedEventArgs.cpp"
#include "Definitions/Kongkong.Win32.UI.PaintRequestedEventArgs.cpp"
#include "Definitions/Kongkong.Win32.UI.Rect.cpp"
#include "Definitions/Kongkong.Win32.UI.SizeChangedEventArgs.cpp"
#include "Definitions/Kongkong.Win32.UI.TextBlock.cpp"
#include "Definitions/Kongkong.Win32.UI.Thickness.cpp"
#include "Definitions/Kongkong.Win32.UI.TitleBar.cpp"
#include "Definitions/Kongkong.Win32.UI.UIElement.cpp"
#include "Definitions/Kongkong.Win32.UI.Window.cpp"
#include "Definitions/Kongkong.Win32.UI.WindowActivatedEventArgs.cpp"
#include "Definitions/Kongkong.Win32.UI.WindowClosingEventArgs.cpp"
#include "Definitions/Kongkong.Win32.UI.WindowCreatingEventArgs.cpp"

#endif //KONGKONG_ENV_WINDOWS