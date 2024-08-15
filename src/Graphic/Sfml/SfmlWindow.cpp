#include "SfmlWindow.hpp"
#include "IDrawable.hpp"
#include "Color.hpp"
#include "CloseWindowEvent.hpp"
#include "ClickEvent.hpp"
#include "KeyPressedEvent.hpp"
#include "KeyReleasedEvent.hpp"

#include <SFML/Window/Mouse.hpp>

#include <exception>

sex::SfmlWindow::SfmlWindow(unsigned int width, unsigned int height) : sf::RenderWindow{{width, height}, "window"}
{
}


void sex::SfmlWindow::close()
{
    sf::RenderWindow::close();
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
    drawObject.draw(*this);
}

void sex::SfmlWindow::clear(Color const &color)
{
    sf::RenderWindow::clear({color.red, color.green, color.blue, color.alpha});
}

void sex::SfmlWindow::display()
{
    sf::RenderWindow::display();
}

void sex::SfmlWindow::fillEvents(std::vector<std::unique_ptr<IEvent>> &events)
{
    sf::Event event;

    while (pollEvent(event)) {
        try {
            events.push_back(fromSfmlEvent(event));
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

        case sf::Event::MouseButtonPressed:
            return std::make_unique<ClickEvent>(getMousePosition());
            break;

        case sf::Event::KeyPressed:
            return std::make_unique<KeyPressedEvent>(fromSfmlKeyCode(event.key.code));
            break;

        case sf::Event::KeyReleased:
            return std::make_unique<KeyReleasedEvent>(fromSfmlKeyCode(event.key.code));
            break;

        default:
            throw std::exception();
    }
}

sex::KeyCode sex::SfmlWindow::fromSfmlKeyCode(sf::Keyboard::Key key) const
{
    return static_cast<sex::KeyCode>(key);
}