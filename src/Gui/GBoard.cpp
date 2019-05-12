#include "GBoard.h"
#include "../GameEngine.h"

#include <QGraphicsScene>
#include "GMoveList.h"
#include "../Figure.h"
#include "GFigure.h"
#include "GUndoButton.h"
#include "GRedoButton.h"
#include <QLabel>
#include "GBoardAxis.h"
#include "../Utils/MoveRecord.h"


GBoard::GBoard(QGraphicsScene *scene, GameEngine *gameEngine) {
    this->stepsDisabled = false;
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

    GBoardAxis::drawAxis(this);

    renderFigures();

    undoButton = new GUndoButton(this);
    scene->addWidget(undoButton);
    connect(undoButton, SIGNAL(released()), this, SLOT(undoBtnClick()));

    redoButton = new GRedoButton(this);
    scene->addWidget(redoButton);
    connect(redoButton, SIGNAL(released()), this, SLOT(redoBtnClick()));

    moveList = new GMoveList;
    scene->addWidget(moveList);
    connect(moveList, SIGNAL(itemSelectionChanged()), this, SLOT(onStepSelect()));

    intervalInput = new GInterval;
    scene->addWidget(intervalInput);

    QLabel *intervalLabel = new QLabel(QString("Interval:"));
    intervalLabel->move(835, 640);
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

    fileSaveAsButton = new GFileSaveAsButton;
    scene->addWidget(fileSaveAsButton);
    connect(fileSaveAsButton, SIGNAL(released()), this, SLOT(fileSaveAsBtnClick()));

    this->timer = new QTimer(this);
    connect(this->timer, SIGNAL(timeout()), this, SLOT(onTimer()));

    QString *item = new QString("Start");
    this->moveList->addItem(*item);
    this->moveList->setCurrentRow(0);

    this->pauseButton->setDisabled(true);
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

    // remove steps from list
    this->moveList->clear();

    // write steps into list
    QString *item = new QString("Start");
    this->moveList->addItem(*item);

    for (const auto &it : this->gameEngine->getGameSteps()) {
        QString *item = new QString(MoveRecord::toString(it.second).data());
        this->moveList->addItem(*item);
    }

    // select current step
    this->moveList->setCurrentRow(this->gameEngine->getCurrentStep() + 1);
}

void GBoard::redoBtnClick() {
    std::cout << "Redo\n";
    this->stepsDisabled = true;
    this->gameEngine->redo();
    this->refresh();
    this->stepsDisabled = false;
}

void GBoard::undoBtnClick() {
    std::cout << "Undo\n";
    this->stepsDisabled = true;
    this->gameEngine->undo();
    this->refresh();
    this->stepsDisabled = false;
}

void GBoard::playBtnClick() {
    std::cout << "Play\n";

    if (this->gameEngine->getGameSteps().size() == 0) {
        return;
    }

    // if last step is selected
    if (this->gameEngine->getCurrentStep() + 1 == this->gameEngine->getGameSteps().size()) {
        return;
    }

    this->timer->start(this->intervalInput->value() * 100);
    this->playButton->setDisabled(true);
    this->pauseButton->setDisabled(false);
}

void GBoard::pauseBtnClick() {
    std::cout << "Pause\n";

    this->timer->stop();
    this->playButton->setDisabled(false);
    this->pauseButton->setDisabled(true);
}

void GBoard::fileOpenBtnClick() {
    std::cout << "Open file dialog\n";

    fileOpen = new GFileOpen;
    QString filename = QFileDialog::getOpenFileName(fileOpen, "Open file", QDir::currentPath(), "All files (*.*)");

    if (false == filename.isNull()) {
        std::cout << "open: " << filename.toUtf8().constData() << "\n";
        this->gameEngine = new GameEngine(filename.toStdString());
        this->refresh();
    }
}

void GBoard::fileSaveAsBtnClick() {
    std::cout << "Save file as...\n";

    fileSaveAs = new GFileSaveAs;
    QString filename = QFileDialog::getSaveFileName(fileSaveAs, "Save file as", QDir::currentPath(), "All files (*.*)");

    if (false == filename.isNull()) {
        std::cout << "save as: " << filename.toUtf8().constData() << "\n";
        this->gameEngine->exportGame(filename.toUtf8().constData());
    }
}

void GBoard::onTimer() {
    this->redoBtnClick();

    // if last step is selected
    if (this->gameEngine->getCurrentStep() + 1 == this->gameEngine->getGameSteps().size()) {
        this->pauseBtnClick();
    }
}

void GBoard::onStepSelect() {
    if (this->stepsDisabled) {
        return;
    }

    std::cout << "On step select\n";
    //if (this->gameEngine->getCurrentStep() != this->moveList->currentRow()) {
    this->stepsDisabled = true;
    this->gameEngine->setCurrentStep(this->moveList->currentRow() - 1);
    this->gameEngine->setStep(this->moveList->currentRow() - 1);
    this->refresh();
    this->stepsDisabled = false;
    this->pauseBtnClick();
    //}
}
