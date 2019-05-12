#include "GField.h"
#include <Qt>
#include <QtGui/QBrush>
#include <QtGui/QPen>
#include <iostream>
#include "GBoard.h"

GField::GField(QGraphicsItem *parent, int x, int y, GBoard *board) {
    this->board = board;
    this->parent = parent;
    this->available = false;
    this->selected = false;
    this->xPos = x;
    this->yPos = y;

    QBrush brush;
    QColor color;

    bool light = false;

    if (y % 2 == 0) {
        if (x % 2 == 1) {
            light = true;
        }
    } else {
        if (x % 2 == 0) {
            light = true;
        }
    }

    if (!light) {
        color.setRed(255);
        color.setGreen(207);
        color.setBlue(153);
    } else {
        color.setRed(210);
        color.setGreen(139);
        color.setBlue(65);
    }

    brush.setColor(color);
    brush.setStyle(Qt::SolidPattern);
    this->setBrush(brush);

    QPen pen;
    pen.setStyle(Qt::NoPen);
    this->setPen(pen);

    setRect(0, 0, 100, 100);
    setPos(x*100 + 20, 700-y*100);
}

void GField::mousePressEvent(QGraphicsSceneMouseEvent *event){
    std::cout << "Click at " + std::to_string(xPos) + ":" + std::to_string(yPos) + "\n";

    if (this->board->fields[yPos][xPos]->available) {
        std::cout << "Move to " << xPos << ":" << yPos << "\n";
        this->board->setAllFieldsNotAvailable();
        this->board->selected->styleNotSelected();

        GField *movedFigureField = this->board->selected;
        Figure *movedFigure = this->board->gameEngine->getCheckboard()->getFieldFigure({
            movedFigureField->xPos, movedFigureField->yPos
        });
        this->board->gameEngine->moveFigure(movedFigure, {xPos, yPos});

        map<int, MoveRecord*> oldGameSteps = this->board->gameEngine->getGameSteps();
        map<int, MoveRecord*> newGameSteps;

        int index = 0;
        for(auto i = oldGameSteps.begin(); i != oldGameSteps.end(); i++){
            if(index == this->board->gameEngine->getCurrentStep() + 1) break;
            newGameSteps[i->first] = i->second;
            index++;
        }

        MoveRecord *newMove = new MoveRecord();
        newMove->isWhitePlayersMove = this->board->whiteOnMove;
        newMove->figure = this->board->gameEngine->translateTypeOfFigure(movedFigure);
        newMove->source = Coords::toString(Field::convertFieldToCoords(movedFigure->getPosition()));
        newMove->target = Coords::toString(Field::convertFieldToCoords({xPos, yPos}));

        newGameSteps[index] = newMove;
        this->board->gameEngine->setGameSteps(newGameSteps);

        this->board->refresh();
        this->board->whiteOnMove = ! this->board->whiteOnMove;
        return;
    }

    if (this->board->gameEngine->getCheckboard()->getFieldFigure({xPos, yPos}) != nullptr) {
        if (this->board->selected != nullptr) {
            this->board->selected->styleNotSelected();
        }

        Figure *movedFigure = this->board->gameEngine->getCheckboard()->getFieldFigure({
               xPos, yPos
        });
        if (this->board->whiteOnMove && false == movedFigure->isWhite()) {
            return;
        }
        if (false == this->board->whiteOnMove && movedFigure->isWhite()) {
            return;
        }

        this->styleSelected();
        this->board->selected = this;

        this->board->showAvailableFields(this);
    }
}

void GField::styleSelected() {
    if (this->selected) {
        return;
    }

    QPen pen(Qt::darkGreen, 5, Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin);
    this->setPen(pen);
    this->setRect(0, 0, 95, 95);
    this->setX(x()+2);
    this->setY(y()+2);

    this->selected = true;
}

void GField::styleNotSelected() {
    if (false == this->selected) {
        return;
    }

    QPen pen(Qt::NoPen);
    this->setPen(pen);
    this->setRect(0, 0, 100, 100);
    this->setX(x()-2);
    this->setY(y()-2);

    this->selected = false;
}

void GField::styleAvailable() {
    if (this->available) {
        return;
    }

    this->available = true;

    QPen pen(Qt::yellow, 5, Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin);
    this->setPen(pen);
    this->setRect(0, 0, 95, 95);
    this->setX(x()+2);
    this->setY(y()+2);
}

void GField::styleNotAvailable() {
    if (false == this->available) {
        return;
    }

    this->available = false;

    QPen pen(Qt::NoPen);
    this->setPen(pen);
    this->setRect(0, 0, 100, 100);
    this->setX(x()-2);
    this->setY(y()-2);
}

