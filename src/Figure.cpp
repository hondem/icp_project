#include "Figure.h"


Figure::Figure(bool white, Field position, Checkboard *checkboard) {
    this->whiteColor = white;
    this->position = position;
    this->checkboard = checkboard;
}

bool Figure::isWhite() {
    return this->whiteColor;
}

bool Figure::isMovePossible(Field field) {
    (void) field;

    return false;
};
