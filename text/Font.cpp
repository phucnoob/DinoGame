//
// Created by laplace on 5/9/22.
//

#include "Font.h"
#include "miscellaneous/RuntimeError.h"
using namespace std::string_literals;
namespace DinoSP {
    Font::Font(const string &fontName, int size) {
        font = TTF_OpenFont(fontName.c_str(), size);
        if(font == nullptr) {
            throw RuntimeError("Can't load font, "s + TTF_GetError());
        }

        this->size = size;
    }

    Font::~Font() {
        TTF_CloseFont(font);
        font = nullptr;
    }

    TTF_Font *Font::getFont() const {
        return font;
    }
} // DinoSP