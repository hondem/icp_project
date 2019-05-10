#include "Rook.h"
#include "string.h"

Rook::Rook(bool white, Field position, Checkboard *checkboard) : Figure(white, position, checkboard) {
    strcpy(this->figureImg, "Chess_rlt45.png");
}

bool Rook::isMovePossible(Field field) {
    /**
     * Moving in columns
     */
    if(this->getPosition().x == field.x){

        if(field.y > this->getPosition().y){
            for(int i = this->getPosition().y + 1; i < field.y; i++){
                if(this->checkboard->getFieldFigure((Field){this->getPosition().x, i}) != nullptr){
                    return false;
                }
            }

            if(
                this->checkboard->getFieldFigure(field) != nullptr &&
                this->checkboard->getFieldFigure(field)->isWhite() == this->isWhite()
            ){
                return false;
            }
        } else {
            for(int i = this->getPosition().y - 1; i > field.y; i--){
                if(this->checkboard->getFieldFigure((Field){this->getPosition().x, i}) != nullptr){
                    return false;
                }
            }

            if(
                this->checkboard->getFieldFigure(field) != nullptr &&
                this->checkboard->getFieldFigure(field)->isWhite() == this->isWhite()
            ){
                return false;
            }
        }
    }

    /**
     * Moving in rows
     */
    if(this->getPosition().y == field.y){

        if(field.x > this->getPosition().x){
            for(int i = this->getPosition().x + 1; i < field.x; i++){
                if(this->checkboard->getFieldFigure((Field){i, this->getPosition().y}) != nullptr){
                    return false;
                }
            }

            if(
                this->checkboard->getFieldFigure(field) != nullptr &&
                this->checkboard->getFieldFigure(field)->isWhite() == this->isWhite()
            ){
                return false;
            }
        } else {
            for(int i = this->getPosition().x - 1; i > field.x; i--){
                if(this->checkboard->getFieldFigure((Field){i, this->getPosition().y}) != nullptr){
                    return false;
                }
            }

            if(
                this->checkboard->getFieldFigure(field) != nullptr &&
                this->checkboard->getFieldFigure(field)->isWhite() == this->isWhite()
            ){
                return false;
            }
        }
    }

    return true;
}
