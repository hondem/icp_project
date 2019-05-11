#ifndef CHESS_GREDOBUTTON_H
#define CHESS_GREDOBUTTON_H

#include <QPushButton>
#include "GBoard.h"

class GRedoButton : public QPushButton {
    GBoard *board;
public:
    GRedoButton(GBoard *board);
};


#endif //CHESS_GREDOBUTTON_H
