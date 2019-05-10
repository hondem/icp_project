#ifndef CHESS_GBOARD_H
#define CHESS_GBOARD_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "GField.h"

class GBoard : public QGraphicsRectItem {
    GField *fields[8][8];
    QGraphicsScene *scene;

public:
    GBoard(QGraphicsScene *scene);
};


#endif //CHESS_GBOARD_H
