#include "SfmlGraphicModule.hpp"
#include "SfmlWindow.hpp"
#include "Texture.hpp"
#include "IWindow.hpp"
#include "Color.hpp"
#include "SfmlDrawable.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Color.hpp>


sex::SfmlGraphicModule::SfmlGraphicModule()
{

}

sex::IDrawable *sex::SfmlGraphicModule::createRectangle(int width, int height, Color const &color)
{
    sf::RectangleShape *rect = new sf::RectangleShape{{0, 0}};
    IDrawable *drawable = new SfmlDrawable{rect};

    rect->setFillColor(sf::Color{color.red, color.green, color.blue, color.alpha});
    rect->setSize({width, height});
    return drawable;
}

sex::Texture sex::SfmlGraphicModule::loadTexture(std::string const &texturePath)
{
    return 0;
}

void sex::SfmlGraphicModule::removeTexture(sex::Texture texture)
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