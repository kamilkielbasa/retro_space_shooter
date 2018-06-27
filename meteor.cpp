#include "meteor.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include "player.h"
#include "game.h"

extern Game *game;

Meteor::Meteor(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    counter = 0;

    int random_number = rand() % 700;
    this->setPos(random_number, 0);

    if (random_number % 2 == 0) {
        this->setPixmap(QPixmap(":/images/png/meteorBig.png").scaled(
                        QSize(60,60), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    } else {
        this->setPixmap(QPixmap(":/images/png/meteorSmall.png"));
    }

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    connect(timer, SIGNAL(timeout()), this, SLOT(rotate()));
    timer->start(50);
}

void Meteor::move()
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

    this->setPos(x(), y()+8);

    if (this->pos().y() > 850) {
        scene()->removeItem(this);
        delete this;
    }
}

void Meteor::rotate()
{
    counter += 3;
    this->setRotation(counter);
}
