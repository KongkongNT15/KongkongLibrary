#ifndef KONGKONG_CSTD_CTHREADPOOL_H
#define KONGKONG_CSTD_CTHREADPOOL_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Memory.Buffer.h"
#include "Kongkong.CStd.CThread.h"
#include "Kongkong.CStd.CMutex.h"
#include "Kongkong.CStd.CConditionVariable.h"
#include "Kongkong.Collections.Turbo.FastArrayQueue.h"
#include "Kongkong.Collections.KeyValuePair.h"

namespace KONGKONG_NAMESPACE::CStd
{
    struct CThreadPool final : public ValueType {
        using FuncType = void(*)(void*);

        CThreadPool();
        CThreadPool(CThreadPool const&) = delete;

        ~CThreadPool();

        CThreadPool& operator=(CThreadPool const&) = delete;

        /// @brief ふぁ！？っく
        void PushTask(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void PushTask(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void PushTask(std::nullptr_t, void*) = delete;

        void PushTask(FuncType func);
        void PushTask(FuncType func, std::nullptr_t);
        void PushTask(FuncType func, void* args);

        /// @brief ふぁ！？っく
        void PushTaskUnsafe(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void PushTaskUnsafe(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void PushTaskUnsafe(std::nullptr_t, void*) = delete;

        void PushTaskUnsafe(FuncType func);
        void PushTaskUnsafe(FuncType func, std::nullptr_t);
        void PushTaskUnsafe(FuncType func, void* args);

        /// @brief スレッド数
        [[nodiscard]]
        constexpr ssize_t ThreadCount() const noexcept { return _buffer.Length(); }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:

        static int _threadFunction(void* args) noexcept;

        static void _checkFunc(FuncType func);

        Memory::Buffer<CThread> _buffer;
        CMutex _mutex;
        CConditionVariable _conditionVariable;
        Collections::Turbo::FastArrayQueue<Collections::KeyValuePair<FuncType, void*>> _taskQueue;
        bool _isRunning;
    };
}

#endif //!KONGKONG_CSTD_CTHREADPOOL_H
