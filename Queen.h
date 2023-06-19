#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
#include "Game.h"

/**
 * @brief Klasa reprezentująca królową (hetmana).
 *
 * Klasa Queen dziedziczy po klasie Piece i reprezentuje figurę królowej (hetmana) na szachownicy.
 */
class Queen : public Piece
{
public:
    /**
     * @brief Konstruktor klasy Queen.
     * \param team Kolor figury (biały lub czarny).
     */
    Queen(QString team);

    /**
     * @brief Destruktor klasy Queen.
     */
    ~Queen();

    /**
     * @brief Wykonanie ruchu przez królową.
     *
     * Metoda move() realizuje odpowiedni ruch królową na szachownicy.
     */
    void move();
};

#endif // QUEEN_H
