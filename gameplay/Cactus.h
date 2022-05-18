//
// Created by laplace on 5/11/22.
//

#ifndef DINO_CACTUS_H
#define DINO_CACTUS_H

#include "guikit/Texture.h"
#include "constants/Constants.h"
#include <queue>

namespace DinoSP {

    class Cactus : public Texture {
    private:
        Vector2 pos;
        const int padding = 16;
    public:
        SDL_Rect hitBox;


        Cactus(string path, SDL_Rect clipRect);
        ~Cactus();

        void render() override;
        void update(float time);

        Vector2 randomPos(int id);

        void setPos(Vector2 _pos);
        Vector2 getPos();

        void move(Vector2 vel);

        bool offScreen();

    };

} // DinoSP

#endif //DINO_CACTUS_H
