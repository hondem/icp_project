#ifndef CPPPROJECT_FIGURE_H
#define CPPPROJECT_FIGURE_H

#include "Field.h"
#include "Checkboard.h"

class Checkboard;

/**
 * @brief Třída, jejíž instance reprezentují jednotlivé šachové figurky.
 */
class Figure {
private:
    /**
     * @brief Aktuální pozice figurky
     */
    Field position;

    /**
     * @brief True pokud je figurka bílá.
     */
    bool whiteColor;

protected:

    /**
     * @brief Ukazatel na šachovnici, na které je daná figurka.
     */
    Checkboard *checkboard;

public:
    /**
     * @brief Konstruktor figurky
     * @param white True pokud je nová figurka bílá, False pokud černá
     * @param position Počáteční pozice figurky
     * @param checkboard Ukazatel na šachovnici, na které bude figurka umístěna.
     */
    Figure(bool white, Field position, Checkboard *checkboard);

    /**
     * @brief Vrací barvu figurky.
     * @return True, pokud je barva bílá.
     */
    bool isWhite();

    /**
     * @brief Vrací pozici figurky
     * @return
     */
    Field getPosition();

    /**
     * Abstraktní metoda
     *
     * @brief Kontroluje, jestli daná figurka může provést tah na dané políčko.
     * @param field Cílové políčko.
     * @return bool Vrací true, pokud figurka může provést tah.
     */
    virtual bool isMovePossible(Field field);

    char figureImg[200];
};


#endif //CPPPROJECT_FIGURE_H
