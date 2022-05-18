//
// Created by laplace on 5/14/22.
//

#ifndef DINO_BUTTON_H
#define DINO_BUTTON_H
#include "BaseButton.h"
#include "Texture.h"
#include "audio/AudioManager.h"
#include "constants/Constants.h"

namespace DinoSP {
    // Giải thích về đa kê thừa ( ghi lại k quên mất )
    class Button final: public BaseButton, public Texture {

        // Override lại hàm getWidth, hàm này sẽ trả về width của texture
        // Tuy nhiên, hàm isClick( thuộc BasebButton, sẽ sử dụng hàm getWidth này, do tính đa hình, ta có được
        // chiều dài của texture ( phục vụ sử lý click )
        // Hàm BaseButton::isClick không hề biết thông tin về Texture, vậy mà code 'just work' ( ảo tung chảo )

    public:
        int getWidth() override;
        int getHeight() override;

        // Xử lí UI khi bị click
        void onClick();
        // Dùng hàm update của Button ( tính toán click )
        void update() override;

        // Dùng hàm render của Texture
        void render() override;
        Button(string path, SDL_Rect clipRect);
        explicit Button(string path);

        void onHover();
    };
}


#endif //DINO_BUTTON_H
