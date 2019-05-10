#ifndef CHESS_GFIELD_H
#define CHESS_GFIELD_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>

class GField : public QGraphicsRectItem {
    QGraphicsItem *parent;
public:
    GField(QGraphicsItem *parent, bool light);
};


#endif //CHESS_GFIELD_H
