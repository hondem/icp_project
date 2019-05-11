#ifndef CHESS_GFIELD_H
#define CHESS_GFIELD_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>

class GBoard;

class GField : public QGraphicsRectItem {
    int xPos;
    int yPos;
    QGraphicsItem *parent;
    GBoard *board;

    void styleSelected();
    void styleNotSelected();

public:
    GField(QGraphicsItem *parent, int x, int y, GBoard *board);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};


#endif //CHESS_GFIELD_H
