#ifndef CPPPROJECT_KING_H
#define CPPPROJECT_KING_H

#include "../Figure.h"
#include "../Field.h"
#include "../Checkboard.h"

/**
 * @brief Třída reprezentující krále.
 */
class King: public Figure {
public:
    King (bool white, Field position, Checkboard *checkboard);

    bool isMovePossible(Field field);
};


#endif //CPPPROJECT_KING_H
