//
// Created by laplace on 5/10/22.
//

#ifndef DINO_SCREEN_H
#define DINO_SCREEN_H

#include <SDL.h>
#include "utils/Timer.h"
#include "ScreenManager.h"
#include "utils/Graphics.h"

#include <memory>
#include <iostream>

namespace DinoSP {
    class ScreenManager;
    class Screen {
    protected:
        float timePassed;
        ScreenManager *manager;
        std::string name;
    public:
        Screen();
        explicit Screen(ScreenManager* manager);
        void drawBackground(SDL_Color color);
        virtual void update();
        virtual void render();
        virtual void userInput();
        virtual ~Screen();

        virtual void lostFocus();

        virtual void gainFocus();

        virtual void quit();

        virtual void handleEvent(const SDL_Event& event);
    };

} // DinoSP

#endif //DINO_SCREEN_H
