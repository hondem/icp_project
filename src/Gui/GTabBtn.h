/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#ifndef CHESS_GTABBTN_H
#define CHESS_GTABBTN_H

#include <QToolButton>
#include <QMouseEvent>
#include "Window.h"

/**
 * @brief New tab button
 */
class GTabBtn : public QToolButton {
    /**
     * @brief Window object
     */
    Window *window;
public:
    /**
     * @brief Creates new add tab button
     * @param window Window to append
     */
    GTabBtn(Window *window);

    /**
     * @brief Mouse click event hanler
     * @param event Event
     */
    void mousePressEvent(QMouseEvent *event);
};


#endif //CHESS_GTABBTN_H
