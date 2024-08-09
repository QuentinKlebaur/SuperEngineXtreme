#include "Registry.hpp"
#include "PositionComponent.hpp"
#include "Chrono.hpp"
#include "FallSystem.hpp"
#include "SfmlGraphicModule.hpp"
#include "RenderSystem.hpp"
#include "DrawableComponent.hpp"
#include "Color.hpp"
#include "EventSystem.hpp"
#include "IEvent.hpp"
#include "ClickEvent.hpp"

#include <iostream>

int main(int , char **)
{
    sex::Registry registry;
    sex::Chrono chrono;
    sex::SfmlGraphicModule graphicModule;
    sex::Vector2<int> w{1080, 720};
    int64_t useconds = 0;
    unsigned int loop = 0;

    graphicModule.createWindow(w.x, w.y);
    registry.addSystem<sex::FallSystem>();
    registry.addSystem<sex::EventSystem>();
    registry.addSystem<sex::RenderSystem>(graphicModule.window());

    sex::EventSystem *eventSystem = registry.getSystem<sex::EventSystem>();

    eventSystem->addCallBack(sex::EventType::CLOSE_WINDOW, [&](sex::IEvent const &) -> bool{
        graphicModule.window()->close();
        return false;
    });

    eventSystem->addCallBack(sex::EventType::CLICK, [&](sex::IEvent const &event) -> bool{
        sex::ClickEvent const *clickEvent = static_cast<sex::ClickEvent const *>(&event);

        sex::Entity entity = registry.createEntity();

        //std::cout << "ClickEvent: " << clickEvent->mousePosition.x << " | " << clickEvent->mousePosition.y << std::endl;
        registry.addComponent<sex::PositionComponent>(entity, clickEvent->mousePosition.x, clickEvent->mousePosition.y);
        registry.addComponent<sex::DrawableComponent>(entity, graphicModule.createRectangle(10, 10, sex::Color{std::rand() % 256, std::rand() % 256, std::rand() % 256}));
        return false;
    });
    chrono.reset();
    while (graphicModule.window()->isOpen()) {
        useconds = chrono.reset();
        registry.update(graphicModule, useconds);
    }
}