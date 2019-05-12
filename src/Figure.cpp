/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#include "Figure.h"


Figure::Figure(bool white, Field position, Checkboard *checkboard) {
    this->whiteColor = white;
    this->position = position;
    this->checkboard = checkboard;
}

bool Figure::isWhite() {
    return this->whiteColor;
}

Field Figure::getPosition() {
    return this->position;
}

bool Figure::isMovePossible(Field field) {
    (void) field;

    return false;
};

void Figure::setPosition(Field position) {
    this->position = position;
}
