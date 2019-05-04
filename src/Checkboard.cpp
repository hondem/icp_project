#include "Checkboard.h"

Checkboard::Checkboard() {
    for (int y = 0; y < CHECKBOARD_LENGTH; y++) {
        for (int x = 0; x < CHECKBOARD_LENGTH; x++) {
            this->fields[y][x] = nullptr;
        }
    }
}

Figure* Checkboard::getFieldFigure(Field position) {
    return this->fields[position.y][position.x];
}

void Checkboard::setFieldFigure(Field position, Figure *figure) {
    this->fields[position.y][position.x] = figure;
}
