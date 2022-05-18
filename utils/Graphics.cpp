//
// Created by laplace on 5/9/22.
//

#include "Graphics.h"
#include "constants/Constants.h"
#include <map>
#include <SDL_mixer.h>

using namespace std::string_literals;

namespace DinoSP {
    // init static var
    SDL_Renderer* Graphics::renderer = nullptr;
    Graphics* Graphics::sInstance = nullptr;


    SDL_Texture* Graphics::loadTexture(const char* path) {

        SDL_Texture* tmpTexure = IMG_LoadTexture(ren, path);
        if(tmpTexure == nullptr) {
            throw RuntimeError("Cant load texture \n "s + SDL_GetError());
        }

        return tmpTexure;
    }


    SDL_Texture *Graphics::createText(const char *text, const Font &font, SDL_Color color) {
        SDL_Surface* oldSurface = TTF_RenderText_Blended(font.getFont(), text, color);

        if (oldSurface == nullptr) {
            throw RuntimeError("Can't not create the text"s + TTF_GetError());
        }

        SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(ren, oldSurface);

        if (tmpTexture == nullptr) {
            throw RuntimeError("Can't not create the text"s + TTF_GetError());
        }

        SDL_FreeSurface(oldSurface);
        return tmpTexture;

    }


    void Graphics::drawRect(SDL_Rect rect, SDL_Color color) {
        SDL_SetRenderDrawColor(ren, color.r, color.g ,color.b, color.a);
        SDL_RenderDrawRect(ren, &rect);
        SDL_SetRenderDrawColor(ren, Constants::BG.r, Constants::BG.g ,Constants::BG.b, Constants::BG.a);
    }

    Graphics *Graphics::Instance() {

        if (sInstance == nullptr ) {
            sInstance = new Graphics();
        }

        return sInstance;
    }


    bool Graphics::init() {
        // Init SDL
        if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0) {
            successInit = false;
            throw RuntimeError("SDL initzalize failed "s + SDL_GetError());
        }

        // Init SDL_image
        int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
        if(! (IMG_Init(imgFlags) & imgFlags)) {
            successInit = false;
            throw RuntimeError("SDL image initzalize failed "s + IMG_GetError());
        }

        // Init SDL_ttf
        if(TTF_Init() < 0) {
            successInit = false;
            throw RuntimeError("TTF initzalize failed "s + TTF_GetError());
        }

        // SDL mixxer
        int mixFlags = MIX_INIT_MP3 | MIX_INIT_OGG;
        if (!(Mix_Init(mixFlags) & mixFlags)) {
            successInit = false;
            throw RuntimeError("Mixer can't be init "s + SDL_GetError());
        }

        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
            successInit = false;
            throw RuntimeError("Can't open audio "s + Mix_GetError());
        }

        window = SDL_CreateWindow(Constants::title.c_str(),
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  Constants::width, Constants::height,
                                  SDL_WINDOW_SHOWN);

        SDL_Surface* icon = IMG_Load(Constants::icon.c_str());

        SDL_SetWindowIcon(window, icon);

        SDL_FreeSurface(icon);

        ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        // Independent with os scale
        SDL_RenderSetLogicalSize(ren, Constants::width, Constants::height);

        return successInit;
    }

    void Graphics::drawTexture(SDL_Texture *texture, SDL_Rect src, SDL_Rect rend) {
        SDL_Rect rect = {0,0,0,0};
        if (SDL_RectEquals(&src, &rect)) {
            SDL_RenderCopy(ren, texture, nullptr, &rend);
        } else {
            SDL_RenderCopy(ren, texture, &src, &rend);
        }
    }

    void Graphics::render() {
        SDL_RenderPresent(ren);
    }

    void Graphics::setColor(SDL_Color color) {

    }

    void Graphics::drawBackGround(SDL_Color bg) {
        SDL_SetRenderDrawColor(ren, bg.r, bg.g, bg.b, bg.a);
        SDL_RenderClear(ren);
        // SDL_SetRenderDrawColor(ren, )
    }

    void Graphics::darkenTexture(SDL_Texture *texture) {
        SDL_SetTextureColorMod(texture, 180,180, 180);
    }

    void Graphics::resetTexture(SDL_Texture *texture) {
        SDL_SetTextureColorMod(texture, 255,255, 255);
    }

    void Graphics::fillRect(SDL_Rect rect, SDL_Color color) {
        SDL_SetRenderDrawColor(ren, color.r, color.g ,color.b, color.a);
        SDL_RenderFillRect(ren, &rect);
        SDL_SetRenderDrawColor(ren, Constants::BG.r, Constants::BG.g ,Constants::BG.b, Constants::BG.a);
    }



} // DinoSP


