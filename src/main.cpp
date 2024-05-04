#include "Registry.hpp"
#include "PositionComponent.hpp"
#include "Chrono.hpp"
#include "FallSystem.hpp"
#include "SfmlGraphicModule.hpp"
#include "RenderSystem.hpp"
#include "DrawableComponent.hpp"
#include "Color.hpp"

#include <iostream>


#include <SFML/Graphics/Sprite.hpp>

int main(int ac, char **argv)
{
    sex::Registry registry;
    sex::Chrono chrono;
    sex::SfmlGraphicModule graphicModule;
    sex::Vector2<int> w{1080, 720};
    int64_t useconds = 0;
    unsigned int loop = 0;

    graphicModule.createWindow(w.x, w.y);
    registry.addSystem<sex::FallSystem>();
    registry.addSystem<sex::RenderSystem>(graphicModule.window());
    for (unsigned int i = 0; i < 10000; ++i) {
        sex::Entity entity = registry.createEntity();

        registry.addComponent<sex::PositionComponent>(entity, 0 + std::rand() % w.x, w.y + std::rand() % w.y + 500);
        registry.addComponent<sex::DrawableComponent>(entity, graphicModule.createRectangle(10, 10, sex::Color{std::rand() % 256, std::rand() % 256, std::rand() % 256}));
    }
    chrono.reset();
    while (registry.getEntities().size()) {
        useconds = chrono.reset();
        registry.update(useconds);
//        std::cout << "---- Loop number " << loop++ << " ----" << std::endl;
//        std::cout << "Elapsed time: " << useconds << std::endl;
//        std::cout << "Entities remaining: " << registry.getEntities().size() << std::endl;
    }
    /*sf::Sprite *sprite = new sf::Sprite();
    sf::Drawable *drawable = sprite;
    sf::Transformable *transformable = sprite;
    sf::Transformable *transformable2 = dynamic_cast<sf::Transformable*>(drawable);

    std::cout << "Sprite Adrr [" << sprite << "]" << std::endl;
    std::cout << "Drawable Adrr [" << drawable << "]" << std::endl;
    std::cout << "Transformable Adrr [" << transformable << "]" << std::endl;
    std::cout << "Drawable + size Adrr [" << drawable + sizeof(sf::Drawable) << "]" << std::endl;
    std::cout << "Transformable2 Adrr [" << transformable2 << "]" << std::endl;*/
}