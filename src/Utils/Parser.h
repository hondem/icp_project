#ifndef PARSER_HEADER
#define PARSER_HEADER

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <regex>
#include <map>

#include "MoveRecord.h"

using namespace std;

class Parser{
public:
    /**
     * Parse file with chess annotation
     * @param filePath Path to file
     * @return Parsed moves
     */
    static map<int, MoveRecord*> LoadFile(string filePath);

private:
    /**
     * Converts move with chess annotation to move record
     * @param isWhitePlayer Indicates player
     * @param move Chess anotation
     * @return Parsed move
     */
    static MoveRecord* ConvertMove(bool isWhitePlayer, string move);

    /**
     * Checks whether given line matches annotation schema
     * @param line Line to check
     * @return
     */
    static bool IsValidChessLine(string line);

    /**
     * Gets first integer from given line
     * @param line
     * @return
     */
    static int GetLineIndex(string line);
};

#endif