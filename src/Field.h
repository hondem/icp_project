#ifndef CPPPROJECT_FIELD_H
#define CPPPROJECT_FIELD_H

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
    bool operator==(const Field& a) {
        return (x == a.x && y == a.y);
    }

    /**
     * Overloading operator for comparison
     * @param a
     * @return
     */
    bool operator!=(const Field& a) {
        return !(x == a.x && y == a.y);
    }

    /**
     * Overloading operator for adding
     * @param a
     * @return
     */
    Field operator+(const Field& a) const {
        return (Field){x+a.x, y+a.y};
    }

    /**
     * Overloading operator for substracting
     * @param a
     * @return
     */
    Field operator-(const Field& a) const {
        return (Field){x-a.x, y-a.y};
    }

    /**
     * Set X argument
     * @param x
     */
    void setX(int x){
        this->x = x;
    }

    /**
     * Set Y argument
     * @param y
     */
    void setY(int y){
        this->y = y;
    }
};
#endif //CPPPROJECT_FIELD_H
