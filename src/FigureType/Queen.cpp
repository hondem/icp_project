#include "Queen.h"
#include "string.h"

Queen::Queen(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {
    if (white) {
        strcpy(this->figureImg, "Chess_qlt45.png");
    } else {
        strcpy(this->figureImg, "Chess_qdt45.png");
    }
}

bool Queen::isMovePossible(Field field) {
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

        if(
            this->checkboard->getFieldFigure(field) != nullptr &&
            this->checkboard->getFieldFigure(field)->isWhite() == this->isWhite()
        ) return false;

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

        if(
            this->checkboard->getFieldFigure(field) != nullptr &&
            this->checkboard->getFieldFigure(field)->isWhite() == this->isWhite()
        ) return false;

        return true;
    }

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

            if(this->checkboard->getFieldFigure(startField) != nullptr) return false;

        } while(field != targetField);

        if(
            this->checkboard->getFieldFigure(field) != nullptr &&
            this->checkboard->getFieldFigure(field)->isWhite() == this->isWhite()
        ) return false;

        return true;
    }

    return false;
}
