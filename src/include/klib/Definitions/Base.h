#ifndef KONGKONG_BASE_H
#define KONGKONG_BASE_H

#define KONGKONG_VERSION_MAJOR       0
#define KONGKONG_VERSION_MINOR       1
#define KONGKONG_VERSION_PATCH       0
#define KONGKONG_VERSION_BUILDNUMBER 26

#define KONGKONG_NAMESPACE klib::Kongkong

//前方宣言
//Concepts

#include <stdint.h>
#include <concepts>
#include <type_traits>

#if __has_include(<threads.h>)
    #define KONGKONG_CTHREAD_ENABLED 1
#endif

//環境判定

#if __has_include(<Windows.h>)
    #define KONGKONG_ENV_WINDOWS 1

    #if __cplusplus == 199711L
        #define KONGKONG_COMPILER_MSVC 1
        #define KONGKONG_CPP_LANG_VERSION _MSVC_LANG
    #else
        #define KONGKONG_COMPILER_MINGW 1
        #define KONGKONG_COMPILER_GCC 1
        #define KONGKONG_CPP_LANG_VERSION __cplusplus
    #endif

    #ifndef _UNICODE
        #define _UNICODE
    #endif
    #ifndef UNICODE
        #define UNICODE
    #endif

    #include <Windows.h>
    #include <dwmapi.h>

    //ふぁ！？っくなマクロを削除
    #undef max
    #undef min

    //何かと干渉するマクロを削除

    #undef CopyFile
    #undef CreateDirectory
    #undef CreateProcess
    #undef GetClassName
    #undef GetCurrentDirectory
    #undef GetDriveType
    #undef GetFileAttributes
    #undef GetModuleFileName
    #undef GetObject
    #undef LoadLibrary
    #undef MessageBox
    #undef ReadConsole
    #undef RemoveDirectory
    #undef SendMessage
    #undef SetFileAttributes
    #undef WaitNamedPipe
    
    #ifdef KONGKONG_COMPILER_MSVC
        #if defined(_AMD64_) || defined(_ARM64_)
            typedef long long ssize_t;
        #elif defined(_X86_) || defined(_ARM_)
            typedef long ssize_t;
        #endif
    #endif

    #define CREATE_CLASS_TYPE(className, classType) \
        namespace KONGKONG_NAMESPACE::Win32 \
        { \
            template <> \
            ::KONGKONG_NAMESPACE::Win32::ClassType ClassTypeHelper::ClassType<className>() noexcept { return ::KONGKONG_NAMESPACE::Win32::ClassType::classType; } \
        }
        
#endif

#if __has_include(<unistd.h>) && !defined(KONGKONG_ENV_WINDOWS)
    #define KONGKONG_ENV_UNIX 1
    #include <dirent.h>
    #include <fcntl.h>
    #include <pthread.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/types.h>
#endif

#ifdef __APPLE__
    #define KONGKONG_ENV_APPLE

    #ifdef KONGKONG_OBJECTIVE_C_DISABLED
    #ifndef KONGKONG_OBJECTIVE_C_METAL_DISABLED
        #define KONGKONG_OBJECTIVE_C_METAL_DISABLED 1
    #endif
    #else
        #define KONGKONG_OBJECTIVE_C_ENABLED 1

        #ifndef KONGKONG_OBJECTIVE_C_METAL_DISABLED
            #define KONGKONG_OBJECTIVE_C_METAL_ENABLED 1
        #endif
    #endif
#endif

#ifndef KONGKONG_CPP_LANG_VERSION
    #define KONGKONG_CPP_LANG_VERSION __cplusplus
#endif

#define KONGKONG_CPP03 199711L
#define KONGKONG_CPP11 201103L
#define KONGKONG_CPP14 201402L
#define KONGKONG_CPP17 201703L
#define KONGKONG_CPP20 202002L
#define KONGKONG_CPP23 202302L

#if KONGKONG_CPP_LANG_VERSION >= KONGKONG_CPP03
    #define KONGKONG_HAS_CPP03 1
#else
    #define KONGKONG_HAS_CPP03 0
#endif

#if KONGKONG_CPP_LANG_VERSION >= KONGKONG_CPP11
    #define KONGKONG_HAS_CPP11 1
#else
    #define KONGKONG_HAS_CPP11 0
#endif

#if KONGKONG_CPP_LANG_VERSION >= KONGKONG_CPP14
    #define KONGKONG_HAS_CPP14 1
#else
    #define KONGKONG_HAS_CPP14 0
#endif

#if KONGKONG_CPP_LANG_VERSION >= KONGKONG_CPP17
    #define KONGKONG_HAS_CPP17 1
#else
    #define KONGKONG_HAS_CPP17 0
#endif

#if KONGKONG_CPP_LANG_VERSION >= KONGKONG_CPP20
    #define KONGKONG_HAS_CPP20 1
#else
    #define KONGKONG_HAS_CPP20 0
#endif

#if KONGKONG_CPP_LANG_VERSION >= KONGKONG_CPP23
    #define KONGKONG_HAS_CPP23 1
#else
    #define KONGKONG_HAS_CPP23 0
#endif

#define NEW new(::std::nothrow)

#define TOSTRING(x) #x
#define EXPAND(x) TOSTRING(x) // ここでマクロを展開してからTOSTRINGに代入
#define EXCEPTION_MESSAGE "Exception Thrown\n" "file name : "  __FILE__ "\n" "line : " EXPAND(__LINE__)

#define IMPLEMENTATION implementation
#define KONGKONG_INTERFACE struct

#define KONGKONG_INCOMPLETED_CLASS [[deprecated("このクラス・構造体は未完成です。使用しないでください。")]]
#define KONGKONG_INCOMPLETED_FUNCTION [[deprecated("この関数は未完成です。使用しないでください。")]]

//
#define CREATE_OPERATOR_OR(enumClass) \
    [[nodiscard]] constexpr enumClass operator|(enumClass left, enumClass right) noexcept { return enumClass((::std::underlying_type_t<enumClass>)left | (::std::underlying_type_t<enumClass>)right); }

#define CREATE_OPERATOR_AND(enumClass) \
    [[nodiscard]] constexpr enumClass operator&(enumClass left, enumClass right) noexcept { return enumClass((::std::underlying_type_t<enumClass>)left & (::std::underlying_type_t<enumClass>)right); }

#define CREATE_OPERATOR_PP(enumClass) \
    [[nodiscard]] constexpr enumClass& operator++(enumClass& value) noexcept \
    { \
        return value = (enumClass)((::std::underlying_type_v<enumClass>)value + 1); \
    } \
    [[nodiscard]] constexpr enumClass operator++(enumClass& value, int) noexcept \
    { \
        enumClass ret = value; \
        value = (enumClass)((::std::underlying_type_t<enumClass>)value + 1); \
        return ret; \
    }

#define CREATE_OPERATOR_MM(enumClass) \
    [[nodiscard]] constexpr enumClass& operator--(enumClass& value) noexcept \
    { \
        return value = (enumClass)((::std::underlying_type_t<enumClass>)value - 1); \
    } \
    [[nodiscard]] constexpr enumClass operator--(enumClass& value, int) noexcept \
    { \
        enumClass ret = value; \
        value = (enumClass)((::std::underlying_type_t<enumClass>)value - 1); \
        return ret; \
    }

#define CREATE_OPERATOR_AND_OR(enumClass) \
    CREATE_OPERATOR_OR(enumClass) \
    CREATE_OPERATOR_AND(enumClass)

#define CREATE_OPERATOR_PP_MM(enumClass, base) \
    CREATE_OPERATOR_PP(enumClass, base) \
    CREATE_OPERATOR_MM(enumClass, base)

//インスタンス化できないようにする
#define STATIC_CLASS(className)                         \
    className() = delete;                               \
    className(className const&) = delete;               \
    className(className&&) = delete;                    \
    ~className() = delete;                              \
    className& operator=(className const&) = delete;    \
    className& operator=(className&&) = delete;         

namespace KONGKONG_NAMESPACE
{
    //すべてのKongkong型の親クラス
    struct KongkongTypeBase;

    struct ValueType;

    KONGKONG_INTERFACE Interface;
    KONGKONG_INTERFACE InterfaceType;

    class HandleType;
    class PointerType;
    class Object;
    class StdType;

    template <class T, class TReturn = T>
    struct RefGetter;
}

namespace KONGKONG_NAMESPACE
{
    //コンセプト
    //数値型
    template <class T>
    concept NumberType = (std::integral<T> || std::floating_point<T>) && !::std::is_same_v<T, bool>;

    //文字型
    template <class T>
    concept CharType = std::same_as<T, char> || 
                       std::same_as<T, wchar_t> || 
                       std::same_as<T, char8_t> || 
                       std::same_as<T, char16_t> || 
                       std::same_as<T, char32_t>;

    //Kongkong型
    template <class T>
    concept KongkongType = std::derived_from<T, KongkongTypeBase>;

    //KongkongObject型
    template <class T>
    concept KongkongObjectType = std::derived_from<T, Object>;

    //KongkongValue型
    template <class T>
    concept KongkongValueType = std::derived_from<T, ValueType>;
}

namespace KONGKONG_NAMESPACE
{
    struct _lazyObjectBase;
    struct _unsafeLazyObjectBase;
    //mainに入る前に処理
    struct Initializer;
    

    struct TypeInfo;

    //引数が無効な値
    struct ArgumentException;

    //引数がnull
    struct ArgumentNullException;

    //引数が範囲外
    struct ArgumentOutOfRangeException;

    //算術演算
    struct ArithmeticException;

    template <class TKS>
    class BoxValueObject;

    //0で割ろうとした結果
    struct DivideByZeroException;

    struct Exception;

    template <class TChar> requires CharType<TChar>
    struct FastGenericString;

    //書式エラー
    struct FormatException;

    class GC;

    template <class TChar> requires CharType<TChar>
    struct GenericString;

    template <class TChar> requires CharType<TChar>
    struct GenericStringView;

    struct InitializationException;

    //不正なキャスト
    struct InvalidCastException;

    struct InvalidOperationException;

    //入出力エラー
    struct IOException;

    template <class T>
    struct LazyObject;

    struct MemoryException;

    struct MemoryAllocationException;

    //関数が実装されていない例外
    struct NotImplementedException;

    //機能がサポートされていないときの例外
    struct NotSupportedException;

    //NULL登場時の例外
    struct NullPointerException;

    

    //範囲外
    struct OutOfRangeException;

    //算術オーバーフロー
    struct OverflowException;

    template <class T>
    struct UnsafeLazyObject;
}

namespace KONGKONG_NAMESPACE::IMPLEMENTATION
{
    //KongkongStructureのボックス化に使用
    //ユーザーは直接扱えない
    template <class TKS>
    struct BoxValueObject;

    struct Object;
}

namespace KONGKONG_NAMESPACE::Algorithms
{
    struct RadixConverter;
    
    class Range;
    class Sorter;
}

namespace KONGKONG_NAMESPACE::Algorithms::Othello
{
    enum struct OthelloValue : uint8_t;

    struct OthelloElement;
    struct OthelloField;
}

namespace KONGKONG_NAMESPACE::Algorithms::Sudoku
{
    struct SudokuElement;
    struct SudokuField;
    enum struct SudokuNumber : uint8_t;

}

#ifdef KONGKONG_OBJECTIVE_C_ENABLED

namespace KONGKONG_NAMESPACE::AppleDevice
{
    class GlobalVariables;
    class NSObject;
    class NSObjectHelper;
}

namespace KONGKONG_NAMESPACE::AppleDevice::AppKit
{
    class NSColor;
    class NSColors;
    class NSColorSpace;
}

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    enum struct NSCalculationError : size_t;

    class NSData;
    class NSDate;
    class NSDebug;
    class NSDecimalNumber;
    class NSError;
    class NSLocale;
    class NSNumber;
    class NSString;
    class NSStringHelper;
    class NSValue;
    
    struct NSDecimal;
    struct NSRange;
}

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    class NSArray;
    class NSDictionary;
    class NSEnumerator;
    class NSMutableArray;
    class NSNull;

    struct ArrayWrapperBase;
    struct DictionaryWrapperBase;
    struct EnumeratorWrapperBase;

    template <class T> //requires std::derived_from<T, NSObject>
    struct ArrayWrapper;

    template <class T> //requires std::derived_from<T, NSObject>
    struct BlockArrayWrapper;

    template <class T> //requires std::derived_from<T, NSObject>
    struct BlockEnumeratorWrapper;

    template <class TKey, class TValue> //requires std::derived_from<TKey, NSObject> && std::derived_from<TValue, NSObject>
    struct DictionaryWrapper;

    template <class T> //requires std::derived_from<T, NSObject>
    struct EnumeratorWrapper;
}

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::FileSystem
{
    class NSFileManager;
}

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Streams
{
    class NSInputStream;
    class NSStream;
}

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Text
{
    class NSScanner;
}

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Text::Xml
{
    enum struct NSXmlNodeKind : size_t;
    
    class NSXmlAttribute;
    class NSXmlDocument;
    class NSXmlElement;
    class NSXmlNode;
    class NSXmlText;
}

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Threading
{
    KONGKONG_INTERFACE NSLocking;
    
    class NSBlockOperation;
    class NSLock;
    class NSOperation;
    class NSOperationQueue;
    class NSThread;

}

#ifdef KONGKONG_OBJECTIVE_C_METAL_ENABLED

namespace KONGKONG_NAMESPACE::AppleDevice::Metal
{
    enum struct MetalCommandBufferError;
    enum struct MetalLogLevel;
    
    KONGKONG_INTERFACE MetalDevice;
    KONGKONG_INTERFACE MetalLogState;

    class MetalCommandQueueDescriptor;
}

#endif //KONGKONG_OBJECTIVE_C_METAL_ENABLED

#endif //KONGKONG_OBJECTIVE_C_ENABLED

namespace KONGKONG_NAMESPACE::Bits
{
    class BitManager;

    struct _bitSetIteratorBase;

    template <ssize_t N> requires (N >= 1)
    struct BitSet;

    struct BitSetElement;
    struct BitSetIterator;

    struct Byte;

    struct ConstBitSetIterator;
}

namespace KONGKONG_NAMESPACE::Collections
{
    enum struct CollectionChange : uint8_t;

    struct _keyValuePairMethods;
    struct _stackElementMethods;
    struct _treeNodeMethods;

    struct ArrayChangingEventArgs;

    template <class T>
    KONGKONG_INTERFACE IArray;

    template <class T>
    KONGKONG_INTERFACE ICollection;

    template <class T>
    KONGKONG_INTERFACE IIterable;

    template <class T>
    KONGKONG_INTERFACE IReadOnlyArray;

    template <class T>
    KONGKONG_INTERFACE IReadOnlyIterable;

    template <class T>
    KONGKONG_INTERFACE IReadOnlyCollection;

    template <class TKey, class TValue>
    struct KeyValuePair;

    template <class T>
    struct LinkElement;

    template <class T>
    struct Span;

    template <class T>
    struct StackElement;

    template <class T>
    struct TreeNode;

    template <class T>
    class Array;

    class ArrayHelper;

    template <class T>
    class ArrayList;

    template <class T>
    class ArrayListBase;

    class CollectionHelper;

    template <class T>
    class List;

    template <class T>
    class ObservableArrayList;

    template <class T>
    class PointerList;

    template <class T>
    class LinkedList;

    template <class T>
    class Stack;

    
}

namespace KONGKONG_NAMESPACE::Collections::IMPLEMENTATION
{
    template <class T>
    KONGKONG_INTERFACE IArray;

    template <class T>
    KONGKONG_INTERFACE ICollection;

    template <class T>
    KONGKONG_INTERFACE IIterable;

    template <class T>
    KONGKONG_INTERFACE IReadOnlyArray;

    template <class T>
    KONGKONG_INTERFACE IReadOnlyIterable;

    template <class T>
    KONGKONG_INTERFACE IReadOnlyCollection;

    //配列のラッパー
    template <class T>
    struct Array;

    template <class T>
    struct ArrayList;

    template <class T>
    struct ArrayListBase;

    template <class T>
    struct LinkedList;

    template <class T>
    struct List;

    template <class T>
    struct ObservableArrayList;

    template <class T>
    struct PointerList;

    template <class T>
    struct Stack;
}

namespace KONGKONG_NAMESPACE::Collections::Iterators
{
    template <class T>
    class ArrayIterator;

    template <class T>
    class ArrayListIterator;

    template <class T>
    class ConstArrayIterator;

    template <class T>
    class ConstArrayListIterator;

    template <class T>
    class ConstIterator;

    template <class T>
    class ConstLinkedListIterator;

    template <class T>
    class ConstPointerListIterator;

    template <class T>
    class Iterator;

    template <class T>
    class LinkedListIterator;

    template <class T>
    class PointerListIterator;
}

namespace KONGKONG_NAMESPACE::Collections::Iterators::IMPLEMENTATION
{
    template <class T>
    struct ArrayIterator;

    template <class T>
    struct ArrayListIterator;

    template <class T>
    struct ConstArrayIterator;

    template <class T>
    struct ConstArrayListIterator;

    template <class T>
    struct ConstIterator;

    template <class T>
    struct ConstLinkedListIterator;

    template <class T>
    struct ConstPointerListIterator;

    template <class T>
    struct Iterator;

    template <class T>
    struct LinkedListIterator;

    template <class T>
    struct PointerListIterator;
}

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T>
    struct ConstFastLinkedListIterator;

    template <class T>
    struct ConstFastPointerArrayIterator;

    template <class T>
    struct FastArray;

    template <class T>
    struct FastArrayBase;

    template <class T>
    struct FastArrayList;

    template <class TKey, class TValue>
    struct FastArrayMap;

    template <class T>
    struct FastArrayQueue;

    template <class T>
    struct FastBinarySearchTree;

    template <class T, ssize_t N> requires (N >= 1 && sizeof(T) != 0)
    struct BuiltInArray;

    template <class T, ssize_t N> requires (N >= 1 && sizeof(T) != 0)
    struct BuiltInArrayList;

    template <class T>
    struct FastLinkedList;

    template <class T>
    struct FastLinkedListIterator;

    template <class T>
    struct FastLinkedQueue;

    template <class TKey, class TValue>
    struct FastMap;

    template <class T>
    struct FastPointerArrayIterator;

    template <class T>
    struct FastPointerList;

    template <class T>
    struct FastThreadSafeArray;

    template <class T>
    struct FastThreadSafeArrayList;

    template <class T, ssize_t N> requires (N >= 1 && sizeof(T) != 0)
    struct _builtInArrayBase;

    template <class T>
    struct _fastLinkedListIteratorBase;

    struct _builtInArrayMethods;
    struct _constFastPointerArrayIteratorMethods;
    struct _fastArrayListMethods;
    struct _fastArrayMapMethods;
    struct _fastArrayMethods;
    struct _fastArrayQueueBase;
    struct _fastBinarySearchTreeMethods;
    struct _fastBuiltInArrayMethods;
    struct _fastCollection;
    struct _fastLinkedListIteratorMethods;
    struct _fastLinkedListMethods;
    struct _fastLinkedQueueMethods;
    struct _fastMapMethods;
    struct _fastPointerArrayIteratorMethods;
    struct _fastPointerListMethods;
    struct _fastThreadSafeArrayListMethods;
    struct _fastThreadSafeArrayMethods;
}

namespace KONGKONG_NAMESPACE::CStd
{
    enum struct CFilePosition;
    enum struct CLocaleCategory;
    enum struct CMutexKind;
    enum struct CThreadSleepResult;
    enum struct CThreadStatus;

    struct _cFileReaderBase;
    struct _cFileStream;
    struct _cFileWriterBase;

    struct CBinaryFileReader;
    struct CBinaryFileWriter;
    struct CFileReader;
    struct CFileWriter;
    struct CStdException;

#if __has_include(<threads.h>)
    class CConditionVariable;
    class CMutex;
    class CThread;
    struct CScopeLock;
    struct CThreadPool;
    struct CThreadResult;
    struct CThreadException;
#endif //__has_include(<threads.h>)

    class BuiltInArray;
    class CConsole;
    class CFile;
    class CLocale;
    class CMemoryManager;
    class CRandomGenerator;
    class CStdErrorChecker;
    class CString;
}

namespace KONGKONG_NAMESPACE::Diagnostics
{
    enum struct LifecycleEventType : uint8_t;

    struct LifecycleEventArgs;
    struct LifecycleObject;
    struct StopWatch;

    class Debug;

}

namespace KONGKONG_NAMESPACE::Events
{
    struct EventArgs;

    template <class TSender, class TArgs>
    struct EventFunction;

    template <class TSender, class TArgs>
    struct EventFunctions;

    //イベントハンドラー
    template <class TSender, class TArgs>
    struct EventHandler;
}

namespace KONGKONG_NAMESPACE::Graphics
{
    struct Color;
    struct ColorF;

    class _winComInitializer;
}

namespace KONGKONG_NAMESPACE::Graphics::Imaging
{
    enum struct ImageFormat;

    struct ImageRenderException;

    class BitmapImage;
}

namespace KONGKONG_NAMESPACE::IO::Storage
{
    class Directory;
    class File;
    class Path;

    struct DirectoryNotFoundException;
    struct FileNotFoundException;
    struct PathAlreadyExistsException;
    struct PathNotFoundException;
}

namespace KONGKONG_NAMESPACE::Memory
{
    template <class T>
    struct Buffer;

    struct BufferBase;
    
    class MemoryAllocator;
    class MemoryBlock;

    template <class THandle>
    class SharedHandle;

    template <class T>
    struct SharedPointer;

    template <class T>
    struct WeakPointer;

    struct _sharedPointerBase;
    struct _weakPointerBase;

    class _sharedHandleBase;
}

namespace KONGKONG_NAMESPACE::Memory::IMPLEMENTATION
{
    struct MemoryBlock;
}

namespace KONGKONG_NAMESPACE::Net
{
    struct IPv4Address;
}

namespace KONGKONG_NAMESPACE::Numeric
{
    enum struct Sign;

    struct BigInteger;

    template <std::floating_point TFloat>
    struct Complex;

    template <NumberType Num>
    struct Div;

    template <NumberType TNum>
    struct DynamicVector;

    template <std::floating_point TNum>
    struct Equation2;

    template <NumberType TNum, ssize_t NRow, ssize_t NColumn> requires (NRow >= 1 && NColumn >= 1)
    struct Matrix;

    template <std::floating_point TFloat>
    struct PolarComplex;

    template <NumberType Num, ssize_t N> requires (N > 0)
    struct Vector;

    class Math;
    class Random;
    class RandomBase;
    class RandomCircle;
    class RandomCircleBase;
}

namespace KONGKONG_NAMESPACE::Numeric::IMPLEMENTATION
{
    struct Random;
    struct RandomBase;
    struct RandomCircle;
    struct RandomCircleBase;
}

namespace KONGKONG_NAMESPACE::Numeric::NumberTypes
{
    template <NumberType Num>
    class NumberTemplate;
}

namespace KONGKONG_NAMESPACE::Numeric::Shapes
{
    class Circle;

    template <ssize_t N> requires (N == 2 || N == 3)
    class Shape;

    class Shape2D;
}

namespace KONGKONG_NAMESPACE::Numeric::Shapes::IMPLEMENTATION
{
    struct Circle;

    struct Point2D;

    template <ssize_t N> requires (N == 2 || N == 3)
    struct Shape;

    struct Shape2D;
}

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    template <NumberType T>
    struct Bin;

    template <class TNum = void> requires NumberType<TNum> || ::std::same_as<TNum, void>
    struct DataSummary;

    template <NumberType T>
    struct Histogram;

    template <NumberType T>
    struct HistogramIterator;

    template <::std::floating_point TNum>
    struct NormalDistribution;

    template <::std::floating_point TNum>
    class StandardNormalDistribution;

    template <::std::floating_point TNum>
    struct UniformDistribution;

    template <::std::floating_point TNum>
    struct ZeroMeanNormalDistribution;

    struct HistogramBase;
    struct _binBase;
    struct _histogramIteratorBase;

    template <::std::floating_point TNum>
    struct _normalDistributionBase;
}

//Posixのみ
#ifdef KONGKONG_ENV_UNIX

namespace KONGKONG_NAMESPACE::Posix
{
    struct PosixException;

    class Environment;
    class Process;
}

namespace KONGKONG_NAMESPACE::Posix::IMPLEMENTATION
{
    struct Process;
    
}

namespace KONGKONG_NAMESPACE::Posix::IO
{
    enum struct FileMode : mode_t;
    enum struct FileOpen;
    enum struct FileType;

    struct DirectoryEntry;
    struct DirectoryInfo;
    struct FileInfo;

    class Directory;
    class DirectoryIterator;
    class FileReader;
    class FileRW;
    class FileWriter;
    class InputDevice;
    class IODevice;
    class IOHelper;
    class OutputDevice;
    class Pipe;
    class Path;
    class RWDevice;
}

namespace KONGKONG_NAMESPACE::Posix::IO::IMPLEMENTATION
{
    struct Directory;
    struct DirectoryIterator;
}

namespace KONGKONG_NAMESPACE::Posix::Threading
{
    enum struct MutexKind;
    enum struct ThreadCreate;
    enum struct ThreadScope;
    
    struct Mutex;
    struct Thread;
    struct ThreadAttribute;
    struct ThreadStackInfo;
    struct ThreadPool;
}

#endif

namespace KONGKONG_NAMESPACE::Std
{
    template <CharType TChar>
    class GenericOutStringStream;

    template <CharType TChar>
    class GenericStringBuffer;
    
    class StdString;

    struct StlThreadPool;

#ifdef KONGKONG_ENV_UNIX

    template <CharType TChar>
    class GenericPosixFileIOBuffer;

    template <CharType TChar>
    class GenericPosixIOBuffer;

#endif //KONGKONG_ENV_UNIX
}

namespace KONGKONG_NAMESPACE::System
{
    struct CppVersion;
    class BuildConfig;
    struct BuildVersion;
}

namespace KONGKONG_NAMESPACE::Text
{
    enum struct StringType : uint8_t;
    enum struct Utf8CharAttribute : uint8_t;

    template <CharType TChar>
    struct _stringPointer;

    struct _stringPointerBase;

    template <CharType TChar, ssize_t N> requires (N >= 1)
    struct GenericFixedString;

    struct InvalidCodePointException;

    template <CharType TChar, ssize_t N>
    struct StaticStringData;

    class _stringGC;
    class AsciiEncoding;
    class Encoding;
    class StaticStringDataCreater;
    class StringHelper;
}

namespace KONGKONG_NAMESPACE::Text::IMPLEMENTATION
{
    struct AsciiEncoding;
    struct Encoding;
}

namespace KONGKONG_NAMESPACE::Text::Json
{
    enum struct JsonValueType : uint8_t;

    class JsonArray;
    //class JsonDocument;
    class JsonObject;
    class JsonParser;
    struct JsonValue;
}

namespace KONGKONG_NAMESPACE::Text::Json::IMPLEMENTATION
{
    struct JsonArray;
    struct JsonObject;
}

namespace KONGKONG_NAMESPACE::Text::Unicode
{
    struct SurrogatePair;
    struct UnicodeRange;
    struct UnicodeRangeIterator;
    struct Utf8Char;

    class ByteOrderMark;
    class UnicodeConverter;
    class UnicodeTraits;
}

namespace KONGKONG_NAMESPACE::Text::Yaml
{
    enum struct YamlDataType : uint8_t;
    enum struct YamlNodeType : uint8_t;

    class YamlNode;
    class YamlText;
}

namespace KONGKONG_NAMESPACE::Text::Xml
{
    enum struct XmlNodeType : uint8_t;

    struct _xmlContent;
    struct _xmlName;
    struct XmlDeclaration;

    class XmlAttribute;
    class XmlComment;
    class XmlContainer;
    class XmlElement;
    class XmlEntities;
    class XmlNode;
    class XmlObject;
}

namespace KONGKONG_NAMESPACE::Text::Xml::IMPLEMENTATION
{
    struct XmlAttribute;
    struct XmlComment;
    struct XmlContainer;
    struct XmlElement;
    struct XmlNode;
    struct XmlObject;
}

namespace KONGKONG_NAMESPACE::Text::Yaml::IMPLEMENTATION
{
    struct YamlNode;
    struct YamlText;
}

namespace KONGKONG_NAMESPACE::Threading
{
    enum struct TaskStatus;

    struct _asyncOperationBase;

    struct _awaiterBase;

    struct AsyncAction;

    template <class T> requires (::std::is_void_v<T> == false)
    struct AsyncOperation;

    struct ThreadStateException;

    struct Mutex;
    struct ScopeLock;

    template <class T>
    struct Generator;

    class ParallelFor;
    class Thread;
    class ThreadPool;
}

namespace KONGKONG_NAMESPACE::Time
{
    enum struct DateTimeKind;
    enum struct DayOfWeek;

    struct DateTime;
}

#ifdef KONGKONG_ENV_WINDOWS

namespace KONGKONG_NAMESPACE::Win32
{
    enum struct ClassType;
    enum struct CodePage : unsigned;
    enum struct ConsoleBackground : int16_t;
    enum struct ConsoleForeground : int16_t;
    enum struct CtrlKeyEventKind;
    enum struct DwmTitleBarTheme;
    enum struct HandleFrag : unsigned long;
    enum struct LoadLibraryFlag;
    enum struct MessageBeepKind : long;
    enum struct MessageBoxButton : long;
    enum struct MessageBoxDefaultButton : long;
    enum struct MessageBoxImage : long;
    enum struct MessageBoxModality : long;
    enum struct MessageBoxOtherOptions : long;
    enum struct MessageBoxResult;
    enum struct ProcessorArchitecture : uint16_t;
    enum struct RegistryKeyAccessRight;
    enum struct RegistryOption : long;
    enum struct RegistryValueType;
    enum struct SecurityFlag;
    enum struct SoundFlag;
    enum struct SoundKind;
    enum struct VersionNT : uint8_t;
    enum struct VersionSuite : uint32_t;
    enum struct WaitStatus : DWORD;
    

    struct ConsolePoint;
    struct HResultException;
    struct LocalTime;
    struct MemoryStatus;
    struct OSVersionInfo;
    struct RegistryValue;
    struct SystemInfo;
    struct SystemTime;
    struct SystemTimeBase;
    struct WaitObjectInfo;

    class CharHelper;
    class ClassTypeHelper;
    class ComputerName;
    class Environment;
    class Handle;
    class MessageBox;
    class MinWinHelper;
    class RegistryKey;
    class RegistryKeyBase;
    class RegistryKeyView;
    class Sound;
    class StringHelper;
    
}

namespace KONGKONG_NAMESPACE::Win32::Execution
{
    class Module;
    class ModuleBase;
    class ModuleWeakRef;
}

namespace KONGKONG_NAMESPACE::Win32::IO
{
    enum struct DriveKind;
    enum struct FileAccessMode : unsigned long;
    enum struct FileAttribute;
    enum struct FileFlag : unsigned;
    enum struct FileNameKind;
    enum struct FileOpenMode;
    enum struct FileShareMode;
    enum struct FileType;
    enum struct VolumeNameKind;

    struct FileSystemInfo;

    class Directory;
    class File;
    class InputDevice;
    class IODevice;
    class OutputDevice;
    class Path;
    class WinConsole;
}

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    class ConsoleAPI;
    class DesktopWindowManager;
    class ErrorChecker;
    class FileAPI;
    class HandleAPI;
    class LibLoaderAPI;
    class NamedPipeAPI;
    class ProcessThreadAPI;
    class SyncHAPI;
    class SysInfoAPI;
    class TimeZoneAPI;
    class VersionHelper;
    class WinBase;
    class WinHttp;
    class WinRegistry;
    class WinUser;
}

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    enum struct ThreadStart;
    
    struct CallbackEnvironment;
    struct ProcessorNumber;
    struct StackInfo;

    class _cleanupGroupBase;
    class _threadPoolBase;
    
    class CleanupGroup;
    class CleanupGroupView;
    class Event;
    class Mutex;
    class Semaphore;
    class Thread;
    class ThreadPool;
    class ThreadPoolView;
    class WaitHandle;
}

namespace KONGKONG_NAMESPACE::Win32::UI
{
    enum struct ElementTheme;
    enum struct HorizontalAlignment;
    enum struct SystemBackDrop;
    enum struct VerticalAlignment;
    enum struct WindowActivate;
    enum struct WindowCornerPreference;


    struct Color;
    struct DpiChangedEventArgs;
    struct Rect;

    template <NumberType TNum>
    struct _Size;


    struct PaintRequestedEventArgs;
    struct SizeChangedEventArgs;
    struct Thickness;
    struct WindowActivatedEventArgs;
    struct WindowClosingEventArgs;
    struct WindowCreatingEventArgs;

    class ButtonBase;
    
    class TitleBar;
    class UIElement;
    class Window;
    
}

namespace KONGKONG_NAMESPACE::Win32::UI::IMPLEMENTATION
{
    struct Button;
    struct ButtonBase;
    struct Control;
    struct TextBlock;
    struct TitleBar;
    struct UIElement;
    struct Window;
}

#endif //KONGKONG_ENV_WINDOWS

namespace KONGKONG_NAMESPACE
{
    using String = GenericString<char16_t>;
    
    using CharString = GenericString<char>;
    using WideString = GenericString<wchar_t>;
    using Utf8String = GenericString<char8_t>;
    using Utf16String = GenericString<char16_t>;
    using Utf32String = GenericString<char32_t>;

    using FastString = FastGenericString<char16_t>;
    
    using FastCharString = FastGenericString<char>;
    using FastWideString = FastGenericString<wchar_t>;
    using FastUtf8String = FastGenericString<char8_t>;
    using FastUtf16String = FastGenericString<char16_t>;
    using FastUtf32String = FastGenericString<char32_t>;

    using StringView = GenericStringView<char16_t>;
    
    using CharStringView = GenericStringView<char>;
    using WideStringView = GenericStringView<wchar_t>;
    using Utf8StringView = GenericStringView<char8_t>;
    using Utf16StringView = GenericStringView<char16_t>;
    using Utf32StringView = GenericStringView<char32_t>;
}

namespace KONGKONG_NAMESPACE::Collections
{
    template <class TArray>
    using ArrayChangingEventHandler = Events::EventHandler<TArray, ArrayChangingEventArgs>;
}

namespace KONGKONG_NAMESPACE::Diagnostics
{
    using LifecycleEventHandler = Events::EventHandler<LifecycleObject, LifecycleEventArgs>;
}

namespace KONGKONG_NAMESPACE::Graphics
{
    using Point2F = Numeric::Vector<float, 2>;
}

namespace KONGKONG_NAMESPACE::Numeric
{
    using DivNativeInt = Div<int>;
    using DivNativeUInt = Div<unsigned>;
    using DivInt8 = Div<int8_t>;
    using DivInt16 = Div<int16_t>;
    using DivInt32 = Div<int32_t>;
    using DivInt64 = Div<int64_t>;
    using DivUInt8 = Div<uint8_t>;
    using DivUInt16 = Div<uint16_t>;
    using DivUInt32 = Div<uint32_t>;
    using DivUInt64 = Div<uint64_t>;

    template <NumberType TNum, ssize_t N> requires (N >= 1)
    using SquareMatrix = Matrix<TNum, N, N>;

    template <NumberType TNum>
    using Vector2 = Vector<TNum, 2>;

    template <NumberType TNum>
    using Vector3 = Vector<TNum, 3>;

    using Vector2Int = Vector2<int>;
    using Vector2Double = Vector2<double>;

    using Vector3Int = Vector3<int>;
    using Vector3Double = Vector3<double>;
}

namespace KONGKONG_NAMESPACE::Numeric::NumberTypes
{
    using Int = NumberTemplate<int>;
    using UInt = NumberTemplate<unsigned>;

    using Int8 = NumberTemplate<int8_t>;
    using Int16 = NumberTemplate<int16_t>;
    using Int32 = NumberTemplate<int32_t>;
    using Int64 = NumberTemplate<int64_t>;
    using UInt8 = NumberTemplate<uint8_t>;
    using UInt16 = NumberTemplate<uint16_t>;
    using UInt32 = NumberTemplate<uint32_t>;
    using UInt64 = NumberTemplate<uint64_t>;
    using Single = NumberTemplate<float>;
    using Double = NumberTemplate<double>;

    using IntPtr = NumberTemplate<ssize_t>;
    using UIntPtr = NumberTemplate<size_t>;
}

namespace KONGKONG_NAMESPACE::Std
{
    using StringBuffer = GenericStringBuffer<char16_t>;

    using CharStringBuffer = GenericStringBuffer<char>;
    using WideStringBuffer = GenericStringBuffer<wchar_t>;
    using Utf8StringBuffer = GenericStringBuffer<char8_t>;
    using Utf32StringBuffer = GenericStringBuffer<char32_t>;

    using OutStringStream = GenericOutStringStream<char16_t>;

    using CharOutStringStream = GenericOutStringStream<char>;
    using WideOutStringStream = GenericOutStringStream<wchar_t>;
    using Utf8OutStringStream = GenericOutStringStream<char8_t>;
    using Utf32OutStringStream = GenericOutStringStream<char32_t>;

#ifdef KONGKONG_ENV_UNIX

    using PosixIOBuffer = GenericPosixIOBuffer<char16_t>;

    using CharPosixIOBuffer = GenericPosixIOBuffer<char>;
    using WidePosixIOBuffer = GenericPosixIOBuffer<wchar_t>;
    using Utf8PosixIOBuffer = GenericPosixIOBuffer<char8_t>;
    using Utf32PosixIOBuffer = GenericPosixIOBuffer<char32_t>;

    using PosixFileIOBuffer = GenericPosixFileIOBuffer<char16_t>;

    using CharPosixFileIOBuffer = GenericPosixFileIOBuffer<char>;
    using WidePosixFileIOBuffer = GenericPosixFileIOBuffer<wchar_t>;
    using Utf8PosixFileIOBuffer = GenericPosixFileIOBuffer<char8_t>;
    using Utf32PosixFileIOBuffer = GenericPosixFileIOBuffer<char32_t>;

#endif //KONGKONG_ENV_UNIX
}

namespace KONGKONG_NAMESPACE::System
{
#ifdef KONGKONG_ENV_WINDOWS
    using Environment = ::KONGKONG_NAMESPACE::Win32::Environment;
#elif defined(KONGKONG_ENV_UNIX)
    using Environment = ::KONGKONG_NAMESPACE::Posix::Environment;
#else
    class Environment;
#endif
}

#ifdef KONGKONG_ENV_WINDOWS

namespace KONGKONG_NAMESPACE::Win32::UI
{
    using Size = _Size<double>;
    using SizeInt32 = _Size<int32_t>;
    
    using ClickEventHandler = Events::EventHandler<ButtonBase, Events::EventArgs>;
    using DpiChangedEventHandler = Events::EventHandler<UIElement, DpiChangedEventArgs>;
    using PaintRequestedEventHandler = Events::EventHandler<UIElement, PaintRequestedEventArgs>;
    using SizeChangedEventHandler = Events::EventHandler<UIElement, SizeChangedEventArgs>;
    using WindowEventHandler = Events::EventHandler<Window, Events::EventArgs>;
    using WindowActivatedEventHandler = Events::EventHandler<Window, WindowActivatedEventArgs>;
    using WindowClosingEventHandler = Events::EventHandler<Window, WindowClosingEventArgs>;
    using WindowCratingEventHandler = Events::EventHandler<Window, WindowCreatingEventArgs>;
}

#endif //KONGKONG_ENV_WINDOWS

namespace KONGKONG_NAMESPACE
{

    //すべてのKongkong型の親クラス
    struct KongkongTypeBase {
        protected:
        KongkongTypeBase() = default;
    };

    //mainに入る前に処理
    struct Initializer : public KongkongTypeBase {
        Initializer(void(*func())) { func(); }
        Initializer(void(*func)(void)) { func(); }

        Initializer(Initializer const&) = delete;

        Initializer& operator=(Initializer const&) = delete;
    };
}

#endif //!KONGKONG_BASE_H
