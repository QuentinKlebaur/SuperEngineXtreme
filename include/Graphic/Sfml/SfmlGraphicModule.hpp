#pragma once

#include "IGraphicModule.hpp"

#include <memory>

namespace sex {
    class SfmlGraphicModule : public IGraphicModule {
        public:
            SfmlGraphicModule();
            SfmlGraphicModule(SfmlGraphicModule const &) = delete;
            SfmlGraphicModule(SfmlGraphicModule &&) = delete;
            ~SfmlGraphicModule() = default;

            Texture loadTexture(std::string const &texturePath) override;
            void removeTexture(Texture texture) override;
            void createWindow(unsigned int width, unsigned int height) override;
            IWindow *window() override;

        private:
            std::unique_ptr<IWindow> _window;
    };
}