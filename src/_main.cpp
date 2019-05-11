#include <iostream>
#include <QApplication>
#include <QPushButton>
#include "GameEngine.h"
#include "Utils/Parser.h"
#include "Gui/Window.h"

int main(int argc, char *argv[]) {
    std::cout << "Cus\n";

    GameEngine *engine = new GameEngine();

    Window *window = new Window();

    return window->run(argc, argv, engine);
}
