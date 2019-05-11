#ifndef CPPPROJECT_FIELD_H
#define CPPPROJECT_FIELD_H

#include <string>
#include "Coords.h"

struct Coords;
/**
 * @brief Struktura pro zaznamenávání souřadnic na hrací ploše.
 */
struct Field {
    /**
     * Vodorovná složka
     */
    int x;

    /**
     * Svislá složka
     */
    int y;

    /**
     * Overloading operator for comparison
     * @param a
     * @return
     */
    bool operator==(const Field& a);

    /**
     * Overloading operator for comparison
     * @param a
     * @return
     */
    bool operator!=(const Field& a);

    /**
     * Overloading operator for adding
     * @param a
     * @return
     */
    Field operator+(const Field& a) const;

    /**
     * Overloading operator for substracting
     * @param a
     * @return
     */
    Field operator-(const Field& a) const;

    /**
     * Set X argument
     * @param x
     */
    void setX(int x);

    /**
     * Set Y argument
     * @param y
     */
    void setY(int y);

    /**
     * Converts coords string to field
     * @param coords
     * @return
     */
    static Field convertCoordsStringToField(std::string coords);

    /**
     * Converts field to coords instance
     * @param field
     * @return
     */
    static Coords convertFieldToCoords(Field field);
};
#endif //CPPPROJECT_FIELD_H
