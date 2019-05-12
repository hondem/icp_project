#ifndef CPPPROJECT_FIGURE_H
#define CPPPROJECT_FIGURE_H

#include "Field.h"
#include "Checkboard.h"

class Checkboard;

/**
 * @brief Class, whose instance represents single figure
 */
class Figure {
private:
    /**
     * @brief Current figure position
     */
    Field position;

    /**
     * @brief True if figure is white
     */
    bool whiteColor;

protected:

    /**
     * @brief Pointer to checkboard where figure is saved
     */
    Checkboard *checkboard;

public:
    /**
     * @brief Constructor of figure
     * @param white True if new figure is white, else False
     * @param position Beginning position of figure
     * @param checkboard Pointer to checkboard where figure should be saved
     */
    Figure(bool white, Field position, Checkboard *checkboard);

    /**
     * @brief Returns color of figure
     * @return True, if color is white, else False
     */
    bool isWhite();

    /**
     * @brief Returns position of figure
     * @return
     */
    Field getPosition();

    /**
     * @brief Sets new position to the figure
     * @param position New position
     */
    void setPosition(Field position);

    /**
     * Abstract method
     * @brief Checks, whether figure can move to certain field
     * @param field Target field
     * @return bool Returns true, when figure can move to target field
     */
    virtual bool isMovePossible(Field field);

    char figureImg[200];
};


#endif //CPPPROJECT_FIGURE_H
