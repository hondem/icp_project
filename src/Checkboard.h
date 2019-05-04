#ifndef CPPPROJECT_CHECKBOARD_H
#define CPPPROJECT_CHECKBOARD_H

#include "Figure.h"
#include "Field.h"

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
public:
    /**
     * @brief Kontruktor šachovnice.
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
