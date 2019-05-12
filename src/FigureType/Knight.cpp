/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#include "Knight.h"
#include "string.h"


Knight::Knight(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {
    if (white) {
        strcpy(this->figureImg, "Chess_nlt45.png");
    } else {
        strcpy(this->figureImg, "Chess_ndt45.png");
    }
}

bool Knight::isMovePossible(Field field) {
    if(
        this->checkboard->getFieldFigure(field) != nullptr &&
        this->checkboard->getFieldFigure(field)->isWhite() == this->isWhite()
    ) return false;

    Field resField = field - this->getPosition();

    if((abs(resField.x) == 2 && abs(resField.y) == 1) || (abs(resField.x) == 1 && abs(resField.y) == 2)) return true;

    return false;
}