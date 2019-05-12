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

/**
 * @brief Class representing one game board
 */
class GBoard : public QObject, public QGraphicsRectItem {
Q_OBJECT;

/**
 * @brief Removes all fields from the board
 */
void deselectAllFields();

public:

    /**
     * @brief True if the game step change handler should be disabled.
     */
    bool stepsDisabled;

    /**
     * @brief true if the next move is white's, false otherwise
     */
    bool whiteOnMove;

    /**
     * @brief Board fields
     */
    GField *fields[8][8];

    /**
     * @brief Graphics scene
     */
    QGraphicsScene *scene;

    /**
     * @brief Redo button
     */
    GRedoButton *redoButton;

    /**
     * @brief Undo button
     */
    GUndoButton *undoButton;

    /**
     * @brief List of moves
     */
    GMoveList *moveList;

    /**
     * @brief Interval input
     */
    GInterval *intervalInput;

    /**
     * @brief Play button
     */
    GPlayButton *playButton;

    /**
     * @brief Pause button
     */
    GPauseButton *pauseButton;

    /**
     * @brief File open window
     */
    GFileOpen *fileOpen;

    /**
     * @brief File open button
     */
    GFileOpenButton *fileOpenButton;

    /**
     * @brief File save window
     */
    GFileSaveAs *fileSaveAs;

    /**
     * @brief File save button
     */
    GFileSaveAsButton *fileSaveAsButton;

    /**
     * @brief Timer for game interval
     */
    QTimer *timer;

    /**
     * @brief Current selected field with the figure, that is moved with.
     */
    GField *selected;
    /**
     * @brief Game engine of the Game
     */
    GameEngine *gameEngine;

    /**
     * @brief Figures on the board
     */
    std::vector<GFigure *> figures;

    /**
     * @brief Renders all figures that are on the board.
     */
    void renderFigures();

    /**
     * @brief GBoard contructor, creates new board and its fields.
     * Also renders game, that is in the gameEngine.
     * @param scene scene, that should be drawn to.
     * @param gameEngine gameEngine of played game
     */
    GBoard(QGraphicsScene *scene, GameEngine *gameEngine);

    /**
     * @brief Borders all fields, which are accessible from the source field.
     * It depends on the figure, that is on the source field.
     */
    void showAvailableFields(GField *source);

    /**
     * @brief Removes border from all bordered fields.
     */
    void setAllFieldsNotAvailable();

    /**
     * @brief Renders all the scene again.
     */
    void refresh();

public slots:
    /**
     * @brief Redo button click handler.
     */
    void redoBtnClick();

    /**
     * @brief Undo button click handler.
     */
    void undoBtnClick();

    /**
     * @brief Play button click handler.
     */
    void playBtnClick();

    /**
     * @brief Pause button click handler
     */
    void pauseBtnClick();

    /**
     * @brief File open button click.
     */
    void fileOpenBtnClick();

    /**
     * @brief File save as button click handler
     */
    void fileSaveAsBtnClick();

    /**
     * @brief Function invoked by the timer once in a interval
     */
    void onTimer();

    /**
     * @brief Function called when a step in a steplist is changed.
     */
    void onStepSelect();
};


#endif //CHESS_GBOARD_H
