/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#include "GUndoButton.h"

GUndoButton::GUndoButton(GBoard *board) {
    this->board = board;

    this->setText(QString("Undo"));
    this->move(835, 0);
    this->setFixedSize(150, 50);
}
