#include "Rook.h"

Rook::Rook(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {

}

bool Rook::isMovePossible(Field field) {
    return false;
}
