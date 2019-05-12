/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#ifndef CHESS_GREDOBUTTON_H
#define CHESS_GREDOBUTTON_H

#include <QPushButton>
#include "GBoard.h"

/**
 * @brief Redo button
 */
class GRedoButton : public QPushButton {
    /**
     * @brief board of the button
     */
    GBoard *board;
public:
    /**
     * @brief Creates new redo button
     * @param board Board
     */
    GRedoButton(GBoard *board);
};


#endif //CHESS_GREDOBUTTON_H
