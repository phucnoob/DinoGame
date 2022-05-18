//
// Created by laplace on 5/10/22.
//

#ifndef DINO_VECTOR2_H
#define DINO_VECTOR2_H

namespace DinoSP {
    struct Vector2 {
        int x, y;

        inline Vector2(int x, int y) {
            this->x = x;
            this->y = y;
        };

        inline Vector2(): Vector2(0,0) {

        }

        Vector2 operator+ (const Vector2& rhs ) const {
            return {this->x + rhs.x, this->y + rhs.y};
        }

        Vector2 operator- (const Vector2& rhs ) const {
            return {this->x - rhs.x, this->y - rhs.y};
        }

        Vector2 operator* (float number) const {
            return {static_cast<int>(this->x * number),
                    static_cast<int>(this->y * number) };
        }

    };
}

#endif //DINO_VECTOR2_H
