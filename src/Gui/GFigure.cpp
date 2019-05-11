#include "GFigure.h"
#include "string.h"

GFigure::GFigure(Figure *figure) : QGraphicsPixmapItem() {
    char *img = figure->figureImg;
    //char imgAbs[200] = ":/";
    char imgAbs[200] = "/home/martinbuchta/Dokumenty/cppProject/src/Images/";
    strcat(imgAbs, img);
    setPixmap(QPixmap(imgAbs));
    int x = figure->getPosition().x * 100 + 20;
    int y = 700 - figure->getPosition().y * 100;
    setPos(x, y);
    this->setScale(0.1);
}
