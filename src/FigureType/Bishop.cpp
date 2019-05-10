#include "Bishop.h"
#include "string.h"

Bishop::Bishop(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {
    strcpy(this->figureImg, "Chess_blt45.png");
}

bool Bishop::isMovePossible(Field field) {
    (void) field;
    return false;
}