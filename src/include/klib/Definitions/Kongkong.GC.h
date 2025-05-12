#ifndef KONGKONG_GC_H
#define KONGKONG_GC_H

#include "Base.h"
#include "Kongkong.Threading.Mutex.h"

#include <map>

namespace KONGKONG_NAMESPACE
{
    /// @brief ガベージコレクタ
    /// @attention Javaのそれみたいに賢くはないよ
    class GC final {
        public:

        STATIC_CLASS(GC)

        /// @brief ハンドル数を取得
        [[nodiscard]]
        static ssize_t HandleCount() noexcept;

        /// @brief インスタンスの数を取得
        [[nodiscard]]
        static ssize_t ObjectCount() noexcept;

        private:

        using ImplType = void;

        static ssize_t _userCount(void* p) noexcept;

        template <class Ty>
        static void _deleteP(void* p) noexcept
        {
            delete (Ty*)p;
        }

        /// @brief オブジェクトの参照カウンタ
        class __objectCounter {
            public:
            /// @brief 参照カウント
            size_t _count;

            /// @brief インターフェースを参照していて実際のオブジェクトとポインターの位置がずれているかどうか
            bool __isNotReal;

            /// @brief インターフェースを参照していてオブジェクトの実態とポインターがずれているときの実際のオブジェクトの位置
            void* __realPointer;

            /// @brief オブジェクトの開放を行う関数ポインター
            /// @attention インターフェースを参照していてオブジェクトの実態とポインターがずれているときはnullptr
            void (*_f)(void*);

            constexpr __objectCounter(void (*f)(void*)) noexcept : _f(f), _count(1), __isNotReal(false), __realPointer(nullptr) {}
            //__objectCounter(__objectCounter const&) = delete;
            //__objectCounter(__objectCounter&&) = default;
            __objectCounter() = default;
            constexpr __objectCounter(ImplType* realPointer) noexcept : _f(nullptr), _count(1), __isNotReal(true), __realPointer(realPointer) {}

            constexpr __objectCounter& operator++() noexcept { ++_count; return *this; }
            constexpr __objectCounter& operator--() noexcept { --_count; return *this; }

            constexpr bool __hasNoReference() const noexcept { return _count == 0; }

            void operator()(void* p) { _f(p); }

            void __erase(void* p);

        };

        //オブジェクトへのポインタ
        class __objectPtr {
            public:
            ImplType* _p;
            constexpr __objectPtr() noexcept : _p(nullptr) {}

            /// @brief pがすでに_gcに登録されていることを前提に作成
            __objectPtr(ImplType* p) noexcept;
            __objectPtr(ImplType* p, ImplType* pReal);

            __objectPtr(__objectPtr const& right) noexcept;
            constexpr __objectPtr(__objectPtr&& right) noexcept : _p(right._p) { right._p = nullptr; }

            ~__objectPtr() { __erase(); }

            __objectPtr& operator=(__objectPtr const& right);
            __objectPtr& operator=(__objectPtr&& right) noexcept;

            void __erase();

        };

        static std::map<void*, __objectCounter> _gc;
        static Threading::Mutex _mutex;

        friend Object;
        friend Memory::_sharedPointerBase;
        friend Memory::_weakPointerBase;
        friend Memory::_sharedHandleBase;

        template <class T>
        friend struct Memory::SharedPointer;

        template <class THandle>
        friend class Memory::SharedHandle;

    };
}

#endif //!KONGKONG_GC_H
