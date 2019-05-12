#ifndef MOVERECORD_HEADER
#define MOVERECORD_HEADER

#include <sstream>
#include <string>

using namespace std;

/**
 * @brief Struct representing MoveRecord
 */
struct MoveRecord{
    /**
     * @brief To detect which player's move is it
     */
    bool isWhitePlayersMove;

    /**
     * @brief Source field
     */
    string source;

    /**
     * @brief Target field
     */
    string target;

    /**
     * @brief Type of figure to move
     */
    string figure;

    /**
     * @brief Throws the figure on target field out
     */
    bool throwAway;

    /**
     * @brief Contains whether it is check or mat
     */
    char flag;

    /**
     * @brief Converts MoveRecord to string
     * @param moveRecord
     * @return
     */
    string static toString(MoveRecord *moveRecord);
};

#endif