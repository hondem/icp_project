#include "GField.h"
#include <Qt>
#include <QtGui/QBrush>
#include <QtGui/QPen>


GField::GField(QGraphicsItem *parent, bool light) {
    this->parent = parent;

    QBrush brush;
    QColor color;

    if (!light) {
        color.setRed(255);
        color.setGreen(207);
        color.setBlue(153);
    } else {
        color.setRed(210);
        color.setGreen(139);
        color.setBlue(65);
    }

    brush.setColor(color);
    brush.setStyle(Qt::SolidPattern);
    this->setBrush(brush);

    QPen pen;
    pen.setStyle(Qt::NoPen);
    this->setPen(pen);

    setRect(0, 0, 100, 100);
}
