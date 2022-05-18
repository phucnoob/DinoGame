//
// Created by laplace on 5/9/22.
//

#ifndef DINO_TEXTURE_H
#define DINO_TEXTURE_H
#include <SDL.h>
#include <SDL_image.h>
#include "../utils/Graphics.h"
#include "../utils/Vector2.h"

namespace DinoSP {
    class Texture {

    private:
        bool cliped {false};
    protected:
        SDL_Texture* image = nullptr ;
        SDL_Rect srcRect {};
        SDL_Rect desRect {};

    public:

        inline int getX() const { return desRect.x; };
        inline int getY() const { return desRect.y; };

        inline int getWidth() const { return desRect.w; };
        inline int getHeight() const { return desRect.h; };

        // Create texture from file
        Texture(const string& path);

        // Create texture from raw sdl_texture
        Texture(SDL_Texture* image);

        //
        Texture(const string& path, const SDL_Rect& clipRect );
        Texture();
        ~Texture();

        // Copy and swap, from
        // https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
        Texture( Texture& other);
        Texture& operator=(Texture other);
        friend void swap(Texture& first,Texture& second);

        virtual void render();
        virtual void render(int x, int y);
        virtual void render(Vector2 pos);
        virtual void update();
    };

    void swap(Texture& first,Texture& second);
}



#endif //DINO_TEXTURE_H
