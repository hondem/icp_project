#ifndef CPPPROJECT_KING_H
#define CPPPROJECT_KING_H

#include "../Figure.h"
#include "../Field.h"
#include "../Checkboard.h"

/**
 * @brief Class representing a king
 */
class King : public Figure {
public:
    King(bool white, Field position, Checkboard *checkboard);

    bool isMovePossible(Field field);

private:
    /**
     * @brief Checks whether field is 'dangerous'
     * @param field
     * @return
     */
    bool checkIfFieldIsAttacked(Field field);
};


#endif //CPPPROJECT_KING_H
