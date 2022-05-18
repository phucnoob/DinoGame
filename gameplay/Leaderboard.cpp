//
// Created by laplace on 5/16/22.
//

#include "Leaderboard.h"
#include "utils/Utils.h"
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

namespace DinoSP {
//    const int Leaderboard::hiscoreWidth = 50;
    Leaderboard::Leaderboard() {
        loadHiscore();

        font = new Font(Constants::main_font, 16);

        Font bigFont(Constants::main_font, 20);

        hiscoreText = new StaticText("HI SCORE"s, bigFont);
        inputNote = new StaticText ("Yourname: "s, *font);

        for(const auto& hiscore: hiscores) {
            string text = Leaderboard::formatHiScore(hiscore.first, hiscore.second);
            auto s = new StaticText(text, *font);
            hiscoreTxt.push_back(s);
        }

        pos = {10, 150};

    }

    void Leaderboard::render() {
        hiscoreText->render(pos.x, pos.y);
        inputNote->render(10, Constants::height - inputNote->getHeight() - 4);
//        SDL_SetS
        for (int i = 0; i < hiscoreTxt.size(); ++i) {
            hiscoreTxt[i]->render(pos.x + 10, pos.y + hiscoreText->getHeight() + 20 // padding
                                            + i * (hiscoreTxt[i]->getHeight() + 8 ));
        }
    }

    void Leaderboard::update() {

    }

    void Leaderboard::addHiScore(int score) {

    }

    void Leaderboard::loadHiscore() {
//        addDummyData();
        // get the path to store config?
        char* configPath = SDL_GetPrefPath(Constants::config.org.c_str()
                                            , Constants::config.author.c_str());

        fs::path config(configPath);
        config /= Constants::config.filename;

        if (fs::exists(fs::path(config))) {
            hiscores = Utils::readHiScore(config.string());
        } else {
            // create file
            ofstream file(config.c_str());
            file.close();
        }

        SDL_free(configPath);
    }

    Leaderboard::~Leaderboard() {
        delete font;
        delete hiscoreText;
    }

    string Leaderboard::formatHiScore(string name, int score ) {
        string scoreStr = to_string(score);
        size_t padNum = hiscoreWidth - name.length() - scoreStr.length();
        for (int i = 0; i < padNum; ++i) {
            name.append(" "s);
        }
        return name + scoreStr;
    }

    void Leaderboard::addDummyData() {
        hiscores.emplace_back("phuc", 1029283);
        hiscores.emplace_back("hau", 1234);
        hiscores.emplace_back("quang", 1124);
        hiscores.emplace_back("this is some king long", 0);
    }
} // DinoSP