#include "Knight.h"
#include "string.h"


Knight::Knight(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {
    if (white) {
        strcpy(this->figureImg, "Chess_nlt45.png");
    } else {
        strcpy(this->figureImg, "Chess_ndt45.png");
    }
}

bool Knight::isMovePossible(Field field) {
    (void) field;

    return false;
}