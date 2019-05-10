#ifndef CHESS_WINDOW_H
#define CHESS_WINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>


class Window {
QGraphicsScene *scene;
QGraphicsView *view;

public:
    int run(int argc, char *argv[]);
};


#endif //CHESS_WINDOW_H
