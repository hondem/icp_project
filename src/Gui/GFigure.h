#ifndef CHESS_GFIGURE_H
#define CHESS_GFIGURE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include "GField.h"
#include "../Figure.h"

/**
 * @brief Figure on the board
 */
class GFigure : public QGraphicsPixmapItem {
    GField *field;
public:
    /**
     * @brief Creates new figure and places it on the board
     * @param figure Figure
     */
    GFigure(Figure *figure);
};


#endif //CHESS_GFIGURE_H
