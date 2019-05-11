#include <map>

#include "Checkboard.h"
#include "FigureType/Bishop.h"
#include "FigureType/King.h"
#include "FigureType/Knight.h"
#include "FigureType/Pawn.h"
#include "FigureType/Queen.h"
#include "FigureType/Rook.h"

Checkboard::Checkboard() {
    // nulování šachovnice
    for (int y = 0; y < CHECKBOARD_LENGTH; y++) {
        for (int x = 0; x < CHECKBOARD_LENGTH; x++) {
            this->fields[y][x] = nullptr;
        }
    }

    // vytvoření figurek
    // věže
    this->addRook({.x = 0, .y = 0}, true);
    this->addRook({.x = 7, .y = 0}, true);
    this->addRook({.x = 0, .y = 7}, false);
    this->addRook({.x = 7, .y = 7}, false);

    // jezdci
    this->addKnight({.x = 1, .y = 0}, true);
    this->addKnight({.x = 6, .y = 0}, true);
    this->addKnight({.x = 1, .y = 7}, false);
    this->addKnight({.x = 6, .y = 7}, false);

    // střelci
    this->addBishop({.x = 2, .y = 0}, true);
    this->addBishop({.x = 5, .y = 0}, true);
    this->addBishop({.x = 2, .y = 7}, false);
    this->addBishop({.x = 5, .y = 7}, false);

    // dámy
    this->addQueen({.x = 3, .y = 0}, true);
    this->addQueen({.x = 3, .y = 7}, false);

    // králové
    this->addKing({.x = 4, .y = 0}, true);
    this->addKing({.x = 4, .y = 7}, false);

    // pěšci
    for (int y: {1, 6}) {
        for (int x = 0; x < 8; x++) {
            this->addPawn({.x = x, .y = y}, y == 1);
        }
    }
}

Figure* Checkboard::getFieldFigure(Field position) {
    return this->fields[position.y][position.x];
}

void Checkboard::setFieldFigure(Field position, Figure *figure) {
    this->fields[position.y][position.x] = figure;
}

void Checkboard::addBishop(Field position, bool white) {
    this->fields[position.y][position.x] = new Bishop(white, position, this);
}

void Checkboard::addKing(Field position, bool white) {
    this->fields[position.y][position.x] = new King(white, position, this);
}

void Checkboard::addKnight(Field position, bool white) {
    this->fields[position.y][position.x] = new Knight(white, position, this);
}

void Checkboard::addPawn(Field position, bool white) {
    this->fields[position.y][position.x] = new Pawn(white, position, this);
}

void Checkboard::addQueen(Field position, bool white) {
    this->fields[position.y][position.x] = new Queen(white, position, this);
}

void Checkboard::addRook(Field position, bool white) {
    this->fields[position.y][position.x] = new Rook(white, position, this);
}