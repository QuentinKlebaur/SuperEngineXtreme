#pragma once

#include "Entity.hpp"

#include <cstdint>

namespace sex {
    class UpdateContext;

    class ISystem {
        public:
            virtual ~ISystem() {};

            virtual void beforeUpdate(UpdateContext const &) = 0;
            virtual void update(UpdateContext const &) = 0;
            virtual void afterUpdate(UpdateContext const &) = 0;
    };
}