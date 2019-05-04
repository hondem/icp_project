#ifndef CPPPROJECT_QUEEN_H
#define CPPPROJECT_QUEEN_H

#include "../Figure.h"
#include "../Field.h"
#include "../Checkboard.h"

/**
 * @brief Třída reprezentující dámu.
 */
class Queen: public Figure {
public:
    Queen (bool white, Field position, Checkboard *checkboard);

    bool isMovePossible(Field field);
};


#endif //CPPPROJECT_QUEEN_H
