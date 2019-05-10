#include "Queen.h"
#include "string.h"

Queen::Queen(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {
    strcpy(this->figureImg, "Chess_qlt45.png");
}

bool Queen::isMovePossible(Field field) {
    (void) field;

    return false;
}
