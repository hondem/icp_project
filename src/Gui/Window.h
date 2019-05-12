/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#ifndef CHESS_WINDOW_H
#define CHESS_WINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTabWidget>
#include <QObject>
#include "../GameEngine.h"

/**
 * @brief Represents one window of the app's GUI.
 */
class Window : public QObject {
    Q_OBJECT

    /**
     * @brief Application
     */
    QApplication *app;

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
    int tabsOpen;

    /**
     * @brief Count of tabs, that were opened.
     */
    int tabsGenerated;

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

public slots:
    /**
     * @brief Closes tab with the index
     * @param index Index of the tab
     */
    void closeTab(int index);
};


#endif //CHESS_WINDOW_H
