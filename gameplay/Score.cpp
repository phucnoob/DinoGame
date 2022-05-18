//
// Created by laplace on 5/11/22.
//

#include "Score.h"
#include "utils/Utils.h"

namespace DinoSP {
    Score::Score(const Font& font) {
        this->hiScore = make_unique<DynamicText>("HI 00000"s, font);
        this->currentScore = make_unique<DynamicText>("0"s, font);
//        this->currentScore->changeColor(Color::GRAY);
    }

    void Score::updateHiScore() {
        if (score.hiScore < score.currentScore) {
            score.hiScore = score.currentScore;

            string hiStr = to_string(score.hiScore);
            Utils::padding(hiStr, 5, '0');

            hiScore->changeText("HI " + hiStr);
        }
    }

    void Score::update(float time) {

        score.currentScore += time * score.SCORE_RATIO;
        score.currentScoreInt = (uint)( score.currentScore);
        string text = to_string(score.currentScoreInt);

        // padding 0
        Utils::padding(text, 5, '0');

        currentScore->changeText(text);

        if (score.currentScoreInt > 0 &&
            score.currentScoreInt % SCORE_SOUND_INTERVAL == 0 &&
            score.currentScore - score.currentScoreInt < (5.0f / SCORE_SOUND_INTERVAL )) { // frame time, to it work properly
            AudioManager::playSound(Constants::sounds.coin);
            effectCounter = 50;
        }

        if (effectCounter > 0) {
            effectCounter --;
        }
    }

    void Score::render() {
        render(pos.x, pos.y);
    }

    void Score::setPos(Vector2 _pos) {
        this->pos = _pos;
    }

    void Score::render(int x, int y) {

        hiScore->render(x, y);

        if (effectCounter & 16) return;
        currentScore->render(x + hiScore->getWidth() + HISCORE_PADDING, y);
    }

    void Score::reset() {
        currentScore->changeText("00000"s);
        score.currentScore = 0;
        score.currentScoreInt = 0;
    }

    uint Score::getScore() {
        return (uint) ( score.currentScore );
    }

    uint Score::getHiscore() {
        return score.hiScore;
    }
} // DinoSP