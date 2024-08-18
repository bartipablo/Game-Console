#ifndef ForbiddenOperation_H
#define ForbiddenOperation_H

#include <stdexcept>
#include <string>


class ForbiddenOperation : public std::runtime_error {
public:
    explicit ForbiddenOperation(const char* message)
        : std::runtime_error(message) {}
};

#endif