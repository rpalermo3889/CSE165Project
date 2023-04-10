#include <QApplication>
#include "Headers/Game.h"

Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    /*
    Game w;
    w.resize(640,480);
    */

    game = new Game();
    game->show();

    return a.exec();
}
