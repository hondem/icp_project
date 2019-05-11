#include "Bishop.h"
#include "string.h"

Bishop::Bishop(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {
    if (white) {
        strcpy(this->figureImg, "Chess_blt45.png");
    } else {
        strcpy(this->figureImg, "Chess_bdt45.png");
    }
}

bool Bishop::isMovePossible(Field field) {
    (void) field;
    return false;
}