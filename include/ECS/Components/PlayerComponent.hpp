#pragma once

#include "IComponent.hpp"

namespace sex {
    class PlayerComponent : public IComponent {
        public:
            PlayerComponent() = default;
            PlayerComponent(PlayerComponent const &) = delete;
            PlayerComponent(PlayerComponent &&) = delete;
            ~PlayerComponent() = default;
    };
}