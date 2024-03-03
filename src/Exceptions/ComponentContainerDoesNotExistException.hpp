#pragma once

#include <exception>
#include <string>

namespace sex {
    class ComponentContainerDoesNotExistException : public std::exception {
        public:
            ComponentContainerDoesNotExistException() {}
            ComponentContainerDoesNotExistException(std::string const &msg) : _msg(msg) {}
            ComponentContainerDoesNotExistException(char const *msg) : _msg(msg) {}

            virtual ~ComponentContainerDoesNotExistException() noexcept {}

            virtual const char* what() const noexcept override {
                return _msg.c_str();
            }

        private:
            std::string _msg;
    };
}