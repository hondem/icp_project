#include "GMoveList.h"

GMoveList::GMoveList() {
    addItem(QString("Prvni tah"));
    addItem(QString("Druhy tah"));

    setFixedSize(215, 300);
    move(815, 65);
}
