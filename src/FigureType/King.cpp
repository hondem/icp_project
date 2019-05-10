#include "King.h"
#include "string.h"

King::King(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {
    strcpy(this->figureImg, "Chess_klt45.png");
}

bool King::isMovePossible(Field field) {
    (void) field;

    return false;
}
