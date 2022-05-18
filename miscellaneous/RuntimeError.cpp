//
// Created by laplace on 5/9/22.
//

#include "RuntimeError.h"

#include <utility>

namespace DinoSP {
    RuntimeError::RuntimeError(string message): message(std::move(message)) {

    }

    const char *RuntimeError::what() const noexcept {
        return message.c_str();
    }
} // DinoSP