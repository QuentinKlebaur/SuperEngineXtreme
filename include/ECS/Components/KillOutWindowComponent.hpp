#pragma once

#include "IComponent.hpp"

namespace sex {
    class KillOutWindowComponent : public IComponent {
        public:
            KillOutWindowComponent() = default;
            KillOutWindowComponent(KillOutWindowComponent const &) = delete;
            KillOutWindowComponent(KillOutWindowComponent &&) = delete;
            ~KillOutWindowComponent() = default;
    };
}