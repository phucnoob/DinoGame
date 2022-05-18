//
// Created by laplace on 5/9/22.
//

#ifndef DINO_STATICTEXT_H
#define DINO_STATICTEXT_H


#include "../guikit/Texture.h"
#include "Font.h"
#include "../constants/Constants.h"

#include <memory>

namespace DinoSP {
    class StaticText {
    protected:
        Texture* image;
        const Font& font;

    public:
        StaticText(string text, const Font& font);

        void render();
        void render(int x, int y);

        inline int getX() const { return image->getX(); };
        inline int getY() const { return image->getY(); };

        inline int getWidth() const { return image->getWidth(); };
        inline int getHeight() const { return image->getHeight(); };


        ~StaticText();

    };
}

#endif //DINO_STATICTEXT_H
