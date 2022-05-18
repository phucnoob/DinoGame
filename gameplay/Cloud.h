//
// Created by laplace on 5/11/22.
//

#ifndef DINO_CLOUD_H
#define DINO_CLOUD_H

#include "guikit/Texture.h"
#include "utils/Random.h"
#include "constants/Constants.h"
#include <array>

namespace DinoSP {

    class Cloud : public Texture{
        static constexpr int MAX_CLOUDs = 4;
        static constexpr int CLOUD_VEL = -1;
        array<Vector2, MAX_CLOUDs> clouds;

        Cloud(string path);

        // Cloud just moving horizontal
        bool offScreen(Vector2 pos);
        static Vector2 randCloudPos();


    public:
        Cloud(string path , SDL_Rect clipRect);
        void render() override;
        void update() override;
    };

} // DinoSP

#endif //DINO_CLOUD_H
