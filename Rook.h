#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

/**
 * @brief Klasa reprezentująca wieżę na szachownicy.
 *
 * Klasa Rook dziedziczy po klasie Piece i odpowiada za logikę ruchu wieży na szachownicy.
 */
class Rook : public Piece
{
public:
    /**
     * @brief Konstruktor klasy Rook.
     * \param team Strona (kolor) figury - "biały" lub "czarny".
     */
    Rook(QString team);

    /**
     * @brief Destruktor klasy Rook.
     */
    ~Rook();

    /**
     * @brief Wykonuje ruch wieży na szachownicy.
     *
     * Metoda move() implementuje logikę ruchu wieży na szachownicy.
     */
    void move();
};

#endif // ROOK_H
