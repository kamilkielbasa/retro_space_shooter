#ifndef BONUS_H
#define BONUS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bonus : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Bonus(QGraphicsItem *parent = nullptr);

private slots:
    void move();

private:
    void chooseBonus();
};

#endif // BONUS_H
