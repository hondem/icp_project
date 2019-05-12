/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#ifndef CHESS_GUNDOBUTTON_H
#define CHESS_GUNDOBUTTON_H

#include <QPushButton>
#include "GBoard.h"

/**
 * @brief Undo button
 */
class GUndoButton : public QPushButton {
    /**
     * @brief Board of the button
     */
    GBoard *board;
public:
    /**
     * @brief Creates new undo button
     * @param board Board
     */
    GUndoButton(GBoard *board);
};


#endif //CHESS_GUNDOBUTTON_H
