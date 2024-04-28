#include "Registry.hpp"
#include "PositionComponent.hpp"
#include "Chrono.hpp"
#include "FallSystem.hpp"

#include <iostream>

int main(int ac, char **argv)
{
    sex::Registry registry;
    sex::Chrono chrono;
    int64_t useconds = 0;
    unsigned int loop = 0;

    registry.addSystem<sex::FallSystem>();
    for (unsigned int i = 0; i < 10000; ++i) {
        sex::Entity entity = registry.createEntity();

        registry.addComponent<sex::PositionComponent>(entity, 0, 10 + std::rand() % 90);
    }
    chrono.reset();
    while (registry.getEntities().size()) {
        useconds = chrono.reset();
        registry.update(useconds);
        std::cout << "---- Loop number " << loop++ << " ----" << std::endl;
        std::cout << "Elapsed time: " << useconds << std::endl;
        std::cout << "Entities remaining: " << registry.getEntities().size() << std::endl;
    }
}