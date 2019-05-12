/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#include "GBoardAxis.h"
#include <QLabel>

void GBoardAxis::drawAxis(GBoard *board) {
    int i = 0;
    for (const char *val: {"8", "7", "6", "5", "4", "3", "2", "1"}) {
        QLabel *label = new QLabel;
        label->setText(QString(val));
        label->setFixedSize(20, 100);
        label->move(0, i*100);
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("background-color: #ececec; color: black;");
        board->scene->addWidget(label);
        i++;
    }

    i = 0;
    for (const char *val: {"A", "B", "C", "D", "E", "F", "G", "H"}) {
        QLabel *label = new QLabel;
        label->setText(QString(val));
        label->setFixedSize(100, 20);
        label->move(i*100 + 20, 800);
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("background-color: #ececec; color: black;");
        board->scene->addWidget(label);
        i++;
    }
}
