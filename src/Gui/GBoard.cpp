#include "GBoard.h"
#include "../GameEngine.h"

#include <QGraphicsScene>
#include "../Figure.h"
#include "GFigure.h"


GBoard::GBoard(QGraphicsScene *scene, GameEngine *gameEngine) {
    this->selected = nullptr;
    this->scene = scene;
    this->gameEngine = gameEngine;

    setRect(0, 0, 8 * 100, 8 * 100);

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            fields[y][x] = new GField(this, x, y, this);
        }
    }

    renderFigures();
}

void GBoard::renderFigures() {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            scene->addItem(fields[y][x]);
            Figure *figure = gameEngine->getCheckboard()->getFieldFigure({.x = x, .y = y});

            if (figure != nullptr) {
                GFigure *gFigure = new GFigure(figure);
                this->figures.push_back(gFigure);
                scene->addItem(gFigure);
            }
        }
    }

}

void GBoard::showAvailableFields(GField *source) {
    Figure *figure = this->gameEngine->getCheckboard()->getFieldFigure({source->xPos, source->yPos});

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (figure->isMovePossible({x, y})) {
                std::cout << "Available " << x << ":" << y << "\n";
                this->fields[y][x]->styleAvailable();
            } else {
                this->fields[y][x]->styleNotAvailable();
            }
        }
    }
}

void GBoard::setAllFieldsNotAvailable() {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            this->fields[y][x]->styleNotAvailable();
        }
    }
}

void GBoard::refresh() {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            scene->removeItem(fields[y][x]);
        }
    }

    for (auto figure : this->figures) {
        scene->removeItem(figure);
    }

    this->figures.clear();

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            fields[y][x] = new GField(this, x, y, this);
        }
    }

    renderFigures();
}