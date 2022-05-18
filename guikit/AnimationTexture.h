//
// Created by laplace on 5/10/22.
//

#ifndef DINO_ANIMATIONTEXTURE_H
#define DINO_ANIMATIONTEXTURE_H


#include "Texture.h"
#include "../utils/Timer.h"

namespace DinoSP {
    // Create an animation from 1 sheet
    class AnimationTexture: public Texture {
    private:
        uint64_t localTime {};
        uint64_t frameCount {};
        uint64_t duration {};

        uint64_t frameTime {};

        SDL_Rect initFrame;

    public:
        AnimationTexture(
                const string &path,
                const SDL_Rect& init ,
                uint64_t frameCount,
                uint64_t duration
                );

        void render() override;
        void render(int x, int y) override;
        void update() override;
        AnimationTexture();
    };
}


#endif //DINO_ANIMATIONTEXTURE_H
