//
// Created by laplace on 5/12/22.
//

#ifndef DINO_ENEMYMANAGER_H
#define DINO_ENEMYMANAGER_H

#include "guikit/Texture.h"
#include "Cactus.h"
#include "Ptero.h"
#include "Dino.h"
#include <list>

namespace DinoSP {

    class EnemyManager {
    private:
        list<Cactus*> allCactus;
        list<Ptero*> allPtero;
        float localTime = 0 ;
        bool firstCase = true;


        static constexpr float SPAWN_INTERVAL = 1.5;
        static constexpr int MAX_CACTUS { 3 };
        static constexpr int MAX_PTERO { 1 };

    public:
        EnemyManager();
        void update();
        void update(float time);
        void render();

        void randCactus();
        void randPtero();
        void moveEnemies(Vector2 vel);
        void removeEnemy();

        // Make sure the cactus not too close
        bool validCactus(Cactus * cactus);

        bool validPtero(Ptero* ptero);

        bool isDinoHit(Dino* dino);

        ~EnemyManager();

        void reset();
    };

} // DinoSP

#endif //DINO_ENEMYMANAGER_H
