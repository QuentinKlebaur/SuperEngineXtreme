#include "SfmlWindow.hpp"
#include "IDrawable.hpp"
#include "Color.hpp"
#include "CloseWindowEvent.hpp"
#include "ClickEvent.hpp"

#include <SFML/Window/Mouse.hpp>

#include <exception>

sex::SfmlWindow::SfmlWindow(unsigned int width, unsigned int height) : sf::RenderWindow{{width, height}, "window"}
{
}

bool sex::SfmlWindow::isOpen() const
{
    return sf::RenderWindow::isOpen();
}

sex::Vector2<short> sex::SfmlWindow::getMousePosition() const
{
    sf::Vector2i pos = sf::Mouse::getPosition(*this);

    return {pos.x, pos.y};
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

void sex::SfmlWindow::fillEvents(std::queue<std::unique_ptr<IEvent>> &events)
{
    sf::Event event;

    while (pollEvent(event)) {
        try {
            events.push(fromSfmlEvent(event));
        } catch (std::exception) {

        }
    }
}

std::unique_ptr<sex::IEvent> sex::SfmlWindow::fromSfmlEvent(sf::Event const &event) const
{
    switch (event.type)
    {
        case sf::Event::Closed:
            return std::make_unique<CloseWindowEvent>();
            break;

        case sf::Event::KeyPressed:
            return std::make_unique<ClickEvent>(getMousePosition());
            break;

        default:
            throw std::exception();
    }
}