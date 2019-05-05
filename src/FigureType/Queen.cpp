#include "Queen.h"

Queen::Queen(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {

}

bool Queen::isMovePossible(Field field) {
    (void) field;

    return false;
}
