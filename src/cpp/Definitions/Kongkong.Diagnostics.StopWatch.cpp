//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Diagnostics
{
    double StopWatch::ElapsedSeconds() const noexcept
    {
        return (double)ElapsedTicks() / Frequency();
    }

    long StopWatch::ElapsedMiliSeconds() const noexcept
    {
        return (long)(ElapsedTicks() * ((double)1000 / Frequency()));
    }

    clock_t StopWatch::ElapsedTicks() const noexcept
    {
        ::clock_t t = ::clock();
        if (IsRunning()) return t - _startTime;
        return _current - _startTime;
    }

    void StopWatch::Reset() noexcept
    {
        _startTime = 0;
        _current = 0;
        _isRunning = false;
        _isStarted = false;
    }

    void StopWatch::Restart() noexcept
    {
        Reset();
        Start();
    }

    void StopWatch::Start() noexcept
    {
        ::clock_t t = ::clock();
        if (_isRunning) [[unlikely]] return;
        if (_isStarted) {
            _startTime += t - _current;
        }
        else {
            _startTime = t;
            _isStarted = true;
        }
        
        _isRunning = true;
    }

    void StopWatch::Stop() noexcept
    {
        ::clock_t t = ::clock();

        if (!IsRunning()) return;

        _current = t;
        _isRunning = false;
    }

    String StopWatch::ToString() const
    {
        return String::ValueOf(ElapsedTicks());
    }

}
