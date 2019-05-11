#include "GTabBtn.h"
#include <iostream>

GTabBtn::GTabBtn(Window *window) {
    this->window = window;
}

void GTabBtn::mousePressEvent(QMouseEvent *event) {
    window->createTab();
}
