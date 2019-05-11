#include "GField.h"
#include <Qt>
#include <QtGui/QBrush>
#include <QtGui/QPen>
#include <iostream>
#include "GBoard.h"

GField::GField(QGraphicsItem *parent, int x, int y, GBoard *board) {
    this->board = board;
    this->parent = parent;
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
    setPos(x*100, 700-y*100);
}

void GField::mousePressEvent(QGraphicsSceneMouseEvent *event){
    std::cout << "Click at " + std::to_string(xPos) + ":" + std::to_string(yPos) + "\n";

    if (this->board->gameEngine->getCheckboard()->getFieldFigure({xPos, yPos}) != nullptr) {
        this->styleSelected();

        if (this->board->selected != nullptr) {
            this->board->selected->styleNotSelected();
        }

        this->board->selected = this;
    }
}

void GField::styleSelected() {
    QPen pen(Qt::darkGreen, 5, Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin);
    this->setPen(pen);
    this->setRect(0, 0, 95, 95);
    this->setX(x()+2);
    this->setY(y()+2);
}

void GField::styleNotSelected() {
    QPen pen(Qt::NoPen);
    this->setPen(pen);
    this->setRect(0, 0, 100, 100);
    this->setX(x()-2);
    this->setY(y()-2);
}

