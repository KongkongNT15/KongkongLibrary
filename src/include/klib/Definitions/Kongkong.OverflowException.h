#ifndef KONGKONG_OVERFLOWEXCEPTION_H
#define KONGKONG_OVERFLOWEXCEPTION_H

namespace KONGKONG_NAMESPACE
{
    /// @brief 算術オーバーフロー
    struct OverflowException : public Exception {
        using Exception::Exception;
    };

}

#endif //!KONGKONG_OVERFLOWEXCEPTION_H
