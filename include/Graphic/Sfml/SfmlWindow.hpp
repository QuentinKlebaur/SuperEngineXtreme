#pragma once

#include "IWindow.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

namespace sex {
    class SfmlWindow : public IWindow, public sf::RenderWindow
    {
        public:
            SfmlWindow(unsigned int width, unsigned int height);
            SfmlWindow(SfmlWindow const &) = delete;
            SfmlWindow(SfmlWindow &&) = delete;
            ~SfmlWindow() = default;

            void draw(IDrawable const &drawObject) override;
            void clear(Color const &color) override;
            void display() override;
    };
}