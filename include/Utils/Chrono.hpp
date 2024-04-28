#pragma once

#include <chrono>

namespace sex {
    class Chrono
    {
        public:
            Chrono();
            Chrono(Chrono const &) = delete;
            Chrono(Chrono const &&) = delete;
            ~Chrono() = default;

            int reset();
            int getElapsedTime();
        private:
            std::chrono::_V2::system_clock::time_point _timer;
    };

}