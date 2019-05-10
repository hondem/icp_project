#include "GFigure.h"
#include "string.h"

GFigure::GFigure(Figure *figure) : QGraphicsPixmapItem() {
    char *img = figure->figureImg;
    char imgAbs[200] = "/home/martinbuchta/Dokumenty/cppProject/src/Images/";
/*
    for (int i = 199; i > 0; i--) {
        if (imgAbs[i] != '\0') {
            if (imgAbs[i] == '/') {
                break;
            } else {
                imgAbs[i] = '\0';
            }
        }
    }*/

    //strcat(imgAbs, "../Images/");
    strcat(imgAbs, img);
    setPixmap(QPixmap(imgAbs));
    int x = figure->getPosition().x * 100;
    int y = 700 - figure->getPosition().y * 100;
    setPos(x, y);
    this->setScale(0.1);
}
