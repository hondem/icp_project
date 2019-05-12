/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#include "Bishop.h"
#include "string.h"

Bishop::Bishop(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {
    if (white) {
        strcpy(this->figureImg, "Chess_blt45.png");
    } else {
        strcpy(this->figureImg, "Chess_bdt45.png");
    }
}

bool Bishop::isMovePossible(Field field) {
    Field startField = this->getPosition();
    Field targetField = field;

    /**
     * Moving in diagonal
     */
    if(abs(field.y - this->getPosition().y) == abs(field.x - this->getPosition().x)){
        int xAdd = (targetField.x > startField.x) ? 1 : -1;
        int yAdd = (targetField.y > startField.y) ? 1 : -1;

        do{
            // Adding differentials to X, Y
            startField.setX(startField.x + xAdd);
            startField.setY(startField.y + yAdd);

            if(startField != targetField) if(this->checkboard->getFieldFigure(startField) != nullptr) return false;

        } while(startField != targetField);

        if(
            this->checkboard->getFieldFigure(field) != nullptr &&
            this->checkboard->getFieldFigure(field)->isWhite() == this->isWhite()
        ) return false;

        return true;
    }

    return false;
}