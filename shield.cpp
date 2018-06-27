#include "shield.h"
#include <QGraphicsScene>
#include <QTimer>
#include "game.h"

extern Game *game;

Shield::Shield(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/images/png/shield.png"));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showShield()));
    timer->start(10000);
}

void Shield::showShield()
{
    scene()->removeItem(this);
    delete this;
    game->shield = nullptr;
}
