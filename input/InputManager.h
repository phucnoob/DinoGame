//
// Created by laplace on 5/10/22.
//

#ifndef DINO_INPUTMANAGER_H
#define DINO_INPUTMANAGER_H
#include <SDL.h>
#include "utils/Vector2.h"

// Processing keyboard
namespace DinoSP {
    class InputManager {
    private:
        InputManager();
        static InputManager* sInstance;

        Uint8* lastKeyState;
        const Uint8* currentKeyState;
        int keyStateLength {};

        Uint32 lastMouseState {};
        Uint32 mouseState {};
        Vector2 mousePos {};

    public:
        /**
         *
         * @param keycode
         * @return true if the key is press( also true when you hold key)
         */
        bool keyDown(SDL_Scancode keycode);

        /**
         *
         * @param keycode
         * @return true if key is press only in that frame ( false if you hold key)
         */
        bool keyPressed(SDL_Scancode keycode);
        /**
         *
         * @param keycode
         * @return true if key up
         */
        bool keyUp(SDL_Scancode keycode);
        /**
         * Update key state ( should be call before render )
         */
        void updateKeyState();

        /**
         * Update last state ( should be call after render )
         */
        void updatelastKeyState();

        /**
         * Update the mouse state( left click or not )
         */
        void updateMouseState();

        bool mouseLeftClick() const;

        bool mouseRightClick() const;


        Vector2 getMousePos();

        ~InputManager();

        static InputManager* Instance();
    };
}


#endif //DINO_INPUTMANAGER_H
