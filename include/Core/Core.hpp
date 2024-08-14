#pragma once

#include "IGraphicModule.hpp"
#include "IGame.hpp"

#include <memory>

namespace sex {
    class Core
    {
        public:
            Core();
            Core(Core const &) = delete;
            Core(Core const &&) = delete;
            ~Core() = default;

            void run();

        private:
            std::unique_ptr<IGame> _game;
            std::unique_ptr<IGraphicModule> _graphicModule;
    };
}