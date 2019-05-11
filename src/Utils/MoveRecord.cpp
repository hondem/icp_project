#include "MoveRecord.h"

string MoveRecord::toString(MoveRecord *moveRecord) {
    //moveRecord->figure + moveRecord->source + ((moveRecord->throwAway) ? "x" : "") + moveRecord->target
    stringstream ss;
    ss << moveRecord->figure << moveRecord->source << ((moveRecord->throwAway) ? "x" : "") << moveRecord->target;
    return ss.str();
    //return this.figure + this.source + ((this.throwAway) ? 'x' : "") + this.target + ((this.flag != '\u0000') ? this.flag : "");
}