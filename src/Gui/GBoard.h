#ifndef CHESS_GBOARD_H
#define CHESS_GBOARD_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "GField.h"
#include "../GameEngine.h"

class GBoard : public QGraphicsRectItem {
    GField *fields[8][8];
    QGraphicsScene *scene;

    /**
     * @brief Game engine of the Game
     */
    GameEngine *gameEngine;

    void renderFigures();

public:
    GBoard(QGraphicsScene *scene, GameEngine *gameEngine);
};


#endif //CHESS_GBOARD_H
