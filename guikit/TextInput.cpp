//
// Created by laplace on 5/16/22.
//

#include "TextInput.h"

namespace DinoSP {

    map<string, TextInput*> TextInput::inputs {};
    void TextInput::addText(string text) {
        // default font
        Font font1(Constants::main_font, 16);

        if (this->text.empty()) {
            this->textTxt = new DynamicText(text, *font);
            this->text.append(text);
        }
        else {
            this->text = this->text.append(text);
            this->textTxt->changeText(this->text);
        }
    }

    TextInput::TextInput(Font& font) {
        this->font = &font;
        this->text = string();
        // default
        this->width = 200;
        this->height = 24;
    }

    void TextInput::render() {
        render(this->pos);
    }

    void TextInput::update() {
        BaseButton::update();
        if (isClick()) {
            focus = true;
        }

        lostFocus();
    }

    TextInput::~TextInput() {
        delete textTxt;
    }

    void TextInput::render(int x, int y) {
        renderBorder();

        if (this->textTxt == nullptr) return; // empty string

        this->textTxt->render(x + 4, y + 4); // padding to center Text
    }

    void TextInput::render(Vector2 pos) {
        render(pos.x, pos.y);
    }


    TextInput::TextInput(Font &font, int width, int height, string name)
    : font(&font), width(width), height(height)  {
        inputs.insert({name, this});
    }

    void TextInput::renderBorder() {
        if (focus) {
            Graphics::Instance()->drawRect(
                    {this->pos.x, this->pos.y, this->width, this->height },
                    focusColor
                    );

        } else {
            Graphics::Instance()->drawRect(
                    {this->pos.x, this->pos.y, this->width, this->height },
                    normalColor
            );
        }
    }

    void TextInput::removeText() {

        if (text.empty()) {
            return;
        }

        this->text.pop_back();
        if (text.empty()) {
            // if text is empty, delete texture to skip rendering
            delete textTxt;
            textTxt = nullptr;
        } else {
            textTxt->changeText(this->text);
        }
    }

    int TextInput::getWidth() {
        return width;
    }

    int TextInput::getHeight() {
        return height;
    }

    bool TextInput::lostFocus() {
        // if not being hover and click means no focus
        if (!isHover()) {
            if (InputManager::Instance()->mouseLeftClick()) {
                focus = false;
            }
        }
        return false;
    }

    string TextInput::getValue() {
        return this->text;
    }

    TextInput *TextInput::getByName(string name) {
        return inputs[name];
    }
} // DinoSP