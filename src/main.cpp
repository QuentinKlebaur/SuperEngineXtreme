#include "ComponentManager.hpp"
#include "PositionComponent.hpp"

#include <iostream>

int main(int ac, char **argv)
{
    sex::ComponentManager componentManager;
    sex::PositionComponent *component = componentManager.add<sex::PositionComponent>(0, 10, 10);
    sex::PositionComponent *componentNull = nullptr;
    sex::PositionComponent *componentBis = nullptr;

    componentNull = componentManager.get<sex::PositionComponent>(1655);
    componentBis = componentManager.get<sex::PositionComponent>(0);

    if (componentNull == nullptr) {
        std::cout << "OK: componentNull is null" << std::endl;
    } else {
        std::cout << "KO: componentNull is null" << std::endl;
    }

    if (componentBis == component) {
        std::cout << "OK: componentBis is equal to component" << std::endl;
    } else {
        std::cout << "KO: componentBis is not equal to component" << std::endl;
    }

    if (componentBis == nullptr) {
        std::cout << "KO: componentBis is Null" << std::endl;
    } else {
        std::cout << "OK: componentBis is not Null" << std::endl;
    }
}