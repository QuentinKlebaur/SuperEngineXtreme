#include "DemoMainScene.hpp"

#include "IEvent.hpp"
#include "IGraphicModule.hpp"
#include "IWindow.hpp"
#include "Color.hpp"
#include "ClickEvent.hpp"
#include "KeyPressedEvent.hpp"
#include "KeyReleasedEvent.hpp"
#include "PositionComponent.hpp"
#include "DrawableComponent.hpp"
#include "VelocityComponent.hpp"
#include "PlayerComponent.hpp"
#include "KillOutWindowComponent.hpp"
#include "VelocitySystem.hpp"
#include "RenderSystem.hpp"
#include "EventSystem.hpp"
#include "KillOutWindowSystem.hpp"

#include <cstdlib>

sex::DemoMainScene::DemoMainScene(IGraphicModule &graphic)
{
    /*
    _registry.addSystem<sex::VelocitySystem>();
    sex::EventSystem &eventSystem = _registry.addSystem<sex::EventSystem>();
    _registry.addSystem<sex::RenderSystem>();

    eventSystem.addCallBack(sex::EventType::CLOSE_WINDOW, [&](sex::IEvent const &) -> bool{
        graphic.window().close();
        return false;
    });

    eventSystem.addCallBack(sex::EventType::CLICK, [&](sex::IEvent const &event) -> bool{
        sex::ClickEvent const &clickEvent = static_cast<sex::ClickEvent const &>(event);

        sex::Entity entity = _registry.createEntity();

        _registry.addComponent<sex::PositionComponent>(entity, clickEvent.mousePosition.x, clickEvent.mousePosition.y);
        _registry.addComponent<sex::VelocityComponent>(entity, 10, 0);
        _registry.addComponent<sex::DrawableComponent>(entity, graphic.createRectangle(10, 10, sex::Color{std::rand() % 256, std::rand() % 256, std::rand() % 256}));
        return false;
    });

    sex::Entity playerEntity = _registry.createEntity();
    _registry.addComponent<sex::PlayerComponent>(playerEntity);
    _registry.addComponent<sex::PositionComponent>(playerEntity, 100, 100);
    _registry.addComponent<sex::DrawableComponent>(playerEntity, graphic.createRectangle(30, 30, sex::Color{std::rand() % 256, std::rand() % 256, std::rand() % 256}));
    _registry.addComponent<sex::VelocityComponent>(playerEntity);


    eventSystem.addCallBack(sex::EventType::KEY_PRESSED, [&](sex::IEvent const &event) -> bool{
        _registry.applyOnComponents<PlayerComponent>([&](Entity player, PlayerComponent&) {
            double maxVelocity = 100;
            sex::KeyPressedEvent const &clickEvent = static_cast<sex::KeyPressedEvent const &>(event);
            sex::VelocityComponent &velocity = _registry.getComponent<sex::VelocityComponent>(player);

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
            }
        );
    });

    eventSystem.addCallBack(sex::EventType::KEY_RELEASED, [&](sex::IEvent const &event) -> bool{
        _registry.applyOnComponents<PlayerComponent>([&](Entity player, PlayerComponent&) {
            double maxVelocity = 100;
            sex::KeyReleasedEvent const &clickEvent = static_cast<sex::KeyReleasedEvent const &>(event);
            sex::VelocityComponent &velocity = _registry.getComponent<sex::VelocityComponent>(player);

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
    });
    */

    _registry.addSystem<sex::VelocitySystem>();
    sex::EventSystem &eventSystem = _registry.addSystem<sex::EventSystem>();
    _registry.addSystem<sex::RenderSystem>();
    _registry.addSystem<sex::KillOutWindowSystem>();


    eventSystem.addCallBack(sex::EventType::CLOSE_WINDOW, [&](sex::IEvent const &) -> bool{
        graphic.window().close();
        return false;
    });

    for (int i = 0; i != 10000; ++i) {
        Entity entity = _registry.createEntity();

        _registry.addComponent<KillOutWindowComponent>(entity);
        _registry.addComponent<DrawableComponent>(entity, graphic.createRectangle(10, 10, {std::rand(), std::rand(), std::rand()}));
        _registry.addComponent<VelocityComponent>(entity, Vector2<double>{0, -100});
        _registry.addComponent<PositionComponent>(entity, Vector2<double>{std::rand() % graphic.window().size().x, std::rand() % graphic.window().size().y});
    }

    sex::Entity playerEntity = _registry.createEntity();
    _registry.addComponent<sex::PlayerComponent>(playerEntity);
    _registry.addComponent<sex::PositionComponent>(playerEntity, 100, 100);
    _registry.addComponent<sex::DrawableComponent>(playerEntity, graphic.createRectangle(30, 30, sex::Color{std::rand() % 256, std::rand() % 256, std::rand() % 256}));
    _registry.addComponent<sex::VelocityComponent>(playerEntity);


    eventSystem.addCallBack(sex::EventType::KEY_PRESSED, [&](sex::IEvent const &event) -> bool{
        _registry.applyOnComponents<PlayerComponent>([&](Entity player, PlayerComponent&) {
            double maxVelocity = 100;
            sex::KeyPressedEvent const &clickEvent = static_cast<sex::KeyPressedEvent const &>(event);
            sex::VelocityComponent &velocity = _registry.getComponent<sex::VelocityComponent>(player);

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
            }
        );
    });

    eventSystem.addCallBack(sex::EventType::KEY_RELEASED, [&](sex::IEvent const &event) -> bool{
        _registry.applyOnComponents<PlayerComponent>([&](Entity player, PlayerComponent&) {
            double maxVelocity = 100;
            sex::KeyReleasedEvent const &clickEvent = static_cast<sex::KeyReleasedEvent const &>(event);
            sex::VelocityComponent &velocity = _registry.getComponent<sex::VelocityComponent>(player);

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
    });
}

void sex::DemoMainScene::event(std::vector<std::unique_ptr<IEvent>> const &events)
{
    _registry.getSystem<EventSystem>().triggerEvents(events);
}