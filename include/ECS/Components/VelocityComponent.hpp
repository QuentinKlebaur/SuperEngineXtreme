#pragma once

#include "IComponent.hpp"
#include "Vector2.hpp"

namespace sex {
    class VelocityComponent : public Vector2<double>, public IComponent {
        public:
            VelocityComponent(double X = 0, double Y = 0) : Vector2<double>(X, Y) {}
            VelocityComponent(Vector2 const &v) : Vector2<double>(v) {}
            VelocityComponent(Vector2 const &&v) : Vector2<double>(v) {}

            ~VelocityComponent() {}
    };
}