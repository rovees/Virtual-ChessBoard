#ifndef SZACHY_H
#define SZACHY_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QtWidgets>
#include <QObject>
#include <set>
#include <QGraphicsPixmapItem>
#include "logika.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Szachy; }
QT_END_NAMESPACE

class Szachy : public QMainWindow
{
    Q_OBJECT

private:
    Ui::Szachy *ui;
    QPushButton* buttons[8][8];

public:
    Szachy(QWidget *parent = nullptr);
    void paintEvent();
    ~Szachy();
};

/*
class ChessBoard : public QWidget
{
public:
    ChessBoard(QWidget* parent = nullptr);
    void makeMove();
    ~ChessBoard();

private:
    QPushButton* buttons[8][8];
    QPushButton* pieces[8][8];
};
*/


class CPieceIcon : public QGraphicsItem
{
public:
    CPieceIcon(int row, int col, QColor color, QGraphicsItem *parent = nullptr) :
        QGraphicsItem(parent), m_row(row), m_col(col), m_color(color)
    {
        setPos(col * 50, row * 50);
        setZValue(1);
    }

    QRectF boundingRect() const override
    {
        return QRectF(0, 0, 50, 50);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override
    {
        painter->setBrush(QBrush(m_color));
        painter->drawEllipse(0, 0, 50, 50);
    }

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override
    {
        m_mousePos = event->pos();
    }

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override
    {
        QPointF delta = event->pos() - m_mousePos;
        moveBy(delta.x(), delta.y());
        m_row = pos().y() / 50;
        m_col = pos().x() / 50;
        m_mousePos = event->pos();
    }

private:
    int m_row;
    int m_col;
    QColor m_color;
    QPointF m_mousePos;
};


// implementacja szachownicy w gui
//

/*
class ChessBoard : public QWidget
{
    Q_OBJECT

public:
    ChessBoard(QWidget *parent = nullptr);
    // void initialize(); // funkcja inicjująca szachownicę wraz z figurmi
    // Field getPosition(); // return p.position; jako argument chyba event kliknięcia myszką na figurę
    ~ChessBoard();

private slots:
    void onSquareClicked();

signals:
    void squareClicked(int row, int column);

private:
    // Field  fields[8][8];
    // Piece *board[8][8];
    int selectedPiece;
    int selectedRow; // współrzędna rzędu wybranej figury
    int selectedCol; // współrzędna kolumny wybranej figury
    int board [8][8];
    QPushButton *m_buttons[8][8]; // tablica przycisków odpowiadających polom szachownicy
};
*/
#endif // SZACHY_H


