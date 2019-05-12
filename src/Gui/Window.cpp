/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#include "Window.h"
#include "GBoard.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtWidgets/QApplication>
#include <QTabWidget>
#include <QBoxLayout>
#include <QGraphicsView>
#include <QToolButton>
#include <QTabBar>
#include <QString>
#include <stdlib.h>
#include <string.h>
#include "GTabBtn.h"

int Window::run(int argc, char *argv[], GameEngine *gameEngine) {
    app = new QApplication(argc, argv);

    // main scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1170, 902);

    // scene for the first tab
    QGraphicsScene *chessScene1 = new QGraphicsScene;
    //QGraphicsScene *chessScene2 = new QGraphicsScene;
    chessScene1->setSceneRect(0, 0, 1150, 820);
    //chessScene2->setSceneRect(0, 0, 800, 800);

    // set view
    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(1200, 910);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // set tab 1 content
    GBoard *board1 = new GBoard(chessScene1, gameEngine);
    board1->moveBy(20, 0);
    chessScene1->addItem(board1);

    //GBoard *board2 = new GBoard(chessScene2, gameEngine);
    //chessScene2->addItem(board2);

    QGraphicsView *widget1 = new QGraphicsView(chessScene1);
    //QGraphicsView *widget2 = new QGraphicsView(chessScene2);

    // tabsOpen
    tabsOpen = 1;
    tabsGenerated = 1;
    tabWidget = new QTabWidget();
    tabWidget->addTab(widget1, "Tab 1");
    //tabWidget->addTab(widget2, "Tab 2");
    tabWidget->setFixedSize(1170, 870);
    QToolButton *toolButton = new GTabBtn(this);
    toolButton->setText("+");
    tabWidget->setCornerWidget(toolButton, Qt::TopRightCorner);
    tabWidget->setTabsClosable(true);

    scene->addWidget(tabWidget);

    connect(tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));

    view->show();

    return app->exec();
}

void Window::createTab() {
    tabsOpen++;
    tabsGenerated++;
    char tabName[20] = "Tab ";
    sprintf(&(tabName[4]), "%d", tabsGenerated);

    QGraphicsScene *chessScene1 = new QGraphicsScene;
    chessScene1->setSceneRect(0, 0, 1150, 820);
    GBoard *board1 = new GBoard(chessScene1, new GameEngine());
    board1->moveBy(20, 0);
    chessScene1->addItem(board1);
    QGraphicsView *widget1 = new QGraphicsView(chessScene1);
    tabWidget->addTab(widget1, QString(tabName));
    tabWidget->tabBar()->tabButton(0, QTabBar::LeftSide);
}

void Window::closeTab(int index) {
    std::cout << "Close tab " << std::to_string(index) << "\n";
    tabWidget->removeTab(index);
    tabsOpen--;

    if (tabsOpen == 0) {
        app->closeAllWindows();
    }
}
