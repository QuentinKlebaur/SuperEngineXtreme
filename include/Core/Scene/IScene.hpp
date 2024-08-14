#pragma once

#include <cstdint>

namespace sex {
    class Registry;
    class IGraphicModule;

    class IScene
    {
        public:
            ~IScene() {};

            virtual void update(IGraphicModule &graphic, int64_t useconds) = 0;
            virtual Registry &getRegistry() = 0;
    };
}