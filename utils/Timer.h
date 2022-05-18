//
// Created by laplace on 5/10/22.
//

#ifndef DINO_TIMER_H
#define DINO_TIMER_H
#include <SDL.h>

namespace DinoSP {
    // Return time in milisecond

    class Timer {

    private:
        static uint64_t lastTime;
        static uint64_t delta;
        static bool isPause;
    public:
        static constexpr float TO_SECOND = 1000.0f;
        static void reset();
        static void update();
        static uint64_t deltaTime();
        static float deltaTimeInSecond();

        static void paused();
        static void resume();
    };

} // DinoSP

#endif //DINO_TIMER_H
