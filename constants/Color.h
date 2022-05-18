//
// Created by laplace on 5/9/22.
//

#ifndef DINO_COLOR_H
#define DINO_COLOR_H

#include <SDL.h>

namespace DinoSP {
    namespace Color {
        constexpr SDL_Color BLACK { 10,10,10,255 };
        constexpr SDL_Color WHITE { 250, 250, 250, 255 };
        constexpr SDL_Color GRAY { 83, 83, 83, 255};
        constexpr SDL_Color GREEN { 0, 255, 0, 255};
        constexpr SDL_Color RED { 255, 0, 0, 255};

    }
}

#endif //DINO_COLOR_H
