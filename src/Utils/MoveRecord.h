#ifndef MOVERECORD_HEADER
#define MOVERECORD_HEADER

#include <string>

using namespace std;

struct MoveRecord{
    /**
     * To detect which player's move is it
     */
    bool isWhitePlayersMove;

    /**
     * Source field
     */
    string source;

    /**
     * Target field
     */
    string target;

    /**
     * Type of figure to move
     */
    string figure;

    /**
     * Throws the figure on target field out
     */
    bool throwAway;

    /**
     * Contains whether it is check or mat
     */
    char flag;
};

#endif