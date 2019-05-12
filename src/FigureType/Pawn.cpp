/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#include "Pawn.h"
#include "string.h"

Pawn::Pawn(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {
    if (white) {
        strcpy(this->figureImg, "Chess_plt45.png");
    } else {
        strcpy(this->figureImg, "Chess_pdt45.png");
    }
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
        this->checkboard->getFieldFigure(field) == nullptr &&
        this->checkboard->getFieldFigure((Field){field.x, field.y - 1}) == nullptr
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
        this->checkboard->getFieldFigure(field) == nullptr &&
        this->checkboard->getFieldFigure((Field){field.x, field.y + 1}) == nullptr
    ){
        return true;
    }

    return false;
}
