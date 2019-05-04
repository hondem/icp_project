#ifndef CPPPROJECT_FIGURE_H
#define CPPPROJECT_FIGURE_H

#include "Field.h"

class Figure {
private:
    /**
     * @brief Aktuální pozice figurky
     */
    Field position;

protected:
    /**
     * @brief True pokud je figurka bílá.
     */
    bool whiteColor;

public:
    /**
     * @brief Konstruktor figurky
     * @param white True pokud je nová figurka bílá, False pokud černá
     * @param position Počáteční pozice figurky
     */
    Figure(bool white, Field position);

    /**
     * @brief Vrací barvu figurky.
     * @return True, pokud je barva bílá.
     */
    bool isWhite();

    /**
     * Abstraktní metoda
     *
     * @brief Kontroluje, jestli daná figurka může provést tah na dané políčko.
     * @param field Cílové políčko.
     * @return bool Vrací true, pokud figurka může provést tah.
     */
    virtual bool isMovePossible(Field field);
};


#endif //CPPPROJECT_FIGURE_H
