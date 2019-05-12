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

/**
 * @brief Class representing Parser
 */
class Parser{
public:
    /**
     * @brief Parse file with chess annotation
     * @param filePath Path to file
     * @return Parsed moves
     */
    static map<int, MoveRecord*> LoadFile(string filePath);

private:
    /**
     * @brief Converts move with chess annotation to move record
     * @param isWhitePlayer Indicates player
     * @param move Chess anotation
     * @return Parsed move
     */
    static MoveRecord* ConvertMove(bool isWhitePlayer, string move);

    /**
     * @brief Checks whether given line matches annotation schema
     * @param line Line to check
     * @return
     */
    static bool IsValidChessLine(string line);

    /**
     * @brief Gets first integer from given line
     * @param line
     * @return
     */
    static int GetLineIndex(string line);
};

#endif