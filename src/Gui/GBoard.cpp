#include "GBoard.h"
#include "../GameEngine.h"

#include <QGraphicsScene>
#include "GMoveList.h"
#include "../Figure.h"
#include "GFigure.h"
#include "GUndoButton.h"
#include "GRedoButton.h"
#include <QLabel>


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

    moveList = new GMoveList;
    scene->addWidget(moveList);

    intervalInput = new GInterval;
    scene->addWidget(intervalInput);

    QLabel *intervalLabel = new QLabel(QString("Interval (sekundy):"));
    intervalLabel->move(815, 450);
    intervalLabel->setStyleSheet("background-color: rgba(0,0,0,0%)");
    scene->addWidget(intervalLabel);

    playButton = new GPlayButton;
    scene->addWidget(playButton);
    connect(playButton, SIGNAL(released()), this, SLOT(playBtnClick()));

    pauseButton = new GPauseButton;
    scene->addWidget(pauseButton);
    connect(pauseButton, SIGNAL(released()), this, SLOT(pauseBtnClick()));

    fileOpenButton = new GFileOpenButton;
    scene->addWidget(fileOpenButton);
    connect(fileOpenButton, SIGNAL(released()), this, SLOT(fileOpenBtnClick()));

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
    this->refresh();
}

void GBoard::undoBtnClick() {
    std::cout << "Undo\n";
    this->gameEngine->undo();
    this->refresh();
}

void GBoard::playBtnClick() {
    std::cout << "Play\n";
}

void GBoard::pauseBtnClick() {
    std::cout << "Pause\n";
}

void GBoard::fileOpenBtnClick() {
    std::cout << "Open file dialog\n";

    fileOpen = new GFileOpen;
    QString filename = QFileDialog::getOpenFileName(fileOpen, "Open file", QDir::currentPath(), "All files (*.*)");

    if (false == filename.isNull()) {
        std::cout << "open: " << filename.toUtf8().constData() << "\n";
    }
}