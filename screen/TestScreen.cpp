//
// Created by laplace on 5/10/22.
//

#include "TestScreen.h"
#include "guikit/Texture.h"
#include "SDL2_gfxPrimitives.h"
#include "guikit/BaseButton.h"

namespace DinoSP {
    TestScreen::TestScreen() : Screen() {
        this->name = "test";
        button = new ToogleButton("assets/buttons/button_test.png", {0,0, 137, 64 });
        button->setPos({10, 10});
//
        wings = new AnimationTexture("/home/laplace/Downloads/wings.png",
                                     {0, 0, 64, 64}, 4, 500 );

        text = new Texture("/home/laplace/Downloads/wings.png");

        siler = new Slider(200, 24, {100, 100});
    }

    void TestScreen::render() {
        Screen::render();
        Graphics::Instance()->drawBackGround(Constants::BG);
        siler->update();
        siler->render();
        Graphics::Instance()->render();
    }

    void TestScreen::update() {

    }
} // DinoSP