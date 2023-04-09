#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iostream>
#include <QString>
#include <vector>

using namespace std;


class Position
{
    int col;
    int row;
};

enum PieceType
{
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King,
    Empty
};

enum Color
{
    White,
    Black
};


/*
class Knight : public Piece
{
public:
    Knight(PieceType t, Color c);
    virtual PieceType getType(PieceType type);
    virtual void move(Position from, Position to);
    virtual Position getPosition();
    virtual Color getColor();
    virtual bool isMoveValid();
    ~Knight();
};

class Bishop : public Piece
{
public:
    Bishop(PieceType t, Color c);
    virtual PieceType getType(PieceType type);
    virtual void move(Position from, Position to);
    virtual Position getPosition();
    virtual Color getColor();
    virtual bool isMoveValid();
    ~Bishop();
};

class Rook : public Piece
{
public:
    Rook(PieceType t, Color c);
    virtual PieceType getType(PieceType type);
    virtual void move(Position from, Position to);
    virtual Position getPosition();
    virtual Color getColor();
    virtual bool isMoveValid();
    ~Rook();
};

class Queen : public Piece
{
public:
    Queen(PieceType t, Color c);
    virtual PieceType getType(PieceType type);
    virtual void move(Position from, Position to);
    virtual Position getPosition();
    virtual Color getColor();
    virtual bool isMoveValid();
    ~Queen();
};

class King : public Piece
{
public:
    King(PieceType t, Color c);
    virtual PieceType getType(PieceType type);
    virtual void move(Position from, Position to);
    virtual Position getPosition();
    virtual Color getColor();
    virtual bool isMoveValid();
    ~King();
};


class ChessBoard
{
    // Field  fields[8][8];
    Piece *board[8][8];


public:
    ChessBoard(bool Pawns, bool Knights, bool Bishops, bool Queens, bool Kings);
    Field getPosition(Piece p); // return p.position; jako argument chyba event kliknięcia myszką na figurę
    void initialize(); // funkcja inicjująca szachownicę wraz z figurmi
    void printBoardAxes();
    Piece *getPiece(const std::pair<int, int> &coords) const;
    ~ChessBoard();
};
*/


#endif // STRUCTURES_H

