#pragma once

#include <cstdint>
#include <vector>
#include <memory>

namespace sex {
    class Registry;
    class IGraphicModule;
    class IEvent;

    class IScene
    {
        public:
            ~IScene() {};

            virtual void update(IGraphicModule &graphic, int64_t useconds) = 0;
            virtual void event(std::vector<std::unique_ptr<IEvent>> const &events) = 0;
            virtual Registry &getRegistry() = 0;
    };
}