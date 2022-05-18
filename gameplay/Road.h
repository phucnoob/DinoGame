//
// Created by laplace on 5/11/22.
//

#ifndef DINO_ROAD_H
#define DINO_ROAD_H

#include "guikit/Texture.h"

namespace DinoSP {

    class Road : public Texture {
        Vector2 pos;
        float accelaration = 0.0025;
        float velocity = 0;
        const Vector2 base_vel { -8, 0};

    public:
        Vector2 vel = { base_vel };
        Road(const string& path, SDL_Rect clipRect);

        void setPos(Vector2 _pos);
        void render() override;
        void move(Vector2 vel);
        void move();

        void reset();
    };

} // DinoSP

#endif //DINO_ROAD_H
