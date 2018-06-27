#include "boss.h"
#include <QTimer>
#include <QList>
#include "player_bullet.h"
#include "player.h"
#include "game.h"
#include "enemy_bullet.h"
#include "enemy_shot.h"

extern Game *game;

Boss::Boss(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    counter = 0;

    int random_number = rand() % 600;
    this->setPos(random_number, 0);

    this->setPixmap(QPixmap(":/images/png/enemyUFO.png").scaled(
                    QSize(80,80), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(75);

    QTimer *timer_shot = new QTimer(this);
    connect(timer_shot, SIGNAL(timeout()), this, SLOT(shot()));
    timer_shot->start(700);
}

void Boss::move()
{
    this->setPos(x(), y()+5);

    QList<QGraphicsItem*> colliding_items = collidingItems();

    for (int i=0, n=colliding_items.size(); i<n; i++) {
        if (typeid(*(colliding_items[i])) == typeid(Player_Bullet)) {
            ++counter;

            if (counter >= 5) {
                game->score->increase(100);
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                delete colliding_items[i];
                delete this;
                return;
            } else {
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
        }

        if (typeid(*(colliding_items[i])) == typeid(Player)) {
            for (int i=0; i<3; i++) {
                game->health->decrease();
            }

            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    if (this->pos().y() > 850) {
        scene()->removeItem(this);
        delete this;
    }
}

void Boss::shot()
{
    if ((this->pos().x() >= (game->player->pos().x() - 40)) &&
        (this->pos().x() <= (game->player->pos().x() + 40))) {
        Enemy_Shot *enemy_shot[2];
        Enemy_Bullet *enemy_bullet[2];

        for(int i=0; i<2; i++) {
            enemy_shot[i] = new Enemy_Shot();
            enemy_bullet[i] = new Enemy_Bullet();
        }

        enemy_shot[0]->setPos(this->pos().x()-24, this->pos().y()+22);
        enemy_shot[1]->setPos(this->pos().x()+50, this->pos().y()+22);

        enemy_bullet[0]->setPos(this->pos().x(), this->pos().y()+30);
        enemy_bullet[1]->setPos(this->pos().x()+75, this->pos().y()+30);

        for(int i=0; i<2; i++) {
            scene()->addItem(enemy_shot[i]);
            scene()->addItem(enemy_bullet[i]);
        }
    }
}
