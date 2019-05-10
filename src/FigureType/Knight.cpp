#include "Knight.h"
#include "string.h"


Knight::Knight(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {
    strcpy(this->figureImg, "Chess_nlt45.png");
}

bool Knight::isMovePossible(Field field) {
    (void) field;

    return false;
}