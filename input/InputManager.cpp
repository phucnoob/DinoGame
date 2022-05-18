//
// Created by laplace on 5/10/22.
//

#include "InputManager.h"

DinoSP::InputManager* DinoSP::InputManager::sInstance = nullptr;

DinoSP::InputManager *DinoSP::InputManager::Instance() {
    if (sInstance == nullptr) {
        sInstance = new InputManager();
    }
    return sInstance;
}

DinoSP::InputManager::~InputManager() {
    delete[] lastKeyState;
    lastKeyState = nullptr;
    // dont need to free currentKeyState as is manage by SDL
}

bool DinoSP::InputManager::keyDown(SDL_Scancode keycode) {
    return currentKeyState[keycode];
}

bool DinoSP::InputManager::keyPressed(SDL_Scancode keycode) {
    return currentKeyState[keycode] && !lastKeyState[keycode];
}

bool DinoSP::InputManager::keyUp(SDL_Scancode keycode) {
    return !currentKeyState[keycode] && lastKeyState[keycode];
}

void DinoSP::InputManager::updatelastKeyState() {

    memcpy(lastKeyState, currentKeyState, keyStateLength);
    lastMouseState = mouseState;
}

void DinoSP::InputManager::updateKeyState() {
//    memcpy(lastKeyState, currentKeyState, keyStateLength);

    currentKeyState = SDL_GetKeyboardState(&keyStateLength);
}

DinoSP::InputManager::InputManager() {

    currentKeyState = SDL_GetKeyboardState(&keyStateLength);

    lastKeyState = new Uint8[keyStateLength];

    // copy to last so we have data on first frame
    memcpy(lastKeyState, currentKeyState, keyStateLength);
}

DinoSP::Vector2 DinoSP::InputManager::getMousePos() {

    return mousePos;
}

void DinoSP::InputManager::updateMouseState() {
    mouseState = SDL_GetMouseState(&mousePos.x, &mousePos.y);
}

bool DinoSP::InputManager::mouseRightClick() const {
    return (mouseState & SDL_BUTTON_RMASK) && !(lastMouseState & SDL_BUTTON_LMASK);
}

bool DinoSP::InputManager::mouseLeftClick() const {
    return (mouseState & SDL_BUTTON_LMASK) && !(lastMouseState & SDL_BUTTON_LMASK);
}

