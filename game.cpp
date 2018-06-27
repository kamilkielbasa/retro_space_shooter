#include "game.h"
#include <QImage>
#include <QTimer>
#include <QMediaPlayer>

Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,900);

    this->setBackgroundBrush(QBrush(QImage(":/images/png/Background/starBackground.png")));
    this->setScene(scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(1200,900);
    this->show();

    QMediaPlayer *background_music = new QMediaPlayer();
    background_music->setMedia(QUrl("qrc:/sounds/sounds/background.mp3"));
    background_music->play();
    background_music->setVolume(50);

    shield = nullptr;

    player = new Player();
    player->setPos(900,800);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    unsigned int enemy_time = 2000;
    unsigned int meteor_time = 1500;
    unsigned int life_time = 8000;
    unsigned int bonus_time = 10000;
    unsigned int boss_time = 12000;

    enemy_timer = new QTimer();
    QObject::connect(enemy_timer, SIGNAL(timeout()), player, SLOT(enemySpawn()));
    enemy_timer->start(enemy_time);

    meteor_timer = new QTimer();
    QObject::connect(meteor_timer, SIGNAL(timeout()), player, SLOT(meteorSpawn()));
    meteor_timer->start(meteor_time);

    life_timer = new QTimer();
    QObject::connect(life_timer, SIGNAL(timeout()), player, SLOT(lifeSpawn()));
    life_timer->start(life_time);

    bonus_timer = new QTimer();
    QObject::connect(bonus_timer, SIGNAL(timeout()), player, SLOT(bonusSpawn()));
    bonus_timer->start(bonus_time);

    boss_timer = new QTimer();
    QObject::connect(boss_timer, SIGNAL(timeout()), player, SLOT(bossSpawn()));
    boss_timer->start(boss_time);

    score = new Score();
    score->setPos(score->x()+25, score->y()+50);
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x()+25, health->y()+25);
    scene->addItem(health);
}
