#ifndef CHESS_GMOVELIST_H
#define CHESS_GMOVELIST_H

#include <QListWidget>
#include <vector>
#include <QString>

/**
 * @brief List of moves
 */
class GMoveList : public QListWidget {
public:
    /**
     * @brief Items of the list
     */
    std::vector<QString *> items;

    /**
     * @brief Creates new steps list
     */
    GMoveList();
};


#endif //CHESS_GMOVELIST_H
