#include "Registry.hpp"
#include "PositionComponent.hpp"
#include "Chrono.hpp"
#include "FallSystem.hpp"
#include "SfmlGraphicModule.hpp"
#include "RenderSystem.hpp"
#include "DrawableComponent.hpp"
#include "Color.hpp"

#include <iostream>

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
    if (registry.getSystem<sex::FallSystem>() == nullptr)
        return 1;
    else
        std::cout << "FALLSYSTEM EXISTS" << std::endl;
    if (registry.getSystem<sex::Registry>() == nullptr)
        return 1;
    for (unsigned int i = 0; i < 40000; ++i) {
        sex::Entity entity = registry.createEntity();

        registry.addComponent<sex::PositionComponent>(entity, 0 + std::rand() % w.x, w.y + std::rand() % w.y);
        registry.addComponent<sex::DrawableComponent>(entity, graphicModule.createRectangle(10, 10, sex::Color{std::rand() % 256, std::rand() % 256, std::rand() % 256}));
    }
    chrono.reset();
    while (registry.getEntities().size()) {
        useconds = chrono.reset();
        registry.update(useconds);
    }
}