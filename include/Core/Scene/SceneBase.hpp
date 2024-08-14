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

        protected:
            Registry _registry;
    };
}