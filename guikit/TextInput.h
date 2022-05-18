//
// Created by laplace on 5/16/22.
//

#ifndef DINO_TEXTINPUT_H
#define DINO_TEXTINPUT_H

#include "utils/Graphics.h"
#include "guikit/Texture.h"
#include "input/InputManager.h"
#include "text/StaticText.h"
#include "text/DynamicText.h"
#include "BaseButton.h"

namespace DinoSP {

    class TextInput: public BaseButton {
    private:
        static map<string, TextInput*> inputs;
        bool focus = false;
        // default
        SDL_Color normalColor { 83, 83, 83, 255 };
        SDL_Color focusColor {160, 160, 160, 255 };
        string text;
        int width, height;
        DynamicText *textTxt = nullptr;

        Font* font = nullptr;

        string name {};
    protected:
        void renderBorder();
        bool lostFocus();
    public:
        TextInput( Font& font);
        TextInput( Font& font, int width, int height, string name = "None");
        void render();

        void render(int x,int y);
        void render(Vector2 pos);
        void update() override;
        void addText(string text);
        // backspace handle
        void removeText();

        ~TextInput();
        int getHeight() override;
        int getWidth() override;
        // get current text
        string getValue();

        static TextInput* getByName(string name);
    };

} // DinoSP

#endif //DINO_TEXTINPUT_H
