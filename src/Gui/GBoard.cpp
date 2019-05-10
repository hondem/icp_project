#include "GBoard.h"

#include <QGraphicsScene>

GBoard::GBoard(QGraphicsScene *scene) {
    this->scene = scene;

    setRect(0, 0, 8*100, 8*100);

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            fields[y][x] = new GField(this, x, y);
            scene->addItem(fields[y][x]);
        }
    }
}