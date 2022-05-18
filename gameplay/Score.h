//
// Created by laplace on 5/11/22.
//

#ifndef DINO_SCORE_H
#define DINO_SCORE_H

#include <memory>
#include "text/StaticText.h"
#include "text/DynamicText.h"
#include "audio/AudioManager.h"

using std::unique_ptr;
using std::make_unique;
using namespace std::string_literals;

namespace DinoSP {

    class Score {

    private:
        Vector2 pos;

        const int HISCORE_PADDING = 20;
        const int SCORE_SOUND_INTERVAL = 100;
        struct {
            int64_t hiScore = 0;
            float currentScore = 0;
            int currentScoreInt = 0;

            const uint SCORE_RATIO = 8;
        } score;

        int effectCounter = 0;

    public:
        unique_ptr<DynamicText> hiScore;
        unique_ptr<DynamicText> currentScore;
        Score(const Font &font);

        void updateHiScore();
        // Update base on time passed( milisecond )
        void reset();
        void update(float time);
        void render();
        void render(int x, int y);

        void setPos(Vector2 _pos);

        uint getScore();
        uint getHiscore();

    };

} // DinoSP

#endif //DINO_SCORE_H
