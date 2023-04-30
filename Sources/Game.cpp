#include "Headers/Game.h"
#include "Headers/Menu.h"
#include <QTimer>
#include <QBrush>
#include <QImage>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QGraphicsItem>
#include <QGraphicsTextItem>


Game::Game(QWidget *parent){
    //create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/Resources/bg.png")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setViewport(new QOpenGLWidget());
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

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

    // loop the music
    connect(music,&QMediaPlayer::mediaStatusChanged,music,&QMediaPlayer::play);

    // play the music
    music->play();

    // show the view
    show();
}

Game::~Game()
{

}
void Game::start(){
    if (!scene->items().isEmpty()) {
        scene->clear();
    }
}


void Game::displayMainMenu(){
    // title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Star Shootr"));
    QFont titleFont("comic sans",50);
    titleText ->setFont(titleFont);
    int txPos = this-> width()/2 - titleText -> boundingRect().width()/2;
    int tyPos = 150;
    titleText -> setPos(txPos, tyPos);
    scene -> addItem(titleText);

    // create play button
    // Play button
    Menu* menuPlay = new Menu(QString("Play"));
    int bxPos = this->width() / 2 - menuPlay->boundingRect().width() / 2;
    int byPos = 275;
    menuPlay->setPos(bxPos, byPos);
    connect(menuPlay, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(menuPlay);

    // quit button
    Menu* quitMenu = new Menu(QString("Quit"));
    int dxPos = this-> width()/2 - quitMenu -> boundingRect().width()/2;
    int dyPos = 350;
    quitMenu-> setPos(dxPos, dyPos);
    connect(quitMenu, SIGNAL(clicked()),this,SLOT(close()));
    scene ->addItem(quitMenu);
}





