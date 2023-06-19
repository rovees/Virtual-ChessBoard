#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include "Game.h"

/**
 * @brief Klasa reprezentująca figurę gońca.
 *
 * Klasa Bishop dziedziczy po klasie Piece i implementuje interfejs ruchu dla gońca.
 */
class Bishop : public Piece
{
public:
    /**
     * @brief Konstruktor klasy Bishop.
     * \param team Kolor figury (biały lub czarny).
     */
    Bishop(QString team);

    /**
     * @brief Destruktor klasy Bishop.
     */
    ~Bishop();

    /**
     * @brief Wykonaj ruch gońcem.
     *
     * Metoda implementująca ruch gońcem na szachownicy.
     * Sprawdza dostępne pola, na które gońcem można się przemieścić.
     */
    void move();
};

#endif // BISHOP_H
