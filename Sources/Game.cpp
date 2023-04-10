#include "Headers/Game.h"
#include <QTimer>
#include <QBrush>
#include <QImage>
#include <QMediaPlayer>
#include <QAudioOutput>

Game::Game(QWidget *parent){
    /*
    view = new QGraphicsView(this);
    QOpenGLWidget *gl = new QOpenGLWidget();
    QSurfaceFormat format;
    format.setSamples(4);
    gl->setFormat(format);
    view->setViewport(gl);
    */

    // /*
    //create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/Resources/bg.png")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    // */

    //create an item to put into the scene
    Player * player = new Player();
    player->setPos(400,540);
    // make the player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    //add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    // play background music
    QMediaPlayer * music = new QMediaPlayer();
    QAudioOutput * audioOutput = new QAudioOutput();
    music->setAudioOutput(audioOutput);
    music->setSource(QUrl("qrc:/sounds/Resources/bgsound.mp3"));
    audioOutput->setVolume(1);

    if(music->playbackState() == QMediaPlayer::PlayingState){
        music->setPosition(0);
    }
    else if (music->playbackState() == QMediaPlayer::StoppedState){
        music->play();
    }

    // show the view
    show();
}

/*
Game::~Game(){

}

void Game::setGame()
{
    //create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/Resources/bg.png")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
}
*/
