//
// Created by Jan Demel on 11/05/2019.
//

#ifndef CHESS_COORDS_H
#define CHESS_COORDS_H

#include "Field.h"
#include <string>

struct Field;

struct Coords {
    /**
     * Horizontal
     */
    char x;

    /**
     * Vertical
     */
    int y;

    /**
     * Converts coords string to coords
     * @param coords
     * @return
     */
    static Coords convertCoordsStringToCoords(std::string coords);

    /**
     * Converts coords to field
     * @param coords
     * @return
     */
    static Field convertCoordsToField(Coords coords);

    /**
     * Converts coords to string
     * @param coords
     * @return
     */
    static std::string toString(Coords coords);
};


#endif //CHESS_COORDS_H
