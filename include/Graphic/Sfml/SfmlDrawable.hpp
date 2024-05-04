#pragma once

#include "IDrawable.hpp"

#include <SFML/Graphics/Drawable.hpp>

#include <memory>

namespace sex {
    class SfmlDrawable : public IDrawable {
        public:
            SfmlDrawable();
            SfmlDrawable(sf::Drawable *drawable);
            SfmlDrawable(SfmlDrawable const &) = delete;
            SfmlDrawable(SfmlDrawable &&) = delete;
            ~SfmlDrawable() = default;

            void draw(IWindow *window) const override;
            void setPosition(Vector2<double> const &position) override;

        private:
            std::unique_ptr<sf::Drawable> _drawableObject;
    };
}