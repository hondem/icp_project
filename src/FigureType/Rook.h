#ifndef CPPPROJECT_ROOK_H
#define CPPPROJECT_ROOK_H

#include "../Figure.h"
#include "../Field.h"
#include "../Checkboard.h"

/**
 * @brief Třída reprezentující Věž
 */
class Rook : public Figure {
public:
    Rook(bool white, Field position, Checkboard *checkboard);

    bool isMovePossible(Field field);
};


#endif //CPPPROJECT_ROOK_H
