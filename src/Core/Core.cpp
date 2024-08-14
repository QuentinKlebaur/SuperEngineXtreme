#include "Core.hpp"
#include "DemoGame.hpp"
#include "SfmlGraphicModule.hpp"

sex::Core::Core()
{
    _graphicModule = std::make_unique<SfmlGraphicModule>();
    _graphicModule->createWindow(1080, 1920);
    _game = std::make_unique<DemoGame>(*_graphicModule.get());
}

void sex::Core::run()
{
    _game->run();
}