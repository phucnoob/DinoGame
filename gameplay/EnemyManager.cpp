//
// Created by laplace on 5/12/22.
//

#include "EnemyManager.h"
#include "utils/Random.h"

namespace DinoSP {

    void EnemyManager::update() {
        removeEnemy();
    }

    void EnemyManager::render() {
        for (auto& item: allCactus) {
            item->render();

            if (Constants::DEBUG) {
                Graphics::Instance()->drawRect(item->hitBox, Color::RED);
            }
        }

        for (auto& item: allPtero) {
            item->render();
            item->update();

            if (Constants::DEBUG) {
                Graphics::Instance()->drawRect(item->hitBox, Color::RED);
            }
        }
    }

    EnemyManager::~EnemyManager() {
        reset();
    }

    void EnemyManager::randCactus() {

        #define cactus Constants::spriteDef.cactus
        SDL_Rect tmpCactusRect;
        if (firstCase) { // on first case, don't spawn big cactus
            tmpCactusRect = cactus[Random::random(0, cactus.size() - 2)];
            firstCase = false;
        } else {
            tmpCactusRect = cactus[Random::random(0, cactus.size() - 1)];
        }

        // Random catus image
        auto* tmpCactus = new Cactus(Constants::sheet, tmpCactusRect);


        // Random cactus pos
        int lastPos = Constants::width; // Init
        if (!allCactus.empty()) {
            lastPos = max(allCactus.back()->getPos().x, lastPos);
        }
        Vector2 randPos { Random::random(lastPos , lastPos + Constants::width ),
                          Constants::height - tmpCactus->getHeight() - 4};

        tmpCactus->setPos(randPos);


        // Make sure the catus is not too close
        if (validCactus(tmpCactus)) {
            allCactus.push_back(tmpCactus);
        } else {
            delete tmpCactus;
            randCactus(); // maybe recursion hell
        }

        #undef cactus
    }



    EnemyManager::EnemyManager() {

    }

    void EnemyManager::removeEnemy() {
        {
            auto it = allCactus.begin();
            while (it != allCactus.end()) {
                if ((*it)->offScreen()) {
                    auto tmp = it;
                    it = allCactus.erase(it);
                    // free resource
                    delete *tmp;
                } else {
                    it++;
                }
            }
        }

        {
            auto it = allPtero.begin();
            while (it != allPtero.end()) {
                if ((*it)->offScreen()) {
                    auto tmp = it;
                    it = allPtero.erase(it);
                    // free resource
                    delete *tmp;
                } else {
                    it++;
                }
            }
        }
    }

    bool EnemyManager::validCactus(Cactus* cactus) {
        for (auto existCactus: allCactus) {
            if (abs(cactus->getPos().x - existCactus->getPos().x) < Constants::width / 2) {
                return false;
            }
        }

        return true;
    }



    void EnemyManager::randPtero() {

        auto ptero = new Ptero(Constants::sheet, Constants::spriteDef.ptero.rect);

        int lastPos = Constants::width; // Init
        if (!allCactus.empty()) {
            lastPos = max(allCactus.back()->getPos().x, lastPos);
        }

         Vector2 pteroPos = {Random::random(lastPos , lastPos + Constants::width)
                             , Constants::height - ptero->getHeight() * Random::random(1, 2)};

         ptero->setPos(pteroPos);

        if (validPtero(ptero)) {
            allPtero.push_back(ptero);
        } else {
            delete ptero;
        }

    }

    void EnemyManager::update(float time) {
        removeEnemy();
        localTime += time;

        if (localTime > SPAWN_INTERVAL) {
            localTime = 0;
            if (Random::random(0, 10)) {
                if (allCactus.size() < MAX_CACTUS) {
                    randCactus();
                }
            } else {
                if (allPtero.size() < MAX_PTERO) {
                    randPtero();
                }
            }
        }
    }

    bool EnemyManager::validPtero(Ptero* ptero) {
        for (auto existCactus: allCactus) {
            if (abs(ptero->getPos().x - existCactus->getPos().x) < Constants::width ) {
                return false;
            }
        }
        return true;
    }

    void EnemyManager::moveEnemies(Vector2 vel) {
        for (auto item: allCactus) {
            item->move(vel);
        }

        for (auto item: allPtero) {
            item->move(vel * 1.25);
        }
    }

    bool EnemyManager::isDinoHit(Dino *dino) {

        for(auto item: allCactus) {
            if (SDL_HasIntersection(&(item->hitBox), &(dino->hitBox)) == SDL_TRUE) {
                SDL_Log("Hit Cactus");
                return true;
            }
        }

        for(auto item: allPtero) {
            if (SDL_HasIntersection(&(item->hitBox), &(dino->hitBox)) == SDL_TRUE) {
                SDL_Log("Hit Ptero");
                return true;
            }
        }

        return false;
    }

    void EnemyManager::reset() {
        for (auto item: allCactus) {
            delete item;
        }

        for (auto item: allPtero) {
            delete item;
        }

        allCactus.clear();
        allPtero.clear();

        firstCase = true;
    }

} // DinoSP