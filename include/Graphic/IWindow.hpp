#pragma once

#include "Vector2.hpp"

#include <queue>
#include <memory>

namespace sex {
    class IDrawable;
    class IEvent;
    class Color;

    class IWindow {
        public:
            virtual ~IWindow() {};

            virtual bool isOpen() const = 0;
            virtual void fillEvents(std::queue<std::unique_ptr<IEvent>> &events) = 0;
            virtual Vector2<short> getMousePosition() const = 0;
            virtual void draw(IDrawable const &drawObject) = 0;
            virtual void clear(Color const &color) = 0;
            virtual void display() = 0;
    };
}