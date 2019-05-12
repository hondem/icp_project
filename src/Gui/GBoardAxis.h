#ifndef CHESS_GBOARDAXIS_H
#define CHESS_GBOARDAXIS_H

#include <QGraphicsItem>
#include "GBoard.h"

/**
 * @brief Class drawing axis of a board
 */
class GBoardAxis : QGraphicsItem {
public:
    /**
     * @brief Draws horizontal and vertical axis for the board.
     * @param board
     */
    static void drawAxis(GBoard *board);
};


#endif //CHESS_GBOARDAXIS_H
