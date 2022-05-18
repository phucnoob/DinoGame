//
// Created by laplace on 5/10/22.
//

#ifndef DINO_STARTSCREEN_H
#define DINO_STARTSCREEN_H

#include "screen/Screen.h"
#include "constants/Constants.h"
#include "guikit/Texture.h"
#include "guikit/Button.h"
#include "guikit/TextInput.h"
#include "gameplay/Leaderboard.h"

#include <array>
using std::array;

namespace DinoSP {
    class StartScreen : public Screen {
        Texture *background;

        // leader board
        // Save and export 5, hi score
        Leaderboard* leaderboard;
        // controls
        Button* play;
        Button* option;
        Button* exit;

        TextInput* input = nullptr;
        Font* font = nullptr;

        array<pair<string, Vector2>, 3> buttons {
                pair<string, Vector2> { "assets/buttons/play_.png", {585, 188}},
                pair<string, Vector2> { "assets/buttons/option.png", {585, 259}},
                pair<string, Vector2> { "assets/buttons/exit.png", {585, 330}}
        };

    public:
        // Load dữ liệu hiscore
        // Load dạng csv <tên>,<điểm số>
        void loadLeaderBoard();

        void update() override;
        void processButton();
        void render() override;
        explicit StartScreen(ScreenManager* mgr);

        // input event
        void handleEvent(const SDL_Event &event) override;

        ~StartScreen() override;
    };
};

#endif //DINO_STARTSCREEN_H
