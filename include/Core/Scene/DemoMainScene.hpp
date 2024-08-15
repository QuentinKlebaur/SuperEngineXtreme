#pragma once

#include "SceneBase.hpp"

namespace sex {
    class DemoMainScene : public SceneBase {
        public:
            DemoMainScene(IGraphicModule &);
            DemoMainScene(DemoMainScene const &) = delete;
            DemoMainScene(DemoMainScene const &&) = delete;
            ~DemoMainScene() = default;

            void event(std::vector<std::unique_ptr<IEvent>> const &events) override;
    };
}
