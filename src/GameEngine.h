/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#ifndef ICP_PROJECT_GAMEENGINE_H
#define ICP_PROJECT_GAMEENGINE_H

#include "Utils/Parser.h"
#include "Checkboard.h"
#include <map>
#include <string>
#include <sstream>
#include <fstream>

class GameEngine {
private:
    /**
     * @brief Game steps parsed from Parser
     */
    map<int, MoveRecord*> gameSteps;

    /**
     * @brief An instance of checkboard
     */
    Checkboard *gameCheckboard;

    /**
     * @brief Current move index
     */
    int currentMove;

    /**
     * @brief Finds figure that should do this move
     * @return Figure / nullptr
     */
    Figure *findFigure(MoveRecord* currentMove);

public:

    /**
     * @brief Default GameEngine constructor
     */
    GameEngine();

    /**
     * @brief Main constructor of GameEngine with inputFile
     * @param inputFile File to read annotation from
     */
    GameEngine(string inputFile);

    /**
     * @brief Go step backwards
     */
    void undo();

    /**
     * @brief Go step forward
     */
    void redo();

    /**
     * @brief Set step to be shown
     * @param stepIndex
     */
    void setStep(int stepIndex);

    /**
     * @brief Getter for game checkboard
     * @return Instance of game checkboard
     */
    Checkboard *getCheckboard();

    /**
     * @brief Moves the figure to the target field.
     * @param figure Figure to be moved with.
     * @param target Target field.
     */
    void moveFigure(Figure *figure, Field target);

    /**
     * @brief Creates string with whole game in notation
     * @return
     */
    void exportGame(const char *filePath);

    /**
     * @brief Returns game steps parsed from Parser
     * @return map<int, MoveRecord*> gameSteps
     */
    map<int, MoveRecord*> getGameSteps();

    /**
     * @brief Sets new game steps
     * @param newGameSteps
     */
    void setGameSteps(map<int, MoveRecord*> newGameSteps);

    /**
     * @brief Returns current move index
     * @return int Current move index
     */
    int getCurrentStep();

    /**
     * @brief Set move index
     * @param currentStep New move index
     */
    void setCurrentStep(int currentStep);

    /**
     * @brief Translates type of figure to internal representation
     * @param figure
     * @return String of converted figure
     */
    string translateTypeOfFigure(Figure *figure);
};


#endif //ICP_PROJECT_GAMEENGINE_H
