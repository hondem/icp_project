#include "Pawn.h"

Pawn::Pawn(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {

}

bool Pawn::isMovePossible(Field field) {
    (void) field;

    return false;
}
