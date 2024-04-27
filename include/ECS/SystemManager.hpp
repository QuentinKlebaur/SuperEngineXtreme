#pragma once

#include "ISystem.hpp"

#include <vector>
#include <memory>

namespace sex
{
    class SystemManager {
        public:
        SystemManager() = default;
        SystemManager(SystemManager const&) = delete;
        SystemManager(SystemManager&&) = default;
        ~SystemManager() = default;
        
        private:
            std::vector<std::unique_ptr<ISystem>> _systems;
    };
}
