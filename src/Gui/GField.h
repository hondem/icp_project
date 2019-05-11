#ifndef CHESS_GFIELD_H
#define CHESS_GFIELD_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>

class GBoard;

class GField : public QGraphicsRectItem {
    QGraphicsItem *parent;
    GBoard *board;

public:
    bool available;
    void styleSelected();
    void styleNotSelected();
    void styleAvailable();

    void styleNotAvailable();
    int xPos;
    int yPos;

    GField(QGraphicsItem *parent, int x, int y, GBoard *board);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};


#endif //CHESS_GFIELD_H
