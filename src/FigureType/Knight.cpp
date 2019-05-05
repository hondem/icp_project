#include "Knight.h"

Knight::Knight(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {

}

bool Knight::isMovePossible(Field field) {
    (void) field;

    return false;
}
