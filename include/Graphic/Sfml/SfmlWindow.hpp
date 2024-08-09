#pragma once

#include "IWindow.hpp"
#include "IEvent.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace sex {
    class SfmlWindow : public IWindow, public sf::RenderWindow
    {
        public:
            SfmlWindow(unsigned int width, unsigned int height);
            SfmlWindow(SfmlWindow const &) = delete;
            SfmlWindow(SfmlWindow &&) = delete;
            ~SfmlWindow() = default;

            bool isOpen() const override;
            Vector2<short> getMousePosition() const override;
            void fillEvents(std::queue<std::unique_ptr<IEvent>> &events) override;
            void draw(IDrawable const &drawObject) override;
            void clear(Color const &color) override;
            void display() override;

        private:
            std::unique_ptr<IEvent> fromSfmlEvent(sf::Event const &) const;
    };
}