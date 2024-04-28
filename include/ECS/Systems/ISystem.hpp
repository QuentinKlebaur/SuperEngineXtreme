#pragma once

#include "Entity.hpp"

namespace sex {
    class ISystem {
        public:
            virtual ~ISystem() {};

            virtual void update(int64_t useconds) = 0;
    };
}