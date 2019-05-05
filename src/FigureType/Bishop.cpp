#include "Bishop.h"

Bishop::Bishop(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {

}

bool Bishop::isMovePossible(Field field) {
    (void) field;
    return false;
}
