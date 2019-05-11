#include "MoveRecord.h"

string MoveRecord::toString(MoveRecord *moveRecord) {
    //moveRecord->figure + moveRecord->source + ((moveRecord->throwAway) ? "x" : "") + moveRecord->target
    stringstream ss;
    char myFlag[2];
    myFlag[0] = moveRecord->flag;
    ss << moveRecord->figure << moveRecord->source << ((moveRecord->throwAway) ? "x" : "") << moveRecord->target << ((moveRecord->flag != '\0') ? string(myFlag) : "");
    return ss.str();
    //return this.figure + this.source + ((this.throwAway) ? 'x' : "") + this.target + ((this.flag != '\u0000') ? this.flag : "");
}