#include <iostream>
#include <QApplication>
#include <QPushButton>
#include "Checkboard.h"

int main(int argc, char *argv[]) {
    std::cout << "Cus\n";
    Checkboard checkboard;


    QApplication app(argc, argv);
    QPushButton qPushButton("Hello Qt");
    qPushButton.show();
    return app.exec();
}


