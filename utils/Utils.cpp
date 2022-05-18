//
// Created by laplace on 5/14/22.
//

#include <fstream>
#include "Utils.h"

namespace DinoSP {
    bool Utils::Color_Equal(SDL_Color a, SDL_Color b) {
        return (a.r == b.r) &&  (a.g == b.g) && (a.b == b.b) && (a.a == b.a);
    }

    void Utils::padding(string& text, int length, char pad) {
        string paded(length, pad);
        text = paded.substr(0, paded.length() - text.length()).append(text);
    }

    bool Utils::mouseInRect(Vector2 mousePos, SDL_Rect rect) {
        SDL_Point p {mousePos.x, mousePos.y };
        return SDL_PointInRect(&p, &rect);
    }

    std::vector<std::pair<string, int>> Utils::readHiScore(string path) {
        vector<std::pair<string, int>> hiscores;
        std::ifstream file(path.c_str());
        // read data
        string line;
        string name;
        int age;
        while (getline(file, line)) {
            int index = line.find(',');
            name = line.substr(0, index);
            age = stoi(line.substr(index + 1, line.length() - index));

            hiscores.emplace_back(name, age);
        }
        file.close();

        return hiscores;
    }
} // DinoSP