//
// Created by laplace on 5/10/22.
//

#include "GameScreen.h"
#include "audio/AudioManager.h"
#include "TestScreen.h"
#include "utils/Utils.h"
#include "guikit/TextInput.h"
#include <filesystem>
#include <fstream>
#include <algorithm>

namespace fs = std::filesystem;

namespace DinoSP {
    GameScreen::GameScreen(ScreenManager* mgr) :
    Screen( mgr)
    {

        this->road = new Road(Constants::sheet, Constants::spriteDef.road);
        road->setPos(Vector2 (0, Constants::height - road->getHeight() ));

        this->font = new Font (Constants::main_font, 20 );

        this->score = new Score ( *font );
        this->score->setPos({500, 20});

        this->cloud = new Cloud(Constants::sheet, Constants::spriteDef.cloud);

        this->enemyManager = new EnemyManager();


        this->dino = new Dino();

        this->dino->setPos(Constants::dino_init_pos);

        this->gameoverText = new Texture(Constants::sheet, Constants::spriteDef.gameover);
        this->restartBtn = new Texture(Constants::sheet, Constants::spriteDef.start);

        this->pauseBtn = new ToogleButton(Constants::buttons.pause.path ,Constants::buttons.pause.rect);
        this->pauseBtn->setPos({10, 10});

        this->musicBtn = new ToogleButton(Constants::buttons.musicSetting.path,
                                          Constants::buttons.musicSetting.rect);
        this->musicBtn->setPos({pauseBtn->getPos().x + pauseBtn->getWidth() + 4, pauseBtn->getPos().y});

        AudioManager::playMusic("assets/sounds/background.mp3");

    }

    void GameScreen::render() {

        drawBackground(this->bg);
        road->render();
        enemyManager->render();
        cloud->render();
        dino->render();
        score->render();
        pauseBtn->render();
        musicBtn->render();

        if (dinoDied) {
            gameoverText->render(
                    (Constants::width - gameoverText->getWidth()) / 2,
                    (Constants::height - gameoverText->getHeight()) / 2  - 75
                    );
            restartBtn->render(
                    (Constants::width - restartBtn->getWidth()) / 2,
                    (Constants::height - restartBtn->getHeight()) / 2
                    );
        }

        Graphics::Instance()->render();
    }


    void GameScreen::update() {

        // dino died = no update screen
        if (dinoDied)
        {
            if (respawnTime > 0) {
                respawnTime -= timePassed;
                return;
            }
            if (InputManager::Instance()->keyPressed(SDL_SCANCODE_SPACE)) {
                resetGame();
            }
            return;
        }
        handleButtonEvent();

        if (paused)
            return;
        Screen::update();
        score->update(timePassed);
        road->move();
        enemyManager->moveEnemies(road->vel);
        cloud->update();
        dino->update();
        enemyManager->update(timePassed);

        handleColison();
        handleChangeDayLight();
    }

    GameScreen::~GameScreen() {
        delete road;
        delete font;
        delete score;
        delete cloud;
        delete enemyManager;
        delete dino;
        delete pauseBtn;
        delete musicBtn;
    }

    void GameScreen:: pauseGame() {
        paused = true;
        AudioManager::pauseMusic();
    }

    void GameScreen::resumeGame() {
        paused = false;
        AudioManager::resumeMusic();
    }

    void GameScreen::handleGameOver() {
        respawnTime = 0.2; // delay
        dino->gameOver();
        Timer::paused();
        dinoDied = true;
        AudioManager::pauseMusic();
    }

    void GameScreen::resetGame() {
        dinoDied = false;
        this->bg = Constants::BG;
        AudioManager::resumeMusic();
        AudioManager::playSound(Constants::spriteDef.dino.jumpSound);
        Timer::resume();
        dino->reset();
        score->updateHiScore();
        score->reset();
        road->reset();
        enemyManager->reset();
    }

    void GameScreen::lostFocus() {
        pauseGame();
    }

    void GameScreen::gainFocus() {
        resumeGame();
    }

    bool GameScreen::changeNightBackground() {
        #define change 5
        if (this->bg.r > Constants::BG_NIGHT.r) {
            this->bg.r -= change;
        }
        if (this->bg.g > Constants::BG_NIGHT.g) {
            this->bg.g -= change;
        }
        if (this->bg.b > Constants::BG_NIGHT.b) {
            this->bg.b -= change;
        }
        #undef change

        if (Utils::Color_Equal(this->bg, Constants::BG_NIGHT)) {
            isNight = true;
            return false;
        }

        return true;
    }

    bool GameScreen::changeDayBackground() {

        #define change 5
        if (this->bg.r < Constants::BG.r) {
            this->bg.r += change;
        }
        if (this->bg.g < Constants::BG.g) {
            this->bg.g += change;
        }
        if (this->bg.b < Constants::BG.b) {
            this->bg.b += change;
        }
        #undef change

        if (Utils::Color_Equal(this->bg, Constants::BG)) {
            isNight = false;
            return false;
        }

        return true;
    }

    bool GameScreen::changeBackGround() {
        if (isNight) {
            return changeDayBackground();
        } else {
            return changeNightBackground();
        }
    }

    void GameScreen::saveHiScore() {
        char* configPath = SDL_GetPrefPath(Constants::config.org.c_str()
                , Constants::config.author.c_str());

        fs::path config(configPath);
        config /= Constants::config.filename;
        vector<std::pair<string, int>> hiscores;

        if (fs::exists(config)) {
            hiscores = Utils::readHiScore(config.string());

            string username = TextInput::getByName("username")->getValue();

            if (username.empty()) {
                return; // if user don't enter name, don't save hi score
            }

            score->updateHiScore();
            hiscores.emplace_back(username, score->getHiscore());

            // sort reverse
            std::sort(hiscores.begin(), hiscores.end(),
                      [](const pair<string, int>& a, const pair<string, int>& b) -> bool
                      { return a.second > b.second; });

            // write data
            ofstream file(config.c_str());
            for (auto& hi: hiscores) {
                file << hi.first << "," << hi.second << endl;
            }
            file.close();
        } else {
            // create
        }
    }

    void GameScreen::quit() {
        Screen::quit();
        saveHiScore();
    }

    void GameScreen::handleButtonEvent() {
        this->musicBtn->update();
        if (this->musicBtn->isClick() || InputManager::Instance()->keyPressed(SDL_SCANCODE_M)) {
            this->musicBtn->onClick();
            muted = !muted;
            if (muted) {
                AudioManager::mute();
            } else {
                AudioManager::unMute();
            }
        }

        pauseBtn->update();
        if (pauseBtn->isClick() || InputManager::Instance()->keyPressed(SDL_SCANCODE_P)) {
            pauseBtn->onClick();
            if (paused) {
                resumeGame();
            } else {
                pauseGame();
            }
        }
    }

    void GameScreen::handleChangeDayLight() {
        if (score->getScore() > 0 && score->getScore() % Constants::day_time == 0) {
            needChange = true;
        }
        if (needChange) {
            needChange = changeBackGround();
        }
    }

    void GameScreen::handleColison() {
        // colision handling
        bool colision = enemyManager->isDinoHit(dino);
        if (colision) {
            handleGameOver();
        }
    }

} // DinoSP