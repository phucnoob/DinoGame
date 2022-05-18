//
// Created by laplace on 5/9/22.
//

#include "Texture.h"
#include "utils/Graphics.h"


DinoSP::Texture::~Texture() {
    if (image == nullptr) {
        return;
    }
    SDL_DestroyTexture(image);
    image = nullptr;
}

DinoSP::Texture::Texture(const string &path){
    this->image = Graphics::Instance()->loadTexture(path.c_str());
    // Load size
    this->cliped = false;
    SDL_QueryTexture(this->image, nullptr, nullptr, &desRect.w, &desRect.h);
}

void DinoSP::Texture::render() {
    render(0,0);
}

void DinoSP::Texture::update() {

}

DinoSP::Texture::Texture(SDL_Texture *image) {
    this->image = image;
    // size
    this->cliped = false;
    SDL_QueryTexture(this->image, nullptr, nullptr, &desRect.w, &desRect.h);
}

DinoSP::Texture::Texture() {

}

void DinoSP::Texture::render(int x, int y) {

    SDL_Rect custom = {x, y, desRect.w, desRect.h};
    if(cliped) {
//        SDL_RenderCopy(renderer, image, &srcRect, &custom);
        Graphics::Instance()->drawTexture(image, srcRect, custom);
    } else {
        Graphics::Instance()->drawTexture(image, srcRect, custom);
    }
}

DinoSP::Texture::Texture(const string &path, const SDL_Rect &clipRect) {
    this->image = Graphics::Instance()->loadTexture(path.c_str());
    // cliped
    this->cliped = true;
    this->srcRect = clipRect;
    this->desRect = {0,0, clipRect.w, clipRect.h };

}

void DinoSP::Texture::render(Vector2 pos){
    render(pos.x, pos.y);
}

DinoSP::Texture& DinoSP::Texture::operator=(DinoSP::Texture other) {

    swap(*this, other);

    return *this;
}

DinoSP::Texture::Texture( DinoSP::Texture& other) {
    swap(*this, other);
}

void DinoSP::swap( DinoSP::Texture &first, DinoSP::Texture &second) {
    // Avoid call to this swap
    using std::swap;

    swap(first.image, second.image);
    swap(first.srcRect, second.srcRect);
    swap(first.desRect, second.desRect);
    swap(first.cliped, second.cliped);
}



