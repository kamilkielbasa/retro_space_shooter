#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include "game.h"
#include "shield.h"
#include <QDebug>
#include "enemy_bullet.h"
#include "enemy_shot.h"

extern Game *game;

Enemy::Enemy(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    int random_number = rand() % 700;
    this->setPos(random_number, 0);

    this->setPixmap(QPixmap(":/images/png/enemyShip.png"));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(75);

    QTimer *timer_shot = new QTimer(this);
    connect(timer_shot, SIGNAL(timeout()), this, SLOT(shot()));
    timer_shot->start(600);
}

void Enemy::move()
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
    }

    this->setPos(x(), y()+5);

    if (this->pos().y() > 850) {
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}

void Enemy::shot()
{
    if ((this->pos().x() >= (game->player->pos().x() - 40)) &&
        (this->pos().x() <= (game->player->pos().x() + 40))) {
        Enemy_Shot *enemy_shot = new Enemy_Shot();
        enemy_shot->setPos(this->pos().x()+22, this->pos().y()+25);
        scene()->addItem(enemy_shot);

        Enemy_Bullet *enemy_bullet = new Enemy_Bullet();
        enemy_bullet->setPos(this->pos().x()+43, this->pos().y()+55);
        scene()->addItem(enemy_bullet);
    }
}
