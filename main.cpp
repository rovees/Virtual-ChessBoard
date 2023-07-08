#include <QApplication>
#include "Game.h"
#include "GameGraphics.h"


Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    game->getGameGraphics()->show();
    game->getGameGraphics()->displayMainMenu();
    return a.exec();
}




