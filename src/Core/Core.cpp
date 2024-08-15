#include "Core.hpp"
#include "DemoGame.hpp"
#include "SfmlGraphicModule.hpp"
#include "IEvent.hpp"

#include <vector>
#include <iostream>

sex::Core::Core()
{
    _graphicModule = std::make_unique<SfmlGraphicModule>();
    _graphicModule->createWindow(1280, 720);
    _game = std::make_unique<DemoGame>(*_graphicModule.get());
}

void sex::Core::run()
{
    _chrono.reset();
    std::vector<std::unique_ptr<IEvent>> events;

    while (_graphicModule->window().isOpen() && _game->isRunning())
    {
        int64_t elapsedTime = _chrono.reset();

        _graphicModule->window().fillEvents(events);
        _game->event(events);
        _game->update(*_graphicModule.get(), elapsedTime);
        events.clear();
    }
}