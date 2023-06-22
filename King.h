#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Game.h"

/**
 * @brief Klasa reprezentująca króla.
 *
 * Klasa King dziedziczy po klasie Piece i implementuje metody związane z ruchem króla.
 */
class King : public Piece
{
public:
    /**
     * @brief Konstruktor klasy King.
     * \param team Kolor króla (biały lub czarny).
     */
    King(QString team);

    /**
     * @brief Destruktor klasy King.
     */
    ~King();

    /**
     * @brief Sprawdza, czy dane pole szachowe jest bezpieczne dla króla.
     * \param square Wskaźnik na obiekt ChessSquare reprezentujący dane pole szachowe.
     * @return Wartość logiczna, czy pole szachowe jest bezpieczne dla króla.
     */
    bool isLocationUnsafe(ChessSquare* square);

    /**
     * @brief Znajduje niebezpieczne pola dla króla.
     *
     * Metoda findUnSafeLocation() znajduje pola szachowe, na które król nie może się przemieścić
     * ze względu na zagrożenie.
     */
    void findUnSafeLocation();

    /**
     * @brief Realizuje ruch króla.
     *
     * Metoda move() realizuje ruch króla na planszy szachowej.
     */
    void move();

    /**
     * @brief Ustawia flagę informującą o możliwości wykonania długiej roszady.
     * \param value Wartość logiczna określająca, czy król może wykonać roszadę.
     */
    void setLongCastling(bool value);

    /**
     * @brief Ustawia flagę informującą o możliwości wykonania krótkiej roszady.
     * \param value Wartość logiczna określająca, czy król może wykonać roszadę.
     */
    void setShortCastling(bool value);

    /**
     * @brief Pobiera wartość flagi informującej o możliwości wykonania długiej roszady.
     * @return Wartość logiczna, czy król może wykonać roszadę.
     */
    bool getLongCastling();

    /**
     * @brief Pobiera wartość flagi informującej o możliwości wykonania krótkiej roszady.
     * @return Wartość logiczna, czy król może wykonać roszadę.
     */
    bool getShortCastling();

private:
    bool longCastling; ///< Flaga informująca, czy król może wykonać długą roszadę.
    bool shortCastling; ///< Flaga informująca czy król może wykonać krótką roszadę.
};

#endif // KING_H
