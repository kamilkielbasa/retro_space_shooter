#include "life.h"
#include "game.h"
#include <QTimer>
#include <QList>

extern Game *game;

Life::Life(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    int random_number = rand() % 700;
    this->setPos(random_number, 0);

    this->setPixmap(QPixmap(":/images/png/heart.png").scaled(
                    QSize(48,48), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(75);
}

void Life::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i=0, n=colliding_items.size(); i<n; i++) {
        if (typeid(*(colliding_items[i])) == typeid(Shield)) {
            game->health->increase();
            scene()->removeItem(this);
            delete this;
            return;
        }

        if (typeid(*(colliding_items[i])) == typeid(Player)) {
            game->health->increase();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    this->setPos(x(), y()+5);

    if (this->pos().y() > 850) {
        scene()->removeItem(this);
        delete this;
    }
}
