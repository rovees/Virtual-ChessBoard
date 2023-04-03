#include "Board.h"

Board::Board(QWidget *parent)
    : QMainWindow(parent)
{
    /*
    // Ustawienie tytułu okna
    setWindowTitle("Szachy");

    // Ustawienie rozmiaru okna
    setFixedSize(800, 800);

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

    // Ustawienie planszy na środku okna
    setCentralWidget(board);
    */
}

Board::~Board()
{
}

void Board::mousePressEvent(QMouseEvent *event)
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

void Board::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("image/x-puzzle-piece"))
        event->accept();
    else
        event->ignore();
}

void Board::dragMoveEvent(QDragMoveEvent *event)
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

void Board::ropEvent(QDropEvent *event)
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
        newLabel->move(event->pos() - offset);
        newLabel->show();

        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void Board::createChessboard()
{
    // tworzenie planszy szachowej
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            QLabel *label = new QLabel(this);
            label->setGeometry(QRect(QPoint(50*j, 50*i), QSize(100, 50)));
            if((i+j)%2==0)
                label->setStyleSheet("background-color: white");
            else
                label->setStyleSheet("background-color: gray");

            // dodanie pionków
            if(i==0 && (j==0 || j==7))
                label->setPixmap(QPixmap("white_rook.png"));
            else if(i==0 && (j==1 || j==6))
                label->setPixmap(QPixmap("white_knight.png"));
            else if(i==0 && (j==2 || j==5))
                label->setPixmap(QPixmap("white_bishop.png"));
            else if(i==0 && j==3)
                label->setPixmap(QPixmap(":white_queen.png"));
            else if(i==0 && j==4)
                label->setPixmap(QPixmap("white_king.png"));
            else if(i==1)
                label->setPixmap(QPixmap("white_pawn.png"));
            else if(i==6)
                label->setPixmap(QPixmap("blackpawn.png"));
            else if(i==7 && (j==0 || j==7))
                label->setPixmap(QPixmap("black_rook.png"));
            else if(i==7 && (j==1 || j==6))
                label->setPixmap(QPixmap("black_knight.png"));
            else if(i==7 && (j==2 || j==5))
                label->setPixmap(QPixmap("black_bishop.png"));
            else if(i==7 && j==3)
                label->setPixmap(QPixmap("black_queen.png"));
            else if(i==7 && j==4)
                label->setPixmap(QPixmap("black_king.png"));

            label->setScaledContents(true);
            label->setAlignment(Qt::AlignCenter);
            label->show();
        }
    }
}
