//
// Created by laplace on 5/18/22.
//

#include "OptionsScreen.h"

namespace DinoSP {
    void OptionsScreen::update() {
        Screen::update();
    }

    void OptionsScreen::render() {
        Screen::render();
    }

    void OptionsScreen::handleEvent(const SDL_Event &event) {
        Screen::handleEvent(event);
    }

    OptionsScreen::~OptionsScreen() {

    }

    OptionsScreen::OptionsScreen(ScreenManager *mgr) : Screen(mgr) {

    }
} // DinoSP