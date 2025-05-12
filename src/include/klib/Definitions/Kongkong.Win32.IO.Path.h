#ifndef KONGKONG_WIN32_IO_PATH_H
#define KONGKONG_WIN32_IO_PATH_H

#include "Base.h"

#include "Kongkong.Win32.Environment.h"
#include "Kongkong.Win32.Primitives.FileAPI.h"

namespace KONGKONG_NAMESPACE::Win32::IO
{
    class Path final {
        public:

        STATIC_CLASS(Path)

        [[nodiscard]] static constexpr uint32_t MaxPathLength() noexcept { return Primitives::FileAPI::MaxPathLength(); }
        [[nodiscard]] static constexpr char16_t Separator() noexcept { return Environment::PathSeparator(); }

        /// @brief ふぁ！？っく
        static bool Exists(std::nullptr_t) = delete;

        //ワイルドカード*を使用することも可能
        [[nodiscard]] static bool Exists(const char16_t* path) noexcept;
        [[nodiscard]] static bool Exists(String const& path) noexcept;

        /// @brief ふぁ！？っく
        static Collections::IArray<FileSystemInfo> Find(std::nullptr_t) = delete;

        /// @brief ワイルドカード*を使用してパスを検索
        /// @param path 検索するパス
        /// @return パスのリスト
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        /// @throws HResultException: 操作に失敗したとき
        [[nodiscard]]
        static Collections::IArray<FileSystemInfo> Find(const char16_t* path);

        /// @brief ワイルドカード*を使用してパスを検索
        /// @param path 検索するパス
        /// @return パスのリスト
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        /// @throws HResultException: 操作に失敗したとき
        [[nodiscard]]
        static Collections::IArray<FileSystemInfo> Find(String const& path);


        [[nodiscard]] static Collections::IArray<FileSystemInfo> GetDirectories(const char16_t* path);
        [[nodiscard]] static Collections::IArray<FileSystemInfo> GetFiles(const char16_t* path);

        /// @brief ふぁ！？っく
        static String GetFullPath(std::nullptr_t) = delete;

        /// @brief 完全パスを取得
        /// @attention このAPIはnameの形式が正しいかどうかは確認しないよ！
        /// @param name パス名
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        /// @throws HResultException: 操作に失敗したとき
        [[nodiscard]]
        static String GetFullPath(const char16_t* name);

        /// @brief 完全パスを取得
        /// @attention このAPIはnameの形式が正しいかどうかは確認しないよ！
        /// @param name パス名
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        /// @throws HResultException: 操作に失敗したとき
        [[nodiscard]]
        static String GetFullPath(String const& name);
        
    };
}

#endif //!KONGKONG_WIN32_IO_PATH_H
