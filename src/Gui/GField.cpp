#include "GField.h"
#include <Qt>
#include <QtGui/QBrush>


GField::GField(QGraphicsItem *parent) {
    this->parent = parent;

    QBrush brush;
    brush.setColor(Qt::darkCyan);
    brush.setStyle(Qt::SolidPattern);
    this->setBrush(brush);

    setRect(0, 0, 100, 100);
}
