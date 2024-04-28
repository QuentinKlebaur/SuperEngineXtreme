#include "Registry.hpp"
#include "PositionComponent.hpp"
#include "Chrono.hpp"

#include <iostream>

int main(int ac, char **argv)
{
    std::cout << "--- ComponentManager ---" << std::endl;
    sex::ComponentManager componentManager;
    sex::Registry registry;
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

    std::cout << "--- Chrono ---" << std::endl;
    sex::Chrono chrono;

    std::cout << "Start chrono" << std::endl;
    while (chrono.getElapsedTime() < 3000000);
    std::cout << "3 seconds elapsed: " << chrono.reset() << std::endl;
    while (chrono.getElapsedTime() < 5000000);
    std::cout << "5 seconds elapsed: " << chrono.getElapsedTime() << std::endl;
}