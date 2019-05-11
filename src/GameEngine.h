//
// Created by Jan Demel on 08/05/2019.
//

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
     * Game steps parsed from Parser
     */
    map<int, MoveRecord*> gameSteps;

    /**
     * An instance of checkboard
     */
    Checkboard *gameCheckboard;

    /**
     * Current move index
     */
    int currentMove;

    /**
     * Finds figure that should do this move
     * @return Figure / nullptr
     */
    Figure *findFigure(MoveRecord* currentMove);

    /**
     * Translates type of figure to internal representation
     * @param figure
     * @return String of converted figure
     */
    string translateTypeOfFigure(Figure *figure);
public:

    /**
     * Default GameEngine constructor
     */
    GameEngine();

    /**
     * Main constructor of GameEngine with inputFile
     * @param inputFile File to read annotation from
     */
    GameEngine(string inputFile);

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

    /**
     * Creates string with whole game in notation
     * @return
     */
    void exportGame(const char *filePath);
};


#endif //ICP_PROJECT_GAMEENGINE_H
