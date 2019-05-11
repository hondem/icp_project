//
// Created by Jan Demel on 08/05/2019.
//

#include "GameEngine.h"
#include <typeinfo>
#include "FigureType/Bishop.h"
#include "FigureType/King.h"
#include "FigureType/Knight.h"
#include "FigureType/Pawn.h"
#include "FigureType/Queen.h"
#include "FigureType/Rook.h"

GameEngine::GameEngine(string inputFile) {
    this->gameSteps = Parser::LoadFile(inputFile);
    this->gameCheckboard = new Checkboard();
    this->currentMove = 0;

    this->redo();
}

void GameEngine::undo() {

}

void GameEngine::redo() {
    
}

void GameEngine::setStep(int stepIndex) {
    this->gameCheckboard = new Checkboard();
    for(int i = 0; i <= stepIndex; i++){

        MoveRecord *currentMoveRecord = this->gameSteps[i];

        Field targetField = Field::convertCoordsStringToField(currentMoveRecord->target);
        Figure *targetFigure = this->findFigure(currentMoveRecord);

        printf("Ahoooj\n");
    }
}

Checkboard* GameEngine::getCheckboard() {
    return this->gameCheckboard;
}

Figure* GameEngine::findFigure(MoveRecord* currentMove) {
    // All possible figures that can be moved
    vector<Figure*> potentials;

    for(int y = 0; y < CHECKBOARD_LENGTH; y++){
        for(int x = 0; x < CHECKBOARD_LENGTH; x++){
            Figure *currentPotentialFigure = this->getCheckboard()->getFieldFigure((Field){x, y});

            if(currentPotentialFigure != nullptr){
                string typeOfFigure = this->translateTypeOfFigure(currentPotentialFigure);
                if(
                    currentPotentialFigure->isWhite() == currentMove->isWhitePlayersMove &&
                    this->translateTypeOfFigure(currentPotentialFigure) == currentMove->figure
                ){
                    potentials.push_back(currentPotentialFigure);
                }
            }
        }
    }

    Field targetField = Field::convertCoordsStringToField(currentMove->target);
    string convertedTargetField = Coords::toString(Field::convertFieldToCoords(targetField));

    for(auto i = potentials.begin(); i != potentials.end(); i++){
        if(!(
            (*i)->isMovePossible(targetField) &&
            convertedTargetField.find(currentMove->source) != string::npos
        )) potentials.erase(i--);
    }

    if(potentials.size() > 1){
        throw new exception();
    }

    return potentials.front();
}

string GameEngine::translateTypeOfFigure(Figure *figure){
    if(figure != nullptr){
        if(typeid(*figure) == typeid(King)) return "K";
        else if(typeid(*figure) == typeid(Queen)) return "D";
        else if(typeid(*figure) == typeid(Rook)) return "V";
        else if(typeid(*figure) == typeid(Bishop)) return "S";
        else if(typeid(*figure) == typeid(Knight)) return "J";
        else if(typeid(*figure) == typeid(Pawn)) return "p";
        else return "";
    } else return "";
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