#include "bonus.h"
#include "game.h"
#include "shield.h"
#include <QTimer>
#include <QList>
#include <QDebug>

extern Game *game;

Bonus::Bonus(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    int random_number = rand() % 700;
    this->setPos(random_number, 0);

    this->setPixmap(QPixmap(":/images/png/bonus.png").scaled(
                    QSize(80,80), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(75);
}

void Bonus::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for (int i=0, n=colliding_items.size(); i<n; i++) {
        if (typeid(*(colliding_items[i])) == typeid(Player)) {
            chooseBonus();

            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    this->setPos(x(), y()+3);

    if (this->pos().y() > 850) {
        scene()->removeItem(this);
        delete this;
    }
}

void Bonus::chooseBonus()
{
    unsigned int random_number = rand() % 3;

    switch (random_number) {
    case 0:
        if (game->shield == nullptr) {
            game->shield = new Shield();
            scene()->addItem(game->shield);
            game->shield->setPos(game->player->pos().x()-25, game->player->pos().y()-25);
        }
        break;
    case 1:
        game->player->setShotType(Double);
        break;
    case 2:
        game->player->setShotType(Triple);
        break;
    default:
        break;
    }
}
