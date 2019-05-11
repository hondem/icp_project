#ifndef CHESS_GMOVELIST_H
#define CHESS_GMOVELIST_H

#include <QListWidget>
#include <vector>
#include <QString>

class GMoveList : public QListWidget {
public:
    std::vector<QString *> items;
    GMoveList();
};


#endif //CHESS_GMOVELIST_H
