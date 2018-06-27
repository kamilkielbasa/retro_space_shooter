#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "game.h"

extern Game *game;

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Enemy(QGraphicsItem *parent = nullptr);
private slots:
    void move();
    void shot();
};

#endif // ENEMY_H
