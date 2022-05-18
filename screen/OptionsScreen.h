//
// Created by laplace on 5/18/22.
//

#ifndef DINO_OPTIONSSCREEN_H
#define DINO_OPTIONSSCREEN_H
#include "Screen.h"
#include "guikit/Texture.h"
#include "guikit/Slider.h"
#include "guikit/Button.h"
#include "text/StaticText.h"
#include "audio/AudioManager.h"
#include "utils/tinyfiledialogs.h"

namespace DinoSP {

    class OptionsScreen : public Screen {
    private:
        Font* font;
        Texture *background;
        StaticText *musicVolumeTxt;
        StaticText *sfxVolumeTxt;

        Slider *musicSlider;
        Slider *sfxSlider;

        Button *changeMusicBtn;

        Button *gobackBtn;
//        Slider*
    public:
        OptionsScreen(ScreenManager * mgr);

        void update() override;
        void render() override;
        void handleEvent(const SDL_Event &event) override;

        static int changeMusic(void* ptr);

        ~OptionsScreen() override;
    };

} // DinoSP

#endif //DINO_OPTIONSSCREEN_H
