#ifndef CHESS_WINDOW_H
#define CHESS_WINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "../GameEngine.h"

/**
 * @brief Represents one window of the app's GUI.
 */
class Window {
    /**
     * @brief Scene of the GUI
     */
    QGraphicsScene *scene;

public:
    /**
     * @brief Runs the app's GUI.
     * @param argc Argument count.
     * @param argv Arguments
     * @return Return code of the program.
     */
    int run(int argc, char *argv[], GameEngine *gameEngine);
};


#endif //CHESS_WINDOW_H
