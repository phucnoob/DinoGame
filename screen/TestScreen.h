//
// Created by laplace on 5/10/22.
//

#ifndef DINO_TESTSCREEN_H
#define DINO_TESTSCREEN_H

#include "Screen.h"
#include "guikit/ToogleButton.h"
#include "guikit/AnimationTexture.h"
#include "guikit/Slider.h"

namespace DinoSP {

    class TestScreen : public Screen {

    private:
        ToogleButton* button;
        AnimationTexture* wings;
        Texture* text;

        Slider *siler;

    public:
        void render() override;
        void update() override;


        TestScreen();

        static int pickFile(void *ptr);
    };

} // DinoSP

#endif //DINO_TESTSCREEN_H
