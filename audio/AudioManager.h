//
// Created by laplace on 5/12/22.
//

#ifndef DINO_AUDIOMANAGER_H
#define DINO_AUDIOMANAGER_H

#include <SDL_mixer.h>
#include <SDL.h>
#include <map>
#include <iostream>
using std::map;
using std::string;
using namespace std::string_literals;



namespace DinoSP {

    namespace AudioManager {
        static map<string, Mix_Chunk* > sounds {};
        static map<string, Mix_Music* > backgrounds {};

        Mix_Chunk* loadSound(string path);
        Mix_Music* loadMusic(string path);

        void playSound(string path);
        void playMusic(string path);

        void pauseMusic();
        void resumeMusic();
        void mute();
        void unMute();

        void setVolume(int vol);
    };

} // DinoSP

#endif //DINO_AUDIOMANAGER_H
