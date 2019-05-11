#ifndef CHESS_WINDOW_H
#define CHESS_WINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTabWidget>
#include "../GameEngine.h"

/**
 * @brief Represents one window of the app's GUI.
 */
class Window {
    /**
     * @brief Scene of the GUI
     */
    QGraphicsScene *scene;

    /**
     * @brief QTabWidget Widget for tab management.
     */
    QTabWidget *tabWidget;

    /**
     * @brief Count of open tabs.
     */
    int tabs;

public:
    /**
     * @brief Runs the app's GUI.
     * @param argc Argument count.
     * @param argv Arguments
     * @return Return code of the program.
     */
    int run(int argc, char *argv[], GameEngine *gameEngine);

    /**
     * @brief Creates new tab with new game.
     */
    void createTab();
};


#endif //CHESS_WINDOW_H
