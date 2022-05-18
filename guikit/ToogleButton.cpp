//
// Created by laplace on 5/13/22.
//

#include "ToogleButton.h"

DinoSP::ToogleButton::ToogleButton(string path, SDL_Rect clipRect)
: Texture(path, clipRect ){

}

int DinoSP::ToogleButton::getWidth() {
    return Texture::getWidth();
}

int DinoSP::ToogleButton::getHeight() {
    return Texture::getHeight();
}

void DinoSP::ToogleButton::onClick() {
    // toogle
    if (srcRect.x < srcRect.w) {
        srcRect.x += srcRect.w;
    } else {
        srcRect.x -= srcRect.w;
    }

    // sound
    AudioManager::playSound(Constants::sounds.click);
}

void DinoSP::ToogleButton::render() {
    Texture::render(pos);
}

void DinoSP::ToogleButton::update() {
    BaseButton::update();
}

bool DinoSP::ToogleButton::getState() {
    return state;
}
