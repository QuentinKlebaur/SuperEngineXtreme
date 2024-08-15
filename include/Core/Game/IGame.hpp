#pragma once

#include "IScene.hpp"
#include "IGraphicModule.hpp"
#include "IEvent.hpp"

#include <memory>
#include <cstdint>
#include <vector>

namespace sex {
    class IGame
    {
        public:
            ~IGame() {};

            virtual void update(IGraphicModule &graphic, uint64_t elapsedTime) = 0;
            virtual void event(std::vector<std::unique_ptr<IEvent>> const &events) = 0;
            virtual bool isRunning() = 0;
    };
}