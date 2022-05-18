//
// Created by laplace on 5/10/22.
//

#ifndef DINO_GAME_H
#define DINO_GAME_H

#include <SDL.h>
#include "screen/ScreenManager.h"
namespace DinoSP {

    class ScreenManager;
    class Game {
    private:
        bool running = true;
        ScreenManager* screenManager;
    public:
        Game();
        ~Game();

        void quit();

        bool init();

        void run();

        void render();

        void update();

        // Things that need to update after render
        void lateUpdate();


        friend void g_quit(Game* game);
    };

} // DinoSP

#endif //DINO_GAME_H
