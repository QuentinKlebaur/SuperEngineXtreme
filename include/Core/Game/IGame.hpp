#pragma once

#include "IScene.hpp"

#include <memory>

namespace sex {
    class IGame
    {
        public:
            ~IGame() {};

            virtual void run() = 0;
    };
}