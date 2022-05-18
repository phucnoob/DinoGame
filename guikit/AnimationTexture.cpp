//
// Created by laplace on 5/10/22.
//

#include "AnimationTexture.h"

DinoSP::AnimationTexture::AnimationTexture() = default;

DinoSP::AnimationTexture::AnimationTexture(
        const string &path,
        const SDL_Rect &init,
        uint64_t frameCount,
        uint64_t duration )
: Texture(path, init)
, frameCount(frameCount)
, duration(duration)
, initFrame(init)
{
    srcRect = init;
    frameTime = duration / frameCount;
}

void DinoSP::AnimationTexture::render() {
    Texture::render();
}

void DinoSP::AnimationTexture::render(int x, int y) {
    Texture::render(x, y);
}

void DinoSP::AnimationTexture::update() {
    localTime += Timer::deltaTime();

    // loop
    if(localTime >= duration)
        localTime = 0;

    uint64_t tmp = localTime / frameTime;

    // Assumed the sheet is horizontal
    srcRect.x = initFrame.x + tmp * initFrame.w;
}
