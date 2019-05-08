#include "Pawn.h"

Pawn::Pawn(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {

}

bool Pawn::isMovePossible(Field field) {

    /**
     * White player attacks
     */
    if(
        this->isWhite() &&
        this->getPosition().y == field.y - 1 &&
        this->checkboard->getFieldFigure(field) != nullptr &&
        !this->checkboard->getFieldFigure(field)->isWhite() &&
        (
            this->getPosition().x == field.x - 1 ||
            this->getPosition().x == field.x + 1
        )
    ){
        return true;
    }

    /**
     * Black player attacks
     */
    if(
        !this->isWhite() &&
        this->getPosition().y == field.y + 1 &&
        this->checkboard->getFieldFigure(field) != nullptr &&
        this->checkboard->getFieldFigure(field)->isWhite() &&
        (
                this->getPosition().x == field.x - 1 ||
                this->getPosition().x == field.x + 1
        )
        ){
        return true;
    }

    /**
     * White player move by one straight up
     */
    if(
        this->isWhite() &&
        this->getPosition().x == field.x &&
        this->getPosition().y == field.y - 1 &&
        this->checkboard->getFieldFigure(field) == nullptr
    ){
        return true;
    }

    /**
     * Black player move by one straight down
     */
    if(
        !this->isWhite() &&
        this->getPosition().x == field.x &&
        this->getPosition().y == field.y + 1 &&
        this->checkboard->getFieldFigure(field) == nullptr
    ){
        return true;
    }

    /**
     * White player move by two straight up
     */
    if(
        this->isWhite() &&
        this->getPosition().x == field.x &&
        this->getPosition().y == 1 &&
        field.y == 3 &&
        this->checkboard->getFieldFigure(field) == nullptr
    ){
        return true;
    }

    /**
     * Black player move by two straight down
     */
    if(
        !this->isWhite() &&
        this->getPosition().x == field.x &&
        this->getPosition().y == 6 &&
        field.y == 4 &&
        this->checkboard->getFieldFigure(field) == nullptr
    ){
        return true;
    }

    return false;
}
