#include "enemy_shot.h"
#include <QGraphicsScene>
#include <QTimer>

Enemy_Shot::Enemy_Shot(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/images/png/laserRedShot.png"));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(deleteShot()));
    timer->start(150);
}

void Enemy_Shot::deleteShot()
{
    scene()->removeItem(this);
    delete this;
}
