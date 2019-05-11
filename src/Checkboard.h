#ifndef CPPPROJECT_CHECKBOARD_H
#define CPPPROJECT_CHECKBOARD_H

#include "Figure.h"
#include "Field.h"
#include "Coords.h"
#include <string>

#define CHECKBOARD_LENGTH 8

class Figure;

/**
 * @brief Třída reprezentující jednu šachovnici.
 */
class Checkboard {
private:
    /**
     * @brief 2D pole ukazatelů na figureku.
     */
    Figure *fields[CHECKBOARD_LENGTH][CHECKBOARD_LENGTH];

    /**
     * @brief Přidá střelce na dané políčko
     * @param position Políčko, kde se vytvoří nová figurka
     * @param white True, pokud se jedná o bílou figurku, False pro černou.
     */
    void addBishop(Field position, bool white);

    /**
     * @brief Přidá krále na dané políčko
     * @param position Políčko
     * @param white True, pokud se jedná o bílou figurku, False pro černou.
     */
    void addKing(Field position, bool white);

    /**
     * @brief Přidá jezdce na dané políčko
     * @param position Políčko
     * @param white True, pokud se jedná o bílou figurku, False pro černou.
     */
    void addKnight(Field position, bool white);

    /**
     * @brief Přidá pěšce na dané políčko
     * @param position Políčko
     * @param white True, pokud se jedná o bílou figurku, False pro černou.
     */
    void addPawn(Field position, bool white);

    /**
     * @brief Přidá dámu na dané políčko
     * @param position Políčko
     * @param white True, pokud se jedná o bílou figurku, False pro černou.
     */
    void addQueen(Field position, bool white);

    /**
     * @brief Přidá věž na dané políčko
     * @param position Políčko
     * @param white True, pokud se jedná o bílou figurku, False pro černou.
     */
    void addRook(Field position, bool white);
public:
    /**
     * @brief Kontruktor šachovnice.
     * Vytvoří novou šachovnici se všemi figurkami na svých místech.
     */
    Checkboard();

    /**
     * @brief Vrací ukazatel na Figure, která je na pozici position, nebo nullptr.
     *
     * @param position Pozice na šachovnici
     * @return Figure * ukazatel na figurku
     */
    Figure *getFieldFigure(Field position);

    /**
     * @brief Umístí figurku na danou pozici na šachovnici.
     *
     * @param position Pozice na šachovnici
     * @param figure Ukazatel na figurku
     */
    void setFieldFigure(Field position, Figure *figure);
};


#endif //CPPPROJECT_CHECKBOARD_H
