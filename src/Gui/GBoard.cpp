#include "GBoard.h"
#include "../GameEngine.h"

#include <QGraphicsScene>
#include "../Figure.h"
#include "GFigure.h"


GBoard::GBoard(QGraphicsScene *scene, GameEngine *gameEngine) {
    this->scene = scene;
    this->gameEngine = gameEngine;

    setRect(0, 0, 8 * 100, 8 * 100);

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            fields[y][x] = new GField(this, x, y);
        }
    }

    renderFigures();
}

void GBoard::renderFigures() {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            scene->addItem(fields[y][x]);
            Figure *figure = gameEngine->gameCheckboard->getFieldFigure({.x = x, .y = y});

            if (figure != nullptr) {
                GFigure *gFigure = new GFigure(figure);
                scene->addItem(gFigure);
            }
        }
    }

}