#pragma once

#include "GameBase.hpp"

namespace sex {
    class DemoGame : public GameBase {
        public:
            DemoGame(IGraphicModule &);
            DemoGame(DemoGame const &) = delete;
            DemoGame(DemoGame const &&) = delete;
            ~DemoGame() = default;
    };
}