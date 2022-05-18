//
// Created by laplace on 5/18/22.
//

#ifndef DINO_SLIDER_H
#define DINO_SLIDER_H

#include "constants/Color.h"
#include "input/InputManager.h"
#include "BaseButton.h"

namespace DinoSP {

    class Slider : public BaseButton {
    private:

        // some default value, write more on getter and setter if i have time
        SDL_Color normalColor = {52, 152, 219, 255};
        SDL_Color focusColor = {46, 204, 113, 255};
        SDL_Rect sliderBar;
        // the bar show how much the slider is |=======   |
        SDL_Color innerColor = { Color::GRAY };
        SDL_Rect innerBar;

        bool isFocus { false };
        int value;
        int maxValue;
    public:
        Slider(int width, int height, Vector2 pos = {0, 0});
        int getWidth() override;
        int getHeight() override;
        void update() override;
        void drawThickBorder();
        void render();

        bool lostFocus();

        void listenEvent();

        void setValue(int i);

        void setMaxValue(int _val);
    };

} // DinoSP

#endif //DINO_SLIDER_H
