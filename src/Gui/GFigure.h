#ifndef CHESS_GFIGURE_H
#define CHESS_GFIGURE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include "GField.h"
#include "../Figure.h"

class GFigure : public QGraphicsPixmapItem {
    GField *field;
public:
    GFigure(Figure *figure);
};


#endif //CHESS_GFIGURE_H
