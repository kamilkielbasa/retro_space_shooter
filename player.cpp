#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include "player_bullet.h"
#include "enemy.h"
#include "meteor.h"
#include "shot.h"
#include "shield.h"
#include "game.h"
#include "life.h"
#include "bonus.h"
#include "boss.h"

extern Game *game;

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/images/png/player.png"));

    shot_type = Single;
    double_shot = 0;
    triple_shot = 0;

    bullet_sound = new QMediaPlayer();
    bullet_sound->setMedia(QUrl("qrc:/sounds/sounds/laser_shot1.mp3"));

    explosion_sound = new QMediaPlayer();
    explosion_sound->setMedia(QUrl("qrc:/sounds/sounds/explosion.mp3"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
    case Qt::Key_Left: {
        if (pos().x() > 10) {
            setPos(x()-30, y());
            if (game->shield != nullptr) {
                game->shield->setPos(game->player->pos().x()-25, game->player->pos().y()-25);
            }
        }
        break;
    }

    case Qt::Key_Right: {
        if (pos().x() < 1080) {
            setPos(x()+30, y());
            if (game->shield != nullptr) {
                game->shield->setPos(game->player->pos().x()-25, game->player->pos().y()-25);
            }
        }
        break;
    }

    case Qt::Key_Space: {
        chooseShotType(shot_type);
        backToSingleShot();

        if (bullet_sound->state() == QMediaPlayer::PlayingState) {
            bullet_sound->setPosition(0);
        } else if (bullet_sound->state() == QMediaPlayer::StoppedState){
            bullet_sound->play();
        }
        break;
    }
    }
}

void Player::meteorSpawn()
{
    Meteor *meteor = new Meteor();
    scene()->addItem(meteor);
}

void Player::lifeSpawn()
{
    Life *life = new Life();
    scene()->addItem(life);
}

void Player::bonusSpawn()
{
    Bonus *bonus = new Bonus();
    scene()->addItem(bonus);
}

void Player::bossSpawn()
{
    Boss *boss = new Boss();
    scene()->addItem(boss);
}

void Player::enemySpawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::chooseShotType(const ShotType& st)
{
    switch (st) {
    case Single: {
        Shot *shot = new Shot();
        shot->setPos(x()+22, y()-28);
        scene()->addItem(shot);

        Player_Bullet *player_bullet = new Player_Bullet();
        player_bullet->setPos(x()+45, y()-30);
        scene()->addItem(player_bullet);
        break;
    }
    case Double: {
        double_shot++;

        Shot *shot[2];
        Player_Bullet *player_bullet[2];

        for (int i=0; i<2; i++) {
            shot[i] = new Shot();
            player_bullet[i] = new Player_Bullet();
        }

        shot[0]->setPos(x()-25, y()+5);
        shot[1]->setPos(x()+67, y()+5);
        player_bullet[0]->setPos(x(), y());
        player_bullet[1]->setPos(x()+90, y());

        for (int i=0; i<2; i++) {
            scene()->addItem(shot[i]);
            scene()->addItem(player_bullet[i]);
        }
        break;
    }

    case Triple: {
        triple_shot++;

        Shot *shot[3];
        Player_Bullet *player_bullet[3];

        for (int i=0; i<3; i++) {
            shot[i] = new Shot();
            player_bullet[i] = new Player_Bullet();
        }

        shot[0]->setPos(x()-25, y()+5);
        shot[1]->setPos(x()+22, y()-28);
        shot[2]->setPos(x()+67, y()+5);
        player_bullet[0]->setPos(x(), y());
        player_bullet[1]->setPos(x()+45, y()-30);
        player_bullet[2]->setPos(x()+90, y());

        for (int i=0; i<3; i++) {
            scene()->addItem(shot[i]);
            scene()->addItem(player_bullet[i]);
        }
    }

    default: {
        break;
    }
    }
}

void Player::backToSingleShot()
{
    switch (shot_type) {
    case Double: {
        if (double_shot >= 15) {
            double_shot = 0;
            shot_type = Single;
        }
        break;
    }

    case Triple: {
        if (triple_shot >= 10) {
            triple_shot = 0;
            shot_type = Single;
        }
        break;
    }

    default:
        break;
    }
}
