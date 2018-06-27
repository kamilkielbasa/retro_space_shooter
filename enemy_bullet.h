#ifndef ENEMY_BULLET_H
#define ENEMY_BULLET_H


#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Enemy_Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Enemy_Bullet(QGraphicsItem *parent = nullptr);
public slots:
    void move();
};

#endif // ENEMY_BULLET_H
