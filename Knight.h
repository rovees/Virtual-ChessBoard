#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

/**
 * @brief Klasa reprezentująca skoczka.
 *
 * Klasa Knight dziedziczy po klasie Piece i reprezentuje figurę szachową - skoczka.
 */
class Knight : public Piece
{
public:
    /**
     * @brief Konstruktor klasy Knight.
     * \param team Kolor figury (biały lub czarny).
     */
    Knight(QString team);

    /**
     * @brief Destruktor klasy Knight.
     */
    ~Knight();

    /**
     * @brief Realizuje ruch skoczka.
     *
     * Metoda move() implementuje odpowiedni ruch dla figury szachowej - skoczka.
     */
    void move();
};

#endif // KNIGHT_H
