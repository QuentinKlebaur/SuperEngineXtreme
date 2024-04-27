#pragma once

#include "ISystem.hpp"

#include <vector>

namespace sex
{
    class ASystem : ISystem
    {

        public:
            ASystem();
            ~ASystem();
        
        private:
            std::vector<Entity> _entities;
    };
}