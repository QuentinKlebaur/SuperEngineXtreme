#pragma once

namespace sex {
    class IDrawable;
    class Color;

    class IWindow {
        public:
            virtual ~IWindow() {};

            virtual void draw(IDrawable const &drawObject) = 0;
            virtual void clear(Color const &color) = 0;
            virtual void display() = 0;
    };
}