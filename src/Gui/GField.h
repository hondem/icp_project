/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#ifndef CHESS_GFIELD_H
#define CHESS_GFIELD_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>

class GBoard;

/**
 * @brief One field of a board
 */
class GField : public QGraphicsRectItem {
    /**
     * @brief Parent
     */
    QGraphicsItem *parent;

    /**
     * @brief Board
     */
    GBoard *board;

public:
    /**
     * @brief True if the figure can go to the field.
     */
    bool available;

    /**
     * @brief True if the field is selected.
     */
    bool selected;

    /**
     * @brief Styles the field as selected
     */
    void styleSelected();

    /**
     * @brief Styles the field as not selected
     */
    void styleNotSelected();

    /**
     * @brief Styles the field as available.
     */
    void styleAvailable();

    /**
     * @brief Styles the field as not available.
     */
    void styleNotAvailable();

    /**
     * @brief X position of the field
     */
    int xPos;

    /**
     * @brief Y position of the field
     */
    int yPos;

    /**
     * @brief Creates new field.
     * @param parent parent
     * @param x X position
     * @param y Y position
     * @param board Board
     */
    GField(QGraphicsItem *parent, int x, int y, GBoard *board);

    /**
     * @brief Field click event handler.
     * @param event Event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};


#endif //CHESS_GFIELD_H
