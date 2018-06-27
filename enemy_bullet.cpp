#include "enemy_bullet.h"
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>
#include <QList>
#include "player.h"
#include "shield.h"
#include "game.h"
#include "player_bullet.h"

extern Game *game;

Enemy_Bullet::Enemy_Bullet(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/images/png/laserRed.png"));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(100);
}

void Enemy_Bullet::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for (int i=0, n=colliding_items.size(); i<n; i++) {
        if (typeid(*(colliding_items[i])) == typeid(Shield)) {
            scene()->removeItem(this);
            delete this;
            return;
        }

        if (typeid(*(colliding_items[i])) == typeid(Player)) {
            game->health->decrease();

            scene()->removeItem(this);
            delete this;
            return;
        }

        if (typeid(*(colliding_items[i])) == typeid(Player_Bullet)) {
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    this->setPos(x(), y()+15);

    if (pos().x() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
