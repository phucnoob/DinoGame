//
// Created by laplace on 5/9/22.
//

#ifndef DINO_GRAPHICS_H
#define DINO_GRAPHICS_H

#include <SDL.h>
#include <SDL_image.h>

#include "../miscellaneous/RuntimeError.h"
#include "../text/Font.h"
#include "SDL2_gfxPrimitives.h"

#include <memory>
#include <map>

using namespace std;

namespace DinoSP {

    class Graphics {
    private:
        bool successInit = false;
        static Graphics* sInstance ;

        SDL_Window* window = nullptr;
        SDL_Renderer* ren = nullptr;

    public:
        bool init();

        // Init global renderer for drawing

        static SDL_Renderer* renderer;

        static Graphics* Instance();



        // load texture from file
         SDL_Texture* loadTexture(const char* path);
         void drawRect(SDL_Rect rect, SDL_Color color);
        void fillRect(SDL_Rect rect, SDL_Color color);
        // create text texture
         SDL_Texture* createText(const char *text, const Font &font, SDL_Color color);

        void setColor(SDL_Color color);
        void drawBackGround(SDL_Color bg);
        void drawTexture(SDL_Texture* texture, SDL_Rect src, SDL_Rect rend);
        void darkenTexture(SDL_Texture* texture);
        void resetTexture(SDL_Texture* texture);
        void render();
    };

} // DinoSP

#endif //DINO_GRAPHICS_H
