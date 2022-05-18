//
// Created by laplace on 5/9/22.
//

#ifndef DINO_CONSTANTS_H
#define DINO_CONSTANTS_H
#include <SDL_ttf.h>
#include <iostream>
#include <array>
using std::string;
#include "Color.h"
#include "utils/Vector2.h"
using namespace std::string_literals;

namespace DinoSP {
    namespace Constants {
         const string title { "Chrome Dino" };

         constexpr int width = 800;
         constexpr int height = 400;

         constexpr bool DEBUG = false;

         const Vector2 dino_init_pos {10, 302 };
         const string main_font { "assets/fonts/PressStart2P-Regular.ttf"s };

         const string icon { "assets/icon.png"s };
         const string unicode_font { "" };

         const string sheet { "assets/sheet.png"s };

         constexpr int MAX_VEL = 13;

         constexpr SDL_Color BG { Color::WHITE };
         constexpr SDL_Color BG_NIGHT { Color::BLACK };

         const string background_image = "assets/background.png"s;

         constexpr int day_time = 200;

         struct {
             string click = "assets/sounds/click_sound_s.wav"s;
             string coin = "assets/sounds/coin_sound.wav"s;
             string death = "assets/sounds/dealth_sound.wav"s;
         } sounds;

         struct  {
             const string filename { "score.csv" };
             const string author { "laplace" };
             const string org { "uet" };
         } config;

         struct {
             struct {
                 string path = "assets/buttons/play.png"s;
                 SDL_Rect rect {35, 2, 34, 33 };
             } pause;

             struct {
                 string path = "assets/buttons/music.png"s;
                 SDL_Rect rect {0, 0, 32, 32 };
             } musicSetting;

             struct {
                 string path = "assets/buttons/change.png"s;
                 SDL_Rect rect {0, 0, 72, 26};
             } change;

             struct {
                 string path = "assets/buttons/exit_arrow.png";
                 SDL_Rect rect {0, 0, 32, 32};
             } exit;
         } buttons;

         struct {
             struct {
                 SDL_Rect rect {1678, 2, 88, 94};
                 int frameCount = 4;
                 string jumpSound = "assets/sounds/jump_sound.wav"s;

                 struct {
                     SDL_Rect rect {2205, 35, 118, 62};
                     int frameCount = 2;
                 } duck;

                 SDL_Rect died = { 2030, 2, 88, 94 };

             } dino;


             SDL_Rect start { 2, 2, 72, 64 };
             SDL_Rect cloud {166, 2, 92, 27};
             SDL_Rect road {2, 100, 2402, 30};
             SDL_Rect gameover {1293, 27, 384, 25 };

             std::array<SDL_Rect, 6 > cactus = {
                     SDL_Rect {446, 2, 34, 70},
                     SDL_Rect {480, 2, 68, 70},
                     SDL_Rect {548, 2, 102, 70},
                     SDL_Rect {652, 2, 50, 100},
                     SDL_Rect {702, 2, 100, 100},
                     SDL_Rect {802, 2, 150, 100}
             };

             struct {
                 SDL_Rect rect { 260, 2, 92, 82};
                 int frameCount = 4;
             } ptero;

         } spriteDef;

    };

} // DinoSP

#endif //DINO_CONSTANTS_H
