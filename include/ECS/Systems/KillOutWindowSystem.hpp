#pragma once

#include "ISystem.hpp"
#include "PositionComponent.hpp"
#include "KillOutWindowComponent.hpp"
#include "UpdateContext.hpp"
#include "Registry.hpp"
#include "IWindow.hpp"

namespace sex {
    class KillOutWindowSystem : public ISystem {
        public:
            KillOutWindowSystem() = default;
            KillOutWindowSystem(KillOutWindowSystem const &) = delete;
            KillOutWindowSystem(KillOutWindowSystem const &&) = delete;
            ~KillOutWindowSystem() = default;

            void beforeUpdate(UpdateContext &) override
            {

            }

            void update(UpdateContext &context) override
            {
                context.getRegistry().applyOnComponents<KillOutWindowComponent>([&](Entity entity, KillOutWindowComponent &){
                        PositionComponent &position = context.getRegistry().getComponent<PositionComponent>(entity);
                        auto winSize = context.getWindow().size();

                        if (position.x < 0 || position.x > winSize.x || position.y < 0 || position.y > winSize.y)
                            context.removeEntity(entity);
                    });
            }

            void afterUpdate(UpdateContext &) override
            {

            }
    };
}