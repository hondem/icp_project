#include "Parser.h"
#include <array>

using namespace std;

map<int, MoveRecord*> Parser::LoadFile(string filePath) {
    ifstream infile(filePath);
    string inputLine;

    // Loaded file lines will be stored here
    list<string> loadedFile;

    while(getline(infile, inputLine)){
        loadedFile.push_back(inputLine);
    }

    // Now let's sort them to be in right order!
    map<int, string> lines;

    for (string line : loadedFile) {
        // Let's find out, if given line might be a valid line
        if (Parser::IsValidChessLine(line)) {

            int lineIndex = Parser::GetLineIndex(line) - 1;

            // If there is already something stored on position, where the string belongs to... ERROR!!!
            try {
                if (lines[lineIndex].empty() && lineIndex < loadedFile.size()) {
                    // Insert the part of line without index number (we don't need it anymore :))
                    line = line.substr(line.find(". ") + 2, line.length());
                    //line = line.erase(line.size() - 1);

                    lines[lineIndex] = line;
                } else {
                    throw exception();
                }
            } catch (exception e) {
                throw exception();
            }
        }
    }

    // Aaaaaand parsed move records goes here!
    map<int, MoveRecord*> moveRecords;

    for (int i = 0; i < lines.size(); i++) {
        bool isWhitePlayer = true;

        string playerA = lines[i].substr(0, lines[i].find(" "));
        string playerB = lines[i].substr(lines[i].find(" ") + 1, lines[i].length());

        moveRecords[i * 2] = Parser::ConvertMove(isWhitePlayer, playerA);
        isWhitePlayer = !isWhitePlayer;
        moveRecords[i * 2 + 1] = Parser::ConvertMove(isWhitePlayer, playerB);
    }

    return moveRecords;
}

bool Parser::IsValidChessLine(string line){
    return regex_match(line, regex("^[1-9][0-9]*\\.\\s[^.]+\\s[^.]+$"));
}

int Parser::GetLineIndex(string line){
    return stoi(line.substr(0, line.find(".")));
}

MoveRecord* Parser::ConvertMove(bool isWhitePlayer, string move){
    MoveRecord *ret = new MoveRecord();
    ret->isWhitePlayersMove = isWhitePlayer;

    int DFA_STATE = 0;
    int charIndex = 0;
    string buffer = "";

    while(!(
        DFA_STATE == 18 ||
        charIndex >= move.length()
    )){
        int inputChar = (int) move[charIndex];

        switch (DFA_STATE){
            case 0:
                if (
                        (char)inputChar == 'K' ||
                        (char)inputChar == 'D' ||
                        (char)inputChar == 'V' ||
                        (char)inputChar == 'S' ||
                        (char)inputChar == 'J' ||
                        (char)inputChar == 'p'
                        ){
                    buffer += (char)inputChar;
                    DFA_STATE = 1;
                } else {
                    DFA_STATE = 2;
                }
                break;

            case 1:
                ret->figure = buffer;
                charIndex++;
                DFA_STATE = 2;
                buffer = "";
                break;

            case 2:
                // If char is 1-8
                if(inputChar >= 49 && inputChar <= 56){
                    buffer += (char)inputChar;
                    DFA_STATE = 3;
                    // If char is a-h
                } else if(inputChar >= 97 && inputChar <= 104){
                    buffer += (char)inputChar;
                    DFA_STATE = 4;
                    charIndex++;
                } else {
                    DFA_STATE = 5;
                }
                break;

            case 3:
                ret->source = buffer;
                charIndex++;
                DFA_STATE = 5;
                buffer = "";
                break;

            case 4:
                // If char is 1-8
                if(inputChar >= 49 && inputChar <= 56){
                    buffer += (char)inputChar;
                    DFA_STATE = 6;
                } else {
                    DFA_STATE = 7;
                }
                break;

            case 5:
                if((char)inputChar == 'x'){
                    buffer += (char)inputChar;
                    DFA_STATE = 8;
                } else {
                    DFA_STATE = 9;
                }
                break;

            case 6:
                ret->source = buffer;
                charIndex++;
                DFA_STATE = 5;
                buffer = "";
                break;

            case 7:
                ret->source = buffer;
                charIndex++;
                DFA_STATE = 5;
                buffer = "";
                break;

            case 8:
                ret->throwAway = true;
                charIndex++;
                DFA_STATE = 9;
                buffer = "";
                break;

            case 9:
                // If char is 1-8
                if(inputChar >= 49 && inputChar <= 56){
                    buffer += (char)inputChar;
                    DFA_STATE = 12;
                    // If char is a-h
                } else if(inputChar >= 97 && inputChar <= 104){
                    buffer += (char)inputChar;
                    DFA_STATE = 10;
                    charIndex++;
                } else {
                    DFA_STATE = 11;
                }
                break;

            case 10:
                // If char is 1-8
                if(inputChar >= 49 && inputChar <= 56){
                    buffer += (char)inputChar;
                    DFA_STATE = 14;
                } else {
                    DFA_STATE = 13;
                }
                break;

            case 11:
                if (
                        (char)inputChar == 'K' ||
                        (char)inputChar == 'D' ||
                        (char)inputChar == 'V' ||
                        (char)inputChar == 'S' ||
                        (char)inputChar == 'J' ||
                        (char)inputChar == 'p'
                        ) {
                    buffer += (char)inputChar;
                    DFA_STATE = 15;
                } else {
                    DFA_STATE = 16;
                }
                break;

            case 12:
                ret->target = buffer;
                charIndex++;
                DFA_STATE = 11;
                buffer = "";
                break;

            case 13:
                ret->target = buffer;
                charIndex++;
                DFA_STATE = 11;
                buffer = "";
                break;

            case 14:
                ret->target = buffer;
                charIndex++;
                DFA_STATE = 11;
                buffer = "";
                break;

            case 15:
                ret->target = buffer;
                charIndex++;
                DFA_STATE = 16;
                buffer = "";
                break;

            case 16:
                if (
                        (char)inputChar == '#' ||
                        (char)inputChar == '+'
                        ){
                    buffer += (char)inputChar;
                    DFA_STATE = 17;
                } else {
                    DFA_STATE = 18;
                }
                break;

            case 17:
                ret->flag = buffer[0];
                DFA_STATE = 18;
                break;
        }
    }

    if (ret->target.empty() && !ret->source.empty()) {
        ret->target = ret->source;
        ret->source = "";
    }

    if (ret->figure.empty()) {
        ret->figure = "p";
    }

    return ret;
}