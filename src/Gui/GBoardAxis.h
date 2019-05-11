#ifndef CHESS_GBOARDAXIS_H
#define CHESS_GBOARDAXIS_H

#include <QGraphicsItem>
#include "GBoard.h"

class GBoardAxis : QGraphicsItem {
public:
    static void drawAxis(GBoard *board);
};


#endif //CHESS_GBOARDAXIS_H
