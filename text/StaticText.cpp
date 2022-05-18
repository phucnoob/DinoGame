//
// Created by laplace on 5/9/22.
//

#include "StaticText.h"
#include "../constants/Color.h"


void DinoSP::StaticText::render() {
    this->image->render();
}

DinoSP::StaticText::StaticText(string text, const DinoSP::Font &font)
: font( font ){

    this->image = new Texture(Graphics::Instance()->createText(text.c_str(), font, Color::GRAY));
}

DinoSP::StaticText::~StaticText() {

    delete this->image;
    this->image = nullptr;

}

void DinoSP::StaticText::render(int x, int y) {
    this->image->render(x, y);
}

