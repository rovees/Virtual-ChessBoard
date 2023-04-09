#include "ChessBoardWindow.h"
#include "Structures.h"
#include <QLabel>

/*
class ChessPiece : public::QLabel
{
    Q_OBJECT

private:
    PieceType m_type;
    Color m_color;
    QPoint m_offset;

public:
    enum PieceType { Pawn, Knight, Bishop, Rook, Queen, King };
    enum PieceColor { White, Black };

    ChessPiece(PieceType type, Color color, QWidget *parent = nullptr) : QLabel(parent)
    {
        // Ustawienie obrazka figury w zależności od typu i koloru
        QString fileName;
        if (color == White)
        {
            switch (type)
            {
            case Pawn: fileName = "white_pawn.png"; break;
            case Knight: fileName = "white_knight.png"; break;
            case Bishop: fileName = "white_bishop.png"; break;
            case Rook: fileName = "white_rook.png"; break;
            case Queen: fileName = "white_queen.png"; break;
            case King: fileName = "white_king.png"; break;
            }
        }
        else
        {
            switch (type)
            {
            case Pawn: fileName = "black_pawn.png"; break;
            case Knight: fileName = "black_knight.png"; break;
            case Bishop: fileName = "black_bishop.png"; break;
            case Rook: fileName = "black_rook.png"; break;
            case Queen: fileName = "black_queen.png"; break;
            case King: fileName = "black_king.png"; break;
            }
        }
        QPixmap pixmap(fileName);
        setPixmap(pixmap);
    }

    PieceType type() const { return m_type; }
    Color color() const { return m_color; }

protected:
    void mousePressEvent(QMouseEvent *event)
    {
        if (event->button() == Qt::LeftButton)
        {
            // Zapisz pozycję kursora myszy względem etykiety
            m_offset = event->pos();
        }

    void mouseMoveEvent(QMouseEvent *event)
    {
        if (event->buttons() & Qt::LeftButton)
        {
            // Oblicz nową pozycję etykiety na podstawie pozycji kursora myszy i offsetu
            QPoint new_pos = mapToParent(event->pos() - m_offset);

            // Ogranicz pozycję do granic wirtualnej szachownicy
            new_pos.setX(qBound(0, new_pos.x(), parentWidget()->width() - width()));
            new_pos.setY(qBound(0, new_pos.y(), parentWidget()->height() - height()));

            // Ustaw nową pozycję etykiety
            move(new_pos);
        }
    }

};
*/


void ChessBoardWindow::createChessboard()
{
    QGridLayout *layout = new QGridLayout;
    // tworzenie planszy szachowej
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            QLabel *label = new QLabel(this);
            label->setGeometry(QRect(QPoint(75*j, 75*i), QSize(75, 75)));
            if((i+j)%2==0)
                label->setStyleSheet("background-color: white");
            else
                label->setStyleSheet("background-color: gray");

            // dodanie figur
            if(i==0 && (j==0 || j==7))
                label->setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/build-Szachy-Desktop_Qt_6_4_2_MinGW_64_bit-Debug/white_rook.png"));
            else if(i==0 && (j==1 || j==6))
                label->setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/build-Szachy-Desktop_Qt_6_4_2_MinGW_64_bit-Debug/white_knight.png"));
            else if(i==0 && (j==2 || j==5))
                label->setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/build-Szachy-Desktop_Qt_6_4_2_MinGW_64_bit-Debug/white_bishop.png"));
            else if(i==0 && j==3)
                label->setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/build-Szachy-Desktop_Qt_6_4_2_MinGW_64_bit-Debug/white_queen.png"));
            else if(i==0 && j==4)
                label->setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/build-Szachy-Desktop_Qt_6_4_2_MinGW_64_bit-Debug/white_king.png"));
            else if(i==1)
                label->setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/build-Szachy-Desktop_Qt_6_4_2_MinGW_64_bit-Debug/white_pawn.png"));
            else if(i==6)
                label->setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/build-Szachy-Desktop_Qt_6_4_2_MinGW_64_bit-Debug/black_pawn.png"));
            else if(i==7 && (j==0 || j==7))
                label->setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/build-Szachy-Desktop_Qt_6_4_2_MinGW_64_bit-Debug/black_rook.png"));
            else if(i==7 && (j==1 || j==6))
                label->setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/build-Szachy-Desktop_Qt_6_4_2_MinGW_64_bit-Debug/black_knight.png"));
            else if(i==7 && (j==2 || j==5))
                label->setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/build-Szachy-Desktop_Qt_6_4_2_MinGW_64_bit-Debug/black_bishop.png"));
            else if(i==7 && j==3)
                label->setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/build-Szachy-Desktop_Qt_6_4_2_MinGW_64_bit-Debug/black_queen.png"));
            else if(i==7 && j==4)
                label->setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/build-Szachy-Desktop_Qt_6_4_2_MinGW_64_bit-Debug/black_king.png"));

            label->setScaledContents(true);
            label->setAlignment(Qt::AlignCenter);
            // dodanie osi

        }
    }
}

ChessBoardWindow::ChessBoardWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createChessboard();

    // Ustawienie tytułu okna
    setWindowTitle("Szachy");

    // Ustawienie rozmiaru okna
    setFixedSize(700, 700);
    setAcceptDrops(true);
    /*
    // Dodanie planszy szachowej
    QWidget *board = new QWidget(this);
    board->setGeometry(0, 0, 800, 800);
    board->setStyleSheet("background-color: white;");

    // Dodanie pól planszy
    int x = 0, y = 0;
    for (int i = 0; i < 64; i++)
    {
        QWidget *square = new QWidget(board);
        square->setGeometry(x, y, 100, 100);
        square->setStyleSheet((i / 8 + i) % 2 ? "background-color: gray;" : "background-color: white;");
        x += 100;
        if (x == 800)
        {
            x = 0;
            y += 100;
        }
    }

    */

    // Ustawienie planszy na środku okna


}

ChessBoardWindow::~ChessBoardWindow()
{
}


void ChessBoardWindow::mousePressEvent(QMouseEvent *event)
{

    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if (!child)
        return;

    QPixmap pixmap = child->pixmap();
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->pos() - child->pos());

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("image/x-puzzle-piece", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - child->pos());

    child->setPixmap(QPixmap());
    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)
        child->close();
    else
        child->setPixmap(pixmap);

}


void ChessBoardWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("image/x-puzzle-piece"))
        event->accept();
    else
        event->ignore();
}

void ChessBoardWindow::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("image/x-puzzle-piece"))
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void ChessBoardWindow::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("image/x-puzzle-piece"))
    {
        QByteArray itemData = event->mimeData()->data("image/x-puzzle-piece");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        QLabel *newLabel = new QLabel(this);
        newLabel->setPixmap(pixmap);
        newLabel->move(event->position().toPoint() - offset);
        newLabel->show();

        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

/*
void Board::movePiece()
{
    QMouseEvent *MouseEvent;
    QDragEnterEvent *DragEnterEvent;
    QDragMoveEvent *DragMoveEvent;
    QDropEvent *DropEvent;
    mousePressEvent(MouseEvent);
    dragEnterEvent(DragEnterEvent);
    dragMoveEvent(DragMoveEvent);
    dropEvent(DropEvent);

}
*/





