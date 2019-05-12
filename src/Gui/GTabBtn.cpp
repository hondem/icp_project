/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#include "GTabBtn.h"
#include <iostream>

GTabBtn::GTabBtn(Window *window) {
    this->window = window;
}

void GTabBtn::mousePressEvent(QMouseEvent *event) {
    window->createTab();
}
