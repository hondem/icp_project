#include "Field.h"

bool Field::operator==(const Field& a) {
    return (x == a.x && y == a.y);
}

bool Field::operator!=(const Field& a) {
    return !(x == a.x && y == a.y);
}

Field Field::operator+(const Field& a) const {
    return (Field){x+a.x, y+a.y};
}

Field Field::operator-(const Field& a) const {
    return (Field){x-a.x, y-a.y};
}

void Field::setX(int x){
    this->x = x;
}

void Field::setY(int y){
    this->y = y;
}

Field Field::convertCoordsStringToField(std::string coords) {
    return (Field){
        (int)coords[0] - 'a',
        (int)coords[1] - '0' - 1
    };
}

Coords Field::convertFieldToCoords(Field field){
    return (Coords){
        (char)(field.x + 'a'),
        field.y + 1
    };
}