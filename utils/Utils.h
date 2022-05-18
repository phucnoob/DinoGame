//
// Created by laplace on 5/14/22.
//

#ifndef DINO_UTILS_H
#define DINO_UTILS_H

#include <SDL_rect.h>
#include <iostream>
#include <vector>
#include <iostream>
#include <utility>
#include "Vector2.h"

using std::fstream;
using std::vector;
using std::string;

namespace DinoSP {

    namespace Utils {
        bool Color_Equal(SDL_Color a, SDL_Color b);

        void padding(string& text, int length, char pad);

        bool mouseInRect(Vector2 mousePos, SDL_Rect rect);

        std::vector<std::pair<string, int>> readHiScore(string path);
    };

} // DinoSP

#endif //DINO_UTILS_H
