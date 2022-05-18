//
// Created by laplace on 5/16/22.
//

#ifndef DINO_LEADERBOARD_H
#define DINO_LEADERBOARD_H

#include "utils/Vector2.h"
#include "utils/Graphics.h"
#include "text/StaticText.h"
#include <vector>
#include <iostream>
#include <utility>
using std::vector;
using std::string;
using std::pair;
using namespace std::string_literals;

namespace DinoSP {

    class Leaderboard {
    private:
        Vector2 pos;
        Font* font;
        vector<pair<string, int>> hiscores;

        StaticText* hiscoreText;
        StaticText* inputNote;

        vector<StaticText* > hiscoreTxt;

        static const int hiscoreWidth = 24;
        static const int MAX_HISCORE = 10;
    public:
        Leaderboard();
        void render();
        void update();
        void addHiScore(int score);
        void loadHiscore();

        static string formatHiScore(string name, int score );

        void addDummyData();

        ~Leaderboard();
    };

} // DinoSP

#endif //DINO_LEADERBOARD_H
