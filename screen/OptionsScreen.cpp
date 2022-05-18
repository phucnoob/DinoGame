//
// Created by laplace on 5/18/22.
//

#include "OptionsScreen.h"

namespace DinoSP {
    void OptionsScreen::update() {
        Screen::update();
        sfxSlider->update();
        musicSlider->update();
        changeMusicBtn->update();
        gobackBtn->update();
        AudioManager::setVolume(musicSlider->getValue());


        if (changeMusicBtn->isClick()) {
            SDL_CreateThread(changeMusic, "pick new file", (void*) ( NULL));
        }

        if (gobackBtn->isClick()) {
            manager->goback();
            SDL_StartTextInput();
        }
    }

    void OptionsScreen::render() {
        Screen::render();
        background->render();
        musicVolumeTxt->render(100, 200);
        sfxVolumeTxt->render(100, 250);
        musicSlider->render();
        sfxSlider->render();
        changeMusicBtn->render();
        gobackBtn->render();

        Graphics::Instance()->render();
    }

    void OptionsScreen::handleEvent(const SDL_Event &event) {
        Screen::handleEvent(event);
    }

    OptionsScreen::~OptionsScreen() {
        delete font;
        delete background;
        delete musicVolumeTxt;
        delete sfxVolumeTxt;
        delete musicSlider;
        delete sfxSlider;
        delete changeMusicBtn;
        delete gobackBtn;
    }

    OptionsScreen::OptionsScreen(ScreenManager *mgr) : Screen(mgr) {
        font = new Font(Constants::main_font, 18);
        background = new Texture(Constants::background_image);
        musicVolumeTxt = new StaticText("Music", *font);
        sfxVolumeTxt = new StaticText("Sound", *font);
        sfxSlider = new Slider(400, 24, {200, 248});
        musicSlider = new Slider(400, 24, {200, 197});

        musicSlider->setMaxValue(MIX_MAX_VOLUME);
        musicSlider->setValue(MIX_MAX_VOLUME);

        changeMusicBtn = new Button(Constants::buttons.change.path, Constants::buttons.change.rect);
        changeMusicBtn->setPos({610, 196});

        gobackBtn =  new Button(Constants::buttons.exit.path, Constants::buttons.exit.rect);
        gobackBtn->setPos({5, 5});

        SDL_Log("option create");
    }

    int OptionsScreen::changeMusic(void* ptr) {
        char const * lFilterPatterns[1] = { "*.mp3"};
        char const * selection = tinyfd_openFileDialog(
                "Select background file (mp3)", // title
                "./",
                1,
                lFilterPatterns,
                NULL,
                0
        );

        if (selection) {
            AudioManager::playMusic(string(selection));
        }
        return 0;
    }
} // DinoSP