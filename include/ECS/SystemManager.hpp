#pragma once

#include "ISystem.hpp"

#include <vector>
#include <memory>

namespace sex
{
    class UpdateContext;

    class SystemManager {
        public:
        SystemManager() = default;
        SystemManager(SystemManager const&) = delete;
        SystemManager(SystemManager&&) = default;
        ~SystemManager() = default;

            template<typename T, typename... Args>
            T &add(Args... args)
            {
                return dynamic_cast<T&>(*_systems.emplace(_systems.end(), std::make_unique<T>(args...))->get());
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

            template<typename T>
            T &get()
            {
                T *system = nullptr;

                for (auto i = _systems.begin(); i != _systems.end(); ++i) {
                    system = dynamic_cast<T*>(i->get());
                    if (system != nullptr)
                        return *system;
                }
                // TODO Better exception
                throw std::exception();
            }

            void update(UpdateContext &);

        private:
            std::vector<std::unique_ptr<ISystem>> _systems;
    };
}
