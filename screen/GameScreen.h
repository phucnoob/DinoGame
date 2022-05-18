//
// Created by laplace on 5/10/22.
//

#ifndef DINO_GAMESCREEN_H
#define DINO_GAMESCREEN_H

#include "Screen.h"
#include "guikit/Texture.h"
#include "guikit/BaseButton.h"
#include "constants/Constants.h"
#include "gameplay/Road.h"
#include "gameplay/Score.h"
#include "gameplay/Cloud.h"
#include "gameplay/Cactus.h"
#include "gameplay/Dino.h"
#include "gameplay/EnemyManager.h"
#include "guikit/ToogleButton.h"

namespace DinoSP {

    class GameScreen final : public Screen {
    private:
        Road* road;
        Score* score;
        Cloud* cloud;
        EnemyManager* enemyManager;
        Dino* dino;

        ToogleButton* pauseBtn;
        ToogleButton* musicBtn;

        // Game over stuff
        Texture* gameoverText;
        Texture* restartBtn;

        Font* font;

        bool paused = false;
        bool muted = false;
        bool dinoDied = false;
        float respawnTime = 0;

        // night screen

        SDL_Color bg = { Constants::BG };
        bool isNight { false };
        bool needChange { false };
    public:

        explicit GameScreen(ScreenManager* mgr);
        void render() override;
        void update() override;

        void pauseGame();
        void resumeGame();

        ~GameScreen() override;

        void handleGameOver();

        void resetGame();

        void lostFocus() override;

        void gainFocus() override;

        /**
         * Should be call every frame before done change
         * @return true if the transition is not done, false otherwise
         */
        bool changeNightBackground();

        /**
         * Should be call every frame before done change
         * @return true if the transition is not done, false otherwise
         */
        bool changeDayBackground();

        bool changeBackGround();

        void saveHiScore();

        // handle button stuff on screen
        void handleButtonEvent();
        // quit
        void quit() override;

        // handle the day/night change
        void handleChangeDayLight();

        void handleColison();
    };

} // DinoSP

#endif //DINO_GAMESCREEN_H
