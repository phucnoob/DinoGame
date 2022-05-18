//
// Created by laplace on 5/10/22.
//

#ifndef DINO_BASEBUTTON_H
#define DINO_BASEBUTTON_H

#include "Texture.h"
#include "input/InputManager.h"

namespace DinoSP {
    // Class handle button behavior ( click and hover )
    // client MUST override getWidth, getHeight, update to use this class
    //  Class hỗ trợ thuộc tính của button ( click và hover )
    // Để sử dụng, cần override các phương thức getWidth, getHeight
    class BaseButton {
    protected:
        bool clicked{ false }, hover { false };
        Vector2 pos;
    public:
        BaseButton ();

        void setPos(Vector2 _pos);
        Vector2 getPos();

        virtual void update();

        bool isClick();

        virtual int getWidth();
        virtual int getHeight();

        bool isHover();
    };

} // DinoSP

#endif //DINO_BASEBUTTON_H
