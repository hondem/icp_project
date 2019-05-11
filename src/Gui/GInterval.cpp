#include "GInterval.h"

GInterval::GInterval() {
    this->setRange(1, 100);
    this->setSingleStep(1);
    this->setValue(5);

    setFixedSize(100, 25);
    move(835, 480);
}
