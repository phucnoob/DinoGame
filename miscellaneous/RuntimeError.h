//
// Created by laplace on 5/9/22.
//

#ifndef DINO_RUNTIMEERROR_H
#define DINO_RUNTIMEERROR_H

#include <exception>
#include <iostream>


using std::string;
namespace DinoSP {

    class RuntimeError : public std::exception {
    private:
        const string message;
    public:
        explicit RuntimeError(string  message);

        virtual const char* what() const noexcept override;

    };

} // DinoSP

#endif //DINO_RUNTIMEERROR_H
