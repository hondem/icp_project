#ifndef CHESS_GUNDOBUTTON_H
#define CHESS_GUNDOBUTTON_H

#include <QPushButton>
#include "GBoard.h"

class GUndoButton : public QPushButton {
    GBoard *board;
public:
    GUndoButton(GBoard *board);
};


#endif //CHESS_GUNDOBUTTON_H
