#ifndef BOSS_H
#define BOSS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Boss : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Boss(QGraphicsItem *parent = nullptr);

private slots:
    void move();
    void shot();

private:
    unsigned int counter;
};

#endif // BOSS_H
