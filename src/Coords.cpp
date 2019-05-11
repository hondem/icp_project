//
// Created by Jan Demel on 11/05/2019.
//

#include "Coords.h"

Coords Coords::convertCoordsStringToCoords(std::string coords) {
    return (Coords){
        coords[0],
        (int)coords[1] - '0'
    };
}

Field Coords::convertCoordsToField(Coords coords){
    return (Field){
        (int)(coords.x - 'a'),
        coords.y - 1
    };
}