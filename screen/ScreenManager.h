//
// Created by laplace on 5/10/22.
//

#ifndef DINO_SCREENMANAGER_H
#define DINO_SCREENMANAGER_H


#include "screen/Screen.h"
#include "gameplay/Game.h"

#include <memory>
#include <stack>
#include <set>

using namespace std;
namespace DinoSP {
    class Game;
    class Screen;
    void g_quit(Game* game);
    class ScreenManager {
    private:
        set<Screen* > allScreens;
        stack<Screen* > stackFrame {};
        Screen* current = nullptr ;
        Game* game;
    public:
        explicit ScreenManager(Game* game);
        void changeScreen(Screen* screen);
        void render();
        void update();
        void goback();

        ~ScreenManager();

        void lostFocus();

        void gainFocus();

        void handleEvent(const SDL_Event& event);

        void quit();
    };

}

#endif //DINO_SCREENMANAGER_H
