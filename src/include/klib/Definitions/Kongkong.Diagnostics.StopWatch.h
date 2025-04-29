#ifndef KONGKONG_DIAGNOSTICS_STOPWATCH_H
#define KONGKONG_DIAGNOSTICS_STOPWATCH_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include <ctime>

namespace KONGKONG_NAMESPACE::Diagnostics
{
    struct StopWatch final : public ValueType {

        static constexpr clock_t Frequency() noexcept { return CLOCKS_PER_SEC; }

        constexpr StopWatch() noexcept : _startTime(0), _isRunning(false), _isStarted(false), _current(0) {}

        double ElapsedSeconds() const noexcept;
        long ElapsedMiliSeconds() const noexcept;
        clock_t ElapsedTicks() const noexcept;

        constexpr bool IsRunning() const noexcept { return _isRunning; }
        
        //計測を中止して経過時間をゼロにする
        void Reset() noexcept;
        //経過時間をゼロにしてから計測を開始する
        void Restart() noexcept;
        //計測を開始、再開する
        void Start() noexcept;
        //計測を中止する
        void Stop() noexcept;

        String ToString() const;

        private:

        //開始したときの時刻
        clock_t _startTime;
        //現在の
        clock_t _current;
        bool _isRunning;
        bool _isStarted;
    };
}

#endif //!KONGKONG_DIAGNOSTICS_STOPWATCH_H
