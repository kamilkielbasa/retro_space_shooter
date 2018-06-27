#ifndef ENEMY_SHOT_H
#define ENEMY_SHOT_H


#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Enemy_Shot : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Enemy_Shot(QGraphicsItem *parent = nullptr);
private slots:
    void deleteShot();
};

#endif // ENEMY_SHOT_H
