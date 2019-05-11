#ifndef CHESS_GBOARD_H
#define CHESS_GBOARD_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "GField.h"
#include "../GameEngine.h"
#include <vector>
#include "GFigure.h"
#include "GRedoButton.h"
#include "GUndoButton.h"
#include "GMoveList.h"
#include <QObject>
#include "GInterval.h"
#include "GPlayButton.h"
#include "GPauseButton.h"
#include "GFileOpen.h"
#include "GFileOpenButton.h"
#include "GFileSaveAs.h"
#include "GFileSaveAsButton.h"
#include <QTimer>

class GRedoButton;
class GUndoButton;

class GBoard : public QObject, public QGraphicsRectItem {
Q_OBJECT;

public:

    /**
     * @brief true if the next move is white's, false otherwise
     */
    bool whiteOnMove;
    GField *fields[8][8];

    QGraphicsScene *scene;

    GRedoButton *redoButton;
    GUndoButton *undoButton;

    GMoveList *moveList;

    GInterval *intervalInput;
    GPlayButton *playButton;
    GPauseButton *pauseButton;
    GFileOpen *fileOpen;
    GFileOpenButton *fileOpenButton;
    GFileSaveAs *fileSaveAs;
    GFileSaveAsButton *fileSaveAsButton;
    QTimer *timer;

    /**
     * @brief Current selected field with the figure, that is moved with.
     */
    GField *selected;
    /**
     * @brief Game engine of the Game
     */
    GameEngine *gameEngine;

    std::vector<GFigure *> figures;

    void renderFigures();

    GBoard(QGraphicsScene *scene, GameEngine *gameEngine);

    void showAvailableFields(GField *source);

    void setAllFieldsNotAvailable();

    void refresh();

public slots:
    void redoBtnClick();
    void undoBtnClick();
    void playBtnClick();
    void pauseBtnClick();
    void fileOpenBtnClick();
    void fileSaveAsBtnClick();
    void onTimer();
};


#endif //CHESS_GBOARD_H
