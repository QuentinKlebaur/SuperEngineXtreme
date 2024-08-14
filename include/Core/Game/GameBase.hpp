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
            GameBase(IGraphicModule &);
            GameBase(GameBase const &) = delete;
            GameBase(GameBase const &&) = delete;
            ~GameBase() = default;

            void run() override;

        protected:
            Chrono _chrono;
            IGraphicModule &_graphicModule;
            std::vector<std::unique_ptr<IScene>> _scenes;
            bool _running = true;
    };
}