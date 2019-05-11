//
// Created by Jan Demel on 08/05/2019.
//

#ifndef ICP_PROJECT_GAMEENGINE_H
#define ICP_PROJECT_GAMEENGINE_H

#include "Utils/Parser.h"
#include "Checkboard.h"
#include <map>
#include <string>

class GameEngine {
private:
    /**
     * Game steps parsed from Parser
     */
    map<int, MoveRecord*> gameSteps;

    /**
     * An instance of checkboard
     */
    Checkboard *gameCheckboard;
public:

    /**
     * Main constructor of GameEngine
     * @param inputFile File to read annotation from
     */
    GameEngine(string inputFile);

    /**
     * Start evaluating steps
     */
    void start();

    /**
     * Pause evaluating steps
     */
    void pause();

    /**
     * Go step backwards
     */
    void undo();

    /**
     * Go step forward
     */
    void redo();

    /**
     * Set step to be shown
     * @param stepIndex
     */
    void setStep(int stepIndex);

    /**
     * Getter for game checkboard
     * @return Instance of game checkboard
     */
    Checkboard *getCheckboard();

    /**
     * @brief Moves the figure to the target field.
     * @param figure Figure to be moved with.
     * @param target Target field.
     */
    void moveFigure(Figure *figure, Field target);
};


#endif //ICP_PROJECT_GAMEENGINE_H
