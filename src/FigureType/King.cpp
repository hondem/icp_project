#include "King.h"

King::King (bool white, Field position, Checkboard *checkboard): Figure(white, position, checkboard) {

}

bool King::isMovePossible(Field field) {
    return false;
}
