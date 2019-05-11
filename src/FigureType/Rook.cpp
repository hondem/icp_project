#include "Rook.h"
#include "string.h"

Rook::Rook(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {
    if (white) {
        strcpy(this->figureImg, "Chess_rlt45.png");
    } else {
        strcpy(this->figureImg, "Chess_rdt45.png");
    }
}

bool Rook::isMovePossible(Field field) {

    Field startField = this->getPosition();
    Field targetField = field;

    /**
     * Moving in columns
     */
    if(field.x == this->getPosition().x){
        // Swap target and source field
        if (startField.y > targetField.y){
            Field tmp = startField;
            startField = targetField;
            targetField = tmp;
        }

        for(int i = startField.y + 1; i < targetField.y; i++){
            if (this->checkboard->getFieldFigure((Field){field.x, i}) != nullptr) return false;
        }

        if (this->checkboard->getFieldFigure(field)->isWhite() == this->isWhite()) return false;

        return true;
    }

    /**
     * Moving in rows
     */
    if(field.y == this->getPosition().y){
        // Swap target and source field
        if (startField.x > targetField.x){
            Field tmp = startField;
            startField = targetField;
            targetField = tmp;
        }

        for(int i = startField.x + 1; i < targetField.x; i++){
            if (this->checkboard->getFieldFigure((Field){i, field.y}) != nullptr) return false;
        }

        if (this->checkboard->getFieldFigure(field)->isWhite() == this->isWhite()) return false;

        return true;
    }

    return false;
}
