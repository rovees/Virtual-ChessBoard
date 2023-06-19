#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "Game.h"
#include "Queen.h"

/**
 * @brief Klasa reprezentująca pionka.
 *
 * Klasa Pawn dziedziczy po klasie Piece i reprezentuje figurę szachową - pionka.
 */
class Pawn : public Piece
{
public:
    /**
     * @brief Konstruktor klasy Pawn.
     * \param team Kolor figury (biały lub czarny).
     */
    Pawn(QString team);

    /**
     * @brief Destruktor klasy Pawn.
     */
    ~Pawn();

    /**
     * @brief Realizacja ruchu pionka.
     *
     * Metoda move() implementuje możliwość ruchu pionka na planszy szachowej.
     */
    void move();
    void promoteToQueen();
};

#endif // PAWN_H
