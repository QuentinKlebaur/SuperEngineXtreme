#pragma once

#include "IGraphicModule.hpp"
#include "IWindow.hpp"

#include <memory>

namespace sex {
    class SfmlGraphicModule : public IGraphicModule {
        public:
            SfmlGraphicModule();
            SfmlGraphicModule(SfmlGraphicModule const &) = delete;
            SfmlGraphicModule(SfmlGraphicModule &&) = delete;
            ~SfmlGraphicModule() = default;

            IDrawable *createRectangle(unsigned int width, unsigned int height, Color const &color) override;
            IWindow *window() override;
            Texture loadTexture(std::string const &texturePath) override;
            void removeTexture(Texture texture) override;
            void createWindow(unsigned int width, unsigned int height) override;

        private:
            std::unique_ptr<IWindow> _window;
    };
}