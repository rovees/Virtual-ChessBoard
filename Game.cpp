#include "Game.h"
#include "Button.h"
#include <QPixmap>
#include "King.h"
#include <QDebug>

Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    // utworzenie sceny
    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,0.8*1400,0.8*900);

    // utworzenie widoku
    setFixedSize(0.8*1400,0.8*900);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(gameScene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);
    pieceToMove = nullptr;

    // wyswietlanie aktualnej tury
    turnDisplay = new QGraphicsTextItem();
    turnDisplay->setPos(width()/2-0.8*100,0.8*10);
    turnDisplay->setZValue(1);
    turnDisplay->setDefaultTextColor(Qt::white);
    turnDisplay->setFont(QFont("",0.8*18));
    turnDisplay->setPlainText("Turn : WHITE");

    // wyświetlanie informacji czy jest szach szacha
    check = new QGraphicsTextItem();
    check->setPos(width()/2-0.8*100,0.8*860);
    check->setZValue(4);
    check->setDefaultTextColor(Qt::red);
    check->setFont(QFont("",0.8*18));
    check->setPlainText("CHECK!");
    check->setVisible(false);
    setTurn("WHITE");
}

void Game::drawChessBoard()
{
    chess = new ChessBoard();
    drawDeadHolder(0,0,Qt::lightGray);
    drawDeadHolder(0.8*1100,0,Qt::lightGray);
    chess->drawBoxes(width()/2-0.8*400,0.8*50);

}

void Game::displayDeadWhite()
{
    int SHIFT = 0.8*50;
    int j = 0;
    int k = 0;
    for(size_t i = 0, n = whiteDead.size(); i < n; i++) {
        if(j == 3){
            k++;
            j = 0;
        }
        j++;
        whiteDead[i]->setPos(0.8*40+SHIFT*j,0.8*100+SHIFT*2*k);
    }
}

void Game::displayDeadBlack()
{
    int SHIFT = 0.8*50;
    int j = 0;
    int k = 0;
    for(size_t i = 0, n = blackDead.size(); i<n; i++) {
        if(j == 3){
            k++;
            j = 0;
        }
        j++;
        blackDead[i]->setPos(0.8*1140+SHIFT*j,0.8*100+SHIFT*2*k);
    }
}

void Game::placeInDeadPlace(Piece *piece)
{

    // umieszczenie zbitej figury w odpowiednim miejscu w zależności od koloru
    if(piece->getSide() == "WHITE") {
        whiteDead.append(piece);
        displayDeadWhite();
    }
    else{
        blackDead.append(piece);
        displayDeadBlack();
    }

    // usunięcie zbitej figury z listy żywych figur
    alivePiece.removeAll(piece);
}


void Game::addToScene(QGraphicsItem *item)
{
    qDebug() << item;

    gameScene->addItem(item);
}

void Game::removeFromScene(QGraphicsItem *item)
{
    gameScene->removeItem(item);

}

QString Game::getTurn()
{
    return turn;
}

void Game::setTurn(QString value)
{
    turn = value;
}


void Game::changeTurn()
{
    if(getTurn() == "WHITE")
        setTurn("BLACK");
    else
        setTurn("WHITE");
    turnDisplay->setPlainText("Turn : " + getTurn());
}

void Game::start()
{
    for(size_t i = 0, n = listG.size(); i < n; i++)
        removeFromScene(listG[i]);

    addToScene(turnDisplay);
    QGraphicsTextItem *whitePiece = new QGraphicsTextItem();
    whitePiece->setPos(0.8*70,0.8*10);
    whitePiece->setZValue(1);
    whitePiece->setDefaultTextColor(Qt::white);
    whitePiece->setFont(QFont("",0.8*14));
    whitePiece->setPlainText("WHITE PIECE");
    addToScene(whitePiece);

    QGraphicsTextItem *blackPiece = new QGraphicsTextItem();
    blackPiece->setPos(0.8*1170,0.8*10);
    blackPiece->setZValue(1);
    blackPiece->setDefaultTextColor(Qt::black);
    blackPiece->setFont(QFont("",0.8*14));
    blackPiece->setPlainText("BLACK PIECE");
    addToScene(blackPiece);
    addToScene(check);
    chess->addChessPiece();
}

void Game::drawDeadHolder(int x, int y, QColor color)
{
    deadHolder = new QGraphicsRectItem(x, y, 0.8*300, 0.8*900);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    deadHolder->setBrush(brush);
    addToScene(deadHolder);
}

void Game::displayMainMenu()
{

    QGraphicsPixmapItem *p = new QGraphicsPixmapItem();
    p->setPixmap(QPixmap(":/images/white_king.png"));
    p->setPos(0.8*420,0.8*170);
    addToScene(p);
    listG.append(p);

    QGraphicsPixmapItem *p1 = new QGraphicsPixmapItem();
    p1->setPixmap(QPixmap(":/images/black_king.png"));
    p1->setPos(0.8*920,0.8*170);
    addToScene(p1);
    listG.append(p1);

    // utworzenie tytułu
    QGraphicsTextItem *titleText = new QGraphicsTextItem("Chess");
    QFont titleFont("arial", 0.8*50);
    titleText->setFont(titleFont);
    int xPos = width()/2 - titleText->boundingRect().width()/2;
    int yPos = 0.8*150;
    titleText->setPos(xPos,yPos);
    addToScene(titleText);
    listG.append(titleText);

    // utworzenie przycisku
    Button * playButton = new Button("Play");
    int pxPos = width()/2 - playButton->boundingRect().width()/2;
    int pyPos = 0.8*300;
    playButton->setPos(pxPos,pyPos);
    connect(playButton, SIGNAL(clicked()) , this, SLOT(start()));
    addToScene(playButton);
    listG.append(playButton);

    // utworzenie przycisku wyjścia z aplikacji
    Button * quitButton = new Button("Quit");
    int qxPos = width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 0.8*375;
    quitButton->setPos(qxPos, qyPos);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    addToScene(quitButton);
    drawChessBoard();
    listG.append(quitButton);
}

void Game::setTurnDisplay(QString value)
{
    turnDisplay->setPlainText(value);
}

void Game::removeAll(){
    QList<QGraphicsItem*> itemsList = gameScene->items();
    for(size_t i = 0, n = itemsList.size();i<n;i++) {
        // if(itemsList[i] != check)
        removeFromScene(itemsList[i]);
    }
}


