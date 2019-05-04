#ifndef CPPPROJECT_PAWN_H
#define CPPPROJECT_PAWN_H

#include "../Figure.h"
#include "../Field.h"
#include "../Checkboard.h"

/**
 * Třída reprezentující Pěšce
 */
class Pawn : public Figure {
public:
    Pawn(bool white, Field position, Checkboard *checkboard);

    bool isMovePossible(Field field);
};


#endif //CPPPROJECT_PAWN_H
