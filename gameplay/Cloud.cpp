//
// Created by laplace on 5/11/22.
//

#include "Cloud.h"

namespace DinoSP {
    Cloud::Cloud(string path, SDL_Rect clip):
    Texture(path, clip){

        // rand first case
        for (auto& pos: clouds) {
            pos = randCloudPos();
        }
    }

    Cloud::Cloud(string path) :
    Texture(path) {
        // rand first case
        for (auto& pos: clouds) {
            pos = randCloudPos();
        }
    }

    Vector2 Cloud::randCloudPos() {
        return { Random::random(Constants::width, Random::random(Constants::width, Constants::width * 3) )
                 ,Random::random(2, Constants::height / 2 ) };
    }

    bool Cloud::offScreen(Vector2 pos) {
        return pos.x + getWidth() < 0;
    }

    void Cloud::render() {
        for (auto& pos: clouds) {
            Texture::render(pos);
        }
    }

    void Cloud::update() {
        for (auto& pos: clouds) {
            if (this->offScreen(pos)) {
                pos = randCloudPos();
            }
            pos.x +=  CLOUD_VEL;
        }
    }

} // DinoSP