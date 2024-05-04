#include "SfmlWindow.hpp"

sex::SfmlWindow::SfmlWindow(unsigned int width, unsigned int height) : sf::RenderWindow{{width, height}, "window"}
{
}

void sex::SfmlWindow::draw(IDrawable const &drawObject)
{

}