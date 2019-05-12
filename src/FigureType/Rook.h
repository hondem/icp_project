/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#ifndef CPPPROJECT_ROOK_H
#define CPPPROJECT_ROOK_H

#include "../Figure.h"
#include "../Field.h"
#include "../Checkboard.h"

/**
 * @brief Class representing rook figure
 */
class Rook : public Figure {
public:
    Rook(bool white, Field position, Checkboard *checkboard);

    bool isMovePossible(Field field);
};


#endif //CPPPROJECT_ROOK_H
