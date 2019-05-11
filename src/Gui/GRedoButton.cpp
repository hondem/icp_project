#include "GRedoButton.h"
#include <iostream>

GRedoButton::GRedoButton(GBoard *board) {
    this->board = board;

    this->setText(QString("Redo"));
    this->move(930, 0);
    this->setFixedSize(100, 50);
}
