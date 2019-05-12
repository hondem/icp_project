#ifndef CPPPROJECT_CHECKBOARD_H
#define CPPPROJECT_CHECKBOARD_H

#include "Figure.h"
#include "Field.h"
#include "Coords.h"
#include <string>

#define CHECKBOARD_LENGTH 8

class Figure;

/**
 * @brief Class representing a checkboard
 */
class Checkboard {
private:
    /**
     * @brief 2D array of pointers to Figure instance
     */
    Figure *fields[CHECKBOARD_LENGTH][CHECKBOARD_LENGTH];

    /**
     * @brief Adds bishop to certain field on board
     * @param position Field
     * @param white True if figure is white, else False
     */
    void addBishop(Field position, bool white);

    /**
     * @brief Adds king to certain field on board
     * @param position Field
     * @param white True if figure is white, else False
     */
    void addKing(Field position, bool white);

    /**
     * @brief Adds knight to certain field on board
     * @param position Field
     * @param white True if figure is white, else False
     */
    void addKnight(Field position, bool white);

    /**
     * @brief Adds pawn to certain field on board
     * @param position Field
     * @param white True if figure is white, else False
     */
    void addPawn(Field position, bool white);

    /**
     * @brief Adds queen to certain field on board
     * @param position Field
     * @param white True if figure is white, else False
     */
    void addQueen(Field position, bool white);

    /**
     * @brief Adds rook to certain field on board
     * @param position Field
     * @param white True if figure is white, else False
     */
    void addRook(Field position, bool white);
public:
    /**
     * @brief Constructor of checkboard
     * Creates new checkboard with all figures on its position
     */
    Checkboard();

    /**
     * @brief Return pointer to Figure which is on position, or nullptr
     * @param position Field on checkboard
     * @return Figure * Pointer to Figure
     */
    Figure *getFieldFigure(Field position);

    /**
     * @brief Places figure on certain field on checkboard
     * @param position Field on checkboard
     * @param figure Pointer to figure
     */
    void setFieldFigure(Field position, Figure *figure);
};


#endif //CPPPROJECT_CHECKBOARD_H
