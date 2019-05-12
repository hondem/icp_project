/**
 * @authors Martin Buchta (xbucht28@fit.vutbr.cz) Jan Demel (xdemel01@fit.vutbr.cz)
 */

#ifndef CPPPROJECT_FIELD_H
#define CPPPROJECT_FIELD_H

#include <string>
#include "Coords.h"

struct Coords;
/**
 * @brief Struct for fields on checkboard
 */
struct Field {
    /**
     * @brief Horizontal
     */
    int x;

    /**
     * @brief Vertical
     */
    int y;

    /**
     * @brief Overloading operator for comparison
     * @param a
     * @return
     */
    bool operator==(const Field& a);

    /**
     * @brief Overloading operator for comparison
     * @param a
     * @return
     */
    bool operator!=(const Field& a);

    /**
     * @brief Overloading operator for adding
     * @param a
     * @return
     */
    Field operator+(const Field& a) const;

    /**
     * @brief Overloading operator for substracting
     * @param a
     * @return
     */
    Field operator-(const Field& a) const;

    /**
     * @brief Set X argument
     * @param x
     */
    void setX(int x);

    /**
     * @brief Set Y argument
     * @param y
     */
    void setY(int y);

    /**
     * @brief Converts coords string to field
     * @param coords
     * @return
     */
    static Field convertCoordsStringToField(std::string coords);

    /**
     * @brief Converts field to coords instance
     * @param field
     * @return
     */
    static Coords convertFieldToCoords(Field field);
};
#endif //CPPPROJECT_FIELD_H
