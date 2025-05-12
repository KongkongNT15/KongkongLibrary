#ifndef KONGKONG_WIN32_MESSAGEBOX_H
#define KONGKONG_WIN32_MESSAGEBOX_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    class MessageBox final {
        public:

        STATIC_CLASS(MessageBox)

        /// @brief ふぁ！？っく
        static MessageBoxResult Show(::HWND, std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static MessageBoxResult Show(::HWND, std::nullptr_t, String const&) = delete;

        /// @brief ふぁ！？っく
        static MessageBoxResult Show(::HWND, String const&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static MessageBoxResult Show(::HWND, std::nullptr_t, std::nullptr_t, MessageBoxButton) = delete;

        /// @brief ふぁ！？っく
        static MessageBoxResult Show(::HWND, std::nullptr_t, String const&, MessageBoxButton) = delete;

        /// @brief ふぁ！？っく
        static MessageBoxResult Show(::HWND, String const&, std::nullptr_t, MessageBoxButton) = delete;

        /// @brief ふぁ！？っく
        static MessageBoxResult Show(::HWND, std::nullptr_t, std::nullptr_t, MessageBoxImage) = delete;

        /// @brief ふぁ！？っく
        static MessageBoxResult Show(::HWND, std::nullptr_t, String const&, MessageBoxImage) = delete;

        /// @brief ふぁ！？っく
        static MessageBoxResult Show(::HWND, String const&, std::nullptr_t, MessageBoxImage) = delete;

        /// @brief ふぁ！？っく
        static MessageBoxResult Show(::HWND, std::nullptr_t, std::nullptr_t, MessageBoxButton, MessageBoxImage) = delete;

        /// @brief ふぁ！？っく
        static MessageBoxResult Show(::HWND, std::nullptr_t, String const&, MessageBoxButton, MessageBoxImage) = delete;

        /// @brief ふぁ！？っく
        static MessageBoxResult Show(::HWND, String const&, std::nullptr_t, MessageBoxButton, MessageBoxImage) = delete;

        /// @brief ふぁ！？っく
        static MessageBoxResult Show(::HWND, std::nullptr_t, std::nullptr_t, MessageBoxButton, MessageBoxImage, MessageBoxDefaultButton, MessageBoxModality, MessageBoxOtherOptions) = delete;

        /// @brief ふぁ！？っく
        static MessageBoxResult Show(::HWND, std::nullptr_t, String const&, MessageBoxButton, MessageBoxImage, MessageBoxDefaultButton, MessageBoxModality, MessageBoxOtherOptions) = delete;

        /// @brief ふぁ！？っく
        static MessageBoxResult Show(::HWND, String const&, std::nullptr_t, MessageBoxButton, MessageBoxImage, MessageBoxDefaultButton, MessageBoxModality, MessageBoxOtherOptions) = delete;

        static MessageBoxResult Show(::HWND hWnd, const char16_t* messageText, const char16_t* caption);
        static MessageBoxResult Show(::HWND hWnd, const char16_t* messageText, const char16_t* caption, MessageBoxButton button);
        static MessageBoxResult Show(::HWND hWnd, const char16_t* messageText, const char16_t* caption, MessageBoxImage icon);
        static MessageBoxResult Show(::HWND hWnd, const char16_t* messageText, const char16_t* caption, MessageBoxButton button, MessageBoxImage icon);
        static MessageBoxResult Show(::HWND hWnd, const char16_t* messageText, const char16_t* caption, MessageBoxButton button, MessageBoxImage icon, MessageBoxDefaultButton defaultButton, MessageBoxModality modality, MessageBoxOtherOptions options);

        static MessageBoxResult Show(::HWND hWnd, const char16_t* messageText, String const& caption);
        static MessageBoxResult Show(::HWND hWnd, const char16_t* messageText, String const& caption, MessageBoxButton button);
        static MessageBoxResult Show(::HWND hWnd, const char16_t* messageText, String const& caption, MessageBoxImage icon);
        static MessageBoxResult Show(::HWND hWnd, const char16_t* messageText, String const& caption, MessageBoxButton button, MessageBoxImage icon);
        static MessageBoxResult Show(::HWND hWnd, const char16_t* messageText, String const& caption, MessageBoxButton button, MessageBoxImage icon, MessageBoxDefaultButton defaultButton, MessageBoxModality modality, MessageBoxOtherOptions options);

        static MessageBoxResult Show(::HWND hWnd, String const& messageText, const char16_t* caption);
        static MessageBoxResult Show(::HWND hWnd, String const& messageText, const char16_t* caption, MessageBoxButton button);
        static MessageBoxResult Show(::HWND hWnd, String const& messageText, const char16_t* caption, MessageBoxImage icon);
        static MessageBoxResult Show(::HWND hWnd, String const& messageText, const char16_t* caption, MessageBoxButton button, MessageBoxImage icon);
        static MessageBoxResult Show(::HWND hWnd, String const& messageText, const char16_t* caption, MessageBoxButton button, MessageBoxImage icon, MessageBoxDefaultButton defaultButton, MessageBoxModality modality, MessageBoxOtherOptions options);

        static MessageBoxResult Show(::HWND hWnd, String const& messageText, String const& caption);
        static MessageBoxResult Show(::HWND hWnd, String const& messageText, String const& caption, MessageBoxButton button);
        static MessageBoxResult Show(::HWND hWnd, String const& messageText, String const& caption, MessageBoxImage icon);
        static MessageBoxResult Show(::HWND hWnd, String const& messageText, String const& caption, MessageBoxButton button, MessageBoxImage icon);
        static MessageBoxResult Show(::HWND hWnd, String const& messageText, String const& caption, MessageBoxButton button, MessageBoxImage icon, MessageBoxDefaultButton defaultButton, MessageBoxModality modality, MessageBoxOtherOptions options);

    };
}

#endif //!KONGKONG_WIN32_MESSAGEBOX_H
