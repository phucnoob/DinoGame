//
// Created by laplace on 5/10/22.
//

#include "StartScreen.h"
#include "utils/Graphics.h"
#include "GameScreen.h"
#include "OptionsScreen.h"

void DinoSP::StartScreen::render() {
    Screen::render();
    Graphics::Instance()->drawBackGround({255, 255, 255, 255});
    background->render();
    play->render();
    option->render();
    exit->render();
    leaderboard->render();
    input->render();
    Graphics::Instance()->render();
}

DinoSP::StartScreen::StartScreen(ScreenManager* mgr)
: Screen(mgr) {
    background = new Texture(Constants::background_image);
    play = new Button(buttons[0].first);
    play->setPos(buttons[0].second);

    option = new Button(buttons[1].first);
    option->setPos(buttons[1].second);

    exit = new Button(buttons[2].first);
    exit->setPos(buttons[2].second);

    leaderboard = new Leaderboard();

    this->font = new Font(Constants::main_font, 16);
    input = new TextInput(*font, 200, 24, "username");
    input->setPos({156, 375});
    SDL_StartTextInput();
}

DinoSP::StartScreen::~StartScreen() {
    // Giải phóng bộ nhớ
    delete play;
    delete option;
    delete exit;
    delete background;
    delete input;
}

void DinoSP::StartScreen::update() {
    Screen::update();
    play->update();
    option->update();
    exit->update();
    leaderboard->update();
    input->update();
    processButton();
}

void DinoSP::StartScreen::processButton() {
    if (exit->isClick()) {
        SDL_StopTextInput();
        manager->quit();
        return; // Chỉ thực thi 1 lệnh ( tránh chlick 2 button cùng lúc)
    }

    if (play->isClick()) {
        SDL_StopTextInput();
        manager->changeScreen(new GameScreen(manager));
        return;
    }

    if (option->isClick()) {
        SDL_StopTextInput();
        manager->changeScreen(new OptionsScreen(manager));
    }
}

void DinoSP::StartScreen::handleEvent(const SDL_Event &event) {
    Screen::handleEvent(event);
    switch (event.type) {
        case SDL_TEXTINPUT:
            input->addText(string(event.text.text));
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_BACKSPACE:
                    input->removeText();
                    break;
                default:
                    break;
            }
            break;

    }
}


