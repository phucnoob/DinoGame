//
// Created by laplace on 5/11/22.
//

#include "Road.h"
#include "constants/Constants.h"

namespace DinoSP {

    Road::Road(const string& path, SDL_Rect clipRect)
    : Texture(path, clipRect){

    }

    void Road::render() {
        Texture::render(pos);
        Texture::render(pos.x + this->getWidth(), pos.y);
    }

    void Road::move(Vector2 vel) {
        pos = pos + vel;
        if(pos.x < -this->getWidth()) {
            pos.x = 0;
        }

        velocity += accelaration;
        // when accelaration = 1, increase vel
        if (velocity < 1) {
            return;
        }
        if (this->vel.x > -Constants::MAX_VEL) {
            this->vel.x--;
            velocity = 0;
        }
    }

    void Road::setPos(Vector2 _pos) {
        this->pos = _pos;
    }

    void Road::move() {
        move(this->vel);
    }

    void Road::reset() {
        this->vel = base_vel;
    }
} // DinoSP