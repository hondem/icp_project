#include "Window.h"
#include "GBoard.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtWidgets/QApplication>

int Window::run(int argc, char *argv[]) {
    QApplication app(argc, argv);

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1300, 802);

    view = new QGraphicsView(scene);
    view->setFixedSize(1300, 802);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    GBoard *board = new GBoard(scene);
    scene->addItem(board);

    view->show();

    return app.exec();
}
