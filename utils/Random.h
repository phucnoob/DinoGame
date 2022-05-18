//
// Created by laplace on 5/10/22.
//

#ifndef DINO_RANDOM_H
#define DINO_RANDOM_H
#include <random>
#include <SDL_pixels.h>

namespace DinoSP {
    struct Random {
        // ..
        static int random(int begin, int end);
        // random from 0 - 1024 by default
        static int random();

        static SDL_Color randomColor();
    };
}


#endif //DINO_RANDOM_H
