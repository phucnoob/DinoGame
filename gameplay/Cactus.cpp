//
// Created by laplace on 5/11/22.
//

#include "Cactus.h"

namespace DinoSP {


    Cactus::~Cactus() = default;

    void Cactus::render() {
       Texture::render(pos);
    }

    void Cactus::update(float time) {

    }

    Vector2 Cactus::randomPos(int i) {
        return {0,0 };
    }

    Cactus::Cactus(string path, SDL_Rect rect)
    : Texture(path, rect) {
        hitBox = { pos.x + padding, pos.x + padding, getWidth() - padding * 2, getHeight() - padding * 2};
    }

    void Cactus::setPos(Vector2 _pos) {
        this->pos = _pos;
        hitBox.x = _pos.x + padding;
        hitBox.y = _pos.y + padding;
    }

    Vector2 Cactus::getPos() {
        return pos;
    }

    void Cactus::move(Vector2 vel) {
        pos = pos + vel;
        setPos(pos);
    }

    bool Cactus::offScreen() {
        return getPos().x + getWidth() < 0;
    }



} // DinoSP