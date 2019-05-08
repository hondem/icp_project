#include <iostream>
#include <QApplication>
#include <QPushButton>
#include "GameEngine.h"
#include "Utils/Parser.h"

int main(int argc, char *argv[]) {
    std::cout << "Cus\n";

    GameEngine *engine = new GameEngine("../tests/3.src");

    QApplication app(argc, argv);
    QPushButton qPushButton("Hello Qt");
    qPushButton.show();
    return app.exec();
}
