# ICP Project 2019
## MiniDoc
### Parser
#### Example usage
```cpp
map<int, MoveRecord*> parsedMoves = Parser::LoadFile("../tests/3.src");
```
#### MoveRecord structure
```cpp
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
```


## Contributors  
**Martin Buchta** - <xbucht28@stud.fit.vutbr.cz>  
**Jan Demel** - <xdemel01@stud.fit.vutbr.cz>
