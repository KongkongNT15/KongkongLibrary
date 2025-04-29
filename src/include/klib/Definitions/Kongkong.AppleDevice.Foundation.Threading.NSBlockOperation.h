#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSBLOCKOPERATION_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSBLOCKOPERATION_H

#include "Base.h"
#include "Kongkong.AppleDevice.Foundation.Threading.NSOperation.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Threading
{
    class NSBlockOperation : public NSOperation {
        public:
        using BlockType = void(^)(void);
        using VoidFuncType = void(*)();
        using ArgsFuncType = void(*)(void*);

        /// @brief タスクを作成
        /// @param block 実行するタスク
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static NSBlockOperation CreateUnsafe(BlockType block);

        /// @brief タスクを作成
        /// @param func 実行するタスク
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static NSBlockOperation CreateUnsafe(VoidFuncType func);

        /// @brief タスクを作成
        /// @param func 実行するタスク
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static NSBlockOperation CreateUnsafe(ArgsFuncType func);

        /// @brief タスクを作成
        /// @param func 実行するタスク
        /// @param args funcに与える引数
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static NSBlockOperation CreateUnsafe(ArgsFuncType func, void* args);

        /// @brief タスクを作成
        /// @param func 実行するタスク
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static NSBlockOperation CreateUnsafe(ArgsFuncType func, std::nullptr_t);

        /// @brief ふぁ！？っく
        NSBlockOperation(std::nullptr_t, void*) = delete;
        
        /// @brief タスクを作成
        /// @param block 実行するタスク
        /// @throws ArgumentNullException: blockがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSBlockOperation(BlockType block);

        /// @brief タスクを作成
        /// @param func 実行するタスク
        /// @throws ArgumentNullException: funcがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSBlockOperation(VoidFuncType func);

        /// @brief タスクを作成
        /// @param func 実行するタスク
        /// @throws ArgumentNullException: funcがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSBlockOperation(ArgsFuncType func);

        /// @brief タスクを作成
        /// @param func 実行するタスク
        /// @param args funcに与える引数
        /// @throws ArgumentNullException: funcがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSBlockOperation(ArgsFuncType func, void* args);

        /// @brief タスクを作成
        /// @param func 実行するタスク
        /// @throws ArgumentNullException: funcがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        NSBlockOperation(ArgsFuncType func, std::nullptr_t);

        /// @brief nullptrとして作成
        constexpr NSBlockOperation(std::nullptr_t) noexcept : NSOperation(nullptr) {}

        /// @brief タスクを追加
        /// @param block タスク
        /// @throws ArgumentNullException: blockがnullptrのとき
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void AddExecutionBlock(BlockType block) const;

        /// @brief タスクを作成
        /// @param func タスク
        /// @throws ArgumentNullException: funcがnullptrのとき
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void AddExecutionBlock(VoidFuncType func) const;

        /// @brief タスクを作成
        /// @param func タスク
        /// @throws ArgumentNullException: funcがnullptrのとき
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void AddExecutionBlock(ArgsFuncType func) const;

        /// @brief タスクを作成
        /// @param func タスク
        /// @param args funcに与える引数
        /// @throws ArgumentNullException: funcがnullptrのとき
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void AddExecutionBlock(ArgsFuncType func, void* args) const;

        /// @brief タスクを作成
        /// @param func タスク
        /// @throws ArgumentNullException: funcがnullptrのとき
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void AddExecutionBlock(ArgsFuncType func, std::nullptr_t) const;

        /// @brief タスクを追加
        /// @param block タスク
        /// @throws ArgumentNullException: blockがnullptrのとき
        void AddExecutionBlockUnsafe(BlockType block) const noexcept;

        /// @brief タスクを作成
        /// @param func タスク
        /// @throws ArgumentNullException: funcがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        void AddExecutionBlockUnsafe(VoidFuncType func) const noexcept;

        /// @brief タスクを作成
        /// @param func タスク
        /// @throws ArgumentNullException: funcがnullptrのとき
        void AddExecutionBlockUnsafe(ArgsFuncType func) const noexcept;

        /// @brief タスクを作成
        /// @param func タスク
        /// @param args funcに与える引数
        /// @throws ArgumentNullException: funcがnullptrのとき
        void AddExecutionBlockUnsafe(ArgsFuncType func, void* args) const noexcept;

        /// @brief タスクを作成
        /// @param func タスク
        /// @throws ArgumentNullException: funcがnullptrのとき
        void AddExecutionBlockUnsafe(ArgsFuncType func, std::nullptr_t) const noexcept;

        /// @brief タスクのリスト
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        Collections::BlockArrayWrapper<BlockType> ExecutionBlocks() const;

        /// @brief タスクのリストを取得
        [[nodiscard]]
        Collections::BlockArrayWrapper<BlockType> GetExecutionBlocksUnsafe() const noexcept;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSBLOCKOPERATION_H
