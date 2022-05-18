//
// Created by laplace on 5/13/22.
//

#ifndef DINO_TOOGLEBUTTON_H
#define DINO_TOOGLEBUTTON_H

#include "BaseButton.h"
#include "audio/AudioManager.h"
#include "constants/Constants.h"

namespace DinoSP {

    class ToogleButton final : public BaseButton, public Texture {
    private:
        bool state = true;
    public:
        ToogleButton(string path, SDL_Rect clipRect);

        int getWidth() override;
        int getHeight() override;

        void onClick();

        bool getState();

        void update() override;

        void render() override;
    };

}

#endif //DINO_TOOGLEBUTTON_H
