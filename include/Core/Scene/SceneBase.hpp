#pragma once

#include "IScene.hpp"
#include "Registry.hpp"

namespace sex {
    class SceneBase : public IScene
    {
        public:
            SceneBase() = default;
            SceneBase(SceneBase const &) = delete;
            SceneBase(SceneBase const &&) = delete;
            ~SceneBase() = default;

            Registry &getRegistry() override;
            void update(IGraphicModule &graphic, int64_t useconds) override;

        protected:
            virtual void updateScene(IGraphicModule &graphic, int64_t useconds);
            Registry _registry;
    };
}