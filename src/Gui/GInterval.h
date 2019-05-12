/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#ifndef CHESS_GINTERVAL_H
#define CHESS_GINTERVAL_H

#include <QSpinBox>

/**
 * @brief Interval for the game auto play
 */
class GInterval : public QSpinBox {
public:
    /**
     * @brief Generates new input
     */
    GInterval();
};


#endif //CHESS_GINTERVAL_H
