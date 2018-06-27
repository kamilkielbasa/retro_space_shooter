#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Player_Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Player_Bullet(QGraphicsItem *parent = nullptr);
public slots:
    void move();
};

#endif // BULLET_H
