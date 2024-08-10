#include "Registry.hpp"
#include "PositionComponent.hpp"
#include "Chrono.hpp"
#include "VelocitySystem.hpp"
#include "SfmlGraphicModule.hpp"
#include "RenderSystem.hpp"
#include "DrawableComponent.hpp"
#include "Color.hpp"
#include "EventSystem.hpp"
#include "IEvent.hpp"
#include "ClickEvent.hpp"
#include "VelocityComponent.hpp"
#include "KeyPressedEvent.hpp"
#include "KeyReleasedEvent.hpp"

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
    registry.addSystem<sex::VelocitySystem>();
    sex::EventSystem &eventSystem = registry.addSystem<sex::EventSystem>();
    registry.addSystem<sex::RenderSystem>(&graphicModule.window());

    eventSystem.addCallBack(sex::EventType::CLOSE_WINDOW, [&](sex::IEvent const &) -> bool{
        graphicModule.window().close();
        return false;
    });

    eventSystem.addCallBack(sex::EventType::CLICK, [&](sex::IEvent const &event) -> bool{
        sex::ClickEvent const &clickEvent = static_cast<sex::ClickEvent const &>(event);

        sex::Entity entity = registry.createEntity();

        registry.addComponent<sex::PositionComponent>(entity, clickEvent.mousePosition.x, clickEvent.mousePosition.y);
        registry.addComponent<sex::VelocityComponent>(entity, 10, 0);
        registry.addComponent<sex::DrawableComponent>(entity, graphicModule.createRectangle(10, 10, sex::Color{std::rand() % 256, std::rand() % 256, std::rand() % 256}));
        return false;
    });

    sex::Entity player = registry.createEntity();
    registry.addComponent<sex::PositionComponent>(player, w.x / 2, w.y / 2);
    registry.addComponent<sex::DrawableComponent>(player, graphicModule.createRectangle(30, 30, sex::Color{std::rand() % 256, std::rand() % 256, std::rand() % 256}));
    registry.addComponent<sex::VelocityComponent>(player);

    double maxVelocity = 100;

    eventSystem.addCallBack(sex::EventType::KEY_PRESSED, [&](sex::IEvent const &event) -> bool{
        sex::KeyPressedEvent const &clickEvent = static_cast<sex::KeyPressedEvent const &>(event);
        sex::VelocityComponent &velocity = registry.getComponent<sex::VelocityComponent>(player);

        switch (clickEvent.keyCode)
        {
        case sex::KeyCode::S:
            velocity.y += ((velocity.y + maxVelocity) > maxVelocity) ? 0 : maxVelocity;
            break;
        case sex::KeyCode::Q:
            velocity.x += ((velocity.x - maxVelocity) < -maxVelocity) ? 0 : -maxVelocity;
            break;
        case sex::KeyCode::Z:
            velocity.y += ((velocity.y - maxVelocity) < -maxVelocity) ? 0 : -maxVelocity;
            break;
        case sex::KeyCode::D:
            velocity.x += ((velocity.x + maxVelocity) > maxVelocity) ? 0 : maxVelocity;
            break;
        }
        return false;
    });

    eventSystem.addCallBack(sex::EventType::KEY_RELEASED, [&](sex::IEvent const &event) -> bool{
        sex::KeyReleasedEvent const &clickEvent = static_cast<sex::KeyReleasedEvent const &>(event);
        sex::VelocityComponent &velocity = registry.getComponent<sex::VelocityComponent>(player);

            switch (clickEvent.keyCode)
            {
            case sex::KeyCode::Z:
                velocity.y += ((velocity.y + maxVelocity) > maxVelocity) ? 0 : maxVelocity;
                break;
            case sex::KeyCode::D:
                velocity.x += ((velocity.x - maxVelocity) < -maxVelocity) ? 0 : -maxVelocity;
                break;
            case sex::KeyCode::S:
                velocity.y += ((velocity.y - maxVelocity) < -maxVelocity) ? 0 : -maxVelocity;
                break;
            case sex::KeyCode::Q:
                velocity.x += ((velocity.x + maxVelocity) > maxVelocity) ? 0 : maxVelocity;
                break;
            }
        return false;
    });


    chrono.reset();
    while (graphicModule.window().isOpen()) {
        useconds = chrono.reset();
        registry.update(graphicModule, useconds);
    }
}