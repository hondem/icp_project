#include "Figure.h"


Figure::Figure(bool white, Field position) {
    this->whiteColor = white;
    this->position = position;
}

bool Figure::isWhite() {
    return this->whiteColor;
}

bool Figure::isMovePossible(Field field) {
    return false;
};
