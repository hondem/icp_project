#include "GBoard.h"

#include <QGraphicsScene>

GBoard::GBoard(QGraphicsScene *scene) {
    this->scene = scene;

    setRect(0, 0, 8*100, 8*100);

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            bool light = false;

            if (y % 2 == 0) {
                if (x % 2 == 1) {
                    light = true;
                }
            } else {
                if (x % 2 == 0) {
                    light = true;
                }
            }

            fields[y][x] = new GField(this, light);
            fields[y][x]->setPos(x*100, y*100);
            scene->addItem(fields[y][x]);
        }
    }
}