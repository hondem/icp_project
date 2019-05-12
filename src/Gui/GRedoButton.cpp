/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#include "GRedoButton.h"
#include <iostream>

GRedoButton::GRedoButton(GBoard *board) {
    this->board = board;

    this->setText(QString("Redo"));
    this->move(1000, 0);
    this->setFixedSize(150, 50);
}
