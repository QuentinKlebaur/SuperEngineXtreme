#pragma once

namespace sex {
    class IWindow;

    class IDrawable
    {
    public:
        virtual ~IDrawable() {}

        virtual void draw(IWindow *window) const = 0;
    };
}