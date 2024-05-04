#pragma once

#include "IDrawable.hpp"

namespace sex {
    class IWindow {
        public:
            virtual ~IWindow() {};

            virtual void draw(IDrawable const &drawObject) = 0;
    };
}