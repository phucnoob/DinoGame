//
// Created by laplace on 5/10/22.
//

#include "Random.h"

int DinoSP::Random::random() {
    static std::random_device rd;
    static std::mt19937_64 gen(rd());
    static std::uniform_int_distribution<int> rand(0, INT32_MAX);

    return rand(gen);
}

int DinoSP::Random::random(int begin, int end) {
    static std::random_device rd;
    static std::mt19937_64 gen(rd());

    std::uniform_int_distribution<int> cusRand(begin, end);
    return cusRand(gen);
}

SDL_Color DinoSP::Random::randomColor() {
    static std::random_device rd;
    static std::mt19937_64 gen(rd());

    static std::uniform_int_distribution<int> rand(0, 255);

    SDL_Color rColor {};
    rColor.r = rand(gen);
    rColor.g = rand(gen);
    rColor.b = rand(gen);
    rColor.a = rand(gen);

    return rColor;
}
