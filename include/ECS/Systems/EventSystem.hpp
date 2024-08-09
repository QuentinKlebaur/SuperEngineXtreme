#pragma once

#include "ISystem.hpp"

#include <functional>
#include <map>

namespace sex
{
    class EventSystem : public ISystem
    {
        public:
            EventSystem() = default;
            EventSystem(EventSystem const &) = delete;
            EventSystem(EventSystem const &&) = delete;
            ~EventSystem() = default;

            void beforeUpdate(Registry &registry, int64_t useconds) override;
            void update(Registry &registry, int64_t useconds) override;
            void afterUpdate(Registry &registry, int64_t useconds) override;

        private:
//            std::multimap<>
    };
}