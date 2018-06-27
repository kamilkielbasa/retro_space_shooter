#include "player_bullet.h"
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>
#include <QList>
#include "enemy.h"
#include "game.h"
#include "meteor.h"
#include "enemy_bullet.h"

extern Game *game;

Player_Bullet::Player_Bullet(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/images/png/laserGreen.png"));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(75);
}

void Player_Bullet::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for (int i=0, n=colliding_items.size(); i<n; i++) {
        if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
            game->score->increase(20);

            if (game->player->getExpSound().state() == QMediaPlayer::PlayingState) {
                game->player->setExpSound().setPosition(0);
            } else if (game->player->getExpSound().state() == QMediaPlayer::StoppedState) {
                game->player->setExpSound().play();
            }

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(Meteor)) {
            game->score->increase(2);

            if (game->player->getExpSound().state() == QMediaPlayer::PlayingState) {
                game->player->setExpSound().setPosition(0);
            } else if (game->player->getExpSound().state() == QMediaPlayer::StoppedState) {
                game->player->setExpSound().play();
            }

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }

        if (typeid(*(colliding_items[i])) == typeid(Enemy_Bullet)) {
            game->score->increase(1);
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    this->setPos(x(), y()-15);
    if (pos().x() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
