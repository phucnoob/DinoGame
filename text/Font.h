//
// Created by laplace on 5/9/22.
//

#ifndef DINO_FONT_H
#define DINO_FONT_H

#include <SDL_ttf.h>
#include <iostream>

using std::string;
namespace DinoSP {

    class Font {
        TTF_Font* font = nullptr;
        int size;

    public:
        TTF_Font* getFont() const;

        Font(const string& fontName, int size);

        ~Font();
    };

} // DInoSP

#endif //DINO_FONT_H
