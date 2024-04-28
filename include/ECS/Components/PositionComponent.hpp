#pragma once

#include "IComponent.hpp"
#include "Vector2.hpp"

namespace sex {
    class PositionComponent : public Vector2<double>, public IComponent {
        public:
            PositionComponent(double X = 0, double Y = 0) : Vector2<double>(X, Y) {}
            PositionComponent(Vector2 const &v) : Vector2<double>(v) {}
            PositionComponent(Vector2 const &&v) : Vector2<double>(v) {}

            ~PositionComponent() {}
    };
}