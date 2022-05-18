//
// Created by laplace on 5/12/22.
//

#ifndef DINO_PTERO_H
#define DINO_PTERO_H

#include "guikit/AnimationTexture.h"

namespace DinoSP {

    class Ptero : public AnimationTexture {
    private:
        Vector2 pos;
        const int padding = 10;
        static constexpr uint64_t DEFAULT_FRAME = 2;
        static constexpr uint64_t DEFAULT_DURATION = 600; // milisec
    public:
        SDL_Rect hitBox;
        Ptero();
        Ptero(const string& path, const SDL_Rect& init);
        Ptero(const string &path, const SDL_Rect& init , uint64_t frameCount, uint64_t duration);
        void update() override;
        void render() override;
        void render(int x, int y) override;

        void move(Vector2 vel);

        void setPos(Vector2 _pos);
        Vector2 getPos() const;


        void updateHitBox();
        bool offScreen();
    };

} // DinoSP

#endif //DINO_PTERO_H
