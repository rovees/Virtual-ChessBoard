#ifndef LOGIKA_H
#define LOGIKA_H

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
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    EMPTY
};

enum Color
{
    WHITE,
    BLACK
};

class Piece
{

protected:
    PieceType type;
    Color color;
    Position position;

public:
    Piece(PieceType t, Color c);
    virtual void getType(PieceType type) = 0;
    virtual void move(Position from, Position to) = 0; // funkcja zlecająca ruch daną figurą
    virtual Position getPosition() = 0;
    virtual Color getColor() = 0;
    virtual bool isMoveValid() = 0;
};

class Pawn : public Piece
{
public:
    Pawn(PieceType t, Color c);
    virtual void getType(PieceType type);
    virtual void move(Position from, Position to);
    virtual Position getPosition();
    virtual Color getColor();
    virtual bool isMoveValid();
    /*
    bool czyRuchJestLegalny(int x1, int y1, int x2, int y2, Piece* pionki[8][8]); // sprawdza, czy ruch figury jest zgodny z zasadami szachów
    bool czyPoleMoznaZajac(int x, int y, Piece* pionki[8][8]); // sprawdza, czy pole na szachownicy jest wolne i można je zająć przez figurę
    */
    ~Pawn();
};

class Knight : public Piece
{
public:
    Knight(PieceType t, Color c);
    virtual void getType(PieceType type);
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
    virtual void getType(PieceType type);
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
    virtual void getType(PieceType type);
    virtual void move(Position from, Position to);
    virtual Position getPosition();
    virtual Color getColor();
    virtual bool isMoveValid();
    // ~Rook();
};

class Queen : public Piece
{
public:
    Queen(PieceType t, Color c);
    virtual void getType(PieceType type);
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
    virtual void getType(PieceType type);
    virtual void move(Position from, Position to);
    virtual Position getPosition();
    virtual Color getColor();
    virtual bool isMoveValid();
    ~King();
};

/*
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


class ChessBoard
{
    vector <vector <Piece>> *board; // szachownica w postaci tablicy dwuwymiarowej
    Color turn;

public:
    ChessBoard();
    void getPiece();
    Color getTurn(Color turn);
    // void setTurn();
    bool makeMove(bool moveValid); // zwraca true jeżeli ruch został wykonany, w przeciwnym wypadku zwraca false
    bool isFieldEmpty(Position pos); // funkcja sprawdzająca czy pole na szachownicy jest puste
    void getBoard(vector <vector<string>> board); // uaktualnianie stanu szachownicy w trakcie partii
    ~ChessBoard();
};


// obiekt reprezentujący szachownicę od strony aktualnego stanu pozycji figur i pól
class ChessGame
{
    ChessGame();
    void makeMove(); // funkcja realizująca dany ruch na szachownicy, aktualizacja stanu szachownicy
    void run();
    ~ChessGame();
};

#endif // LOGIKA_H

