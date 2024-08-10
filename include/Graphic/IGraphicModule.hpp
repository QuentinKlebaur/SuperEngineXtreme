#pragma once

#include "Texture.hpp"

#include <string>

namespace sex {
    class IWindow;
    class IDrawable;
    class Color;

    class IGraphicModule {
        public:
            virtual ~IGraphicModule() {};

            virtual Texture loadTexture(std::string const &texturePath) = 0;
            virtual void removeTexture(Texture texture) = 0;
            virtual void createWindow(unsigned int height, unsigned int width) = 0;
            virtual IWindow &window() = 0;

            virtual IDrawable *createRectangle(unsigned int x, unsigned int y, Color const &color) = 0;
    };
}