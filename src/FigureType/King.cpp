#include "King.h"
#include "string.h"

King::King(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {
    if (white) {
        strcpy(this->figureImg, "Chess_klt45.png");
    } else {
        strcpy(this->figureImg, "Chess_kdt45.png");
    }
}

bool King::isMovePossible(Field field) {
    if(
        this->checkboard->getFieldFigure(field) != nullptr &&
        this->checkboard->getFieldFigure(field)->isWhite() == this->isWhite()
    ) return false;

    Field resField = field - this->getPosition();

    resField.setX(abs(resField.x));
    resField.setY(abs(resField.y));

    if(resField.x >= 0 && resField.x <= 1 && resField.y >= 0 && resField.y <= 1){



    }
    return false;
}
