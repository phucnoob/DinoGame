//
// Created by laplace on 5/18/22.
//

#ifndef DINO_OPTIONSSCREEN_H
#define DINO_OPTIONSSCREEN_H
#include "Screen.h"
#include "guikit/Texture.h"
#include "text/StaticText.h"
#include "audio/AudioManager.h"

namespace DinoSP {

    class OptionsScreen : public Screen {
    private:
        Texture *background;
        StaticText *musicVolumeTxt;
        StaticText *sfxVolumeTxt;

//        Slider*
    public:
        OptionsScreen(ScreenManager * mgr);

        void update() override;
        void render() override;
        void handleEvent(const SDL_Event &event) override;

        ~OptionsScreen() override;
    };

} // DinoSP

#endif //DINO_OPTIONSSCREEN_H
