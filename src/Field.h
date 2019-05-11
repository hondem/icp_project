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
     * Overriding operator for comparison
     * @param a
     * @return
     */
    bool operator==(const Field& a) {
        return (x == a.x && y == a.y);
    }

    /**
     * Overriding operator for comparison
     * @param a
     * @return
     */
    bool operator!=(const Field& a) {
        return !(x == a.x && y == a.y);
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
