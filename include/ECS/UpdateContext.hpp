#include <cstdint>

namespace sex {
    class IGraphicModule;
    class IWindow;
    class Registry;

    class UpdateContext
    {
        public:
            UpdateContext() = default;
            UpdateContext(IGraphicModule &, Registry &, int64_t elapsedTime);
            UpdateContext(UpdateContext const &) = default;
            UpdateContext(UpdateContext const &&) = delete;
            ~UpdateContext() = default;

            Registry &getRegistry() const;
            IGraphicModule &getGraphicModule() const;
            IWindow &getWindow() const;
            int64_t getElapsedTime() const;

        private:
            IGraphicModule &_graphicModule;
            Registry &_registry;
            int64_t _elapsedTime;
    };
}