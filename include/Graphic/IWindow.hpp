#pragma once

#include "Vector2.hpp"

#include <vector>
#include <memory>

namespace sex {
    class IDrawable;
    class IEvent;
    class Color;

    class IWindow {
        public:
            virtual ~IWindow() {};

            virtual void close() = 0;
            virtual bool isOpen() const = 0;
            virtual void fillEvents(std::vector<std::unique_ptr<IEvent>> &events) = 0;
            virtual Vector2<short> getMousePosition() const = 0;
            virtual Vector2<short> size() const = 0;
            virtual void draw(IDrawable const &drawObject) = 0;
            virtual void clear(Color const &color) = 0;
            virtual void display() = 0;
    };
}