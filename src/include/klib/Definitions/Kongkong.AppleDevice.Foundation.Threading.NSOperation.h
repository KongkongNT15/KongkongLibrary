#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSOPERATION_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSOPERATION_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Threading
{
    class NSOperation : public NSObject {
        public:

        /// @brief nullptrとして作成
        constexpr NSOperation(std::nullptr_t) noexcept : NSObject(nullptr) {}

        /// @brief ふぁ！？っく
        void AddDependency(std::nullptr_t) const = delete;

        /// @brief 指定したタスクが完了するまでこのタスクを実行しないようにする
        /// @param op タスク
        /// @throws ArgumentNullException: opがnullptrのとき
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void AddDependency(NSOperation const& op) const;

        /// @brief ふぁ！？っく
        void AddDependencyUnsafe(std::nullptr_t) const = delete;

        /// @brief 指定したタスクが完了するまでこのタスクを実行しないようにする
        /// @param op タスク
        void AddDependencyUnsafe(NSOperation const& op) const noexcept;

        /// @brief 依存関係タスクの配列
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        Collections::ArrayWrapper<NSOperation> Dependencies() const;

        /// @brief 依存関係タスクの配列を取得
        [[nodiscard]]
        Collections::ArrayWrapper<NSOperation> GetDependenciesUnsafe() const noexcept;

        /// @brief タスクがこのスレッドに対して非同期的に実行されるかどうかを取得
        [[nodiscard]]
        bool GetIsAsynchronous() const noexcept;

        /// @brief タスクがキャンセルされたかどうかを取得
        [[nodiscard]]
        bool GetIsCancelledUnsafe() const noexcept;

        /// @brief タスクが実行中かどうかを取得
        [[nodiscard]]
        bool GetIsExecutingUnsafe() const noexcept;

        /// @brief タスクが終了したかどうかを取得
        [[nodiscard]]
        bool GetIsFinishedUnsafe() const noexcept;

        /// @brief タスクを実行可能かを取得
        [[nodiscard]]
        bool GetIsReadyUnsafe() const noexcept;

        [[nodiscard]]
        NSString GetNameUnsafe() const noexcept;

        /// @brief タスクがこのスレッドに対して非同期的に実行されるかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool IsAsynchronous() const;

        /// @brief タスクがキャンセルされたかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool IsCancelled() const;

        /// @brief タスクが実行中かどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool IsExecuting() const;

        /// @brief タスクが終了したかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool IsFinished() const;

        /// @brief タスクを実行可能かどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool IsReady() const;

        [[nodiscard]]
        NSString Name() const;

        void Name(::std::nullptr_t) const;
        void Name(NSString const& name) const;

        /// @brief ふぁ！？っく
        void RemoveDependency(std::nullptr_t) const = delete;

        void RemoveDependency(NSOperation const& op) const;

        /// @brief ふぁ！？っく
        void RemoveDependencyUnsafe(std::nullptr_t) const = delete;

        void RemoveDependencyUnsafe(NSOperation const& op) const noexcept;

        void SetNameUnsafe(::std::nullptr_t) const noexcept;
        void SetNameUnsafe(NSString const& name) const noexcept;

        /// @brief タスクを開始
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws InvalidOperationException: タスクがキャンセルされているか、実行されている時
        void Start() const;

        /// @brief タスクを開始
        /// @return 操作に成功したかどうか
        bool StartUnsafe() const noexcept;

        /// @brief タスクが終了するまで待機する
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void WaitUntilFinished() const;

        /// @brief タスクが終了するまで待機する
        void WaitUntilFinishedUnsafe() const noexcept;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSOPERATION_H
