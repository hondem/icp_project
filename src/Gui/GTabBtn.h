#ifndef CHESS_GTABBTN_H
#define CHESS_GTABBTN_H

#include <QToolButton>
#include <QMouseEvent>
#include "Window.h"

class GTabBtn : public QToolButton {
    Window *window;
public:
    GTabBtn(Window *window);
    void mousePressEvent(QMouseEvent *event);
};


#endif //CHESS_GTABBTN_H
