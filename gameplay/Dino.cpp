//
// Created by laplace on 5/12/22.
//

#include "Dino.h"
#include "constants/Constants.h"
#include "audio/AudioManager.h"

namespace DinoSP {
    void Dino::handleInput() {

        if (InputManager::Instance()->keyPressed(SDL_SCANCODE_SPACE)) {
            if (jumping) // if the dino is already jump, do nothing
                return;
            jumping = true;
            vel.y = 18;
            AudioManager::playSound(Constants::spriteDef.dino.jumpSound);
        }

        ducking = false;
        if (InputManager::Instance()->keyDown(SDL_SCANCODE_DOWN)) {
            if (jumping) return;
            ducking = true;
        }
    }

    void Dino::update() {
        handleInput();

        if (died) {
            return;
        }
        // pauseGame animation when jump
        if (! jumping) {
            normalTxt->update();
        }


        if (ducking) {
            duckTxt->update();
            pos.y = Constants::dino_init_pos.y + (normalTxt->getHeight() - duckTxt->getHeight()) ;
            updateHitbox();
            // no jump when duckTxt
            return;
        }

        if (jumping) {
            pos.y -= vel.y;
            vel.y -= 1;

            if (vel.y < -10) {
                vel.y -= 1;
            }
        }

        // hit ground
        if(pos.y > Constants::dino_init_pos.y) {
            jumping = false;
            vel.y = 0;
            pos.y = Constants::dino_init_pos.y;
            hitBox.y = pos.y + padding;
        }
        updateHitbox();
    }

    void Dino::render(int x, int y) {
        if (ducking) {
            duckTxt->render(x, y);
        } else if (died) {
            diedTxt->render(x, y);
        } else {
            normalTxt->render(x, y);
        }

        if (Constants::DEBUG) {
            Graphics::Instance()->drawRect(hitBox, Color::GREEN);
        }
    }

    void Dino::render() {
        render(pos.x, pos.y);
    }

    Dino::Dino()
    {
        #define dino Constants::spriteDef.dino
        normalTxt = new AnimationTexture(Constants::sheet, dino.rect, dino.frameCount, 500);

        duckTxt = new AnimationTexture(Constants::sheet, dino.duck.rect, dino.duck.frameCount, 500);
        diedTxt = new Texture(Constants::sheet, dino.died);
        updateHitbox();
        #undef dino
    }

    Vector2 Dino::getPos() {
        return pos;
    }

    void Dino::setPos(Vector2 _pos) {
        pos = _pos;
        updateHitbox();
    }

    Dino::Dino(string path, SDL_Rect clipRect, uint64_t frameCount, uint64_t duration)
    {
        #define dino Constants::spriteDef.dino
        normalTxt = new AnimationTexture(path, clipRect, frameCount, duration);
        duckTxt = new AnimationTexture(path, dino.duck.rect, dino.duck.frameCount, duration);
        diedTxt = new Texture(path, dino.died);
        updateHitbox();
        #undef dino

    }

    void Dino::updateHitbox() {
        hitBox = { pos.x + padding, pos.y ,  getWidth() - padding * 2, getHeight() - padding };
    }

    int Dino::getHeight() {
        if (ducking) {
            return duckTxt->getHeight();
        } else {
            return normalTxt->getHeight();
        }
    }

    int Dino::getWidth() {
        if (ducking) {
            return duckTxt->getWidth();
        } else {
            return normalTxt->getWidth();
        }
    }

    Dino::~Dino() {
        delete normalTxt;
        delete diedTxt;
        delete duckTxt;
    }

    void Dino::gameOver() {
        died = true;
        AudioManager::playSound(Constants::sounds.death);
    }

    void Dino::reset() {
        died = false;
    }


} // DinoSP