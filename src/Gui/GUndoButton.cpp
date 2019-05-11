#include "GUndoButton.h"

GUndoButton::GUndoButton(GBoard *board) {
    this->board = board;

    this->setText(QString("Undo"));
    this->move(835, 0);
    this->setFixedSize(150, 50);
}
