#include "King.h"
#include "string.h"

King::King(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {
    if (white) {
        strcpy(this->figureImg, "Chess_klt45.png");
    } else {
        strcpy(this->figureImg, "Chess_kdt45.png");
    }
}

bool King::isMovePossible(Field field) {
    (void) field;

    return false;
}
