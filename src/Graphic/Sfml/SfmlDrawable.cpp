#include "SfmlDrawable.hpp"
#include "SfmlWindow.hpp"
#include "Vector2.hpp"

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <iostream>

sex::SfmlDrawable::SfmlDrawable()
{
}

sex::SfmlDrawable::SfmlDrawable(sf::Drawable *drawable) : _drawableObject(drawable)
{
}

void sex::SfmlDrawable::draw(IWindow *window) const
{
    SfmlWindow *sfmlWindow = dynamic_cast<SfmlWindow*>(window);

    if (sfmlWindow) {
        sf::RenderWindow *renderWindow = sfmlWindow;

        renderWindow->draw(*_drawableObject.get());
    }
}


void sex::SfmlDrawable::setPosition(Vector2<double> const &position)
{
    sf::Transformable *transformable = dynamic_cast<sf::Transformable *>(_drawableObject.get());

    if (transformable) {
        transformable->setPosition({position.x, position.y});
    }
}