/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#ifndef CHESS_COORDS_H
#define CHESS_COORDS_H

#include "Field.h"
#include <string>

struct Field;

/**
 * @brief Struct for coordinations
 */
struct Coords {
    /**
     * @brief Horizontal
     */
    char x;

    /**
     * @brief Vertical
     */
    int y;

    /**
     * @brief Converts coords string to coords
     * @param coords
     * @return
     */
    static Coords convertCoordsStringToCoords(std::string coords);

    /**
     * @brief Converts coords to field
     * @param coords
     * @return
     */
    static Field convertCoordsToField(Coords coords);

    /**
     * @brief Converts coords to string
     * @param coords
     * @return
     */
    static std::string toString(Coords coords);
};


#endif //CHESS_COORDS_H
