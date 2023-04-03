#include "Board.h"
#include "Szachy.h"
#include <QApplication>
#include <QtWidgets>

/*
class ChessBoard : public QWidget {
public:
    ChessBoard(QWidget* parent = nullptr) : QWidget(parent) {
        QGridLayout* grid = new QGridLayout(this);

        // create chessboard grid
        for(int row = 0; row < 8; ++row) {
            for(int col = 0; col < 8; ++col) {
                QPushButton* button = new QPushButton(this);
                button->setFixedSize(50, 50);

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
    }

private:
    QPushButton* buttons[8][8];
};

*/

int main(int argc, char** argv) {

    QApplication a(argc, argv);
    Board b;
    b.createChessboard();
    b.show();
    return a.exec();
}

/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chessboard w;
    w.show();
    return a.exec();
}
*/





