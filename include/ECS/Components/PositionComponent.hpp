#pragma once

#include "IComponent.hpp"
#include "Vector2.hpp"

namespace sex {
    class PositionComponent : public Vector2<float>, public IComponent {
        public:
            PositionComponent(float X = 0, float Y = 0) : Vector2<float>(X, Y) {}
            PositionComponent(Vector2 const &v) : Vector2<float>(v) {}
            PositionComponent(Vector2 const &&v) : Vector2<float>(v) {}

            ~PositionComponent() {}
    };
}