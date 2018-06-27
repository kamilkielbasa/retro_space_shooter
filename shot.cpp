#include "shot.h"
#include <QGraphicsScene>
#include <QTimer>

Shot::Shot(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/images/png/laserGreenShot.png"));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(deleteShot()));
    timer->start(100);
}

void Shot::deleteShot()
{
    scene()->removeItem(this);
    delete this;
}

