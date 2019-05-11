#include "GBoard.h"
#include "../GameEngine.h"

#include <QGraphicsScene>
#include "../Figure.h"
#include "GFigure.h"
#include "GUndoButton.h"
#include "GRedoButton.h"


GBoard::GBoard(QGraphicsScene *scene, GameEngine *gameEngine) {
    this->whiteOnMove = true;
    this->selected = nullptr;
    this->scene = scene;
    this->gameEngine = gameEngine;

    setRect(0, 0, 8 * 100, 8 * 100);

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            fields[y][x] = new GField(this, x, y, this);
            scene->addItem(fields[y][x]);
        }
    }

    renderFigures();

    undoButton = new GUndoButton(this);
    scene->addWidget(undoButton);
    connect(undoButton, SIGNAL(released()), this, SLOT(undoBtnClick()));

    redoButton = new GRedoButton(this);
    scene->addWidget(redoButton);
    connect(redoButton, SIGNAL(released()), this, SLOT(redoBtnClick()));
}

void GBoard::renderFigures() {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
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
    for (auto figure : this->figures) {
        scene->removeItem(figure);
        delete figure;
    }

    this->figures.clear();

    renderFigures();
}

void GBoard::redoBtnClick() {
    std::cout << "Redo\n";
    this->gameEngine->redo();
}

void GBoard::undoBtnClick() {
    std::cout << "Undo\n";
    this->gameEngine->undo();
}