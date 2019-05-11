//
// Created by Jan Demel on 08/05/2019.
//

#include "GameEngine.h"

GameEngine::GameEngine(string inputFile) {
    this->gameSteps = Parser::LoadFile(inputFile);
    this->gameCheckboard = new Checkboard();
}

void GameEngine::start() {

}

void GameEngine::pause() {

}

void GameEngine::undo() {

}

void GameEngine::redo() {

}

void GameEngine::setStep(int stepIndex) {

}

Checkboard* GameEngine::getCheckboard() {
    return this->gameCheckboard;
}

void GameEngine::moveFigure(Figure *figure, Field target) {
    if (false == figure->isMovePossible(target)) {
        return;
    }

    Field origField = figure->getPosition();

    this->gameCheckboard->setFieldFigure(target, figure);
    this->gameCheckboard->setFieldFigure(origField, nullptr);
    figure->setPosition(target);
}