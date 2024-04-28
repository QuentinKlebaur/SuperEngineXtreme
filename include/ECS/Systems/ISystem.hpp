#pragma once

#include "Entity.hpp"

#include <cstdint>

namespace sex {
    class Registry;

    class ISystem {
        public:
            virtual ~ISystem() {};

            virtual void beforeUpdate(Registry &registry, int64_t useconds) = 0;
            virtual void update(Registry &registry, int64_t useconds) = 0;
            virtual void afterUpdate(Registry &registry, int64_t useconds) = 0;
    };
}