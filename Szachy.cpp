#include "Szachy.h"
#include "ui_szachy.h"
#include <QtWidgets>
#include <QPushButton>

Szachy::Szachy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Szachy)
{
    ui->setupUi(this);
}

Szachy::~Szachy()
{
    delete ui;
}

/*

ChessBoard::ChessBoard(QWidget* parent) {
    QGridLayout* grid = new QGridLayout(this);

    // create chessboard grid
    for(int row = 0; row < 8; ++row) {
        for(int col = 0; col < 8; ++col) {
            QPushButton* button = new QPushButton(this);
            button->setFixedSize(80, 80);

            if((row + col) % 2 == 0) {
                button->setStyleSheet("background-color: white");
            } else {
                button->setStyleSheet("background-color: gray");
            }

            grid->addWidget(button, row, col);
            buttons[row][col] = button;
        }
    }

    setLayout(grid);

    QGridLayout* grid_pieces = new QGridLayout(this);

}


ChessBoard::~ChessBoard()
{

}
*/

void Szachy::paintEvent()
{
    int x=0,y=0;
    int temp=0;
    QPainter painter;
    for(int i=0;i<8;i++)
    {
    for(int j=0;j<8;j++)
    {
       if(temp==0)
    {
    painter.setBrush(Qt::black);
    temp++;
    }
    else
    {
    painter.setBrush(Qt::white);
    temp--;
    }
       QRect r(x,y,100,100);
       painter.drawRect(r);
       x+=100;
    }
    x=0;
    y+=100;
    if(temp==0)
    temp=1;
    else
     temp=0;
    }

}

/*
void ChessBoard::onSquareClicked()
{

    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender()); // pobierz przycisk, który został kliknięty
    int row = clickedButton->property("row").toInt(); // odczytaj numer wiersza z właściwości przycisku
    int col = clickedButton->property("column").toInt(); // odczytaj numer kolumny z właściwości przycisku
    int piece = board[row][col];
    emit squareClicked(row, col); // wyślij sygnał z koordynatami kliknięcia


    QPushButton *button = qobject_cast<QPushButton *>(sender());
    int row = button->property("row").toInt();
    int col = button->property("col").toInt();
    int piece = board[row][col];



    if (selectedPiece == -1) {
        // Jeśli jeszcze nie wybrano figury, zaznacz wybraną figurę
        if (piece != 0) {
            selectedPiece = piece;
            selectedRow = row;
            selectedCol = col;
            clickedButton->setStyleSheet("background-color: white");
        }
    } else {
        // Jeśli już wybr1ano figurę, spróbuj przesunąć figurę na nową pozycję
        // if (is_move_valid(selectedRow, selectedCol, row, col)) {
            board[row][col] = selectedPiece;
            board[selectedRow][selectedCol] = 0;
            board[row][col]->setIcon(clickedButton->icon());
            board[selectedRow][selectedCol]->setIcon(QIcon());
        }
        board[selectedRow][selectedCol]->setStyleSheet("").toInt();
        selectedPiece = -1;
    }



ChessBoard::ChessBoard(QWidget *parent)
    : QWidget(parent)
{
    // Inicjalizacja planszy
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            board[row][col] = 0;
        }
    }

    // Ustawienie pionków białych
    board[0][0] = board[0][7] = 3;
    board[7][0] = board[7][7] = 4;
    for (int col = 0; col < 8; ++col) {
        board[1][col] = 1;
        board[6][col] = 2;
    }


// Ustawienie pozostałych figurek białych
board[0][1] = board[0][6] = 5;
board[0][2] = board[0][5] = 7;
board[0][3] = 11;
board[0][4] = 9;
// Ustawienie pozostałych figurek czarnych
board[7][1] = board[7][6] = 6;
board[7][2] = board[7][5] = 8;
board[7][3] = 12;
board[7][4] = 10;

// Ustawienie przycisków
QVBoxLayout *mainLayout = new QVBoxLayout;
for (int row = 0; row < 8; ++row) {
    QHBoxLayout *hLayout = new QHBoxLayout;
    for (int col = 0; col < 8; ++col) {
        m_buttons[row][col] = new QPushButton(this);
        m_buttons[row][col]->setFixedSize(50, 50);
        m_buttons[row][col]->setProperty("row", row);
        m_buttons[row][col]->setProperty("col", col);
        connect(m_buttons[row][col], &QPushButton::clicked, this, &ChessBoard::onSquareClicked);
        hLayout->addWidget(m_buttons[row][col]);
    }
    mainLayout->addLayout(hLayout);
}
setLayout(mainLayout);
}


ChessBoard::~ChessBoard()
    {

    }




ChessBoard::ChessBoard(QWidget *parent) : QWidget(parent)
{

    m_selectedX = -1;
    m_selectedY = -1;

    QGridLayout *layout = new QGridLayout(this);

    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
            {
                m_buttons[x][y] = new QPushButton(this);
                m_buttons[x][y]->setFixedSize(50, 50);
                m_buttons[x][y]->setProperty("x", x);
                m_buttons[x][y]->setProperty("y", y);
                m_board[x][y] = 0; // 0 - empty, 1 - white, 2 - black
                connect(m_buttons[x][y], &QPushButton::clicked, this, &ChessBoard::handleButtonClicked);
                layout->addWidget(m_buttons[x][y], y, x);
            }
    }

    for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
                if (m_board[x][y] == 1) {
                    m_buttons[x][y]->setText("W");
                } else if (m_board[x][y] == 2) {
                    m_buttons[x][y]->setText("B");
                }
            }
        }

}


void ChessBoard::initialize()
{

}

Field ChessBoard::getPosition()
{

}

*/






