#pragma once

#include "Texture.hpp"
#include "IWindow.hpp"

#include <string>

namespace sex {
    class IGraphicModule {
        public:
            virtual ~IGraphicModule() {};

            virtual Texture loadTexture(std::string const &texturePath) = 0;
            virtual void removeTexture(Texture texture) = 0;
            virtual void createWindow(unsigned int height, unsigned int width) = 0;
            virtual IWindow *window() = 0;
    };
}