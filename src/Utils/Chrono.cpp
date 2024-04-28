#include "Chrono.hpp"

namespace sex {
    Chrono::Chrono() : _timer(std::chrono::high_resolution_clock::now())
    {
    }

    int Chrono::reset()
    {
        std::chrono::_V2::system_clock::time_point now = std::chrono::high_resolution_clock::now();
        int elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(now - _timer).count();

        _timer = now;
        return elapsedTime;
    }

    int Chrono::getElapsedTime()
    {
        std::chrono::_V2::system_clock::time_point now = std::chrono::high_resolution_clock::now();

        return std::chrono::duration_cast<std::chrono::microseconds>(now - _timer).count();
    }
}