#ifndef MY_MEMORY_H
#define MY_MEMORY_H

#include <memory>
#include <utility>

namespace my_std {
    template<typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
}

#endif
