#ifndef CHESS_GFIELD_H
#define CHESS_GFIELD_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>

class GField : public QGraphicsRectItem {
    int xPos;
    int yPos;
    QGraphicsItem *parent;
public:
    GField(QGraphicsItem *parent, int x, int y);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};


#endif //CHESS_GFIELD_H
