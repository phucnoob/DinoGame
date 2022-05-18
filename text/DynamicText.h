//
// Created by laplace on 5/10/22.
//

#ifndef DINO_DYNAMICTEXT_H
#define DINO_DYNAMICTEXT_H

#include "StaticText.h"

namespace DinoSP {

    class DynamicText: public StaticText{
    private:
        string text;
        SDL_Color color;
    public:
        DynamicText(string text, const Font &font);

        void changeText(const string& text);
        void changeColor(SDL_Color color);
    };

}

#endif //DINO_DYNAMICTEXT_H
