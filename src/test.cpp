#include <iostream>
#include "Figure.h"
#include "Field.h"

int main() {
    Strelec f(true);
    std::cout << "Ahoj\n" << f.isMovePossible({1, 1});
}


