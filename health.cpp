#include "health.h"
#include <QFont>
#include <QTimer>
#include "game.h"

extern Game *game;

Health::Health(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    health = 10;

    this->setPixmapForHealthBar(health);
}

void Health::increase()
{
    if (health >= 4) {
        game->player->setPixmap(QPixmap(":/images/png/player.png"));
    }

    if (health == 10) {
        return;
    } else {
        health++;
        setPixmapForHealthBar(health);
    }
}

void Health::decrease()
{
    if (health <= 3) {
        game->player->setPixmap(QPixmap(":/images/png/playerDamaged.png"));
    }

    if (health == 0) {
        return;
    } else {
        health--;
        setPixmapForHealthBar(health);
    }
}

const int &Health::getHealth() const
{
    return health;
}

void Health::setPixmapForHealthBar(int h)
{
    this->setPixmap(QPixmap(":/life_bar/png/life_bar/life_bar_" + QString::number(h) + ".png").
                    scaled(QSize(250, 500), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}


