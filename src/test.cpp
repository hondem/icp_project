#include <iostream>
#include "Figure.h"
#include "Field.h"
#include "Checkboard.h"
#include "FigureType/King.h"

int main() {
    Checkboard checkboard;

    King f(true, {1, 1}, &checkboard);
    std::cout << "Ahoj\n" << f.isMovePossible({1, 1});
}


