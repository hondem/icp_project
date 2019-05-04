#ifndef CPPPROJECT_BISHOP_H
#define CPPPROJECT_BISHOP_H

#include "../Figure.h"
#include "../Field.h"
#include "../Checkboard.h"

/**
 * @brief Třída reprezentující střelce
 */
class Bishop : public Figure {
public:
    Bishop(bool white, Field position, Checkboard *checkboard);

    bool isMovePossible(Field field);
};


#endif //CPPPROJECT_BISHOP_H
