#pragma once

#include "Entity.hpp"

#include <cstdint>

namespace sex {
    class UpdateContext;

    class ISystem {
        public:
            virtual ~ISystem() {};

            virtual void beforeUpdate(UpdateContext &) = 0;
            virtual void update(UpdateContext &) = 0;
            virtual void afterUpdate(UpdateContext &) = 0;
    };
}