#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QGraphicsRectItem>
#include "Piece.h"

class ChessBoard
{
public:
    /**
     * @brief Konstruktor klasy ChessBoard.
     */
    ChessBoard();

    /**
     * @brief Destruktor klasy ChessBoard.
     */
    ~ChessBoard();

    /**
     * @brief Metoda rysuje pola szachownicy.
     * \param x Współrzędna x pierwszego pola szachownicy.
     * \param y Współrzędna y pierwszego pola szachownicy.
     */
    void drawBoxes(int x, int y);

    /**
     * @brief Metoda ustawia białe figury na szachownicy.
     */
    void setUpWhite();

    /**
     * @brief Metoda ustawia czarne figury na szachownicy.
     */
    void setUpBlack();

    /**
     * @brief Metoda dodaje figurę do szachownicy.
     */
    void addChessPiece();

private:
    QList<Piece*> white; /**< Lista przechowująca białe figury. */
    QList<Piece*> black; /**< Lista przechowująca czarne figury. */
};

#endif // CHESSBOARD_H
