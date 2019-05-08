#include <iostream>
#include <QApplication>
#include <QPushButton>
#include "Checkboard.h"
#include "Utils/Parser.h"

int main(int argc, char *argv[]) {
    std::cout << "Cus\n";
    Checkboard checkboard;

    map<int, MoveRecord*> parsedMoves = Parser::LoadFile("../tests/3.src");

    QApplication app(argc, argv);
    QPushButton qPushButton("Hello Qt");
    qPushButton.show();
    return app.exec();
}
