#pragma once

#include <exception>
#include <string>

namespace sex {
    class NotAComponentException : public std::exception {
        public:
            NotAComponentException() {}
            NotAComponentException(std::string const &msg) : _msg(msg) {}
            NotAComponentException(char const *msg) : _msg(msg) {}

            virtual ~NotAComponentException() noexcept {}

            virtual const char* what() const noexcept override {
                return _msg.c_str();
            }

        private:
            std::string _msg;
    };
}