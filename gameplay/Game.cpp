//
// Created by laplace on 5/10/22.
//

#include "Game.h"
#include "miscellaneous/RuntimeError.h"
#include "constants/Constants.h"
#include "utils/Graphics.h"
#include "input/InputManager.h"
#include "utils/Timer.h"
#include "screen/ScreenManager.h"
#include "screen/StartScreen.h"
#include "screen/TestScreen.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


using namespace std::string_literals;

namespace DinoSP {
    // quit the game from any class (thanks to c++ friend function)
    void g_quit(Game* game);
    bool Game::init() {
        bool success = true;
        success = Graphics::Instance()->init();
        return success;
    }

    void Game::run() {
        SDL_Event event;
        while (running) {
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        screenManager->quit();
                        break;
                    case SDL_WINDOWEVENT:
                        switch (event.window.event) {
                            case SDL_WINDOWEVENT_RESTORED:
                            case SDL_WINDOWEVENT_FOCUS_GAINED:
                                screenManager->gainFocus();
                                break;
                            case SDL_WINDOWEVENT_MINIMIZED:
                            case SDL_WINDOWEVENT_FOCUS_LOST:
                                screenManager->lostFocus();
                                break;
                        }
                        break;
                    default:
                        // custom handle
                        screenManager->handleEvent(event);
                }


            }
            update();
            render();
            lateUpdate();
        }

    }

    Game::Game() {
        init();
        screenManager = new ScreenManager(this);
        screenManager->changeScreen(new StartScreen(screenManager));
        AudioManager::playMusic("assets/sounds/background.mp3");
    }

    void Game::quit() {

        delete screenManager;

        IMG_Quit();
        TTF_Quit();
        SDL_Quit();
    }

    void Game::render() {
        screenManager->render();
    }

    void Game::update() {
        Timer::reset();
        InputManager::Instance()->updateKeyState();
        InputManager::Instance()->updateMouseState();
        screenManager->update();
    }

    Game::~Game() {
        quit();
    }

    void Game::lateUpdate() {
        Timer::update();
        InputManager::Instance()->updatelastKeyState();
    }
} // DinoSP