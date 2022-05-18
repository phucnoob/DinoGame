//
// Created by laplace on 5/12/22.
//

#include "Ptero.h"

namespace DinoSP {
    void Ptero::update() {
        AnimationTexture::update();
        updateHitBox();
    }

    void Ptero::render() {
        AnimationTexture::render(pos.x, pos.y);
    }

    void Ptero::render(int x, int y) {
        AnimationTexture::render(x, y);
    }

    Ptero::Ptero(const string &path, const SDL_Rect &init, uint64_t frameCount, uint64_t duration
                 ) : AnimationTexture(path, init, frameCount, duration) {

    }

    Ptero::Ptero() {

    }

    void Ptero::move(Vector2 vel) {
        pos = pos + vel;
    }

    Vector2 Ptero::getPos() const {
        return pos;
    }

    void Ptero::setPos(Vector2 _pos) {
        this->pos = _pos;
    }

    bool Ptero::offScreen() {
        return this->pos.x + getWidth() < 0;
    }

    Ptero::Ptero(const string &path, const SDL_Rect &init )
    : AnimationTexture(path, init, DEFAULT_FRAME, DEFAULT_DURATION) {

    }

    void Ptero::updateHitBox() {
        hitBox = {pos.x + padding, pos.y + padding, getWidth() - 2 * padding, getHeight() - 2 * padding };
    }

} // DinoSP