#ifndef LIFE_H
#define LIFE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Life : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Life(QGraphicsItem *parent = nullptr);
private slots:
    void move();
};

#endif // LIFE_H
