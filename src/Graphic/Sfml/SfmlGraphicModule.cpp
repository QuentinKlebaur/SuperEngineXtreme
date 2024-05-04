#include "SfmlGraphicModule.hpp"
#include "SfmlWindow.hpp"


sex::SfmlGraphicModule::SfmlGraphicModule()
{

}

sex::Texture sex::SfmlGraphicModule::loadTexture(std::string const &texturePath)
{
    return 0;
}

void sex::SfmlGraphicModule::removeTexture(Texture texture)
{

}

void sex::SfmlGraphicModule::createWindow(unsigned int width, unsigned int height)
{
    _window = std::make_unique<SfmlWindow>(width, height);
}

sex::IWindow *sex::SfmlGraphicModule::window()
{
    return _window.get();
}