//
// Created by laplace on 5/12/22.
//

#ifndef DINO_DINO_H
#define DINO_DINO_H

#include "guikit/AnimationTexture.h"
#include "input/InputManager.h"

namespace DinoSP {

    class Dino {

    private:
        Vector2 pos;
        bool jumping = false;
        bool ducking = false;
        bool died = false;
        const int padding = 20;
        Vector2 vel;

        AnimationTexture *normalTxt;
        AnimationTexture* duckTxt;
        Texture* diedTxt;

    public:
        SDL_Rect hitBox;
        explicit Dino();

        Dino(string path, SDL_Rect clipRect, uint64_t frameCount, uint64_t duration);

        void handleInput();
        void update() ;
        void render(int x, int y) ;
        void render() ;

        void updateHitbox();

        void setPos(Vector2 _pos);
        Vector2 getPos();

        int getWidth();
        int getHeight();

        void gameOver();

        void reset();

        ~Dino();
    };

} // DinoSP

#endif //DINO_DINO_H
