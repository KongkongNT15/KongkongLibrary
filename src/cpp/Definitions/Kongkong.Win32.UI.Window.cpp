//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::UI::IMPLEMENTATION
{
    uint16_t Control::_idCount;

    int Window::_nCmdShow;
    bool Window::_isSetedCmdShow;
    Initializer Window::_init = Initializer(Window::_initialize);
    std::map<::HWND, Window*> Window::_map;

    void Window::MessageLoop()
    {
        MSG msg{};
        while (GetMessage(&msg, nullptr, 0, 0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        
    }

    void Window::SetCmdShow(int nCmdShow) noexcept
    {
        if (_isSetedCmdShow) [[unlikely]] return;
        _nCmdShow = nCmdShow;
        _isSetedCmdShow = true;
    }

    ::LRESULT CALLBACK Window::_procedure(::HWND hwnd, ::UINT uMsg, ::WPARAM wParam, ::LPARAM lParam)
    {
        Window* window = _map[hwnd];

        if (window == nullptr) [[unlikely]] return DefWindowProc(hwnd, uMsg, wParam, lParam);

        Window::ProjType rWindow = Object::ProjType::Make<Window::ProjType, Window>(window);

        switch (uMsg) {

            case WM_ACTIVATE:
            {
                window->_activated.Call(rWindow, WindowActivatedEventArgs(LOWORD(wParam), (bool)HIWORD(wParam)));
                break;
            }
            case WM_CLOSE:
            {
                WindowClosingEventArgs args;
                window->_closing.Call(rWindow, args);

                if (args.Cancel()) [[likely]] ::DestroyWindow(hwnd);
                break;
            }
            case WM_DESTROY:
            {
                _map.erase(hwnd);

                window->_destroyed.Call(rWindow, PaintRequestedEventArgs());

                if (_map.size() == 0) ::PostQuitMessage(0);
                break;
            }
            case WM_DPICHANGED:
            {
                window->_dpiChanged.Call(rWindow, DpiChangedEventArgs(::GetDpiForWindow(hwnd)));
                break;
            }
            case WM_CREATE:
            {
                WindowCreatingEventArgs args;
                window->_creating.Call(rWindow, args);
                
                return args.Create() ? 0 : -1;
            }
            case WM_COMMAND:
            {
                ::WORD idc = LOWORD(wParam);
                break;
            }
            case WM_SETTINGCHANGE:
            {

                break;
            }
            case WM_SIZE:
            {
                window->_sizeChanged.Call(rWindow, SizeChangedEventArgs(window->ActualWidth(), window->ActualHeight()));
                switch (wParam) {
                    case SIZE_RESTORED: /*通常*/ break;
                    case SIZE_MINIMIZED: /*最小化*/ break;
                    case SIZE_MAXIMIZED: /*最大化*/ break;
                    case SIZE_MAXSHOW: /*ほかのウィンドウが最大化状態から移行*/ break;
                    case SIZE_MAXHIDE: /*ほかのウィンドウが最大化*/ break;
                }

                break;
            }
                

            case WM_PAINT:
            {
                PaintRequestedEventArgs args;
                ::HDC hdc = ::BeginPaint(hwnd, &args._paintStruct);

                ::FillRect(hdc, &args._paintStruct.rcPaint, (::HBRUSH)(COLOR_3DFACE + 1));

                window->_paintRequested.Call(rWindow, args);

                ::EndPaint(hwnd, &args._paintStruct);

                break;
            }

            default:
                return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }

        return 0;

    }

    void Window::_initialize()
    {
        //Windowクラスを登録
        constexpr wchar_t CLASS_NAME[] = L"KONGKONG_NAMESPACE::Win32::UI::Window";

        WNDCLASSEX wc = { };

        wc.cbSize = sizeof(WNDCLASSEX);
        wc.lpfnWndProc = _procedure;
        wc.hInstance = GetModuleHandle(nullptr);
        wc.lpszClassName = CLASS_NAME;

        RegisterClassEx(&wc);
    }

    Window::Window() :
        _activated(),
        _closing(),
        _creating(),
        _destroyed(),
        _titleBar(nullptr)
    {
        //Windowを作成
        _handle = ::CreateWindowExW(
            0,                              //Windowスタイルの追加オプション
            L"KONGKONG_NAMESPACE::Win32::UI::Window",                     //Windowのクラス
            L"Desktop Window",    //タイトルバーの表示名
            WS_OVERLAPPEDWINDOW,            //Windowのスタイル

            //Windowサイスと位置
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

            nullptr,       //親Window
            nullptr,       //メニュー
            ::GetModuleHandleW(nullptr),  //インスタンスハンドル
            nullptr        //追加のアプリデータ
        );

        if (_handle == nullptr) [[unlikely]] throw HResultException();

        _titleBar = TitleBar::ProjType(_handle);

        _map[_handle] = this;
    }

    Window::~Window()
    {
        _map.erase(_handle);
    }

    void Window::Activate()
    {
        if (!_isSetedCmdShow) [[unlikely]] throw InvalidOperationException(u"Windowを表示する前にWindow::SetCmdShow()を呼び出してnCmdShowを設定してください");

        ::ShowWindow(_handle, _nCmdShow);
        ::UpdateWindow(_handle);
    }
    
    String Window::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Win32::UI::Window");
    }
}

namespace KONGKONG_NAMESPACE::Win32::UI
{
    
}
