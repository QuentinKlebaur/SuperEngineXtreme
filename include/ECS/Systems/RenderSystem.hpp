#pragma once

#include "ISystem.hpp"

namespace sex {
    class IWindow;

    class RenderSystem : public ISystem
    {
        public:
            RenderSystem(IWindow *window=nullptr);
            RenderSystem(RenderSystem const &) = delete;
            RenderSystem(RenderSystem const &&) = delete;
            ~RenderSystem() = default;

            void beforeUpdate(Registry &registry, int64_t useconds) override;
            void update(Registry &registry, int64_t useconds) override;
            void afterUpdate(Registry &registry, int64_t useconds) override;

        private:
            IWindow *_window;
    };
}