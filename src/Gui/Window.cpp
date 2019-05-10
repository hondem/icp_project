#include "Window.h"
#include "GBoard.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtWidgets/QApplication>
#include <QTabWidget>
#include <QBoxLayout>
#include <QGraphicsView>

int Window::run(int argc, char *argv[]) {
    QApplication app(argc, argv);

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1300, 882);

    QGraphicsScene *chessScene1 = new QGraphicsScene;
    QGraphicsScene *chessScene2 = new QGraphicsScene;
    chessScene1->setSceneRect(0, 0, 800, 800);
    chessScene2->setSceneRect(0, 0, 800, 800);

    view = new QGraphicsView(scene);
    view->setFixedSize(1300, 890);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    GBoard *board1 = new GBoard(chessScene1);
    chessScene1->addItem(board1);

    GBoard *board2 = new GBoard(chessScene2);
    chessScene2->addItem(board2);

    QGraphicsView *widget1 = new QGraphicsView(chessScene1);
    QGraphicsView *widget2 = new QGraphicsView(chessScene2);

    QTabWidget *tabWidget = new QTabWidget();
    tabWidget->addTab(widget1, "Tab 1");
    tabWidget->addTab(widget2, "Tab 2");
    tabWidget->setFixedSize(840, 850);
    scene->addWidget(tabWidget);

    scene->addWidget(tabWidget);

    view->show();

    return app.exec();
}
