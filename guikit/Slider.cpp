//
// Created by laplace on 5/18/22.
//

#include "Slider.h"
#include "utils/Utils.h"

namespace DinoSP {
    int Slider::getWidth() {
        return this->sliderBar.w;
    }

    int Slider::getHeight() {
        return this->sliderBar.h;
    }

    void Slider::update() {
        BaseButton::update();

        if (isClick()) {
            isFocus = true;
        }
        lostFocus();

        listenEvent();
    }

    Slider::Slider(int width, int height, Vector2 pos) {
        setPos(pos);
        this->sliderBar = {pos.x, pos.y, width, height};
        this->innerBar = {pos.x + 2, pos.y + 2, width - 4, height - 4};

        maxValue = 100; // default
        value = 0;
    }

    void Slider::render() {
        drawThickBorder();
        if (isFocus) {
            Graphics::Instance()->drawRect(this->sliderBar, focusColor);
        } else {
            Graphics::Instance()->drawRect(this->sliderBar, normalColor);
        }
        Graphics::Instance()->fillRect(this->innerBar, innerColor);

    }

    void Slider::drawThickBorder() {
        for (int i = 0; i < 2; ++i) {
            SDL_Rect tmp = { sliderBar.x - i, sliderBar.y - i, sliderBar.w + 2 * i , sliderBar.h + 2 * i};
            if (isFocus) {
                Graphics::Instance()->drawRect(tmp, focusColor);
            } else {
                Graphics::Instance()->drawRect(tmp, normalColor);
            }
        }
    }

    bool Slider::lostFocus() {
        // if not being hover and click means no focus
        if (!isHover()) {
            if (InputManager::Instance()->mouseLeftClick()) {
                isFocus = false;
            }
        }
        return false;
    }

    void Slider::listenEvent() {
        if (!isFocus) return;
        InputManager* input = InputManager::Instance();
        if (input->keyDown(SDL_SCANCODE_RIGHT)) {
            setValue(value + 1);
        }

        if (input->keyDown(SDL_SCANCODE_LEFT)) {
            setValue(value - 1);
        }
        Vector2 mousePos = input->getMousePos();
        if (Utils::mouseInRect(mousePos, this->sliderBar) && input->mouseLeftClick()) {
            int val = ((mousePos.x - pos.x) * 1.0f / sliderBar.w) * maxValue + 4;
            setValue(val);
            lostFocus();
        }
    }

    void Slider::setValue(int _val) {
        if (_val > maxValue || _val <  0) {
            return;
        }

        this->value = _val;
        this->innerBar.w = (this->value * 1.0f / maxValue) * ( sliderBar.w - 4);
    }

    void Slider::setMaxValue(int _val) {
        if (_val <= 0) return;

        this->maxValue = _val;
    }

    int Slider::getValue() {
        return value;
    }
} // DinoSP