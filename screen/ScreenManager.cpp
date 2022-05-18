//
// Created by laplace on 5/10/22.
//

#include "ScreenManager.h"
#include "gameplay/Game.h"


void DinoSP::ScreenManager::render() {
    current->render();
}


void DinoSP::ScreenManager::update() {
    current->update();
}

void DinoSP::ScreenManager::lostFocus() {
    current->lostFocus();
}

void DinoSP::ScreenManager::changeScreen(Screen* screen) {
    if(screen == nullptr || screen == current)
        return;

    // if screen not in set, insert ( this for memory manage )
    if (allScreens.count(screen) == 0) {
        allScreens.insert(screen);
    }

    current = screen;
    stackFrame.push(screen);
}

void DinoSP::ScreenManager::goback() {
    stackFrame.pop();
    current = stackFrame.top();
}

DinoSP::ScreenManager::~ScreenManager() {

    allScreens.clear();

//    stackFrame.
}

void DinoSP::ScreenManager::gainFocus() {
//    current->gainFocus();
}

void DinoSP::ScreenManager::quit() {
    current->quit();
    g_quit(game);
}

DinoSP::ScreenManager::ScreenManager(Game *game) {
    this->game = game;
}

void DinoSP::ScreenManager::handleEvent(const SDL_Event &event) {
    current->handleEvent(event);

}

void DinoSP::g_quit(Game* game) {
    game->running = false;
}
