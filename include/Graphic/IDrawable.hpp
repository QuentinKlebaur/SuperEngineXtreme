#pragma once

//#include "Vector2.hpp"

namespace sex {
    class IWindow;
    template<class T>
    class Vector2;

    class IDrawable
    {
    public:
        virtual ~IDrawable() {}

        virtual void draw(IWindow *window) const = 0;
        virtual void setPosition(Vector2<double> const &position) = 0;
    };
}