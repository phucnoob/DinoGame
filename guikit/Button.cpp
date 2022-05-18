//
// Created by laplace on 5/14/22.
//

#include "Button.h"

DinoSP::Button::Button(string path, SDL_Rect clipRect)
: Texture(path, clipRect) {

}

int DinoSP::Button::getWidth() {
    return Texture::getWidth();
}

int DinoSP::Button::getHeight() {
    return Texture::getHeight();
}

void DinoSP::Button::update() {
    BaseButton::update();
    if (isClick()) {
        onClick();
    }
    Graphics::Instance()->resetTexture(Texture::image);
    if (isHover()) {
        onHover();
    }
}

void DinoSP::Button::render() {
    Texture::render(pos);
}

void DinoSP::Button::onHover() {
    SDL_SetTextureColorMod(Texture::image, 128, 128, 128);
    Graphics::Instance()->darkenTexture(Texture::image);
}

void DinoSP::Button::onClick() {
    AudioManager::playSound(Constants::sounds.click);
}

DinoSP::Button::Button(string path): Texture(path) {

}

