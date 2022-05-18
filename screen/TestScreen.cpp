//
// Created by laplace on 5/10/22.
//

#include "TestScreen.h"
#include "guikit/Texture.h"
#include "guikit/BaseButton.h"
#include "utils/tinyfiledialogs.h"

#include <thread>

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

        SDL_CreateThread(pickFile, "test", (void*) NULL);

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

    int TestScreen::pickFile(void* ptr) {
        char const * lFilterPatterns[2] = { "*.mp3", "*.*" };
        char const * selection = tinyfd_openFileDialog( // there is also a wchar_t version
                "Select file", // title
                "./", // optional initial directory
                2, // number of filter patterns
                lFilterPatterns, // char const * lFilterPatterns[2] = { "*.txt", "*.jpg" };
                NULL, // optional filter description
                0 // forbid multiple selections
        );
        if (selection == NULL) return 1;
        AudioManager::playMusic(string(selection));

        return 0;
    }
} // DinoSP