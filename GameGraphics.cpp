#include "Button.h"
#include "Game.h"
#include "GameGraphics.h"

GameGraphics::GameGraphics(QWidget *parent, Game *g) : QGraphicsView(parent)
{
    // utworzenie sceny
    gameLogic = g;
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

    // wyswietlanie aktualnej tury
    turnDisplay = new QGraphicsTextItem();
    turnDisplay->setPos(width()/2-0.8*100, 0.8*10);
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
}

GameGraphics::~GameGraphics()
{

}

Game *GameGraphics::getGameLogic()
{
    return gameLogic;
}

QGraphicsScene *GameGraphics::getGameScene()
{
    return gameScene;
}

void GameGraphics::drawChessBoard()
{
    drawDeadHolder(0,0,Qt::lightGray);
    drawDeadHolder(0.8*1100,0,Qt::lightGray);
    gameLogic->getChess()->drawBoxes(width()/2-0.8*400,0.8*50);
}

void GameGraphics::displayDeadWhite()
{
    int SHIFT = 0.8*50;
    int j = 0;
    int k = 0;
    for(size_t i = 0, n = gameLogic->getWhiteDead().size(); i < n; i++) {
        if(j == 3){
            k++;
            j = 0;
        }
        j++;
        gameLogic->getWhiteDead()[i]->getPieceGraphics()->setPos(0.8*40+SHIFT*j, 0.8*100+SHIFT*2*k);
    }
}

void GameGraphics::displayDeadBlack()
{
    int SHIFT = 0.8*50;
    int j = 0;
    int k = 0;
    for(size_t i = 0, n = gameLogic->getBlackDead().size(); i<n; i++) {
        if(j == 3){
            k++;
            j = 0;
        }
        j++;
        gameLogic->getBlackDead()[i]->getPieceGraphics()->setPos(0.8*1140+SHIFT*j,0.8*100+SHIFT*2*k);
    }
}

void GameGraphics::placeInDeadPlace(Piece *piece)
{

    // umieszczenie zbitej figury w odpowiednim miejscu w zależności od koloru
    if(piece->getSide() == "WHITE") {
        gameLogic->getWhiteDead().append(piece);
        displayDeadWhite();
    }
    else{
        gameLogic->getBlackDead().append(piece);
        displayDeadBlack();
    }

    // usunięcie zbitej figury z listy żywych figur
    gameLogic->getAlivePiece().removeAll(piece);
}


void GameGraphics::addToScene(QGraphicsItem *item)
{
    gameScene->addItem(item);
}

void GameGraphics::removeFromScene(QGraphicsItem *item)
{
    gameScene->removeItem(item);
}

void GameGraphics::changeTurn()
{
    if(gameLogic->getTurn() == "WHITE")
        gameLogic->setTurn("BLACK");
    else
        gameLogic->setTurn("WHITE");
    turnDisplay->setPlainText("Turn : " + gameLogic->getTurn());
}

void GameGraphics::start()
{
    for(size_t i = 0, n = listGraphicsItems.size(); i < n; i++)
        removeFromScene(listGraphicsItems[i]);

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
    gameLogic->getChess()->addChessPiece();
}

void GameGraphics::drawDeadHolder(int x, int y, QColor color)
{
    deadHolder = new QGraphicsRectItem(x, y, 0.8*300, 0.8*900);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    deadHolder->setBrush(brush);
    addToScene(deadHolder);
}


void GameGraphics::displayMainMenu()
{
    // utworzenie tytułu
    QGraphicsTextItem *titleText = new QGraphicsTextItem("Chess");
    QFont titleFont("arial", 0.8*50);
    titleText->setFont(titleFont);
    int xPos = width()/2 - titleText->boundingRect().width()/2;
    int yPos = 0.8*150;
    titleText->setPos(xPos,yPos);
    addToScene(titleText);
    listGraphicsItems.append(titleText);

    // utworzenie przycisku
    Button *playButton = new Button("Play");
    int pxPos = width()/2 - playButton->boundingRect().width()/2;
    int pyPos = 0.8*300;
    playButton->setPos(pxPos,pyPos);
    connect(playButton, SIGNAL(clicked()) , this, SLOT(start()));
    addToScene(playButton);
    listGraphicsItems.append(playButton);

    // utworzenie przycisku wyjścia z aplikacji
    Button *quitButton = new Button("Quit");
    int qxPos = width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 0.45 * height();
    quitButton->setPos(qxPos, qyPos);
    qDebug() << "Height(): " << height();
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    addToScene(quitButton);
    drawChessBoard();
    listGraphicsItems.append(quitButton);
}

void GameGraphics::setWinner(QString winnerColor)
{
    winner = winnerColor;
}

QString GameGraphics::getWinner()
{
    return winner;
}

void GameGraphics::displayWinner(QString winColor)
{
    QGraphicsTextItem *Winner = new QGraphicsTextItem();
    Winner->setDefaultTextColor(Qt::red);
    Winner->setPos(0.3*1400, 0.3*900);
    Winner->setPlainText(winColor + " WON");
    QFont winnerFont("arial", 0.8*50);
    Winner->setFont(winnerFont);
    addToScene(Winner);
}

void GameGraphics::setTurnDisplay(QString value)
{
    turnDisplay->setPlainText(value);
}

void GameGraphics::removeAll(){
    QList<QGraphicsItem*> itemsList = gameScene->items();
    for(size_t i = 0, n = itemsList.size(); i < n; i++) {
        removeFromScene(itemsList[i]);
    }
}

QGraphicsTextItem *GameGraphics::getCheck()
{
    return check;
}
