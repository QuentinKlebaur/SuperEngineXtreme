#include "SfmlWindow.hpp"
#include "IDrawable.hpp"
#include "Color.hpp"

sex::SfmlWindow::SfmlWindow(unsigned int width, unsigned int height) : sf::RenderWindow{{width, height}, "window"}
{
}

void sex::SfmlWindow::draw(IDrawable const &drawObject)
{
    drawObject.draw(this);
}

void sex::SfmlWindow::clear(Color const &color)
{
    sf::RenderWindow::clear({color.red, color.green, color.blue, color.alpha});
}

void sex::SfmlWindow::display()
{
    sf::RenderWindow::display();
}
