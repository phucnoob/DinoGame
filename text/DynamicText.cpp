//
// Created by laplace on 5/10/22.
//

#include "DynamicText.h"

#include <utility>
#include "../constants/Color.h"

namespace DinoSP {

    void DynamicText::changeText(const string &text) {

        if (this->text == text)
            return;

        if (text.empty()) {
            SDL_Log("Empty text is not valid !!");
            return;
        }

        this->text = text;

        if(this->image != nullptr ) {
            // free last text
            delete this->image;
        }
        this->image = new Texture(Graphics::Instance()->createText(text.c_str(), font, this->color));
    }


    DynamicText::DynamicText(string _text, const Font &font)
    : StaticText(_text, font) {
        this->text = _text;
        this->color = Color::GRAY;
    }

    void DynamicText::changeColor(SDL_Color color) {
        this->color = color;

        if(this->image != nullptr ) {
            // free last text
            delete this->image;
        }
        this->image = new Texture(Graphics::Instance()->createText(text.c_str(), font, this->color));
    }
}