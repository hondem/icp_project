/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#ifndef CPPPROJECT_QUEEN_H
#define CPPPROJECT_QUEEN_H

#include "../Figure.h"
#include "../Field.h"
#include "../Checkboard.h"

/**
 * @brief Class representing a queen
 */
class Queen : public Figure {
public:
    Queen(bool white, Field position, Checkboard *checkboard);

    bool isMovePossible(Field field);

    char *getFigureImage();
};


#endif //CPPPROJECT_QUEEN_H
