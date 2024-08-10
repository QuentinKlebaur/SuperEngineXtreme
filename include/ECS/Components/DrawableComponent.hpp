#pragma once

#include "IComponent.hpp"
#include "IDrawable.hpp"

#include <memory>

namespace sex {
    class DrawableComponent : public IComponent {
        public:
            DrawableComponent();
            DrawableComponent(IDrawable *);
            DrawableComponent(DrawableComponent const &) = delete;
            DrawableComponent(DrawableComponent &&) = delete;
            ~DrawableComponent() = default;

            void set(IDrawable *);
            IDrawable &get();
        private:
            std::unique_ptr<IDrawable> _drawable;
    };
}