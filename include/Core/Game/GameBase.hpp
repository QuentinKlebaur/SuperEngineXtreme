#pragma once

#include "IGame.hpp"
#include "IScene.hpp"
#include "Chrono.hpp"
#include "IGraphicModule.hpp"

#include <vector>
#include <memory>

namespace sex {
    class GameBase : public IGame
    {
        public:
            GameBase() = default;
            GameBase(GameBase const &) = delete;
            GameBase(GameBase const &&) = delete;
            ~GameBase() = default;

            void update(IGraphicModule &graphic, uint64_t elapsedTime) override;
            void event(std::vector<std::unique_ptr<IEvent>> const &events);
            bool isRunning() override;

        protected:
            virtual void gameUpdate(IGraphicModule &graphic, uint64_t elapsedTime);
            virtual void gameEvent(std::vector<std::unique_ptr<IEvent>> const &events);

            std::vector<std::unique_ptr<IScene>> _scenes;
            bool _isRunning = true;
    };
}