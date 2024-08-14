#include "DemoGame.hpp"
#include "DemoMainScene.hpp"

sex::DemoGame::DemoGame(IGraphicModule &graphic) : GameBase{graphic}
{
    _scenes.push_back(std::make_unique<DemoMainScene>(graphic));
}