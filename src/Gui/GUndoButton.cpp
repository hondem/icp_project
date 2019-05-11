#include "GUndoButton.h"

GUndoButton::GUndoButton(GBoard *board) {
    this->board = board;

    this->setText(QString("Undo"));
    this->move(815, 0);
    this->setFixedSize(100, 50);
}
