#pragma once

#include "SceneBase.hpp"

namespace sex {
    class DemoMainScene : public SceneBase {
        public:
            DemoMainScene(IGraphicModule &);
            DemoMainScene(DemoMainScene const &) = delete;
            DemoMainScene(DemoMainScene const &&) = delete;
            ~DemoMainScene() = default;

            void update(IGraphicModule &graphic, int64_t useconds);
    };
}
