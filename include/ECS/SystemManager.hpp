#pragma once

#include "ISystem.hpp"

#include <vector>
#include <memory>

namespace sex
{
    class Registry;

    class SystemManager {
        public:
        SystemManager() = default;
        SystemManager(SystemManager const&) = delete;
        SystemManager(SystemManager&&) = default;
        ~SystemManager() = default;

            template<typename T, typename... Args>
            void add(Args... args)
            {
                _systems.emplace_back(std::make_unique<T>(args...));
            }

            template<typename T>
            void remove()
            {
                T *toRemove = nullptr;

                for (auto i = _systems.begin(); i != _systems.end(); ++i) {
                    toRemove = dynamic_cast<T*>(i->get());
                    if (toRemove) {
                        i = _systems.erase(i);
                    }
                }
            }

            void update(Registry &registry, int64_t useconds);

        private:
            std::vector<std::unique_ptr<ISystem>> _systems;
    };
}
