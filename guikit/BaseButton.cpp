//
// Created by laplace on 5/10/22.
//

#include "BaseButton.h"

namespace DinoSP {
    BaseButton::BaseButton() = default;

    void BaseButton::update() {
        clicked = InputManager::Instance()->mouseLeftClick();
        // If mouse is clicked, check is it in the button
        Vector2 mousePos = InputManager::Instance()->getMousePos();
        if(clicked) {
            if ( pos.x < mousePos.x && mousePos.x < pos.x + getWidth() &&
                 pos.y < mousePos.y && mousePos.y < pos.y + getHeight() ) {
                clicked = true;
            } else {
                clicked = false;
            }
        }

        if (    pos.x < mousePos.x && mousePos.x < pos.x + getWidth() &&
                pos.y < mousePos.y && mousePos.y < pos.y + getHeight()
                ) {
            hover = true;
        } else {
            hover = false;
        }
    }

    void BaseButton::setPos(Vector2 _pos) {
        this->pos = _pos;
    }

    Vector2 BaseButton::getPos() {
        return pos;
    }

    bool BaseButton::isClick() {
        return clicked;
    }

    bool BaseButton::isHover() {
        return hover;
    }

    int BaseButton::getWidth() {
        return 0;
    }

    int BaseButton::getHeight() {
        return 0;
    }
} // DinoSP