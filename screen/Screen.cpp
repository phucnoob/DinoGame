//
// Created by laplace on 5/10/22.
//

#include "Screen.h"

#include <utility>

namespace DinoSP {
    Screen::Screen(){
    }

    void Screen::render() {

    }
    void Screen::update() {
        timePassed = Timer::deltaTimeInSecond();
    }

    void Screen::lostFocus() {

    }

    void Screen::userInput() {

    }

    void Screen::drawBackground(SDL_Color color) {
        Graphics::Instance()->drawBackGround(color);
    }

    Screen::~Screen() {

    }

    void Screen::gainFocus() {

    }

    void Screen::quit() {

    }

    Screen::Screen(ScreenManager * mgr)
    : manager(mgr) {

    }

    void Screen::handleEvent(const SDL_Event& event) {

    }


} // DinoSP