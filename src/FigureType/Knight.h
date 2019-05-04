#ifndef CPPPROJECT_KNIGHT_H
#define CPPPROJECT_KNIGHT_H

#include "../Figure.h"
#include "../Field.h"
#include "../Checkboard.h"

/**
 * Třída reprezentující jezdce
 */
class Knight : public Figure {
public:
    Knight(bool white, Field position, Checkboard *checkboard);

    bool isMovePossible(Field field);
};


#endif //CPPPROJECT_KNIGHT_H
