//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Graphics
{
    _winComInitializer::s_initializer::s_initializer()
    {
        ::CoInitializeEx(nullptr, ::tagCOINIT::COINIT_APARTMENTTHREADED);
    }

    _winComInitializer::s_initializer::~s_initializer()
    {
        Imaging::BitmapImage::s_destory();
        ::CoUninitialize();
    }
}