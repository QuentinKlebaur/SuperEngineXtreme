#pragma once

#include <utility>

namespace sex {
    template <typename T>
    struct Vector2 {
        public:
            Vector2(T X = 0, T Y = 0) : x(X), y(Y) {}
            Vector2(Vector2 const &v) : x(v.x), y(v.y) {}
            Vector2(Vector2 const &&v) : x(std::exchange(v.x), 0), y(std::exchange(v.y), 0) {}

            ~Vector2() {}

            Vector2& operator=(Vector2 const &v) {
                x = v.x;
                y = v.y;
                return *this;
            }

            T x;
            T y;
    };
}